#include <iostream>
#include "ASD-token.h"
#include <cctype> // Per isdigit()

using namespace std;

void separaStringa(const std::string& input, std::string& primaParte, std::string& secondaParte) {
     int pos = input.find(' '); // Trova la posizione del primo spazio

    if (pos != -1) {
        // Se c'è uno spazio, separa la stringa
       
        primaParte = input.substr(0, pos); // La prima parte va dall'inizio fino allo spazio
        secondaParte = input.substr(pos + 1); // La seconda parte va dallo spazio fino alla fine
        
    } else {
        // Se non ci sono spazi, la prima parte sarà l'intera stringa e la seconda sarà vuota
        primaParte = input;
        secondaParte = "";
	
    }
}

int add(int number, int numero){
	number *= 10;
	number += numero;
	return number;
}


bool nextToken(std::string &st, token &tok) {



  
  if (st.empty()) {
    return false; // Handle empty input string
  }

  while(st[0] == ' '){
  	st.erase(0,1);
  }
 
  string tokenS;
  string newST; 
  separaStringa(st, tokenS, newST);
  
  st = newST;
  
  if(tokenS.length() == 1){
  	switch(tokenS[0]){
  		case '(':
			tok.k = PARENTESI_APERTA;
			return true;
			break;  
		case ')':
			tok.k = PARENTESI_CHIUSA;
			return true;
			break;
		case '+':
			tok.k = OP_SOMMA;
			return true;
			break;
		case '-':
			tok.k = OP_SOTTRAZIONE;
			return true;
			break;
		case '*':
			tok.k = OP_MOLTIPLICAZIONE;
			return true;
			break;
				
  	}
  
  }
  
  //se non era un simbolo
  int number = 0;
  for (unsigned int i = 0; i < tokenS.length(); ++i){
  	switch(tokenS[i]){
  		case '1':
  			tok.k = NUMERO;
  			number = add(number, 1);
  			tok.val = number;
  			break;
  		case '2':
  			tok.k = NUMERO;
  			number = add(number, 2);
  			tok.val = number;
  			break;
  		case '3':
  			tok.k = NUMERO;
  			number = add(number, 3);
  			tok.val = number;
  			break;
  		case '4':
  			tok.k = NUMERO;
  			number = add(number, 4);
  			tok.val = number;
  			break;
  		case '5':
  			tok.k = NUMERO;
  			number = add(number, 5);
  			tok.val = number;
  			break;
  		case '6':
  			tok.k = NUMERO;
  			number = add(number, 6);
  			tok.val = number;
  			break;
  		case '7':
  			tok.k = NUMERO;
  			number = add(number, 7);
  			tok.val = number;
  			break;
  		case '8':
  			tok.k = NUMERO;
  			number = add(number, 8);
  			tok.val = number;
  			break;
  		case '9':
  			tok.k = NUMERO;
  			number = add(number, 9);
  			tok.val = number;
  			break;
  		case '0':
  			tok.k = NUMERO;
  			number = add(number, 0);
  			tok.val = number;
  			break;
  		default:
  			//GESTIONE DELL ERRORE LESSICALE //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  			throw string("Lexical error");
  			return false;
  			break;
  	}
  }
  return 1;
  
  
}

