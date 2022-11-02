DELIM   [\t\n ]
DIGITO  [0-9]
LETRA   [A-Za-z_]
DOUBLE  {DIGITO}+("."{DIGITO}+)?
ID      {LETRA}({LETRA}|{DIGITO})*
ESCAPE          [\\][^\n] 
ASPAS_SMP       \'([^']|{ESCAPE}|(\'\'))*\'
ASPAS_DP        \"([^"]|{ESCAPE}|(\"\"))*\"
STRING          {ASPAS_SMP}|{ASPAS_DP}

%%

{DELIM}    { }

             
{DOUBLE}   { yylval.c = yytext; 
             return NUM; }

"let"	   { yylval.c = yytext; 
             return LET; }

"{}"       { yylval.c = yytext; 
             return OBJ; }

"[]"       { yylval.c = yytext;
            return ARRAY; }

"+="        { yylval.c = yytext;
            return ADD; }

{ID}       { yylval.c = yytext; 
             return ID; }

{STRING}   { yylval.c = yytext;
             return STRING; }

.          { yylval.c = yytext;
	     return yytext[0]; }

%%