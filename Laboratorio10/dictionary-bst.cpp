#include "dictionary.h"

using namespace dict;

//STRUCT TO BE COMPLETED
// *** NON AGGIUNGETE IL PUNTATORE AL PADRE ALLA STRUCT!!!! *** 4




//Funzione da implementare
bool dict::isEmpty(const Dictionary& d){

  return d == emptyDictionary;
}
   
//Funzione da implementare
Dictionary dict::createEmptyDict(){
  
  Dictionary d = new bstNode;
  d = emptyDictionary;
  return d;
}

//Funzione da implementare
Error dict::insertElem(const string k, Dictionary& d){
  
  
  //Se il dizionario è vuoto
  if(isEmpty(d)){
  	d = new bstNode;
  	d -> elem.name=k;
  	for (int i = 0; i < 26; ++i)
  		d -> elem.tree = emptyDictionary;
  	d -> ch1 = emptyDictionary;
  	d -> ch2 = emptyDictionary;
  	d -> elem.memberOf = emptyDictionary;
  	d -> elem.leaderOf = emptyDictionary;
  	return OK;	
  }

  if(d -> elem.name == k)
  	return FAIL;
  	
  if(d -> elem.name > k){
  		return insertElem(k,d->ch1);
  }
  return insertElem(k,d->ch2);
}

//Funzione da implementare
Dictionary dict::search(const string k, const Dictionary& d){
  //TODO
  if(d == nullptr)
  	return emptyDictionary;
  else if(d -> elem.name == k)
  	return d;
 else if(d -> elem.name > k)
  	return search(k, d -> ch1);
  else if (d -> elem.name < k)
  	return search(k, d -> ch2);
  
  return emptyDictionary;
  
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
Error dict::deleteElem(const string k, Dictionary& d){
  //se non trovo l'elemento
  if(isEmpty(d)) 
  	return FAIL;
  	
  //Se ho trovato il nodo da eliminare
  if(d -> elem.name == k){
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
  if(d -> elem.name > k){
  		return deleteElem(k, d->ch1);
  }
  return deleteElem(k, d->ch2);
  
}

//Funzione da implementare
void print(const Dictionary& d) {
  //TODO
  if(d == emptyNode) return;
  print(d -> ch1);
  cout <<"     " << d -> elem.name<< endl;
  print(d -> ch2);
}

