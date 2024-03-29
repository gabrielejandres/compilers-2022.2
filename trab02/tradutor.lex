%{
/* Declaracoes em C/C++ */
#include <iostream>
#include <map>

using namespace std;

/* Funcoes de regras da gramatica */
void S();         // inicio do programa
void A();         // atribuicao
void E();         // expressao
void E_linha();      // eliminacao de recursividade a esquerda em E
void T();         
void T_linha();     // eliminacao de recursividade a esquerda em T
void F();
void Args();        // argumentos de funcao
void Args_linha();  // eliminacao de inicio comum em Args
void Fat();         // fatorial
void Pot();         // potencia
void P();           // print

/* Funcoes auxiliares */
void casa(int);
void print(string);
void atualiza_dados(int token);
void erro(string s);

/* Variaveis globais */
string lexema;
int token;
int linha = 1, coluna_atual = 1, coluna_anterior = 0;
enum {
  tk_id = 256,
  tk_num,
  tk_print,
  tk_string
};
map<int, string> nome_tokens = {
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
"print"       { atualiza_dados(tk_print); return tk_print; }
{NUM} 		    { atualiza_dados(tk_num); return tk_num; }
{STRING}      { atualiza_dados(tk_string); return tk_string; }
{ID}		      { atualiza_dados(tk_id); return tk_id; }

.		          { atualiza_dados(yytext[0]); return yytext[0]; }

%%

/* Funcoes da gramatica criada */

// Inicio do programa
void S() {
  if (token == tk_id) {
    A();
    casa(';');
    S();
  }
  if (token == tk_print) {
    P();
    casa(';');
    S();
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

// Expressao
void E() {
  T();
  E_linha();
}

void E_linha() {
  switch(token) {
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
      Fat();  
      Pot();
    } 
      break;
    case tk_num: {
      string temp = lexema;
      casa(tk_num); 
      print(temp); 
      Fat();
      Pot();
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
      Fat();
      Pot();
      break;
    case '+': {
      casa('+'); 
      int temp = token;
      F(); 
      if (temp != '-' && temp != '+') {
        print("+"); 
      }
    }
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

// Fatorial
void Fat() {
  if(token == '!') {
    casa('!');
    print("fat #");
  }
}

// Potencia (exponencial)
void Pot() {
  if(token == '^') {
    casa('^');
    F();
    print("^");
  }
}

// Print
void P() {
  casa(tk_print);
  E();
  print("print #");
}

/* Funcoes auxiliares */

void print(string lexema) {
  cout << lexema << " ";
}

void atualiza_dados(int token) {
  lexema = yytext;
  coluna_anterior = coluna_atual;
  coluna_atual += strlen(yytext); 
}

int proximo_token() {
  return yylex();
}

void erro(string msg) {
  cout << "*** Erro: ***" << endl
       << "Linha: " << linha << ", coluna: " << coluna_anterior << endl
       << msg << endl;
  exit(1);
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

void casa(int esperado) {
  if(token == esperado)
    token = proximo_token();
  else 
    erro("Esperado " + nome_token(esperado) + ", encontrado: " + nome_token(token));
}

auto f = &yyunput;

int main() {
  token = proximo_token();
  S();
  return 0;
}