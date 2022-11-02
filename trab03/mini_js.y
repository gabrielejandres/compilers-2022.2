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

int yylex();
int yyparse();
void yyerror(const char *);
void print_prod(const char *);

%}

%token NUM
%token ID 
%token LET
%token STRING

// Start indica o simbolo inicial da gramatica
%start s

%%

s : cmds { print_prod("s -> cmds; \n"); cout << $1.c << "." << endl; }
  ;

cmds : cmd ';' cmds   { print_prod("cmds -> cmd ; cmds \n"); $$.c = $1.c + "\n" + $3.c; }
  | { print_prod("cmds -> epsilon \n"); $$.c = ""; }
  ;

cmd : atr      { print_prod("cmd -> atr \n"); }
  | LET decl { print_prod("cmd -> LET decl \n"); $$.c = $2.c; }
  ;

decl: ID '=' exp fim_decl { print_prod("decl -> ID = exp fim_decl \n"); $$.c = $1.c + "& " + $1.c + " " + $3.c + " = ^" + $4.c; }
  | ID fim_decl         { print_prod("decl -> ID fim_decl \n"); $$.c = $1.c + "& " + $2.c; }
  ;

fim_decl: ',' decl          { print_prod("fim_decl -> , decl"); $$.c = " " + $2.c; }
  |                    { print_prod("fim_decl -> epsilon"); $$.c = ""; }
  ;

atr : ID '=' exp       { $$.c = $1.c + " " + $3.c + " = ^"; }
  ;

exp : exp '+' op { $$.c = $1.c + " " + $3.c + " +"; }
  | exp '-' op { $$.c = $1.c + " " + $3.c + " -"; }
  | op
  ;

op : op '*' val { $$.c = $1.c + " " + $3.c + " *"; }
  | op '/' val { $$.c = $1.c + " " + $3.c + " /"; }
  | val

val : ID          { $$.c = $1.c + " @"; }
  | NUM         { $$.c = $1.c; }
  | '(' exp ')'   { $$ = $2; }
  | '[' ']'     { $$.c = $1.c + $2.c; }
  | '{' '}'     { $$.c = $1.c + $2.c; }
  | STRING      
  ;

%%

// Include do arquivo do lex - integracao
#include "lex.yy.c"

void yyerror(const char* st) {
   puts(st); 
   printf("Proximo a: %s\n", yytext);
   exit(1);
}

void print_prod(const char *s) {
  // puts(s);
}

int main(int argc, char* argv[]) {
  yyparse();
  
  return 0;
}