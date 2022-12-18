%{
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

enum TipoVar { TIPO_LET, TIPO_VAR, TIPO_CONST };

struct Atributos {
  vector<string> c;
  string v;
  int n_args = 0;
};

struct Simbolo {
  int linha, coluna;
  TipoVar tipo;
};

// Tipo dos atributos: YYSTYPE eh o tipo usado para os atributos
#define YYSTYPE Atributos

// Atualizacao de linhas e colunas
#define YY_USER_ACTION \
    yylloc.first_line = yylloc.last_line; \
    yylloc.first_column = yylloc.last_column; \
    for(int i = 0; yytext[i] != '\0'; i++) { \
        if(yytext[i] == '\n') { \
            yylloc.last_line++; \
            yylloc.last_column = 0; \
        } \
        else { \
            yylloc.last_column++; \
        } \
    }

// Funcoes
int yylex();
int yyparse();
void yyerror(const char *);
void print_prod(const char *);
void atualiza_atributos_token(int token);
vector<string> concatena(vector<string> a, vector<string> b);
vector<string> operator+(vector<string> a, vector<string> b);
vector<string> operator+(vector<string> a, string b);
vector<string> operator+(string a, vector<string> b);
vector<string> to_vector(string s);
string gera_label(string prefixo);
vector<string> resolve_enderecos(vector<string> entrada);
void atualiza_variaveis_declaradas(string var);
void verifica_variaveis_declaradas(string var);
void print_NPR(vector<string>);
vector<string> gera_inicializacao_de_argumento(string id, int n_args);
string trim(string s, string chars);
vector<string> tokeniza(string s);
vector<string> gera_funcao(string id, string label);
vector<string> gera_fim_funcao();
vector<string> gera_retorno();
void atualiza_variaveis_declaradas_escopo(string var);

// Variaveis
map<string, int> variaveis_declaradas;
map<string, int> variaveis_declaradas_escopo;
vector<string> epsilon;
vector<string> funcoes;
int n_params;
vector<bool> pode_retornar = { false };
bool eh_escopo = false;
vector<map<string, Simbolo>> ts = {};

%}

// Opcao para usar a localizacao do bison
%locations

%token NUM
%token ID 
%token LET
%token VAR
%token CONST
%token OBJ
%token ARRAY
%token STRING
%token ADD
%token IF
%token ELSE
%token IGUAL
%token DIF
%token INC
%token WHILE
%token FOR
%token FUNCTION
%token ASM
%token RETURN
%token BLOCO
%token LAMBDA_NOVO_OBJ
%token ARROW
%token TRUE
%token FALSE

// Start indica o simbolo inicial da gramatica
%start s

// Precedencia e associatividade dos operadores
%right '=' 
%right '?'
%left ':'
%nonassoc DIF
%left '+' '-'
%left '*' '/' '%'
%right ADD INC
%right ELSE 'T' // conflito de shift reduce 
%right '('
%left '.'

%%

s : cmds { print_prod("s -> cmds"); $1.c = $1.c + "." + funcoes; print_NPR($1.c); }
  ;

cmds : cmd_1 separador cmds   { print_prod("cmds -> cmd_1 ; cmds"); $$.c = $1.c + $3.c; }
  | cmd_2 cmds                { print_prod("cmds -> cmd_2 cmds"); $$.c = $1.c + $2.c; }
  |                           { print_prod("cmds -> epsilon"); $$.c = epsilon; }
  ;

cmd_1 : atr           { print_prod("cmd_1 -> atr"); $$.c = $1.c + "^"; }
  | LET decl          { print_prod("cmd_1 -> LET decl"); $$.c = $2.c; }
  | VAR decl          { print_prod("cmd_1 -> VAR decl"); $$.c = $2.c; }
  | CONST decl        { print_prod("cmd_1 -> CONST decl"); $$.c = $2.c; }
  | loop              { print_prod("cmd_1 -> loop"); }
  | exp ASM           { print_prod("cmd_1 -> exp ASM"); $$.c = $1.c + $2.c + "^"; }
  | exp               { print_prod("cmd_1 -> exp"); $$.c = $1.c; }
  | RETURN            { print_prod("cmd_1 -> RETURN"); 
                        if(!pode_retornar.back()) {
                            cout << "Erro: Não é permitido 'return' fora de funções." << endl;
                            exit(1);
                        }
                        $$.c = gera_retorno(); 
                      } 
  | RETURN exp        { print_prod("cmd_1 -> RETURN exp"); 
                        if(!pode_retornar.back()) {
                            cout << "Erro: Não é permitido 'return' fora de funções." << endl;
                            exit(1);
                        }
                        $$.c = $2.c + gera_retorno(); 
                      } 
  ;

cmd_2 : condicional       { print_prod("cmd_2 -> condicional"); }
  | funcao                { print_prod("cmd_2 -> funcao"); }
  | bloco                 { print_prod("cmd_2 -> bloco"); }
  ;

bloco: '{' empilha_escopo cmds '}' desempilha_escopo { print_prod("bloco -> { empilha_escopo cmds } desempilha_escopo"); $$.c = "<{" + $3.c + "}>"; }
  ; 

funcao: FUNCTION ID empilha_escopo_func '(' args ')' corpo  desempilha_escopo_func { 
                                          print_prod("funcao -> FUNCTION ID ( args ) corpo"); 
                                          string fim_func = gera_label($2.v); 
                                          funcoes = funcoes + (":" + fim_func) + $5.c + $7.c + gera_fim_funcao();
                                          $$.c = gera_funcao($2.v, fim_func);
                                        }
  | FUNCTION ID empilha_escopo_func '(' ')' corpo desempilha_escopo_func {
                                          print_prod("funcao -> FUNCTION ID ( ) corpo"); 
                                          string fim_func = gera_label($2.v); 
                                          funcoes = funcoes + (":" + fim_func) + $6.c + gera_fim_funcao();
                                          $$.c = gera_funcao($2.v, fim_func);
                                        }
  | FUNCTION empilha_escopo_func '(' args ')' corpo desempilha_escopo_func {
                                          print_prod("funcao -> FUNCTION ( args ) corpo"); 
                                          string fim_func = gera_label("anonima"); 
                                          funcoes = funcoes + (":" + fim_func) + $4.c + $6.c + gera_fim_funcao();
                                          $$.c = gera_funcao("anonima", fim_func);
                                        }
  | ID LAMBDA_NOVO_OBJ  { print_prod("funcao -> ID LAMBDA_NOVO_OBJ"); 
                          // $$.c = gera_novo_objeto($1.v);
                        }
  | ID ARROW BLOCO      { print_prod("funcao -> ID ARROW BLOCO"); 
                          // $$.c = gera_novo_objeto($1.v);
                        }
  | ID ARROW exp        { print_prod("funcao -> ID ARROW exp"); 
                          // $$.c = gera_novo_objeto($1.v);
                        }
  ;

args: args ',' arg { print_prod("args -> args , arg"); 
                      atualiza_variaveis_declaradas_escopo($3.v);
                      $$.v = "";
                      $$.n_args = $1.n_args + 1; 
                      $$.c = $1.c + gera_inicializacao_de_argumento($3.v, $$.n_args);
                  }
  | arg            { print_prod("args -> arg"); 
                     atualiza_variaveis_declaradas_escopo($1.v);
                     $$.v = "";
                     $$.n_args = 1;
                     $$.c = gera_inicializacao_de_argumento($1.v, $$.n_args);
                   }
  ;

arg: ID { print_prod("arg -> ID");
          $$.v = $1.v;
          $$.c = $1.c;
          $$.n_args = 1;
        }
    | ID '=' exp { print_prod("arg -> ID = exp");
                 $$.v = $1.v;
                 $$.c = $1.c + $3.c + gera_inicializacao_de_argumento($1.v, $$.n_args);
                 $$.n_args = 1;
               }
    | exp { print_prod("arg -> exp");
            $$.v = $1.v;
            $$.c = $1.c;
            $$.n_args = 1;
          }
  ;

empilha_escopo_func: empilha_escopo { print_prod("empilha_escopo_func -> empilha_escopo"); pode_retornar.push_back(true); }
  ;

desempilha_escopo_func: desempilha_escopo { print_prod("desempilha_escopo_func -> desempilha_escopo"); pode_retornar.pop_back(); }
  ;

empilha_escopo: { print_prod("empilha_escopo -> "); ts.push_back(map<string, Simbolo>{}); eh_escopo = true; }
  ;

desempilha_escopo: { print_prod("desempilha_escopo -> "); ts.pop_back(); variaveis_declaradas_escopo.clear(); eh_escopo = false; }
  ;

atr: atr_id         { print_prod("atr -> atr_id"); }
  | atr_obj         { print_prod("atr -> atr_obj"); }
  | atr_array       { print_prod("atr -> atr_array"); }
  ;

atr_id: ID '=' exp            { verifica_variaveis_declaradas($1.v); print_prod("atr_id -> ID = exp"); $$.c = to_vector($1.v) + $3.c + "="; }
  | ID '=' atr_recursiva      { verifica_variaveis_declaradas($1.v); print_prod("atr_id -> ID = atr_recursiva"); $$.c = to_vector($1.v) + $3.c + "="; }
  | ID ADD exp                { verifica_variaveis_declaradas($1.v); print_prod("atr_id -> ID ADD exp_id"); $$.c = to_vector($1.v) + to_vector($1.v) + "@" + $3.c + "+" + "="; }
  ;

// nova regra para adicao do @ no final para pegar o valor do id
atr_recursiva: ID '=' exp    { print_prod("atr_recursiva -> ID = exp"); $$.c = to_vector($1.v) + $3.c + "=" + "^" + to_vector($1.v) + "@"; } 
  | ID '=' atr_recursiva     { print_prod("atr_recursiva -> ID = atr_recursiva"); $$.c = to_vector($1.v) + $3.c + "="; }
  ;

atr_obj: ID '.' prop '=' exp     { verifica_variaveis_declaradas($1.v); print_prod("atr_obj -> ID . prop = exp"); $$.c = to_vector($1.v) + "@" + $3.c + $5.c + "[=]"; }
  | ID '.' prop ADD exp          { verifica_variaveis_declaradas($1.v); print_prod("atr_obj -> ID . prop ADD exp"); $$.c = to_vector($1.v) + "@" + $3.c + to_vector($1.v) + "@" + $3.c + "[@]" + $5.c + "+" + "[=]"; }
  ;

prop: ID            { print_prod("prop -> ID"); }
  | ID '[' exp ']'  { print_prod("prop -> ID [ exp ]"); $$.c = to_vector($1.v) + "[@]" + $3.c; }
  ;

atr_array: ID indices '=' rec     { verifica_variaveis_declaradas($1.v); print_prod("atr_array -> ID indices = exp"); $$.c = to_vector($1.v) + "@" + $2.c + $4.c + "[=]"; }
  | ID '[' atr ']' '=' exp        { verifica_variaveis_declaradas($1.v); print_prod("atr_array -> ID [ atr ] = exp"); $$.c = to_vector($1.v) + "@" + $3.c + $6.c + "[=]"; }
  ;

rec: exp          { print_prod("rec -> ID indices = exp"); } 
  | matexp        { print_prod("rec -> matexp"); }
  | exp '=' rec   { print_prod("rec -> exp = rec"); $$.c = $1.c + $2.c; }
  | atr_array     { print_prod("rec -> atr_array"); }
  ;

matexp: matrix          { print_prod("matexp -> matrix"); }
  | matexp '*' matexp   { print_prod("matexp -> matexp * matexp"); $$.c = $1.c + "[@]" + $3.c + "[@]" + "*"; }
  | matexp '+' matexp   { print_prod("matexp -> matexp + matexp"); $$.c = $1.c + "[@]" + $3.c + "+"; }
  ;

matrix: ID indices  { print_prod("matrix -> ID indices"); $$.c = to_vector($1.v) + "@" + $2.c; }
  ;

indices: '[' exp ']' indices { print_prod("indices -> [ exp ] indices"); $$.c = $2.c + "[@]" + $4.c; }
  | '[' exp ']'              { print_prod("indices -> [ exp ]"); $$.c = $2.c; }
  ;

decl: ID '=' exp fim_decl { if(eh_escopo) atualiza_variaveis_declaradas_escopo($1.v); else atualiza_variaveis_declaradas($1.v); print_prod("decl -> ID = exp fim_decl"); $$.c = to_vector($1.v) + "&" + to_vector($1.v) + $3.c + "=" + "^" + $4.c; }
  | ID fim_decl           { if(eh_escopo) atualiza_variaveis_declaradas_escopo($1.v); else atualiza_variaveis_declaradas($1.v);  print_prod("decl -> ID fim_decl"); $$.c = to_vector($1.v) + "&" + $2.c; }
  | ID '=' funcao fim_decl       { print_prod("decl -> funcao fim_decl"); $$.c = to_vector($1.v) + "&" + to_vector($1.v) + $3.c + $4.c; }   
  | ID '=' objeto fim_decl       { print_prod("decl -> ID = { corpo_obj } fim_decl"); $$.c = to_vector($1.v) + "&" + to_vector($1.v) + "{}" + $3.c + "=" + "^"; }
  ;

objeto: '{' corpo_obj '}' { print_prod("objeto -> { corpo_obj }"); $$.c = $2.c; }
  ;

corpo_obj: ID ':' exp ',' corpo_obj { print_prod("corpo_obj -> ID : exp , corpo_obj"); $$.c = to_vector($1.v) + $3.c + "[<=]" + $5.c; }
  | ID ':' exp                   { print_prod("corpo_obj -> ID : exp ,"); $$.c = to_vector($1.v) + $3.c + "[<=]"; }
  | ID ':' objeto                   { print_prod("corpo_obj -> ID : objeto"); $$.c = to_vector($1.v) + "{}" + $3.c + "[<=]"; }
  ;

fim_decl: ',' decl     { print_prod("fim_decl -> , decl"); $$.c = $2.c; }
  |                    { print_prod("fim_decl -> epsilon"); $$.c = epsilon; }
  ;

loop: while_loop        { print_prod("loop -> while_loop"); }
  | for_loop            { print_prod("loop -> for_loop"); }
  ;

separador: separador ';'        { print_prod("separador -> separador ;"); }
  |                             { print_prod("separador -> epsilon"); $$.c = epsilon; }
  ;

while_loop: WHILE '(' condicao ')' corpo { print_prod("while_loop -> WHILE ( condicao ) corpo"); string inicio_while = gera_label("inicio_while"); string fim_while = gera_label("fim_while"); $$.c = (":" + inicio_while) + $3.c + "!" + fim_while + "?" + $5.c + inicio_while + "#" + (":" + fim_while); }
  ;

for_loop: FOR '(' LET decl ';' condicao ';' atr ')' corpo { print_prod("for_loop -> FOR ( decl ; condicao ; atr ) corpo"); string inicio_for = gera_label("inicio_for"); string fim_for = gera_label("fim_for"); $$.c = $4.c + (":" + inicio_for) + $6.c + "!" + fim_for + "?" + $10.c + $8.c + "^" + inicio_for + "#" + (":" + fim_for); }
  | FOR '(' atr ';' condicao ';' atr ')' corpo            { print_prod("for_loop -> FOR ( decl ; condicao ; atr ) corpo"); string inicio_for = gera_label("inicio_for"); string fim_for = gera_label("fim_for"); $$.c = $3.c + "^" + (":" + inicio_for) + $5.c + "!" + fim_for + "?" + $9.c + $7.c + "^" + inicio_for + "#" + (":" + fim_for); }
  | FOR '(' atr ';' condicao ';' val ')' OBJ            { print_prod("for_loop -> FOR ( decl ; condicao ; val ) corpo"); string inicio_for = gera_label("inicio_for"); string fim_for = gera_label("fim_for"); $$.c = $3.c + "^" + (":" + inicio_for) + $5.c + "!" + fim_for + "?" + $9.c + "^" + $7.c + "^" + inicio_for + "#" + (":" + fim_for); }
  ;

condicional: IF '(' condicao ')' empilha_escopo corpo desempilha_escopo  ELSE empilha_escopo corpo desempilha_escopo { print_prod("condicional -> IF (condicao) corpo ELSE corpo"); string else_label = gera_label("else"); string fim_if = gera_label("fim_if"); $$.c = $3.c + "!" + else_label + "?" + $6.c + fim_if + "#" + (":" + else_label) + $10.c + (":" + fim_if); }
	| IF '(' condicao ')' empilha_escopo corpo desempilha_escopo  %prec 'T'           { print_prod("condicional -> IF (condicao) corpo"); string fim_if = gera_label("fim_if"); $$.c = $3.c + "!" + fim_if + "?" + $6.c + (":" + fim_if);}
	;

corpo: '{' cmds '}'           { print_prod("corpo -> { cmds }"); $$.c = $2.c; }
  | cmd_1 ';'                 { print_prod("corpo -> cmd_1 ;"); }
  | cmd_2                     { print_prod("corpo -> cmd_2"); }
  ;

condicao: exp '>' exp   { print_prod("condicao -> exp > exp"); $$.c = $1.c + $3.c + ">"; }
  | exp '<' exp         { print_prod("condicao -> exp < exp"); $$.c = $1.c + $3.c + "<"; }
  | exp IGUAL exp       { print_prod("condicao -> exp IGUAL exp"); $$.c = $1.c + $3.c + "=="; }
  | exp DIF exp         { print_prod("condicao -> exp DIF exp"); $$.c = $1.c + $3.c + "!="; }
  | exp                 { print_prod("condicao -> exp"); $$.c = $1.c; }
  ;

exp: exp '+' exp        { print_prod("exp -> exp + exp"); $$.c = $1.c + $3.c + "+"; }
  | exp '-' exp         { print_prod("exp -> exp - exp"); $$.c = $1.c + $3.c + "-"; }
  | exp '*' exp         { print_prod("exp -> exp * exp"); $$.c = $1.c + $3.c + "*"; }
  | exp '/' exp         { print_prod("exp -> exp / exp"); $$.c = $1.c + $3.c + "/"; }
  | exp '%' exp         { print_prod("exp -> exp % exp"); $$.c = $1.c + $3.c + "%"; }
  | ID '.' ID           { print_prod("exp -> ID . ID"); $$.c = to_vector($1.v) + "@" + $3.v + "[@]"; }
  | val                 { print_prod("exp -> val"); }
  | exp '(' params ')'  { print_prod("exp -> exp ( params )"); $$.c = $3.c + to_string(n_params) + $1.v + "@" + "$"; n_params = 0;}
  ;

params: exp ',' params { print_prod("params -> exp , params"); $$.c = $1.c + $3.c; n_params++; }
  | exp                { print_prod("params -> exp"); $$.c = $1.c; n_params++; }
  |                    { print_prod("params -> epsilon"); $$.c = epsilon; }
  | matrix ',' params  { print_prod("params -> matrix , params"); $$.c = $1.c + $3.c; n_params++; }
  ;

val : TRUE      { print_prod("val -> TRUE"); $$.c = to_vector($1.v); }
  | FALSE        { print_prod("val -> FALSE"); $$.c = to_vector($1.v); }
  | ID          { print_prod("val -> ID"); $$.c = to_vector($1.v) + "@"; }
  | NUM           { print_prod("val -> NUM"); }
  | '-' NUM       { print_prod("val -> - NUM"); $$.c = to_vector("0") + $2.c + "-" ; }
  | '(' exp ')'   { print_prod("val -> ( exp )"); $$ = $2; }
  | OBJ           { print_prod("val -> OBJ"); }
  | ARRAY         { print_prod("val -> ARRAY"); }
  | STRING        { print_prod("val -> STRING"); }
  | ID INC        { print_prod("val -> ID INC"); $$.c = to_vector($1.v) + "@" + to_vector($1.v) + to_vector($1.v) + "@" + "1" + "+" + "=" + "^"; }
  | BLOCO         { print_prod("val -> BLOCO VAZIO"); }
  ;

%%

// Include do arquivo do lex - integracao
#include "lex.yy.c"

auto f = &yyunput;

void yyerror(const char* st) {
   puts(st); 
   printf("Proximo a: %s na linha %d, coluna %d\n", yytext, yylloc.first_line, yylloc.first_column);
   exit(1);
}

void print_NPR(vector<string> c) {
  c = resolve_enderecos(c);  
  for (string s : c) { 
    cout << s + " "; 
  } 
  cout << endl;
}

void print_prod(const char *s) {
  cout << s << endl;
}

vector<string> gera_retorno() {
  return to_vector("'&retorno'") + "@" + "~";
}

vector<string> gera_fim_funcao() {
  return to_vector("undefined") + "@" + "'&retorno'" + "@" + "~";
}

vector<string> gera_inicializacao_de_argumento(string id, int n_args) {
  int indice = n_args - 1;
  return to_vector(id) + "&" + id + "arguments" + "@" + to_string(indice) + "[@]" + "=" + "^";
}

vector<string> gera_funcao(string id, string label) {
  if (id == "anonima") return to_vector("{}") + "=" + "'&funcao'" + label + "[=]" + "^";
  return to_vector(id) + "&" + id + "{}" + "=" + "'&funcao'" + label + "[=]" + "^";
}

void atualiza_variaveis_declaradas(string var) {
  auto it = variaveis_declaradas.find(var);

  if (it == variaveis_declaradas.end()) {
    variaveis_declaradas[var] = yylloc.first_line;
  } else {
    cout << "Erro: a variável '" << var << "' já foi declarada na linha " << variaveis_declaradas[var] << "." << endl;
    exit(1);
  }
}

void atualiza_variaveis_declaradas_escopo(string var) {
  auto it = variaveis_declaradas_escopo.find(var);

  if (it == variaveis_declaradas_escopo.end()) {
    variaveis_declaradas_escopo[var] = yylloc.first_line;
  } else {
    cout << "Erro: a variável '" << var << "' já foi declarada na linha " << variaveis_declaradas_escopo[var] << "." << endl;
    exit(1);
  }
}

void verifica_variaveis_declaradas(string var) {

  if (!eh_escopo) {
    auto it = variaveis_declaradas.find(var);

    if (it == variaveis_declaradas.end()) {
      cout << "Erro: a variável '" << var << "' não foi declarada." << endl;
      exit(1);
    }
  } else {
    auto it = variaveis_declaradas_escopo.find(var);

    if (it == variaveis_declaradas_escopo.end()) {
      cout << "Erro: a variável '" << var << "' não foi declarada." << endl;
      exit(1);
    }
  }
}

vector<string> to_vector(string s) {
  vector<string> v;
  string aux = "";
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == ' ') {
      v.push_back(aux);
      aux = "";
    } else {
      aux += s[i];
    }
  }
  v.push_back(aux);
  return v;
}

vector<string> concatena(vector<string> a, vector<string> b) {
  a.insert(a.end(), b.begin(), b.end());
  return a;
}

vector<string> operator+(vector<string> a, vector<string> b) {
  return concatena(a, b);
}

vector<string> operator+(vector<string> a, string b) {
  a.push_back(b);
  return a;
}

vector<string> operator+(string a, vector<string> b) {
  return epsilon + a + b;
}

string trim(string s, string chars) {
  string result;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] != chars[0] && s[i] != chars[1]) {
      result += s[i];
    }
  }
  return result;
}

vector<string> tokeniza(string s) {
  string s1 = trim(s, "{}");
  vector<string> v;
  string aux = "";
  for (int i = 0; i < s1.size(); i++) {
    if (s1[i] == ' ') {
      v.push_back(aux);
      aux = "";
    } else {
      aux += s1[i];
    }
  }
  v.push_back(aux);
  return v;
}

void atualiza_atributos_token(int token) {
  yylval.v = yytext;
  yylval.c.clear();
  yylval.c.push_back(yytext);
  // cout << 'Token: ' << token << "|" << yytext << "|" << endl;
}

string gera_label(string prefixo) {
  static int n = 0;
  return prefixo + "_" + to_string(++n) + ":";
}

vector<string> resolve_enderecos(vector<string> entrada) {
  map<string,int> label;
  vector<string> saida;

  for(int i = 0; i < entrada.size(); i++) 
    if(entrada[i][0] == ':') 
        label[entrada[i].substr(1)] = saida.size();
    else
      saida.push_back(entrada[i]);
  
  for(int i = 0; i < saida.size(); i++) 
    if(label.count(saida[i]) > 0)
        saida[i] = to_string(label[saida[i]]);
    
  return saida;
}

int main(int argc, char* argv[]) {
  yyparse();
  
  return 0;
}