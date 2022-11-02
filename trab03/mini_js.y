%{
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

struct Atributos {
  string c;
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

// Start indica o simbolo inicial da gramatica
%start s

// Precedencia e associatividade dos operadores
%right '=' 
%left '+' '-'
%left '*' '/'

%%

s : cmds { print_prod("s -> cmds;"); cout << $1.c << "." << endl; }
  ;

cmds : cmd ';' cmds   { print_prod("cmds -> cmd ; cmds"); $$.c = $1.c + "\n" + $3.c; }
  | { print_prod("cmds -> epsilon"); $$.c = ""; }
  ;

cmd : atr      { print_prod("cmd -> atr"); }
  | add      { print_prod("cmd -> add"); }
  | LET decl { print_prod("cmd -> LET decl"); $$.c = $2.c; }
  ;

atr: ID '=' exp     { print_prod("atr -> ID = exp"); $$.c = $1.c + " " + $3.c + " = ^"; }
  | ID '=' atr_id      { print_prod("atr -> ID = atr"); $$.c = $1.c + " " + $3.c + " = ^"; }
  ;

// nova regra para adicao do @ no final para pegar o valor do id
atr_id: ID '=' exp    { print_prod("atr_id -> ID = exp"); $$.c = $1.c + " " + $3.c + " = ^ " + $1.c + "@"; } 
  | ID '=' atr_id      { print_prod("atr_id -> ID = atr_id"); $$.c = $1.c + " " + $3.c + " = ^"; }
  ;

add: ID ADD exp_id { print_prod("add -> ID ADD exp_id"); $$.c = $1.c + " " + $1.c + "@ " + $3.c + " + = ^"; }
  ;

// nova regra para adicao do '+' apos o primeiro argumento
exp_id: val '+' exp_id { print_prod("exp_id -> exp + exp"); $$.c = $1.c + " + " + $3.c; }
  | val
  ;

decl: ID '=' exp fim_decl { print_prod("decl -> ID = exp fim_decl"); $$.c = $1.c + "& " + $1.c + " " + $3.c + " = ^" + $4.c; }
  | ID fim_decl         { print_prod("decl -> ID fim_decl"); $$.c = $1.c + "& " + $2.c; }
  ;

fim_decl: ',' decl          { print_prod("fim_decl -> , decl"); $$.c = " " + $2.c; }
  |                    { print_prod("fim_decl -> epsilon"); $$.c = ""; }
  ;

exp: exp '+' exp { print_prod("exp -> exp + exp"); $$.c = $1.c + " " + $3.c + " +"; }
  | exp '-' exp { print_prod("exp -> exp - exp"); $$.c = $1.c + " " + $3.c + " -"; }
  | exp '*' exp { print_prod("exp -> exp * exp"); $$.c = $1.c + " " + $3.c + " *"; }
  | exp '/' exp { print_prod("exp -> exp / exp"); $$.c = $1.c + " " + $3.c + " /"; }
  | val         { print_prod("exp -> val"); }
  ;

val : ID          { print_prod("val -> ID"); $$.c = $1.c + "@"; }
  | NUM         { print_prod("val -> NUM"); }
  | '(' exp ')'   { print_prod("val -> ( exp )"); $$ = $2; }
  | OBJ       { print_prod("val -> OBJ"); }
  | ARRAY     { print_prod("val -> ARRAY"); }
  | STRING      { print_prod("val -> STRING"); }
  ;

%%

// Include do arquivo do lex - integracao
#include "lex.yy.c"

void yyerror(const char* st) {
   puts(st); 
   printf("Proximo a: %s na linha %d, coluna %d\n", yytext, yylloc.first_line, yylloc.first_column);
   exit(1);
}

void print_prod(const char *s) {
  // printf("%s \n", s);
}

int main(int argc, char* argv[]) {
  yyparse();
  
  return 0;
}