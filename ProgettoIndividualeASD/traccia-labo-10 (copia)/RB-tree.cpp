#include <iostream>
#include <string>
#include <cstdlib>
#include "RB-tree.h"
using namespace std;
using namespace tree;
	
	
	//funzioni ausiliari //
	namespace tree{
	//crea un nuovo nodo
	NodeP createNode(const string& name){
		NodeP node = new Node;
		node -> user.usr_Log = name;
		node -> color = RED;
		node -> left = emptyNode;
		node -> right = emptyNode;
		node -> parent = emptyNode;
		return node;
	}
	
	//funzione per fare una rotazione a sinistra
	void rotateLeft(NodeP& root, NodeP pt){
		NodeP pt_right = pt -> right;
		
		pt->right = pt_right -> left;
		
		if(pt_right-> left != emptyNode){
			pt_right -> left -> parent = pt;
		}
		
		pt_right->parent = pt -> parent;

		if(pt ->parent == emptyNode){
			root = pt_right;
		}
		else if( pt == pt-> parent-> left){
			pt -> parent-> left = pt_right;
		}
		else{
			pt->parent->right = pt_right;
		}
		
		pt_right->left = pt;
		pt->parent = pt_right;
	}
	
	//funzione per fare una rotazione a destra
	void rotateRight(NodeP& root, NodeP pt){
		NodeP pt_left = pt -> left;
		
		pt->left = pt_left -> right;
		
		if(pt_left -> right != emptyNode){
			pt_left -> right -> parent = pt;
		}
		
		pt_left->parent = pt -> parent;

		if(pt ->parent == emptyNode){
			root = pt_left;
		}
		else if( pt == pt-> parent-> right){
			pt -> parent-> left = pt_left;
		}
		else{
			pt->parent->right = pt_left;
		}
		
		pt_left->right = pt;
		pt->parent = pt_left;
	}
	
	//eseguo lo swap fra i colori di due nodi
	void swap(NodeP &node1, NodeP &node2){
		NodeP aux = node1;
		node1 -> color = node2 -> color;
		node2 -> color = aux -> color;
	}
	
	
	//funzione per correggere le proprietà dell'albero rosso-nero
	void fixViolation (NodeP &root, NodeP pt){
		NodeP parent_pt = emptyNode;
		NodeP grand_parent_pt = emptyNode;
		
		while((pt != root) && (pt->color ==RED) && (pt -> parent -> color == RED)){
		
		parent_pt=pt -> parent;
		grand_parent_pt = pt->parent-> parent;
		
		
		//caso 1: il genitore pt è il figlio sinistro del nonno di pt
		if(parent_pt == grand_parent_pt -> left){
			NodeP uncle_pt = grand_parent_pt -> right;
			//caso A: lo zio di pt è ancora rosso
			if(uncle_pt != emptyNode && uncle_pt->color == RED){
				grand_parent_pt -> color = RED;
				parent_pt->color = BLACK;
				uncle_pt->color = BLACK;
				pt = grand_parent_pt;
			}
			//caso B: pt è il figlio destro del suo genitore
			else {
				if(pt == parent_pt -> right){
					rotateLeft(root, parent_pt);
					pt = parent_pt;
					parent_pt = pt-> parent;
				}
				//caso C: pt è il figlio sinistro del suo genitore
				rotateRight(root, grand_parent_pt);
				swap (parent_pt, grand_parent_pt);
				pt = parent_pt;
			}
		} //caso 2: il genitore di pt è il figlio detro del nonno di pt
		else{
		NodeP uncle_pt = grand_parent_pt -> left;
		
		//caso A: lo zio di pt è amche rosso
		if( (uncle_pt != emptyNode) && (uncle_pt-> color == RED)){
			grand_parent_pt ->color = RED;
			parent_pt->color = BLACK;
			uncle_pt->color = BLACK;
			pt = grand_parent_pt;
		}
		//Caso b: pt è il figlio sinsitro del suo genitore
		 else{
		 	if(pt == parent_pt->left){
		 		rotateRight(root, parent_pt);
		 		pt = parent_pt;
		 		parent_pt = pt->parent;
		 	}
		 	
		 	//caso c: pt è il figlio destro del suo genitore
		 	rotateLeft(root, grand_parent_pt);
		 	swap(parent_pt, grand_parent_pt);
		 	pt=parent_pt;
		}
	}
}
root -> color = BLACK;
}
   
   void insert(NodeP& root, NodeP pt){
   	if(root == emptyNode){
   		root = pt;
   		root -> color = BLACK;
   		return;
   	}
   	
   	NodeP parent = emptyNode;
   	NodeP current = root;
   	
   	while( current != emptyNode){
   		parent = current;
   		if(pt->user.usr_Log < current->user.usr_Log)
   			current = current -> left;
   		else if(pt-> user.usr_Log > current->user.usr_Log)
   			current = current -> right;
   		else return; //evita duplicati
   	}
   	
   	pt -> parent = parent;
   	
   	if (pt -> user.usr_Log < parent -> user.usr_Log)
   		parent -> left = pt;
   	else
   		parent -> right = pt;
   	fixViolation(root, pt);
   }



//funzione per stampare l'albero in ordine (stampa simmetrica)
void inorderHelper(NodeP root){
	if(root == emptyNode)
		return;
	inorderHelper(root -> left);
	cout << root -> user.usr_Log << " ";
	inorderHelper (root -> right);
}


void printInOrder(NodeP root){
	inorderHelper(root);
}





NodeP search(NodeP root, const string& key){
	while (root != emptyNode){
		if(key == root -> user.usr_Log)
			return root;
		else if (key < root -> user.usr_Log)
			root = root-> left;
		else
			root = root -> right;
		}
		return emptyNode;
	}


}
