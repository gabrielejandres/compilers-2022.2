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
LETRA	    [A-Za-z]
CARACTERE   {LETRA}|(\_)
ALFA_NUM    {CARACTERE}|{DIGITO}
CMT_LINHA   \/\/[^\n]*
CMT_BLOCO   \/\*([^*]|([*]+([^/])))*\*\/
ESCAPE      [\\][^\n]
TEXTO       [^`${]*
TXT_EXP     \`[^`]*\$   
EXP_TXT     \}[^\`]*\`
ASPAS_SMP   \'([^']|{ESCAPE}|(\'\'))*\'
ASPAS_DP    \"([^"]|{ESCAPE}|(\"\"))*\"
ASPAS_INV   \`{TEXTO}\`|\`{TEXTO}[$]+[^`{]*\`|\`{TEXTO}[{]+[^`]*\`|{TXT_EXP}|{EXP_TXT}

/* 2. Definicoes para os tokens dados */
INT         {DIGITO}+
FLOAT	    {INT}(\.{INT})?([Ee](\+|\-)?{INT})?
FOR         [Ff][Oo][Rr]
IF          [Ii][Ff]
CMT         {CMT_LINHA}|{CMT_BLOCO}
STRING      {ASPAS_SMP}|{ASPAS_DP}
STRING2     {ASPAS_INV}
ID	        (\$|{CARACTERE})((\@)*{ALFA_NUM}+(\@)*)*
EXPR        \{{ID}*
ID_INVALIDO {ALFA_NUM}*(\$)*(\@)*{ALFA_NUM}*(\$)*(\@)*
WS	        [ \t\n]

%%

">="	        { lexema = yytext; return _MAIG; }
"<="	        { lexema = yytext; return _MEIG; }
"=="	        { lexema = yytext; return _IG; }
"!="	        { lexema = yytext; return _DIF; }
{WS}	        { /* ignora espaços, tabs e '\n' */ } 
{INT}           { lexema = yytext; return _INT; }
{FLOAT}         { lexema = yytext; return _FLOAT; }
{FOR}           { lexema = yytext; return _FOR; }
{IF}            { lexema = yytext; return _IF; }
{CMT}           { lexema = yytext; return _COMENTARIO; }
{STRING}        { lexema = yytext; lexema.pop_back(); lexema.erase(lexema.begin()); return _STRING; }
{STRING2}       { lexema = yytext; lexema.pop_back(); lexema.erase(lexema.begin()); return _STRING2; }
{ID}            { lexema = yytext; return _ID; }
{EXPR}          { lexema = yytext; lexema.erase(lexema.begin()); return _EXPR; }
{ID_INVALIDO}   { cout << "Erro: Identificador inválido: " << yytext << endl; }
.               { lexema = yytext; return *yytext;   /* qualquer caractere isolado será retornado pelo seu código ascii. */ }

%%