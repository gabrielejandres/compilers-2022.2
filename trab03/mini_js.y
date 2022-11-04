%{
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>

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

int yylex();
int yyparse();
void yyerror(const char *);
void print_prod(const char *);
void atributos_token(int token);
vector<string> concatena(vector<string> a, vector<string> b);
vector<string> operator+(vector<string> a, vector<string> b);
vector<string> operator+(vector<string> a, string b);
vector<string> to_vector(string s);

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

// Start indica o simbolo inicial da gramatica
%start s

// Precedencia e associatividade dos operadores
%right '=' 
%left '+' '-'
%left '*' '/'

%%

s : cmds { print_prod("s -> cmds;"); for (string c : $1.c) { cout << c; } cout << "." << endl; }
  ;

cmds : cmd ';' cmds   { print_prod("cmds -> cmd ; cmds"); $$.c = $1.c + "\n" + $3.c; }
  | { print_prod("cmds -> epsilon"); $$.c = to_vector(""); }
  ;

cmd : atr      { print_prod("cmd -> atr"); }
  | add      { print_prod("cmd -> add"); }
  // | condicional      { print_prod("cmd -> condicional"); }
  | LET decl { print_prod("cmd -> LET decl"); $$.c = $2.c; }
  ;

atr: ID '=' exp     { print_prod("atr -> ID = exp"); $$.c = to_vector($1.v) + " " + $3.c + " = ^ "; }
  | ID '=' atr_id      { print_prod("atr -> ID = atr"); $$.c = to_vector($1.v) + " " + $3.c + " = ^ "; }
  ;

// nova regra para adicao do @ no final para pegar o valor do id
atr_id: ID '=' exp    { print_prod("atr_id -> ID = exp"); $$.c = to_vector($1.v) + " " + $3.c + " = ^ " + to_vector($1.v) + "@"; } 
  | ID '=' atr_id      { print_prod("atr_id -> ID = atr_id"); $$.c = to_vector($1.v) + " " + $3.c + " = ^ "; }
  ;

add: ID ADD exp_id { print_prod("add -> ID ADD exp_id"); $$.c = to_vector($1.v) + " " + to_vector($1.v) + "@ " + $3.c + " + = ^ "; }
  ;

// nova regra para adicao do '+' apos o primeiro argumento
exp_id: val '+' exp_id { print_prod("exp_id -> exp + exp"); $$.c = $1.c + " + " + $3.c; }
  | val
  ;

decl: ID '=' exp fim_decl { print_prod("decl -> ID = exp fim_decl"); $$.c = to_vector($1.v) + "& " + to_vector($1.v) + " " + $3.c + " = ^ " + $4.c; }
  | ID fim_decl         { print_prod("decl -> ID fim_decl"); $$.c = to_vector($1.v) + "& " + $2.c; }
  ;

fim_decl: ',' decl          { print_prod("fim_decl -> , decl"); $$.c = to_vector(" ") + $2.c; }
  |                    { print_prod("fim_decl -> epsilon"); $$.c = to_vector(""); }
  ;

// condicional: IF '(' condicao ')' '{' bloco '}' ELSE '{' bloco '}'	
// 	| IF '(' condicao ')' '{' bloco '}'	
//   | IF '(' condicao ')' bloco ELSE
//   | IF '(' condicao ')' bloco
// 	;

// condicao: exp '>' exp { print_prod("condicao -> exp > exp"); $$.c = $1.c + " " + $3.c + " >"; }
//   | exp '<' exp { print_prod("condicao -> exp < exp"); $$.c = $1.c + " " + $3.c + " <"; }
//   | exp IGUAL exp { print_prod("condicao -> exp EQ exp"); $$.c = $1.c + " " + $3.c + " ="; }
//   | exp DIF exp { print_prod("condicao -> exp NE exp"); $$.c = $1.c + " " + $3.c + " !="; }
//   | exp { print_prod("condicao -> exp"); }
//   ;

// bloco: bloco conteudo ';'
//   | 
//   ;

// conteudo: atr { print_prod("conteudo -> atr"); }
//   | add       { print_prod("conteudo -> add"); }
//   | condicional { print_prod("conteudo -> condicional"); }
//   | LET decl    { print_prod("conteudo -> LET decl"); $$.c = $2.c; }
//   ;

exp: exp '+' exp { print_prod("exp -> exp + exp"); $$.c = $1.c + " " + $3.c + " +"; }
  | exp '-' exp { print_prod("exp -> exp - exp"); $$.c = $1.c + " " + $3.c + " -"; }
  | exp '*' exp { print_prod("exp -> exp * exp"); $$.c = $1.c + " " + $3.c + " *"; }
  | exp '/' exp { print_prod("exp -> exp / exp"); $$.c = $1.c + " " + $3.c + " /"; }
  | val         { print_prod("exp -> val"); }
  ;

val : ID          { print_prod("val -> ID"); $$.c = to_vector($1.v) + "@"; }
  | NUM         { print_prod("val -> NUM"); }
  | '(' exp ')'   { print_prod("val -> ( exp )"); $$ = $2; }
  | OBJ       { print_prod("val -> OBJ"); }
  | ARRAY     { print_prod("val -> ARRAY"); }
  | STRING      { print_prod("val -> STRING"); }
  // | ID INC      { print_prod("val -> ID INC"); $$.c = $1.c + "@" + " 1 + = ^"; }
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

void print_prod(const char *s) {
  // printf("%s \n", s);
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
  return b + a;
}

void atributos_token(int token) {
  yylval.v = yytext;
  yylval.c.clear();
  yylval.c.push_back(yytext);
  // cout << 'Token: ' << token << "|" << yytext << "|" << endl;
}

int main(int argc, char* argv[]) {
  yyparse();
  
  return 0;
}