#include <iostream>
#include <string>

using namespace std;

const string EmptyNode = "EmptyNode";
const string EmptyTree = "EmptyTree";
const string EmptyUser = "EmptyUser";
const string EmptyGroup = "EmptyGroup";

struct User;

struct Group {
    string nome;
    struct UserRBTree* partecipanti;
};

struct User {
    string user_Log;
    struct UserRBTree* friend_List;
    struct GroupRBTree* LeaderOf;
};

// Strutture per il Red-Black Tree dei gruppi
struct GroupRBTreeNode {
    Group data;
    GroupRBTreeNode* parent;
    GroupRBTreeNode* left;
    GroupRBTreeNode* right;
    bool color; // 1 -> Red, 0 -> Black
};

struct GroupRBTree {
    GroupRBTreeNode* root;
    GroupRBTreeNode* TNULL;
};

// Strutture per il Red-Black Tree degli utenti
struct UserRBTreeNode {
    User data;
    UserRBTreeNode* parent;
    UserRBTreeNode* left;
    UserRBTreeNode* right;
    bool color; // 1 -> Red, 0 -> Black
};

struct UserRBTree {
    UserRBTreeNode* root;
    UserRBTreeNode* TNULL;
};

void createEmptyGroup(GroupRBTree* tree) {
    tree->TNULL = new GroupRBTreeNode;
    tree->TNULL->color = 0;
    tree->TNULL->left = nullptr;
    tree->TNULL->right = nullptr;
    tree->TNULL->data = {EmptyGroup, nullptr};
    tree->root = tree->TNULL;
}

void createEmptyUser(UserRBTree* tree) {
    tree->TNULL = new UserRBTreeNode;
    tree->TNULL->color = 0;
    tree->TNULL->left = nullptr;
    tree->TNULL->right = nullptr;
    tree->TNULL->data = {EmptyUser, nullptr, nullptr};
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

void printGroupTreeHelper(GroupRBTreeNode* root, GroupRBTreeNode* TNULL, string indent, bool last) {
    if (root != TNULL) {
        cout << indent;
        if (last) {
            cout << "R----";
            indent += "   ";
        } else {
            cout << "L----";
            indent += "|  ";
        }

        string sColor = root->color ? "RED" : "BLACK";
        cout << root->data.nome << "(" << sColor << ")" << endl;
        printGroupTreeHelper(root->left, TNULL, indent, false);
        printGroupTreeHelper(root->right, TNULL, indent, true);
    }
}

void printGroupTree(GroupRBTree* tree) {
    if (tree->root) {
        printGroupTreeHelper(tree->root, tree->TNULL, "", true);
    }
}

void printUserTreeHelper(UserRBTreeNode* root, UserRBTreeNode* TNULL, string indent, bool last) {
    if (root != TNULL) {
        cout << indent;
        if (last) {
            cout << "R----";
            indent += "   ";
        } else {
            cout << "L----";
            indent += "|  ";
        }

        string sColor = root->color ? "RED" : "BLACK";
        cout << root->data.user_Log << "(" << sColor << ")" << endl;
        printUserTreeHelper(root->left, TNULL, indent, false);
        printUserTreeHelper(root->right, TNULL, indent, true);
    }
}

void printUserTree(UserRBTree* tree) {
    if (tree->root) {
        printUserTreeHelper(tree->root, tree->TNULL, "", true);
    }
}

void transplantUser(UserRBTree* tree, UserRBTreeNode* u, UserRBTreeNode* v) {
    if (u->parent == nullptr) {
        tree->root = v;
    } else if (u == u->parent->left) {
        u->parent->left = v;
    } else {
        u->parent->right = v;
    }
    v->parent = u->parent;
}




GroupRBTreeNode* minimumGroup(GroupRBTreeNode* node, GroupRBTreeNode* TNULL) {
    while (node->left != TNULL) {
        node = node->left;
    }
    return node;
}

void transplantGroup(GroupRBTree* tree, GroupRBTreeNode* u, GroupRBTreeNode* v) {
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
    while (x != tree->root && x->color == 0) {
        if (x == x->parent->left) {
            UserRBTreeNode* w = x->parent->right;
            if (w->color == 1) {
                w->color = 0;
                x->parent->color = 1;
                leftRotateUser(tree, x->parent);
                w = x->parent->right;
            }
            if (w->left->color == 0 && w->right->color == 0) {
                w->color = 1;
                x = x->parent;
            } else {
                if (w->right->color == 0) {
                    w->left->color = 0;
                    w->color = 1;
                    rightRotateUser(tree, w);
                    w = x->parent->right;
                }
                w->color = x->parent->color;
                x->parent->color = 0;
                w->right->color = 0;
                leftRotateUser(tree, x->parent);
                x = tree->root;
            }
        } else {
            UserRBTreeNode* w = x->parent->left;
            if (w->color == 1) {
                w->color = 0;
                x->parent->color = 1;
                rightRotateUser(tree, x->parent);
                w = x->parent->left;
            }
            if (w->right->color == 0 && w->left->color == 0) {
                w->color = 1;
                x = x->parent;
            } else {
                if (w->left->color == 0) {
                    w->right->color = 0;
                    w->color = 1;
                    leftRotateUser(tree, w);
                    w = x->parent->left;
                }
                w->color = x->parent->color;
                x->parent->color = 0;
                w->left->color = 0;
                rightRotateUser(tree, x->parent);
                x = tree->root;
            }
        }
    }
    x->color = 0;
}

UserRBTreeNode* minimumUser(UserRBTreeNode* node, UserRBTreeNode* TNULL) {
    while (node->left != TNULL) {
        node = node->left;
    }
    return node;
}



void deleteUser(UserRBTree* tree, const string& user_Log) {
    UserRBTreeNode* z = tree->root;
    while (z != tree->TNULL) {
        if (user_Log == z->data.user_Log) {
            break;
        } else if (user_Log < z->data.user_Log) {
            z = z->left;
        } else {
            z = z->right;
        }
    }
    if (z == tree->TNULL) {
        // User not found
        return;
    }

    UserRBTreeNode* y = z;
    bool yOriginalColor = y->color;
    UserRBTreeNode* x;
    if (z->left == tree->TNULL) {
        x = z->right;
        transplantUser(tree, z, z->right);
    } else if (z->right == tree->TNULL) {
        x = z->left;
        transplantUser(tree, z, z->left);
    } else {
        y = minimumUser(z->right, tree->TNULL);
        yOriginalColor = y->color;
        x = y->right;
        if (y->parent == z) {
            x->parent = y;
        } else {
            transplantUser(tree, y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }
        transplantUser(tree, z, y);
        y->left = z->left;
        y->left->parent = y;
        y->color = z->color;
    }
    if (yOriginalColor == 0) {
        deleteFixUser(tree, x);
    }
    delete z;
}





void deleteFixGroup(GroupRBTree* tree, GroupRBTreeNode* x) {
    while (x != tree->root && x->color == 0) {
        if (x == x->parent->left) {
            GroupRBTreeNode* w = x->parent->right;
            if (w->color == 1) {
                w->color = 0;
                x->parent->color = 1;
                leftRotateGroup(tree, x->parent);
                w = x->parent->right;
            }
            if (w->left->color == 0 && w->right->color == 0) {
                w->color = 1;
                x = x->parent;
            } else {
                if (w->right->color == 0) {
                    w->left->color = 0;
                    w->color = 1;
                    rightRotateGroup(tree, w);
                    w = x->parent->right;
                }
                w->color = x->parent->color;
                x->parent->color = 0;
                w->right->color = 0;
                leftRotateGroup(tree, x->parent);
                x = tree->root;
            }
        } else {
            GroupRBTreeNode* w = x->parent->left;
            if (w->color == 1) {
                w->color = 0;
                x->parent->color = 1;
                rightRotateGroup(tree, x->parent);
                w = x->parent->left;
            }
            if (w->right->color == 0 && w->left->color == 0) {
                w->color = 1;
                x = x->parent;
            } else {
                if (w->left->color == 0) {
                    w->right->color = 0;
                    w->color = 1;
                    leftRotateGroup(tree, w);
                    w = x->parent->left;
                }
                w->color = x->parent->color;
                x->parent->color = 0;
                w->left->color = 0;
                rightRotateGroup(tree, x->parent);
                x = tree->root;
            }
        }
    }
    x->color = 0;
}

void deleteGroup(GroupRBTree* tree, const string& nome) {
    GroupRBTreeNode* z = tree->root;
    while (z != tree->TNULL) {
        if (nome == z->data.nome) {
            break;
        } else if (nome < z->data.nome) {
            z = z->left;
        } else {
            z = z->right;
        }
    }
    if (z == tree->TNULL) {
        // Group not found
        return;
    }

    GroupRBTreeNode* y = z;
    bool yOriginalColor = y->color;
    GroupRBTreeNode* x;
    if (z->left == tree->TNULL) {
        x = z->right;
        transplantGroup(tree, z, z->right);
    } else if (z->right == tree->TNULL) {
        x = z->left;
        transplantGroup(tree, z, z->left);
    } else {
        y = minimumGroup(z->right, tree->TNULL);
        yOriginalColor = y->color;
        x = y->right;
        if (y->parent == z) {
            x->parent = y;
        } else {
            transplantGroup(tree, y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }
        transplantGroup(tree, z, y);
        y->left = z->left;
        y->left->parent = y;
        y->color = z->color;
    }
    if (yOriginalColor == 0) {
        deleteFixGroup(tree, x);
    }
    delete z;
}

void deleteGroupFromLeader(UserRBTree* tree, const string& groupNome) {
    // Search for the leader
    UserRBTreeNode* leaderNode = tree->root;
    while (leaderNode != tree->TNULL) {
        GroupRBTreeNode* leaderGroupNode = leaderNode->data.LeaderOf->root;
        bool found = false;
        while (leaderGroupNode != leaderNode->data.LeaderOf->TNULL) {
            if (leaderGroupNode->data.nome == groupNome) {
                found = true;
                break;
            } else if (groupNome < leaderGroupNode->data.nome) {
                leaderGroupNode = leaderGroupNode->left;
            } else {
                leaderGroupNode = leaderGroupNode->right;
            }
        }
        if (found) {
            // Delete the group reference from the leader's LeaderOf tree
            deleteGroup(leaderNode->data.LeaderOf, groupNome);
            break;
        } else {
            if (groupNome < leaderNode->data.user_Log) {
                leaderNode = leaderNode->left;
            } else {
                leaderNode = leaderNode->right;
            }
        }
    }
}




bool areFriends(UserRBTree* tree, const string& user1_Log, const string& user2_Log) {
    UserRBTreeNode* user1_Node = tree->root;
    UserRBTreeNode* user2_Node = tree->root;

    // Trova il nodo dell'utente 1
    while (user1_Node != tree->TNULL) {
        if (user1_Log == user1_Node->data.user_Log) {
            break;
        } else if (user1_Log < user1_Node->data.user_Log) {
            user1_Node = user1_Node->left;
        } else {
            user1_Node = user1_Node->right;
        }
    }

    // Trova il nodo dell'utente 2
    while (user2_Node != tree->TNULL) {
        if (user2_Log == user2_Node->data.user_Log) {
            break;
        } else if (user2_Log < user2_Node->data.user_Log) {
            user2_Node = user2_Node->left;
        } else {
            user2_Node = user2_Node->right;
        }
    }

    // Se uno dei due utenti non esiste, restituisci false
    if (user1_Node == tree->TNULL || user2_Node == tree->TNULL) {
        return false;
    }

    // Verifica se user2 è presente nella lista degli amici di user1
    UserRBTreeNode* currentFriend = user1_Node->data.friend_List->root;
    while (currentFriend != user1_Node->data.friend_List->TNULL) {
        if (currentFriend->data.user_Log == user2_Log) {
            return true; // user2 è un amico di user1
        } else if (user2_Log < currentFriend->data.user_Log) {
            currentFriend = currentFriend->left;
        } else {
            currentFriend = currentFriend->right;
        }
    }

    // Se user2 non è stato trovato nella lista degli amici di user1, restituisci false
    return false;
}


void addUserToGroup(UserRBTree* userTree, GroupRBTree* groupTree, const string& user_Log, const string& groupNome) {
    // Cerca il nodo dell'utente
    UserRBTreeNode* userNode = userTree->root;
    while (userNode != userTree->TNULL) {
        if (user_Log == userNode->data.user_Log) {
            break;
        } else if (user_Log < userNode->data.user_Log) {
            userNode = userNode->left;
        } else {
            userNode = userNode->right;
        }
    }

    // Se l'utente non esiste, esci dalla funzione
    if (userNode == userTree->TNULL) {
        cout << "User not found." << endl;
        return;
    }

    // Cerca il nodo del gruppo
    GroupRBTreeNode* groupNode = groupTree->root;
    while (groupNode != groupTree->TNULL) {
        if (groupNome == groupNode->data.nome) {
            break;
        } else if (groupNome < groupNode->data.nome) {
            groupNode = groupNode->left;
        } else {
            groupNode = groupNode->right;
        }
    }

    // Se il gruppo non esiste, esci dalla funzione
    if (groupNode == groupTree->TNULL) {
        cout << "Group not found." << endl;
        return;
    }

    // Inserisci l'utente nella lista dei partecipanti al gruppo
    insertUser(groupNode->data.partecipanti, userNode->data);

    // Aggiorna il riferimento del gruppo nell'albero degli utenti
    userNode->data.LeaderOf = groupTree;
}


void removeUserFromGroup(GroupRBTree* groupTree, const string& groupNome, const string& user_Log) {
    // Cerca il nodo del gruppo
    GroupRBTreeNode* groupNode = groupTree->root;
    while (groupNode != groupTree->TNULL) {
        if (groupNome == groupNode->data.nome) {
            break;
        } else if (groupNome < groupNode->data.nome) {
            groupNode = groupNode->left;
        } else {
            groupNode = groupNode->right;
        }
    }

    // Se il gruppo non esiste, esci dalla funzione
    if (groupNode == groupTree->TNULL) {
        cout << "Group not found." << endl;
        return;
    }

    // Cerca l'utente nel gruppo e rimuovilo
    deleteUser(groupNode->data.partecipanti, user_Log);
}

void addFriendship(UserRBTree* tree, const string& user1_Log, const string& user2_Log) {
    // Trova il nodo dell'utente 1
    UserRBTreeNode* user1_Node = tree->root;
    while (user1_Node != tree->TNULL) {
        if (user1_Log == user1_Node->data.user_Log) {
            break;
        } else if (user1_Log < user1_Node->data.user_Log) {
            user1_Node = user1_Node->left;
        } else {
            user1_Node = user1_Node->right;
        }
    }

    // Se l'utente 1 non esiste, esci dalla funzione
    if (user1_Node == tree->TNULL) {
        cout << "User1 not found." << endl;
        return;
    }

    // Trova il nodo dell'utente 2
    UserRBTreeNode* user2_Node = tree->root;
    while (user2_Node != tree->TNULL) {
        if (user2_Log == user2_Node->data.user_Log) {
            break;
        } else if (user2_Log < user2_Node->data.user_Log) {
            user2_Node = user2_Node->left;
        } else {
            user2_Node = user2_Node->right;
        }
    }

    // Se l'utente 2 non esiste, esci dalla funzione
    if (user2_Node == tree->TNULL) {
        cout << "User2 not found." << endl;
        return;
    }

    // Verifica se i due utenti sono già amici
    if (areFriends(tree, user1_Log, user2_Log)) {
        cout << "Users are already friends." << endl;
        return;
    }

    // Aggiungi l'amicizia tra i due utenti
    insertUser(user1_Node->data.friend_List, user2_Node->data);
    insertUser(user2_Node->data.friend_List, user1_Node->data);
}





/*



int main() {
    // Creazione degli alberi
    GroupRBTree groupTree;
    createEmptyGroup(&groupTree);

    UserRBTree userTree;
    createEmptyUser(&userTree);

    // Creazione dei gruppi
    Group g1 = {"Group1", new UserRBTree};
    Group g2 = {"Group2", new UserRBTree};
    Group g3 = {"Group3", new UserRBTree};
    Group g4 = {"Group4", new UserRBTree};
    
    createEmptyUser(g1.partecipanti);
    createEmptyUser(g2.partecipanti);
    createEmptyUser(g3.partecipanti);
    createEmptyUser(g4.partecipanti);
    
    insertGroup(&groupTree, g1);
    insertGroup(&groupTree, g2);
    insertGroup(&groupTree, g3);
    insertGroup(&groupTree, g4);

    // Stampa dell'albero dei gruppi prima dell'eliminazione
    cout << "Group RB Tree:" << endl;
    printGroupTree(&groupTree);
    cout << endl;

    // Eliminazione di un gruppo
    deleteGroup(&groupTree, "Group2");

    // Stampa dell'albero dei gruppi dopo l'eliminazione
    cout << "Group RB Tree after deleting Group2:" << endl;
    printGroupTree(&groupTree);
    cout << endl;

    // Eliminazione del riferimento al gruppo dall'albero LeaderOf dell'utente leader
    deleteGroupFromLeader(&userTree, "Group2");

    // Stampa dell'albero degli utenti del gruppo dopo l'eliminazione del gruppo
    cout << "Users in Group1 after deleting Group2:" << endl;
    printUserTree(g1.partecipanti);
    cout << "Users in Group2 after deleting Group2:" << endl;
    printUserTree(g2.partecipanti);
    cout << "Users in Group3 after deleting Group2:" << endl;
    printUserTree(g3.partecipanti);
    cout << "Users in Group4 after deleting Group2:" << endl;
    printUserTree(g4.partecipanti);

    return 0;
}*/



