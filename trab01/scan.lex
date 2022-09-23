%{ 
/* Declaracoes em C/C++ */

#include <stdio.h>
#include <string>

using namespace std;

enum TOKEN { _ID = 256, _FOR, _IF, _INT, _FLOAT, _MAIG, _MEIG, _IG, _DIF, _STRING, _STRING2, _COMENTARIO, EXPR };

string lexema;

%}

/* Definicoes regulares */

/* 1. Definicoes auxiliares */
DIGITO      [0-9]
LETRA	    [A-Za-z_]
CMT_LINHA   \/\/[^\n]*
CMT_BLOCO   \/\*([^*]|([*]+([^/])))*\*\/
ASPAS_SMP   \'(([^\n\']|[\\\']|(\'\'))*)\'
ASPAS_DP    \"(([^\n\"]|[\\\"]|(\"\"))*)\"

/* 2. Definicoes para os tokens dados */
ID	        (\$|{LETRA})((\@)*({LETRA}|{DIGITO})+)*
INT         {DIGITO}+
FLOAT	    {INT}(\.{INT})?([Ee](\+|\-)?{INT})?
FOR         [Ff][Oo][Rr]
IF          [Ii][Ff]
CMT         {CMT_LINHA}|{CMT_BLOCO}
STRING      {ASPAS_SMP}|{ASPAS_DP}
STRING2
WS	        [ \t\n]

%%

{WS}	{ /* ignora espaços, tabs e '\n' */ } 

ID      { lexema = yytext; return _ID; }
INT     { lexema = yytext; return _INT; }
FLOAT   { lexema = yytext; return _FLOAT; }
FOR     { lexema = yytext; return _FOR; }
IF      { lexema = yytext; return _IF; }
CMT     { lexema = yytext; return _COMENTARIO; }
STRING  { lexema = yytext; return _STRING; }

">="	{ return _MAIG; }
"<="	{ return _MEIG; }
"=="	{ return _IG; }
"!="	{ return _DIF; }

.       { return *yytext;   /* qualquer caractere isolado será retornado pelo seu código ascii. */ }

%%