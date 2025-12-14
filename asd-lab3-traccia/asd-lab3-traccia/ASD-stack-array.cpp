// FILE DA MODIFICARE
#include <iostream>
#include <fstream>
#include <string>

#include "ASD-stack-array.h"

using namespace stack;
using namespace std;

/**************************************************/
/*      funzioni da implementare                  */
/**************************************************/
/* restituisce lo stack vuoto */
Stack stack::createEmpty(){
	// to do
	
	Stack sret;
	sret.size = 0;
	sret.maxsize = BLOCKDIM;
	sret.data = new Elem[BLOCKDIM];
	return sret;
}

/* restituisce true se lo stack e' vuoto */
bool stack::isEmpty(const Stack& st){
	
	return st.size == 0;
}

/* aggiunge elem in cima (operazione safe, si può sempre fare) */
void stack::push(const Elem el, Stack& st){
   // to do
if (st.size >= st.maxsize) {
		Elem* aux = new Elem[st.maxsize + BLOCKDIM];
		for (unsigned int i = 0; i < st.size; i++) {
			aux[i] = st.data[i];
		}
		
		delete[] st.data;
		st.data = aux;
		st.maxsize += BLOCKDIM;
	}
	st.data[st.size] = el;
	st.size++;
   	
}

/* toglie dallo stack l'ultimo elemento e lo restituisce */
/* se lo stack è vuoto solleva una eccezione di tipo string */
Elem stack::pop(Stack& st){
   if(st.size == 0) {
      string error = "Lista vuota";
      throw error;
   }
   
   Elem ret = st.data[st.size-1];
   st.size--;

   // Ridimensionamento dell'array se necessario
   if(st.size < st.maxsize - BLOCKDIM) {
      st.maxsize -= BLOCKDIM;
      Elem* new_data = new Elem[st.maxsize];
      for(unsigned int i = 0; i < st.size; i++) {
         new_data[i] = st.data[i];
      }
      delete[] st.data;
      st.data = new_data;
   }

   return ret;
}


/* restituisce l'ultimo elemento dello stack senza toglierlo.*/
/* Se lo stack è vuoto solleva una eccezione di tipo string*/
Elem stack::top(Stack& st){
   // to do
   	if(st.size == 0){
   		string error= "Errore";
   		throw error;
   	}
	Elem ret = st.data[st.size-1];
	return ret;
}


/**************************************************/
/*      funzioni implementate                    */
/**************************************************/

/* riempie lo stack da file */
Stack stack::readFromFile(std::string name_file){
   ifstream infile;
   string read_data;
   infile.open(name_file);
   Stack sret=createEmpty();
   while (getline (infile,read_data)){
      if(read_data.length()>0){
         push(stoi(read_data),sret);
      } 
   }
   return sret;
}

/* legge il contenuto di uno stack da standard input */
Stack stack::readFromStdin(){
   cout << "Inserire una sequenza di numeri separati da spazi seguiti da END per terminare\n";
   Stack sret=createEmpty();
   string read_data;
   cin>>read_data;
   while(read_data!="END"){
      push(stoi(read_data),sret);
      cin>>read_data;
   }
   return sret;
}

/* stampa lo stack*/
void stack::print(const Stack& st){
   cout<<tostring(st)<<endl;
}

/* produce una stringa contenente lo stack*/
std::string stack::tostring(const Stack& st){
   string out="";
   out+="{";
   unsigned int pos=0;
   while(pos<st.size){
      out+=to_string(st.data[pos]);
      if(pos+1!=st.size){
         out+=",";
      }
      ++pos;
   }
   out+="}";
   return out;
}

