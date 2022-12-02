%{
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <map>
#include <bits/stdc++.h>

using namespace std;

struct Atributos {
  vector<string> c;
  string v;
  int n_args = 0;
};

struct Simbolo {
  int linha;
  string tipo;
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
void atualiza_variaveis_declaradas(string var, string tipo);
void verifica_variaveis_declaradas(string var);
void print_NPR(vector<string>);
vector<string> gera_inicializacao_de_argumento(string id, int n_args);
string trim(string s, string chars);
vector<string> tokeniza(string s);
vector<string> gera_funcao(string id, string label);
vector<string> gera_fim_funcao();
vector<string> gera_retorno();
void atualiza_variaveis_declaradas_escopo(string var, string tipo);
int obtem_indice(vector<string> v, string K);

// Variaveis
map<string, Simbolo> variaveis_declaradas;
map<string, Simbolo> variaveis_declaradas_escopo;
vector<string> epsilon;
vector<string> funcoes;
int n_params;
vector<bool> pode_retornar = { false };
vector<bool> escopos;

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
%token OBJ_VAZIO
%token ARRAY_VAZIO
%token TRUE

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
  | tipo_var decl     { print_prod("cmd_1 -> tipo_var decl"); if(escopos.size() > 0) atualiza_variaveis_declaradas_escopo($2.c[0], $1.v); else atualiza_variaveis_declaradas($2.c[0], $1.v); $$.c = $2.c; }
  | loop              { print_prod("cmd_1 -> loop"); }
  | exp ASM           { print_prod("cmd_1 -> exp ASM"); $$.c = $1.c + $2.c + "^"; }
  | exp               { print_prod("cmd_1 -> exp"); $$.c = $1.c; }
  | RETURN            { print_prod("cmd_1 -> RETURN"); 
                        if(!pode_retornar.back()) {
                            yyerror("Comando RETURN fora de funcao");
                        }
                        $$.c = gera_retorno(); 
                      } 
  | RETURN exp        { print_prod("cmd_1 -> RETURN exp"); 
                        if(!pode_retornar.back()) {
                            yyerror("Comando RETURN fora de funcao");
                        }
                        $$.c = $2.c + gera_retorno(); 
                      } 
  | exp '(' params ')' { print_prod("cmd_1 -> exp '(' params ')'"); // chamada de funcao
                         $$.c = $3.c + to_string(n_params) + $1.c + "$" + "^"; 
                         n_params = 0; 
                       }
  | ID '.' ID '(' params ')' { print_prod("cmd_1 -> ID . ID '(' params ')'"); // chamada de funcao
                        $$.c = $5.c + to_string(n_params) + $1.c + "@" + $3.c + "[@]" + "$" + "^"; 
                        n_params = 0; 
                      }
  | ID '.' ID '.' ID '[' exp ']' '(' params ')' { print_prod("cmd_1 -> ID . ID . matrix ( params )"); // chamada de funcao
                         $$.c = $10.c + to_string(n_params) + $1.c + "@" + $3.c + "[@]" + $5.c + "[@]" + $7.c + "[@]" + "$" + "^"; 
                         n_params = 0; 
                       }
  | funcao             { print_prod("cmd_1 -> funcao"); }
  ;

tipo_var: LET { print_prod("tipo_var -> LET"); $$.v = $1.v; }
  | VAR { print_prod("tipo_var -> VAR"); $$.v = $1.v; }
  | CONST { print_prod("tipo_var -> CONST"); $$.v = $1.v; }
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
  ;

args: args ',' arg { print_prod("args -> args , arg"); 
                      atualiza_variaveis_declaradas_escopo($3.v, "let");
                      $$.v = "";
                      $$.n_args = $1.n_args + 1; 
                      $$.c = $1.c + gera_inicializacao_de_argumento($3.v, $$.n_args);
                  }
  | arg            { print_prod("args -> arg"); 
                     atualiza_variaveis_declaradas_escopo($1.v, "let");
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

empilha_escopo: { print_prod("empilha_escopo -> "); escopos.push_back(true); }
  ;

desempilha_escopo: { print_prod("desempilha_escopo -> "); variaveis_declaradas_escopo.clear(); escopos.pop_back(); }
  ;

atr: atr_id         { print_prod("atr -> atr_id"); if(escopos.size() == 0) verifica_variaveis_declaradas($1.c[0]); }
  | atr_obj         { print_prod("atr -> atr_obj"); if(escopos.size() == 0) verifica_variaveis_declaradas($1.c[0]); }
  | atr_array       { print_prod("atr -> atr_array"); if(escopos.size() == 0) verifica_variaveis_declaradas($1.c[0]); }
  ;

atr_id: ID '=' exp            { print_prod("atr_id -> ID = exp"); $$.c = to_vector($1.v) + $3.c + "="; }
  | ID '=' atr_recursiva      { print_prod("atr_id -> ID = atr_recursiva"); $$.c = to_vector($1.v) + $3.c + "="; }
  | ID ADD exp                { print_prod("atr_id -> ID ADD exp_id"); $$.c = to_vector($1.v) + to_vector($1.v) + "@" + $3.c + "+" + "="; }
  ;

// nova regra para adicao do @ no final para pegar o valor do id
atr_recursiva: ID '=' exp    { print_prod("atr_recursiva -> ID = exp"); $$.c = to_vector($1.v) + $3.c + "=" + "^" + to_vector($1.v) + "@"; } 
  | ID '=' atr_recursiva     { print_prod("atr_recursiva -> ID = atr_recursiva"); $$.c = to_vector($1.v) + $3.c + "="; }
  ;

atr_obj: ID '.' prop '=' exp     { print_prod("atr_obj -> ID . prop = exp"); $$.c = $1.c + "@" + $3.c + $5.c + "[=]"; }
  | ID '.' prop ADD exp          { print_prod("atr_obj -> ID . prop ADD exp"); $$.c = $1.c + "@" + $3.c + to_vector($1.v) + "@" + $3.c + "[@]" + $5.c + "+" + "[=]"; }
  | '(' exp ')' '.' prop '=' exp { print_prod("atr_obj -> ID . prop = exp"); $$.c = $2.c + $5.c + $7.c + "[=]"; }
  ;

prop: exp            { print_prod("prop -> ID"); $$.c = to_vector($1.v); }
  | ID '.' prop      { print_prod("prop -> ID . prop"); $$.c = to_vector($1.v) + "[@]" + $3.c; }
  | ID '[' exp ']'   { print_prod("prop -> ID [exp] "); $$.c = to_vector($1.v) + "[@]" + $3.c; }
  ;

atr_array: exp indices '=' rec    { print_prod("atr_array -> ID indices = exp"); $$.c = $1.c + $2.c + $4.c + "[=]"; }
  | ID '[' atr ']' '=' exp        { print_prod("atr_array -> ID [ atr ] = exp"); $$.c = to_vector($1.v) + "@" + $3.c + $6.c + "[=]"; }
  | ID '[' exp ']' '=' exp        { print_prod("atr_array -> ID [ exp ] = exp"); $$.c = to_vector($1.v) + "@" + $3.c + $6.c + "[=]"; }
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

decl: ID '=' exp fim_decl { print_prod("decl -> ID = exp fim_decl"); 
                            if (escopos.size() == 0) {
                              auto it = variaveis_declaradas.find($1.v);
                              if (it == variaveis_declaradas.end()) { 
                                $$.c = to_vector($1.v) + "&" + to_vector($1.v) + $3.c + "=" + "^" + $4.c;
                              } else {
                                $$.c = to_vector($1.v) + $3.c + "=" + "^" + $4.c;
                              }
                            } else $$.c = to_vector($1.v) + "&" + to_vector($1.v) + $3.c + "=" + "^" + $4.c;                           
                          }
  | ID fim_decl           { print_prod("decl -> ID fim_decl"); $$.c = to_vector($1.v) + "&" + $2.c; }
  ;

fim_decl: ',' decl     { print_prod("fim_decl -> , decl"); $$.c = $2.c; if (escopos.size() == 0) atualiza_variaveis_declaradas($2.c[0], "var"); } // atencao t4
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
  ;

condicional: IF '(' condicao ')' empilha_escopo corpo desempilha_escopo ELSE empilha_escopo corpo desempilha_escopo { print_prod("condicional -> IF (condicao) corpo ELSE corpo"); 
                                                                                                                      string else_label = gera_label("else"); 
                                                                                                                      string fim_if = gera_label("fim_if"); 
                                                                                                                      if(escopos.size() > 0) {
                                                                                                                        $$.c = $3.c + "!" + else_label + "?" + $6.c + fim_if + "#" + (":" + else_label) + $10.c + (":" + fim_if); 
                                                                                                                      }
                                                                                                                      else {
                                                                                                                        $$.c = $3.c + "!" + else_label + "?" + "<{" + $6.c + "}>" + fim_if + "#" + (":" + else_label) + "<{" + $10.c + "}>" + (":" + fim_if); 
                                                                                                                      }
                                                                                                                    }
	| IF '(' condicao ')' empilha_escopo corpo desempilha_escopo  %prec 'T'           { print_prod("condicional -> IF (condicao) corpo"); 
                                                                                      string fim_if = gera_label("fim_if"); 
                                                                                      if (escopos.size() > 0) {
                                                                                        $$.c = $3.c + "!" + fim_if + "?" + $6.c + fim_if + "#" + (":" + fim_if);
                                                                                      } else {
                                                                                        $$.c = $3.c + "!" + fim_if + "?" + "<{" + $6.c + "}>" + fim_if + "#" + (":" + fim_if);
                                                                                      }
                                                                                    }
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
  | matrix              { print_prod("condicao -> matrix"); $$.c = $1.c + "[@]"; }
  ;

exp: exp '+' exp        { print_prod("exp -> exp + exp"); $$.c = $1.c + $3.c + "+"; }
  | exp '-' exp         { print_prod("exp -> exp - exp"); $$.c = $1.c + $3.c + "-"; }
  | exp '*' exp         { print_prod("exp -> exp * exp"); $$.c = $1.c + $3.c + "*"; }
  | exp '/' exp         { print_prod("exp -> exp / exp"); $$.c = $1.c + $3.c + "/"; }
  | exp '%' exp         { print_prod("exp -> exp % exp"); $$.c = $1.c + $3.c + "%"; }
  | exp '.' exp         { print_prod("exp -> exp . exp");
                          if ($3.c[($3.c).size() - 1] == "@" || $3.c[($3.c).size() - 1] == "[@]") $3.c.pop_back();
                          if (obtem_indice($3.c, "@") != -1) $3.c.at(obtem_indice($3.c, "@")) = "[@]";
                          $$.c = $1.c + $3.c + "[@]";
                        }
  | matrix              { print_prod("exp -> matrix"); $$.c = $1.c + "[@]"; }
  | val                 { print_prod("exp -> val"); }
  | exp '(' params ')'  { print_prod("exp -> exp ( params )"); 
                          $$.c = $3.c + to_string(n_params) + $1.c + "$";
                          n_params = 0;
                        }
  ;

params: param ',' params { print_prod("params -> param , params"); $$.c = $1.c + $3.c; n_params++; }
  | param                { print_prod("params -> param"); $$.c = $1.c; n_params++; }
  |                      { print_prod("params -> epsilon"); $$.c = epsilon; }
  ;

param: exp     { print_prod("param -> exp"); }
  | ID '=' exp { print_prod("param -> ID = exp");
                 $$.v = $1.v;
                 $$.c = $1.c + $3.c + "=";
               }
  ;

val : ID          { print_prod("val -> ID"); $$.c = to_vector($1.v) + "@"; }
  | NUM           { print_prod("val -> NUM"); }
  | '-' NUM       { print_prod("val -> - NUM"); $$.c = to_vector("0") + $2.c + "-" ; }
  | '(' exp ')'   { print_prod("val -> ( exp )"); $$ = $2; $$.c = $2.c; }
  | OBJ           { print_prod("val -> OBJ"); }
  | ARRAY         { print_prod("val -> ARRAY"); }
  | STRING        { print_prod("val -> STRING"); }
  | ID INC        { print_prod("val -> ID INC"); $$.c = to_vector($1.v) + "@" + to_vector($1.v) + to_vector($1.v) + "@" + "1" + "+" + "=" + "^"; }
  | OBJ_VAZIO         { print_prod("val -> OBJ_VAZIO VAZIO"); $$.c = to_vector("{}"); }
  | ARRAY_VAZIO   { print_prod("val -> ARRAY_VAZIO"); $$.c = to_vector("[]"); }
  | TRUE          { print_prod("val -> TRUE"); }
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
  return to_vector(id) + "&" + id + "{}" + "=" + "'&funcao'" + label + "[=]" + "^";
}

void atualiza_variaveis_declaradas(string var, string tipo) {
  auto it = variaveis_declaradas.find(var);

  if (it == variaveis_declaradas.end()) {
    Simbolo novo;
    novo.tipo = tipo;
    novo.linha = yylloc.first_line;
    variaveis_declaradas[var] = novo;
  } else {
    if (tipo != "var") {
      cout << "Erro: a variável '" << var << "' já foi declarada na linha " << variaveis_declaradas[var].linha << "." << endl;
      exit(1);
    }
  }
}

void atualiza_variaveis_declaradas_escopo(string var, string tipo) {
  auto it = variaveis_declaradas_escopo.find(var);

  if (it == variaveis_declaradas_escopo.end()) {
    Simbolo novo;
    novo.tipo = tipo;
    novo.linha = yylloc.first_line;
    variaveis_declaradas_escopo[var] = novo;
  } else {
    if(tipo != "var") {
      cout << "Erro: a variável '" << var << "' já foi declarada na linha " << variaveis_declaradas_escopo[var].linha << "." << endl;
      exit(1);
    }
  }
}

void verifica_variaveis_declaradas(string var) {
  auto it = variaveis_declaradas.find(var);

  if (it == variaveis_declaradas.end()) {
    cout << "Erro: a variável '" << var << "' não foi declarada." << endl;
    exit(1);
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

int obtem_indice(vector<string> v, string K) {
    auto it = find(v.begin(), v.end(), K);

    if (it != v.end()) return it - v.begin();

    return -1;
}

int main(int argc, char* argv[]) {
  yyparse();
  
  return 0;
}