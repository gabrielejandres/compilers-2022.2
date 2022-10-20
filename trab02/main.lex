%{
/* Declaracoes em C/C++ */
#include <iostream>
#include <map>
  
using namespace std;  
  
string lexema;
int token;
int linha = 1, coluna_atual = 1, coluna_anterior = 0;

void S(); // inicio do programa
void A(); 
void E();
void E_linha();
void T(); 
void T_linha();
void F();
void casa(int);
void print(string);

enum { tk_int = 256, tk_char, tk_double, tk_id, tk_num };

map<int,string> nome_tokens = {
  { tk_int, "int" },
  { tk_char, "char" },
  { tk_double, "double" },
  { tk_id, "nome de identificador" },
  { tk_num, "numero" }
};

int tk(int token);

%}

/* Definicoes regulares */

DIGITO	[0-9]
LETRA	[A-Za-z_]

NUM	{DIGITO}+
ID	{LETRA}({LETRA}|{DIGITO})*

%%

" "  		{ coluna_anterior = coluna_atual++; }
"\t"		{ coluna_anterior = coluna_atual; 
                  coluna_atual += 2; }
"\n"            { linha++; 
                  coluna_anterior = coluna_atual;
                  coluna_atual = 1; }
{NUM} 		{ lexema = yytext; return tk( tk_num ); }
"char"		{ lexema = yytext; return tk( tk_char ); }
"int"		{ lexema = yytext; return tk( tk_int ); }
"double"	{ lexema = yytext; return tk( tk_double ); }

{ID}		{ lexema = yytext; return tk( tk_id ); }

.		{ lexema = yytext; return tk( yytext[0] ); }

%%

/* Codigo auxiliar em C */

int tk(int token) {
  coluna_anterior = coluna_atual;
  coluna_atual += strlen( yytext ); 
  return token;
}

int next_token() {
  return yylex();
}

void erro(string msg) {
  cout << "*** Erro: ***" << endl
       << "Linha: " << linha << ", coluna: " << coluna_anterior << endl
       << msg << endl;
  exit( 1 );
}

void print(string lexema){
    cout << lexema << " ";
}

string nome_token(int token) {
  if(nome_tokens.find(token) != nome_tokens.end())
    return nome_tokens[token];
  else {
    string r;
    r = (char) token;
    return "'" + r + "'";
  }
}

void E() {
  T();
  E_linha();
}

void E_linha() {
  switch( token ) {
    case '+' : casa('+'); T(); print("+"); E_linha(); break;
    case '-' : casa('-'); T(); print("-"); E_linha(); break;
  }
}

void A() {
  // Guardamos o lexema pois a função 'casa' altera o seu valor.
  string temp = lexema; 
  casa(tk_id);
  print(temp);
  casa('=');
  E();
  print("=");
}

// Inicio do programa
void S() {
    if(token == tk_id) {
        A();
        casa(';');
        S();
    }
}

void T() {
  F();
  T_linha();
}

void T_linha() {
  switch( token ) {
    case '*' : casa('*'); F(); print("*"); T_linha(); break;
    case '/' : casa('/'); F(); print("/"); T_linha(); break;
  }
}

void F() {
  switch( token ) {
    case tk_id: {
      string temp = lexema;
      casa(tk_id); print(temp + "@"); } 
      break;
    case tk_num : {
      string temp = lexema;
      casa(tk_num); print(temp); }
      break;
    case '(': 
      casa( '(' ); E(); casa( ')' ); break;
    default:
      erro("Operando esperado, encontrado " + lexema);
  }
}

void casa(int esperado) {
  if(token == esperado)
    token = next_token();
  else 
    erro("Esperado " + nome_token( esperado ) + ", encontrado: " + nome_token( token ));
}

auto f = &yyunput;

int main() {
  token = next_token();
  S();
  return 0;
}