// FILE DA MODIFICARE
#include <string>
#include <iostream>
#include "ASD-aritexpr.h"
#include "ASD-token.h"
#include "ASD-stack.h"

using namespace stack;
using namespace std;

/*Calcula il valore intero dell'espressione aritmetica st*/
/*se st non corrisponde ad un expression aritmetica solleva un eccezione di tipo string*/
/*con valore: "Lexical Error" se st non è composta da tokens*/
/*e valore: "Syntactical Error" se st è ben formata*/
int compute_arithmetic_expr(const string& st){
	token tok;
	token el;
	int var1 = 0;
	int var2 = 0;
	token result;
	token op;
	Stack pila = createEmpty();

	//Copia della st ?
	string st2 = st;

	while (nextToken(st2, tok))
	{
		push(tok, pila);
		if(tok.k == PARENTESI_CHIUSA){
		for (int i = 0; i < 5; i++)
		{
			//check size != vuoto
			if(st.length() == 0){
				string err = "ERROR: NO String FOUND";
				//throw err;
			}

			//el = pop(pila); //el?

			switch (i)
			{
			case 0:
				if(tok.k != PARENTESI_CHIUSA){
					string err = "SYNTACTICAL ERROR";
					//throw err;
				}; // lancia err
				break;
			case 1:
				if(tok.k != NUMERO){
					string err = "SYNTACTICAL ERROR";
				//	throw err;
				}
				var2 = tok.val;
				break;
			case 2:
				op.k = tok.k;
				//il controllo è dopo
				break;
			case 3:
				if(tok.k != NUMERO){
					string err = "SYNTACTICAL ERROR";
				//	throw err;
				}
				var1 = tok.val;
				break;
			case 4:
				if(tok.k != PARENTESI_APERTA){
					string err = "SYNTACTICAL ERROR";
					//throw err;
				}
				break;
			
			default:
				/*string err = "LEXYCAL ERROR";
				throw err;*/
				break;
			}

			
		}
		//check operatore 
			switch (op.k)
			{
			case OP_SOMMA:
				result.val = var1 + var2;
				break;
			case OP_SOTTRAZIONE:
				result.val = var1 - var2;
				break;
			case OP_MOLTIPLICAZIONE:
				result.val = var1 * var2;
				break;
			
			default:
				string err = "SYNTACTICAL ERROR";
				throw err;
				break;
			}

			push(result, pila);
		}
		
	}

	int output = pop(pila).val;
	return output;
}

