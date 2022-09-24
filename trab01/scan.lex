%{ 
/* Declaracoes em C/C++ */

#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

string lexema;

%}

/* Definicoes regulares */

/* 1. Definicoes auxiliares */
DIGITO      [0-9]
LETRA	    [A-Za-z_]
CMT_LINHA   \/\/[^\n]*
CMT_BLOCO   \/\*([^*]|([*]+([^/])))*\*\/
ASPAS_SMP   \'([^'\\]|[\\][^\n]|('')*)*\'
ASPAS_DP    \"([^"\\]|[\\][^\n]|("")*)*\"
ASPAS_INV   \`[^`${]*\`|\`[^`${]*[$]+[^`{]*\`|\`[^`${]*[{]+[^`]*\`|\`[^`]*\$|\}[^\`]*\`

/* 2. Definicoes para os tokens dados */
INT         {DIGITO}+
FLOAT	    {INT}(\.{INT})?([Ee](\+|\-)?{INT})?
FOR         [Ff][Oo][Rr]
IF          [Ii][Ff]
CMT         {CMT_LINHA}|{CMT_BLOCO}
STRING      {ASPAS_SMP}|{ASPAS_DP}
STRING2     {ASPAS_INV}
ID	        (\$|{LETRA})((\@|{LETRA}|{DIGITO})*({LETRA}|{DIGITO})+(\@|{LETRA}|{DIGITO})*)*
EXPR        \{{ID}*
INVALID_ID  ({LETRA}|{DIGITO})*(\$)*(\@)*({LETRA}|{DIGITO})*(\$)*(\@)*
WS	        [ \t\n]

%%

{WS}	        { /* ignora espaços, tabs e '\n' */ } 
{INT}           { lexema = yytext; return _INT; }
{FLOAT}         { lexema = yytext; return _FLOAT; }
{FOR}           { lexema = yytext; return _FOR; }
{IF}            { lexema = yytext; return _IF; }
{CMT}           { lexema = yytext; return _COMENTARIO; }
{STRING}        { lexema = yytext; lexema.pop_back(); lexema.erase(lexema.begin()); return _STRING; }
{STRING2}       { lexema = yytext; lexema.pop_back(); lexema.erase(lexema.begin()); return _STRING2; }
{ID}            { lexema = yytext; return _ID; }
{INVALID_ID}    { cout << "Erro: Identificador inválido: " << yytext << endl; }
{EXPR}          { lexema = yytext; lexema.erase(lexema.begin()); return _EXPR; }
">="	        { lexema = yytext; return _MAIG; }
"<="	        { lexema = yytext; return _MEIG; }
"=="	        { lexema = yytext; return _IG; }
"!="	        { lexema = yytext; return _DIF; }

.               { lexema = yytext; return *yytext;   /* qualquer caractere isolado será retornado pelo seu código ascii. */ }

%%