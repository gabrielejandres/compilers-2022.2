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

             
{DOUBLE}   { atributos_token(NUM);
             return NUM; }

"let"	   { atributos_token(LET);
             return LET; }

"{}"       { atributos_token(OBJ);
             return OBJ; }

"[]"       { atributos_token(ARRAY);
            return ARRAY; }

"+="        { atributos_token(ADD);
            return ADD; }

"if"    { atributos_token(IF);
            return IF; }

"else"    { atributos_token(ELSE);
            return ELSE; }

"=="   { atributos_token(IGUAL);
            return IGUAL; }

"!="   { atributos_token(DIF);
            return DIF; }

{ID}       { atributos_token(ID);
             return ID; }

{STRING}   { atributos_token(STRING);
             return STRING; }

.          { atributos_token(yytext[0]);
	     return yytext[0]; }

%%