// FILE DA MODIFICARE
#include <iostream>
#include <string>

#include "ASD-aritexpr.h"
#include "ASD-token.h"
#include "ASD-stack.h"

using namespace stack;
using namespace std;

/*Calcula il valore intero dell'espressione aritmetica st*/
/*se st non corrisponde ad un expression aritmetica*/
/*solleva un eccezione di tipo string*/
/*con valore: "Lexical Error" se st non è composta da tokens*/
/*e valore: "Syntactical Error" se st è ben formata*/



void throw_error(const string& message) {
  cerr << "Errore: " << message << endl;
  exit(1); // Terminate program with an error code
}

int compute_arithmetic_expr(const string& st) {
	

   // cout << "[debug]";
    string copyST = st;
    token tok;
    Stack s = createEmpty();

    while(copyST.length() > 0) {
       
       try{
        nextToken(copyST, tok);
        push(tok, s);
	if(s.size > 1 && s.data[0].k != PARENTESI_APERTA){
		throw string("Syntactical error");
	}
       
      //  cerr << "valore: " << tok.val << " kind: " << tok.k << " valore della stringa: " << copyST << endl;
        
        
        if(s.data[s.size-1].k == PARENTESI_CHIUSA){
        if(s.size > 4){
        	if(s.data[s.size-2].k == NUMERO && (s.data[s.size-3].k == OP_SOMMA || s.data[s.size-3].k == OP_SOTTRAZIONE || s.data[s.size-3].k == OP_MOLTIPLICAZIONE) && s.data[s.size-4].k == NUMERO && s.data[s.size-5].k == PARENTESI_APERTA){
        	
        	int numero = 0;
        		switch(s.data[s.size-3].k){
        			case OP_SOMMA:
        				numero = s.data[s.size-2].val + s.data[s.size-4].val;
        				//cout << "CASO SOMMA:" << numero << endl;
        				break;
        			case OP_SOTTRAZIONE:
        				numero = s.data[s.size-4].val - s.data[s.size-2].val;
        				//cout << "CASO SOTTRAZIONE:" << numero << endl;
        				break;
        			case OP_MOLTIPLICAZIONE:
        				numero = s.data[s.size-2].val * s.data[s.size-4].val;
        				//cout << "CASO MOLTIPLICAZIONE:" << numero << endl;
        					break; 	
        			default:
        				break;			
        		}
        		
        		pop(s);
        		pop(s);
        		pop(s);
        		pop(s);
        		pop(s);
        		token tok2;
        		tok2.k = NUMERO;
        		tok2.val =numero;
        		push(tok2, s);
        		
        	}
        	else{throw string("Syntactical error");}
        	
        	}
        	else{throw string("Syntactical error");}
        }
         if(s.size == 3){
        	if(s.data[0].k == PARENTESI_APERTA && s.data[2].k == PARENTESI_CHIUSA && s.data[1].val == NUMERO){
        		return s.data[1].val;
        	}
        }
        
        }
        catch(string error){
        	throw error;
        }
    }
    
    
    
    return s.data[s.size-1].val;
}




