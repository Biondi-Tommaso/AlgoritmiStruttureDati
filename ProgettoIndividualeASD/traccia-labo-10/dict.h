#ifndef DICT_H
#define DICT_H

// Implementa LIST con strutture indicizzate e tipo base Elem dotato di ordinamento
#include <string> 
#include "RB-tree.h"
using namespace std; 
using namespace tree;

 
namespace dict{


	void insert(NodeP dict[], const string name);
	void print(NodeP dict[]);
	bool isUser(NodeP dict[], const string& key);
	tree::NodeP getNode(NodeP dict[], const string& key);
}

#endif
