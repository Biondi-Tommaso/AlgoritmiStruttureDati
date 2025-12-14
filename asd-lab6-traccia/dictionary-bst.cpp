#include "dictionary.h"

using namespace dict;

//STRUCT TO BE COMPLETED
// *** NON AGGIUNGETE IL PUNTATORE AL PADRE ALLA STRUCT!!!! *** 
struct dict::bstNode {
  //TO COMPLETE
  Dictionary ch1;
  Dictionary ch2;
  Elem elem;
};

//Funzione da implementare
bool dict::isEmpty(const Dictionary& d){
  //TODO
  return d == emptyDictionary;
}
   
//Funzione da implementare
Dictionary dict::createEmptyDict(){
  //TODO
  Dictionary d = new bstNode;
  d = emptyDictionary;
  return d;
}

//Funzione da implementare
Error dict::insertElem(const Key k, const Value v, Dictionary& d){
  //TODO
  
  //Se il dizionario è vuoto
  if(isEmpty(d)){
  	d = new bstNode;
  	d -> elem.key=k;
  	d -> elem.value = v;
  	d -> ch1 = emptyDictionary;
  	d -> ch2 = emptyDictionary;
  	return OK;	
  }

  if(d -> elem.key == k)
  	return FAIL;
  	
  if(d -> elem.key > k){
  		return insertElem(k,v,d->ch1);
  }
  return insertElem(k,v,d->ch2);
}

//Funzione da implementare
Value dict::search(const Key k, const Dictionary& d){
  //TODO
  if(d == emptyDictionary)
  	return emptyValue;
  if(d -> elem.key == k)
  	return d -> elem.value;
  if(d -> elem.key > k)
  	return search(k, d -> ch1);
  if(d -> elem.key < k)
  	return search(k, d -> ch2);
  
  return emptyValue;
  
}

Elem deleteMin( Dictionary& d){
	if(d -> ch1 == nullptr){
		Elem a = d -> elem;
		Dictionary aux = d -> ch2; 
		delete d;
		d = aux;
		return a;
	}
	return deleteMin(d->ch1);
}



//Funzione da implementare
Error dict::deleteElem(const Key k, Dictionary& d){
  //se non trovo l'elemento
  if(isEmpty(d)) 
  	return FAIL;
  	
  //Se ho trovato il nodo da eliminare
  if(d -> elem.key == k){
  	if(d -> ch1 == nullptr){
  		Dictionary aux = d -> ch2;
  		delete d;
  		d = aux;
  		return OK;
  	}
  	if(d -> ch2 == nullptr){
  		Dictionary aux = d -> ch1;
  		delete d;
  		d = aux;
  		return OK;
  	}
  	
  	d -> elem = deleteMin(d -> ch2);
  	return OK;
  }
  
  //Se non lo trovo
  if(d -> elem.key > k){
  		return deleteElem(k, d->ch1);
  }
  return deleteElem(k, d->ch2);
  
}

//Funzione da implementare
void print(const Dictionary& d) {
  //TODO
  if(d == emptyNode) return;
  print(d -> ch1);
  cout <<"     " << d -> elem.key <<": " << d -> elem.value << endl;
  print(d -> ch2);
}

/****************************************************************/
/*              FUNZIONE IMPLEMENTATE                           */
/****************************************************************/
Dictionary readFromFile(string nome_file){
  ifstream ifs(nome_file.c_str()); // apertura di uno stream associato ad un file, in lettura
  if (!ifs) {cout << "\nErrore apertura file, verificare di avere inserito un nome corretto\n"; return emptyDictionary;}  
  return readFromStream(ifs);
}

Dictionary readFromStdin(){
  cout << "\nInserire una sequenza di linee che rispettano la sintassi key: value.<enter>\nDigitare CTRL^ D per terminare l'inserimento\n";
  Dictionary d = readFromStream((std::cin));
  // Questa serve per aggirare un bug di alcune versioni attuali di glibc.
  clearerr(stdin);
  return d;
}

Dictionary readFromStream(istream& str){
  Dictionary d = emptyDictionary; 
  string key, kcopy;
  string value;
  getline (str, key, ':'); 
  getline (str, value); 
  while (!str.eof())  
    {        
      kcopy = key;
      removeBlanksAndLower(kcopy); 
      insertElem(kcopy, value, d);
      getline (str, key, ':'); 
      getline (str, value); 
    }
  str.clear();
  return d;
}
