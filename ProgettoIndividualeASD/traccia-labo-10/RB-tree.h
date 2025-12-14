#ifndef RB_TREE_H
#define RB_TREE_H

// Implementa LIST con strutture indicizzate e tipo base Elem dotato di ordinamento
#include <string> 

using namespace std; 

namespace tree{
	enum Color { RED, BLACK};
	struct st_User;
	typedef st_User* User;
	struct st_User{
	
		User left;
		User right;
		User parent;
	};
	

/*
struct User;	
typedef User* UserP;
const UserP emptyUser = NULL;
typedef User elem;
namespace tree{
	struct Node;
	typedef Node* NodeP;
	const NodeP emptyNode = nullptr;
}







struct User {
	string usr_Log;
	tree::Node* FriendsList[26] = {tree::emptyNode};
	};


	
namespace tree{

enum Color { RED, BLACK};
	
struct Node{
	elem user;
	Color color;
	Node *left;
	Node *right;
	Node *parent;
};
	
	
	
	
	

  /************************* operazioni stateful (con side effect) ******************************************/

  /*NodeP createNode(const string&);
  void insert(NodeP&, NodeP);
  void printInOrder(NodeP);
  NodeP search(NodeP, const string&);
*/
}

#endif
