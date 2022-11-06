%{
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct Atributos {
  vector<string> c;
  string v;
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
vector<string> to_vector(string s);
string gera_label(string prefixo);
vector<string> resolve_enderecos(vector<string> entrada);
void atualiza_variaveis_declaradas(string var);
void verifica_variaveis_declaradas(string var);
void print_NPR(vector<string>);

// Variaveis
map<string, int> variaveis_declaradas;
vector<string> epsilon;

%}

// Opcao para usar a localizacao do bison
%locations

%token NUM
%token ID 
%token LET
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

// Start indica o simbolo inicial da gramatica
%start s

// Precedencia e associatividade dos operadores
%right '=' 
%left '+' '-'
%left '*' '/'
%right ADD INC
%right ELSE '#' // conflito de shift reduce 

%%

s : cmds { print_prod("s -> cmds"); print_NPR($1.c); }
  ;

cmds : cmd_1 ';' cmds   { print_prod("cmds -> cmd_1 ; cmds"); $$.c = $1.c + $3.c; }
  | cmd_2 cmds          { print_prod("cmds -> cmd_2 cmds"); $$.c = $1.c + $2.c; }
  |                     { print_prod("cmds -> epsilon"); $$.c = epsilon; }
  ;

cmd_1 : atr           { print_prod("cmd_1 -> atr"); }
  | LET decl          { print_prod("cmd_1 -> LET decl"); $$.c = $2.c; }
  ;

cmd_2 : condicional       { print_prod("cmd_2 -> condicional"); }
  ;

atr: atr_id         { print_prod("atr -> atr_id"); }
  | atr_obj         { print_prod("atr -> atr_obj"); }
  | atr_array       { print_prod("atr -> atr_array"); }
  ;

atr_id: ID '=' exp            { verifica_variaveis_declaradas($1.v); print_prod("atr_id -> ID = exp"); $$.c = to_vector($1.v) + $3.c + "=" + "^"; }
  | ID '=' atr_recursiva      { verifica_variaveis_declaradas($1.v); print_prod("atr_id -> ID = atr_recursiva"); $$.c = to_vector($1.v) + $3.c + "=" + "^"; }
  | ID ADD exp                { verifica_variaveis_declaradas($1.v); print_prod("atr_id -> ID ADD exp_id"); $$.c = to_vector($1.v) + to_vector($1.v) + "@" + $3.c + "+" + "=" + "^"; }
  ;

// nova regra para adicao do @ no final para pegar o valor do id
atr_recursiva: ID '=' exp    { print_prod("atr_recursiva -> ID = exp"); $$.c = to_vector($1.v) + $3.c + "= ^" + to_vector($1.v) + "@"; } 
  | ID '=' atr_recursiva      { print_prod("atr_recursiva -> ID = atr_recursiva"); $$.c = to_vector($1.v) + $3.c + "=" + "^"; }
  ;

atr_obj: ID '.' prop '=' exp     { verifica_variaveis_declaradas($1.v); print_prod("atr_obj -> ID . prop = exp"); $$.c = to_vector($1.v) + "@" + $3.c + $5.c + "[=]" + "^"; }
  | ID '.' prop ADD exp          { verifica_variaveis_declaradas($1.v); print_prod("atr_obj -> ID . prop ADD exp"); $$.c = to_vector($1.v) + "@" + $3.c + to_vector($1.v) + "@" + $3.c + "[@]" + $5.c + "+" + "[=]" + "^"; }
  ;

prop: ID            { print_prod("prop -> ID"); }
  | ID '[' exp ']'  { print_prod("prop -> ID [ exp ]"); $$.c = to_vector($1.v) + "[@]" + $3.c; }
  ;

atr_array: ID '[' exp ']' '=' exp     { verifica_variaveis_declaradas($1.v); print_prod("atr_array -> ID [ exp ] = exp"); $$.c = to_vector($1.v) + "@" + $3.c + $6.c + "[=]" + "^"; }
  ;

decl: ID '=' exp fim_decl { atualiza_variaveis_declaradas($1.v); print_prod("decl -> ID = exp fim_decl"); $$.c = to_vector($1.v) + "&" + to_vector($1.v) + $3.c + "=" + "^" + $4.c; }
  | ID fim_decl           { atualiza_variaveis_declaradas($1.v); print_prod("decl -> ID fim_decl"); $$.c = to_vector($1.v) + "&" + $2.c; }
  ;

fim_decl: ',' decl     { print_prod("fim_decl -> , decl"); $$.c = $2.c; }
  |                    { print_prod("fim_decl -> epsilon"); $$.c = epsilon; }
  ;

condicional: IF '(' condicao ')' corpo ELSE corpo { print_prod("condicional -> IF (condicao) corpo ELSE corpo"); string else_label = gera_label("else"); string end_if = gera_label("end_if"); $$.c = $3.c + "!" + else_label + "?" + $5.c + end_if + "#" + (":" + else_label) + $7.c + (":" + end_if); }
	| IF '(' condicao ')' corpo %prec '#' { print_prod("condicional -> IF (condicao) corpo"); string end_if = gera_label("end_if"); $$.c = $3.c + "!" + end_if + "?" + $5.c + (":" + end_if);}
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

exp: exp '+' exp    { print_prod("exp -> exp + exp"); $$.c = $1.c + $3.c + "+"; }
  | exp '-' exp     { print_prod("exp -> exp - exp"); $$.c = $1.c + $3.c + "-"; }
  | exp '*' exp     { print_prod("exp -> exp * exp"); $$.c = $1.c + $3.c + "*"; }
  | exp '/' exp     { print_prod("exp -> exp / exp"); $$.c = $1.c + $3.c + "/"; }
  | ID '.' ID       { print_prod("exp -> ID . ID"); $$.c = to_vector($1.v) + "@" + $3.v + "[@]"; }
  | ID '[' exp ']'  { print_prod("exp -> ID [ exp ]"); $$.c = to_vector($1.v) + "[@]" + $3.c; }
  | val             { print_prod("exp -> val"); }
  ;

val : ID          { print_prod("val -> ID"); $$.c = to_vector($1.v) + "@"; }
  | NUM           { print_prod("val -> NUM"); }
  | '-' NUM       { print_prod("val -> - NUM"); $$.c = to_vector("0") + $2.c + "-" ; }
  | '(' exp ')'   { print_prod("val -> ( exp )"); $$ = $2; }
  | OBJ           { print_prod("val -> OBJ"); }
  | ARRAY         { print_prod("val -> ARRAY"); }
  | STRING        { print_prod("val -> STRING"); }
  | ID INC        { print_prod("val -> ID INC"); $$.c = to_vector($1.v) + "@" + to_vector($1.v) + to_vector($1.v) + "@" + "1" + "+" + "=" + "^"; }
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
  cout << "." << endl;
}

void print_prod(const char *s) {
  cout << s << endl;
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