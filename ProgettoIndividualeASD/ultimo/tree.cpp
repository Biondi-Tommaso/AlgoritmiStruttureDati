#include <iostream>
#include "tree.h"

using namespace tree;

namespace tree{
void createEmptyGroup(GroupRBTree*& tree) {
    tree->TNULL = new GroupRBTreeNode;
    tree->TNULL->color = 0;
    tree->TNULL->left = nullptr;
    tree->TNULL->right = nullptr;
    tree->TNULL->data = {EmptyGroup, nullptr};
    tree->root = tree->TNULL;
}

void createEmptyUser(UserRBTree*& tree) {
    tree->TNULL = new UserRBTreeNode;
    tree->TNULL->color = 0;
    tree->TNULL->left = nullptr;
    tree->TNULL->right = nullptr;
    tree->TNULL->data = {EmptyUser, nullptr, nullptr, nullptr};
    tree->root = tree->TNULL;
}


void leftRotateGroup(GroupRBTree* tree, GroupRBTreeNode* x) {
    GroupRBTreeNode* y = x->right;
    x->right = y->left;
    if (y->left != tree->TNULL) {
        y->left->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == nullptr) {
        tree->root = y;
    } else if (x == x->parent->left) {
        x->parent->left = y;
    } else {
        x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
}

void rightRotateGroup(GroupRBTree* tree, GroupRBTreeNode* x) {
    GroupRBTreeNode* y = x->left;
    x->left = y->right;
    if (y->right != tree->TNULL) {
        y->right->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == nullptr) {
        tree->root = y;
    } else if (x == x->parent->right) {
        x->parent->right = y;
    } else {
        x->parent->left = y;
    }
    y->right = x;
    x->parent = y;
}

void leftRotateUser(UserRBTree* tree, UserRBTreeNode* x) {
    UserRBTreeNode* y = x->right;
    x->right = y->left;
    if (y->left != tree->TNULL) {
        y->left->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == nullptr) {
        tree->root = y;
    } else if (x == x->parent->left) {
        x->parent->left = y;
    } else {
        x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
}

void rightRotateUser(UserRBTree* tree, UserRBTreeNode* x) {
    UserRBTreeNode* y = x->left;
    x->left = y->right;
    if (y->right != tree->TNULL) {
        y->right->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == nullptr) {
        tree->root = y;
    } else if (x == x->parent->right) {
        x->parent->right = y;
    } else {
        x->parent->left = y;
    }
    y->right = x;
    x->parent = y;
}

void insertFixGroup(GroupRBTree* tree, GroupRBTreeNode* k) {
    GroupRBTreeNode* u;
    while (k->parent->color == 1) {
        if (k->parent == k->parent->parent->right) {
            u = k->parent->parent->left;
            if (u->color == 1) {
                u->color = 0;
                k->parent->color = 0;
                k->parent->parent->color = 1;
                k = k->parent->parent;
            } else {
                if (k == k->parent->left) {
                    k = k->parent;
                    rightRotateGroup(tree, k);
                }
                k->parent->color = 0;
                k->parent->parent->color = 1;
                leftRotateGroup(tree, k->parent->parent);
            }
        } else {
            u = k->parent->parent->right;
            if (u->color == 1) {
                u->color = 0;
                k->parent->color = 0;
                k->parent->parent->color = 1;
                k = k->parent->parent;
            } else {
                if (k == k->parent->right) {
                    k = k->parent;
                    leftRotateGroup(tree, k);
                }
                k->parent->color = 0;
                k->parent->parent->color = 1;
                rightRotateGroup(tree, k->parent->parent);
            }
        }
        if (k == tree->root) {
            break;
        }
    }
    tree->root->color = 0;
}

void insertFixUser(UserRBTree* tree, UserRBTreeNode* k) {
    UserRBTreeNode* u;
    while (k->parent->color == 1) {
        if (k->parent == k->parent->parent->right) {
            u = k->parent->parent->left;
            if (u->color == 1) {
                u->color = 0;
                k->parent->color = 0;
                k->parent->parent->color = 1;
                k = k->parent->parent;
            } else {
                if (k == k->parent->left) {
                    k = k->parent;
                    rightRotateUser(tree, k);
                }
                k->parent->color = 0;
                k->parent->parent->color = 1;
                leftRotateUser(tree, k->parent->parent);
            }
        } else {
            u = k->parent->parent->right;
            if (u->color == 1) {
                u->color = 0;
                k->parent->color = 0;
                k->parent->parent->color = 1;
                k = k->parent->parent;
            } else {
                if (k == k->parent->right) {
                    k = k->parent;
                    leftRotateUser(tree, k);
                }
                k->parent->color = 0;
                k->parent->parent->color = 1;
                rightRotateUser(tree, k->parent->parent);
            }
        }
        if (k == tree->root) {
            break;
        }
    }
    tree->root->color = 0;
}

void insertGroup(GroupRBTree* tree, Group key) {
    GroupRBTreeNode* node = new GroupRBTreeNode;
    node->parent = nullptr;
    node->data = key;
    node->left = tree->TNULL;
    node->right = tree->TNULL;
    node->color = 1; // New node must be red

    GroupRBTreeNode* y = nullptr;
    GroupRBTreeNode* x = tree->root;

    while (x != tree->TNULL) {
        y = x;
        if (node->data.nome < x->data.nome) {
            x = x->left;
        } else {
            x = x->right;
        }
    }

    node->parent = y;
    if (y == nullptr) {
        tree->root = node;
    } else if (node->data.nome < y->data.nome) {
        y->left = node;
    } else {
        y->right = node;
    }

    if (node->parent == nullptr) {
        node->color = 0;
        return;
    }

    if (node->parent->parent == nullptr) {
        return;
    }

    insertFixGroup(tree, node);
}

void insertUser(UserRBTree* tree, User key) {
    // Initialize MemberOf field
    key.MemberOf = new GroupRBTree;
    createEmptyGroup(key.MemberOf);

    UserRBTreeNode* node = new UserRBTreeNode;
    node->parent = nullptr;
    node->data = key;
    node->left = tree->TNULL;
    node->right = tree->TNULL;
    node->color = 1; // New node must be red

    UserRBTreeNode* y = nullptr;
    UserRBTreeNode* x = tree->root;

    while (x != tree->TNULL) {
        y = x;
        if (node->data.user_Log < x->data.user_Log) {
            x = x->left;
        } else {
            x = x->right;
        }
    }

	


    node->parent = y;
    if (y == nullptr) {
        tree->root = node;
    } else if (node->data.user_Log < y->data.user_Log) {
        y->left = node;
    } else {
        y->right = node;
    }

    if (node->parent == nullptr) {
        node->color = 0;
        return;
    }

    if (node->parent->parent == nullptr) {
        return;
    }

    insertFixUser(tree, node);
}




GroupRBTreeNode* searchTreeHelperGroup(GroupRBTreeNode* node, GroupRBTreeNode* TNULL, std::string key) {
    if (node == TNULL || key == node->data.nome) {
        return node;
    }

    if (key < node->data.nome) {
        return searchTreeHelperGroup(node->left, TNULL, key);
    }
    return searchTreeHelperGroup(node->right, TNULL, key);
}

UserRBTreeNode* searchTreeHelperUser(UserRBTreeNode* node, UserRBTreeNode* TNULL, std::string key) {
   if (node == TNULL) {
        return node;
    } else if (key == node->data.user_Log){
    	return node;
    }

    if (key < node->data.user_Log) {
        return searchTreeHelperUser(node->left, TNULL, key);
    }
    return searchTreeHelperUser(node->right, TNULL, key);
}

GroupRBTreeNode* searchGroup(GroupRBTree* tree, std::string k) {
    return searchTreeHelperGroup(tree->root, tree->TNULL, k);
}

UserRBTreeNode* searchUser(UserRBTree* tree, std::string k) {
   return searchTreeHelperUser(tree->root, tree->TNULL, k);
    
  /*  
   std::cout << "si avvia\n ";
    //if(tree -> root == tree -> TNULL) std::cout << "l'albero è vuoto";
    //else std::cout << "BEççA";
    
    return tree->TNULL;*/
}

// Function to perform an inorder tree traversal for users
void inorderHelperUser(UserRBTreeNode* node, UserRBTreeNode* TNULL) {
    if (node != TNULL) {
        inorderHelperUser(node->left, TNULL);
        std::cout << node->data.user_Log << " ";
        inorderHelperUser(node->right, TNULL);
    }
}

// Function to perform an inorder tree traversal for groups
void inorderHelperGroup(GroupRBTreeNode* node, GroupRBTreeNode* TNULL) {
    if (node != TNULL) {
        inorderHelperGroup(node->left, TNULL);
        std::cout << node->data.nome << " ";
        inorderHelperGroup(node->right, TNULL);
    }
}

void inorderUser(UserRBTree* tree) {
    inorderHelperUser(tree->root, tree->TNULL);
}

void inorderGroup(GroupRBTree* tree) {
    inorderHelperGroup(tree->root, tree->TNULL);
}



// Funzione helper per cancellare un nodo dall'albero RBTree dei gruppi
void rbTransplantGroup(GroupRBTree* tree, GroupRBTreeNode* u, GroupRBTreeNode* v) {
    if (u->parent == nullptr) {
        tree->root = v;
    } else if (u == u->parent->left) {
        u->parent->left = v;
    } else {
        u->parent->right = v;
    }
    v->parent = u->parent;
}

void deleteFixGroup(GroupRBTree* tree, GroupRBTreeNode* x) {
    GroupRBTreeNode* s;
    while (x != tree->root && x->color == 0) {
        if (x == x->parent->left) {
            s = x->parent->right;
            if (s->color == 1) {
                s->color = 0;
                x->parent->color = 1;
                leftRotateGroup(tree, x->parent);
                s = x->parent->right;
            }

            if (s->left->color == 0 && s->right->color == 0) {
                s->color = 1;
                x = x->parent;
            } else {
                if (s->right->color == 0) {
                    s->left->color = 0;
                    s->color = 1;
                    rightRotateGroup(tree, s);
                    s = x->parent->right;
                }

                s->color = x->parent->color;
                x->parent->color = 0;
                s->right->color = 0;
                leftRotateGroup(tree, x->parent);
                x = tree->root;
            }
        } else {
            s = x->parent->left;
            if (s->color == 1) {
                s->color = 0;
                x->parent->color = 1;
                rightRotateGroup(tree, x->parent);
                s = x->parent->left;
            }

            if (s->right->color == 0 && s->left->color == 0) {
                s->color = 1;
                x = x->parent;
            } else {
                if (s->left->color == 0) {
                    s->right->color = 0;
                    s->color = 1;
                    leftRotateGroup(tree, s);
                    s = x->parent->left;
                }

                s->color = x->parent->color;
                x->parent->color = 0;
                s->left->color = 0;
                rightRotateGroup(tree, x->parent);
                x = tree->root;
            }
        }
    }
    x->color = 0;
}

// Funzione helper per trovare il minimo valore in un albero di tipo GroupRBTree
GroupRBTreeNode* minimum(GroupRBTree* tree, GroupRBTreeNode* node) {
    while (node->left != tree->TNULL) {
        node = node->left;
    }
    return node;
}

// Funzione helper per trovare il minimo valore in un albero di tipo UserRBTree
UserRBTreeNode* minimum(UserRBTree* tree, UserRBTreeNode* node) {
    while (node->left != tree->TNULL) {
        node = node->left;
    }
    return node;
}



// Funzione helper per cancellare un nodo dall'albero RBTree degli utenti
void rbTransplantUser(UserRBTree* tree, UserRBTreeNode* u, UserRBTreeNode* v) {
    if (u->parent == nullptr) {
        tree->root = v;
    } else if (u == u->parent->left) {
        u->parent->left = v;
    } else {
        u->parent->right = v;
    }
    v->parent = u->parent;
}

void deleteFixUser(UserRBTree* tree, UserRBTreeNode* x) {
    UserRBTreeNode* s;
    while (x != tree->root && x->color == 0) {
        if (x == x->parent->left) {
            s = x->parent->right;
            if (s->color == 1) {
                s->color = 0;
                x->parent->color = 1;
                leftRotateUser(tree, x->parent);
                s = x->parent->right;
            }

            if (s->left->color == 0 && s->right->color == 0) {
                s->color = 1;
                x = x->parent;
            } else {
                if (s->right->color == 0) {
                    s->left->color = 0;
                    s->color = 1;
                    rightRotateUser(tree, s);
                    s = x->parent->right;
                }

                s->color = x->parent->color;
                x->parent->color = 0;
                s->right->color = 0;
                leftRotateUser(tree, x->parent);
                x = tree->root;
            }
        } else {
            s = x->parent->left;
            if (s->color == 1) {
                s->color = 0;
                x->parent->color = 1;
                rightRotateUser(tree, x->parent);
                s = x->parent->left;
            }

            if (s->right->color == 0 && s->left->color == 0) {
                s->color = 1;
                x = x->parent;
            } else {
                if (s->left->color == 0) {
                    s->right->color = 0;
                    s->color = 1;
                    leftRotateUser(tree, s);
                    s = x->parent->left;
                }

                s->color = x->parent->color;
                x->parent->color = 0;
                s->left->color = 0;
                rightRotateUser(tree, x->parent);
                x = tree->root;
            }
        }
    }
    x->color = 0;
}

void deleteUser(UserRBTree* tree, std::string key) {
    UserRBTreeNode* node = searchTreeHelperUser(tree->root, tree->TNULL, key);
    if (node == tree->TNULL) {
        return;
    }

    // Clear the MemberOf tree
    clearGroupTree(node->data.MemberOf);
    delete node->data.MemberOf;

    UserRBTreeNode* z = node;
    UserRBTreeNode* x, * y = z;
    int yOriginalColor = y->color;

    if (z->left == tree->TNULL) {
        x = z->right;
        rbTransplantUser(tree, z, z->right);
    } else if (z->right == tree->TNULL) {
        x = z->left;
        rbTransplantUser(tree, z, z->left);
    } else {
        y = minimum(tree, z->right);
        yOriginalColor = y->color;
        x = y->right;
        if (y->parent == z) {
            x->parent = y;
        } else {
            rbTransplantUser(tree, y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }

        rbTransplantUser(tree, z, y);
        y->left = z->left;
        y->left->parent = y;
        y->color = z->color;
    }

    delete z;

    if (yOriginalColor == 0) {
        deleteFixUser(tree, x);
    }
}



void deleteGroup(GroupRBTree* tree, std::string key) {
    GroupRBTreeNode* node = searchTreeHelperGroup(tree->root, tree->TNULL, key);
    if (node == tree->TNULL) {
        return;
    }

    GroupRBTreeNode* z = node;
    GroupRBTreeNode* x, * y = z;
    int yOriginalColor = y->color;
    if (z->left == tree->TNULL) {
        x = z->right;
        rbTransplantGroup(tree, z, z->right);
    } else if (z->right == tree->TNULL) {
        x = z->left;
        rbTransplantGroup(tree, z, z->left);
    } else {
        y = minimum(tree, z->right);
        yOriginalColor = y->color;
        x = y->right;
        if (y->parent == z) {
            x->parent = y;
        } else {
            rbTransplantGroup(tree, y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }

        rbTransplantGroup(tree, z, y);
        y->left = z->left;
        y->left->parent = y;
        y->color = z->color;
    }
    delete z;
    if (yOriginalColor == 0) {
        deleteFixGroup(tree, x);
    }
}

void clearGroupTree(UserRBTree* tree) {
    while (tree->root != tree->TNULL) {
        deleteUser(tree, tree->root->data.user_Log);
    }
    delete tree->TNULL;
}

void clearGroupTree(GroupRBTree* tree) {
    while (tree->root != tree->TNULL) {
        deleteGroup(tree, tree->root->data.nome);
    }
    delete tree->TNULL;
}

void clearUserTree(UserRBTree* tree) {
    while (tree->root != tree->TNULL) {
        deleteUser(tree, tree->root->data.user_Log);
    }
    delete tree->TNULL;
}

void memberAux(UserRBTreeNode* tree, list::List& list){

	if(tree == nullptr) return ;
	
	memberAux(tree  -> left, list);

	if(tree  -> data.user_Log != EmptyUser){

		list::addBack(tree -> data.user_Log,list);
		
	}	
	memberAux(tree  -> right, list);
	return ;
	}


void member(UserRBTreeNode* tree, list::List& list){
	return memberAux(tree, list);
}



void groupAux(GroupRBTreeNode* tree, list::List& list){

	if(tree == nullptr) return ;
	
	groupAux(tree  -> left, list);
	if(tree  -> data.nome != EmptyUser){
		list::addBack(tree -> data.nome,list);
		
	}	
	groupAux(tree  -> right, list);
	return ;
	}


void groups(GroupRBTreeNode* tree, list::List& list){
	return groupAux(tree, list);
}

}




#include <iomanip> // Include this for std::setw
namespace tree {

// Helper function to print the UserRBTreeNode
void printUserNode(UserRBTreeNode* node, UserRBTreeNode* TNULL, int indent = 0) {
    if (node != TNULL) {
        if (node->right) {
            printUserNode(node->right, TNULL, indent + 4);
        }
        if (indent) {
            std::cout << std::setw(indent) << ' ';
        }
        if (node->right) {
            std::cout << " /\n" << std::setw(indent) << ' ';
        }
        std::cout << node->data.user_Log << "\n ";
        if (node->left) {
            std::cout << std::setw(indent) << ' ' << " \\\n";
            printUserNode(node->left, TNULL, indent + 4);
        }
    }
}

// Function to print the entire User Red-Black Tree
void printUserTree(UserRBTree* tree) {
    if (tree == nullptr || tree->root == nullptr) {
        std::cout << "The User Red-Black Tree is empty.\n";
        return;
    }
    printUserNode(tree->root, tree->TNULL);
}

// Helper function to print the GroupRBTreeNode
void printGroupNode(GroupRBTreeNode* node, GroupRBTreeNode* TNULL, int indent = 0) {
    if (node != TNULL) {
        if (node->right) {
            printGroupNode(node->right, TNULL, indent + 4);
        }
        if (indent) {
            std::cout << std::setw(indent) << ' ';
        }
        if (node->right) {
            std::cout << " /\n" << std::setw(indent) << ' ';
        }
        std::cout << node->data.nome << "\n ";
        if (node->left) {
            std::cout << std::setw(indent) << ' ' << " \\\n";
            printGroupNode(node->left, TNULL, indent + 4);
        }
    }
}

// Function to print the entire Group Red-Black Tree
void printGroupTree(GroupRBTree* tree) {
    if (tree == nullptr || tree->root == nullptr) {
        std::cout << "The Group Red-Black Tree is empty.\n";
        return;
    }
    printGroupNode(tree->root, tree->TNULL);
}

} // namespace tree

