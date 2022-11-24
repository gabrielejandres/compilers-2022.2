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

             
{DOUBLE}   { atualiza_atributos_token(NUM);
             return NUM; }

"{}"       { atualiza_atributos_token(OBJ);
             return OBJ; }

"[]"       { atualiza_atributos_token(ARRAY);
            return ARRAY; }

"+="        { atualiza_atributos_token(ADD);
            return ADD; }

"++"        { atualiza_atributos_token(INC);
            return INC; }

"=="   { atualiza_atributos_token(IGUAL);
            return IGUAL; }

"!="   { atualiza_atributos_token(DIF);
            return DIF; }

"let"	   { atualiza_atributos_token(LET);
             return LET; }

"var"     { atualiza_atributos_token(VAR);
             return VAR; }

"const"   { atualiza_atributos_token(CONST);
             return CONST; }

"if"    { atualiza_atributos_token(IF);
            return IF; }

"else"    { atualiza_atributos_token(ELSE);
            return ELSE; }

"while"    { atualiza_atributos_token(WHILE);
            return WHILE; }

"for"    { atualiza_atributos_token(FOR);
            return FOR; }

"function"    { atualiza_atributos_token(FUNCTION);
                return FUNCTION; }


"return"    { atualiza_atributos_token(RETURN);
                return RETURN; }

"asm{".*"}"  {  yylval.c = tokeniza(yytext + 3);
                return ASM; }

{ID}       { atualiza_atributos_token(ID);
             return ID; }

{STRING}   { atualiza_atributos_token(STRING);
             return STRING; }

.          { atualiza_atributos_token(yytext[0]);
	     return yytext[0]; }

%%