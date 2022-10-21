%{
/* Declaracoes em C/C++ */
#include <iostream>
#include <map>

using namespace std;

/* Funcoes de regras da gramatica */
void S();         // inicio do programa
void A();         // atribuicao
void E();         // expressao
void E_linha();   // eliminacao de recursividade a esquerda em E
void T();         
void T_linha();   // eliminacao de recursividade a esquerda em T
void F();
void Args();        // argumentos de funcao
void Args_linha(); // eliminacao de inicio comum em Args
void P();          // print

/* Funcoes auxiliares */
void casa(int);
void print(string);
int tk(int token);

/* Variaveis globais */
string lexema;
int token;
int linha = 1, coluna_atual = 1, coluna_anterior = 0;
enum {
  tk_int = 256,
  tk_char,
  tk_double,
  tk_id,
  tk_num,
  tk_print,
  tk_string
};
map<int, string> nome_tokens = {
  {tk_int, "int"},
  {tk_char, "char"},
  {tk_double, "double"},
  {tk_id, "nome de identificador"},
  {tk_num, "numero"},
  {tk_print, "print"},
  {tk_string, "string"}
};

%}

/* Definicoes regulares */
DIGITO	        [0-9]
LETRA	          [A-Za-z_]
INT             {DIGITO}+
NUM	            {INT}(\.{INT})?([Ee](\+|\-)?{INT})?
ID	            {LETRA}({LETRA}|{DIGITO})*
ESCAPE          [\\][^\n] 
ASPAS_SMP       \'([^']|{ESCAPE}|(\'\'))*\'
ASPAS_DP        \"([^"]|{ESCAPE}|(\"\"))*\"
STRING          {ASPAS_SMP}|{ASPAS_DP}

%%

" "  		      { coluna_anterior = coluna_atual++; }
"\t"		      { coluna_anterior = coluna_atual; coluna_atual += 2; }
"\n"          { linha++; coluna_anterior = coluna_atual; coluna_atual = 1; }
"char"		    { lexema = yytext; return tk(tk_char); }
"int"		      { lexema = yytext; return tk(tk_int); }
"double"	    { lexema = yytext; return tk(tk_double); }
"print"       { lexema = yytext; return tk(tk_print); }
{NUM} 		    { lexema = yytext; return tk(tk_num); }
{STRING}      { lexema = yytext; return tk(tk_string); }
{ID}		      { lexema = yytext; return tk(tk_id); }

.		          { lexema = yytext; return tk(yytext[0]); }

%%

/* Codigo auxiliar em C */

int tk(int token) {
  coluna_anterior = coluna_atual;
  coluna_atual += strlen(yytext); 
  return token;
}

int next_token() {
  return yylex();
}

void erro(string msg) {
  cout << "*** Erro: ***" << endl
       << "Linha: " << linha << ", coluna: " << coluna_anterior << endl
       << msg << endl;
  exit(1);
}

void print(string lexema) {
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

// Expressao
void E() {
  T();
  E_linha();
}

void E_linha() {
  switch( token ) {
    case '+' : 
      casa('+'); 
      T(); 
      print("+"); 
      E_linha(); 
      break;
    case '-' : 
      casa('-'); 
      T(); 
      print("-"); 
      E_linha(); 
      break;
  }
}

// Atribuicao
void A() {
  string temp = lexema; // guardamos o lexema pois a função 'casa' altera o seu valor.
  casa(tk_id);
  print(temp);
  casa('=');
  E();
  print("=");
}

// Inicio do programa
void S() {
  if (token == tk_id) {
    A();
    casa(';');
    S();
  }
  if (token == tk_print) {
    P();
    S();
  }
}

// Print
void P() {
  casa(tk_print);
  E();
  print("print #");
  casa(';');
}

// Expressao
void T() {
  F();
  T_linha();
}

void T_linha() {
  switch( token ) {
    case '*' : 
      casa('*'); 
      F(); 
      print("*"); 
      T_linha(); 
      break;
    case '/' : 
      casa('/'); 
      F(); 
      print("/"); 
      T_linha(); 
      break;
  }
}

void F() {
  switch(token) {
    case tk_id: {
      string temp = lexema;
      casa(tk_id); 
      if(token == '(') {
        casa('('); 
        if(token == ')'){
            casa(')');
            } else {
                Args();
                casa(')');
        }
        print(temp + " #"); // funcao
      } else {
        print(temp + " @"); // variavel
      }  
    } 
      break;
    case tk_num: {
      string temp = lexema;
      casa(tk_num); 
      print(temp); 
    }
      break;
    case tk_string: {
        string temp = lexema;
        casa(tk_string); 
        print(temp); 
    }
      break;
    case '(': 
      casa( '(' ); 
      E(); 
      casa( ')' ); 
      break;
    case '+':
      casa('+'); 
      F(); 
      print("+"); 
      break;
    case '-':
      casa('-'); 
      print("0"); 
      F(); 
      print("-"); 
      break;
    default:
      erro("Operando esperado, encontrado " + lexema);
  }
}

// Argumentos da funcao
void Args() {
  E();
  Args_linha();
}

void Args_linha() {
  if(token == ',') {
    casa(',');
    E();
    Args_linha();
  }
}

void casa(int esperado) {
  if(token == esperado)
    token = next_token();
  else 
    erro("Esperado " + nome_token(esperado) + ", encontrado: " + nome_token(token));
}

auto f = &yyunput;

int main() {
  token = next_token();
  S();
  return 0;
}