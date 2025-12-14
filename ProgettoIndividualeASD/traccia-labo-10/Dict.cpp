#include <iostream>
#include <string>
#include <cstdlib>
#include "dict.h"

using namespace std;

	
	/*//funzioni ausiliari //
	namespace dict{
	
	//inserisci il nodo all'interno dell'albero coretto
	
	int hash(const string s){
	
		if(s.empty())
			throw string("errore la stringa è vuota");
		char firstChar = s[0];
		if(firstChar < 'a' || firstChar > 'z')
			throw string("Errore la stringa presenta caratteri non validi");
			
		int result = firstChar-'a'; 
		return result;
	}
	
	void insert(NodeP dict[], const string name){
		tree::NodeP newNode = tree::createNode(name);
		int index = hash(name);
		tree::insert(dict[index],newNode);
	}
	
	
	void print(NodeP dict[]){
		
		for(int i=0; i < 26; ++i){
			tree::printInOrder(dict[i]);
		}
	}
	

	
	bool isUser(NodeP dict[], const string& key){
		int index = hash(key);
		if(index <0 || index >= 26)return 0;
		return !(tree::search(dict[index], key) == emptyNode);

	}
	
	tree::NodeP getNode(NodeP dict[], const string& key){
		int index = hash(key);
		if(index <0 || index >= 26)return 0;
		return tree::search(dict[index], key);

	}
}*/

