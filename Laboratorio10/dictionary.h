#include <iostream>
#include <stdexcept>
#include <vector> 
#include <fstream> 
#include <chrono>          // necessario compilare con -std=c++11
#include <stdlib.h>        // srand, rand
#include <string>          // std::string



using namespace std::chrono; 
using namespace std; 

namespace dict {

  // Codici di errore
  enum Error {OK, FAIL};


	typedef string Key;
	typedef string Value;


  // Implementazione basata su albero binario di ricerca
  struct bstNode; // forward declaration

  typedef bstNode* Dictionary;

  typedef struct {
    std::string name;
    Dictionary tree;
    Dictionary leaderOf; // solo per gli utenti
    Dictionary memberOf; // solo per gli utenti
  } Elem;
  
  struct bstNode {
  //TO COMPLETE
  Dictionary ch1;
  Dictionary ch2;
  Elem elem;
};
  
  
  const Dictionary emptyNode = NULL;
  const Dictionary emptyDictionary = NULL;

  //Prototipi di funzione da implementare
  Error insertElem(const string k, Dictionary& d);
  Error deleteElem(const string, Dictionary&);
  Dictionary search(const string k, const Dictionary& d);
  Dictionary createEmptyDict();
  bool isEmpty(const Dictionary&);
}  // end namespace Dict

//Funzione da implementare
void print(const dict::Dictionary&);


