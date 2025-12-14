#ifndef TREE_H
#define TREE_H

#include "list-array.h"
namespace tree {


const std::string EmptyUser = "";
const std::string EmptyGroup = "";

// Predeclarations
struct Group;
struct GroupRBTree;
struct UserRBTree;

// User structure
struct User {
    std::string user_Log;
    UserRBTree* friend_List;
    GroupRBTree* LeaderOf;
    GroupRBTree* MemberOf; // New field for groups the user is a member of
};

// Group structure
struct Group {
    std::string nome;
    UserRBTree* partecipanti;
};

// Red-Black Tree Node for Groups
struct GroupRBTreeNode {
    Group data;
    GroupRBTreeNode* parent;
    GroupRBTreeNode* left;
    GroupRBTreeNode* right;
    bool color; // 1 -> Red, 0 -> Black
};

// Red-Black Tree for Groups
struct GroupRBTree {
    GroupRBTreeNode* root;
    GroupRBTreeNode* TNULL;
};

// Red-Black Tree Node for Users
struct UserRBTreeNode {
    User data;
    UserRBTreeNode* parent;
    UserRBTreeNode* left;
    UserRBTreeNode* right;
    bool color; // 1 -> Red, 0 -> Black
};

// Red-Black Tree for Users
struct UserRBTree {
    UserRBTreeNode* root;
    UserRBTreeNode* TNULL;
};
void createEmptyGroup(GroupRBTree*& tree);
void createEmptyUser(UserRBTree*& tree);

void leftRotateGroup(GroupRBTree* tree, GroupRBTreeNode* x);
void rightRotateGroup(GroupRBTree* tree, GroupRBTreeNode* x);
void leftRotateUser(UserRBTree* tree, UserRBTreeNode* x);
void rightRotateUser(UserRBTree* tree, UserRBTreeNode* x);

void insertFixGroup(GroupRBTree* tree, GroupRBTreeNode* k);
void insertFixUser(UserRBTree* tree, UserRBTreeNode* k);

void insertGroup(GroupRBTree* tree, Group key);
void insertUser(UserRBTree* tree, User key);

GroupRBTreeNode* searchTreeHelperGroup(GroupRBTreeNode* node, GroupRBTreeNode* TNULL, std::string key);
UserRBTreeNode* searchTreeHelperUser(UserRBTreeNode* node, UserRBTreeNode* TNULL, std::string key);

GroupRBTreeNode* searchGroup(GroupRBTree* tree, std::string k);
UserRBTreeNode* searchUser(UserRBTree* tree, std::string k);


void inorderHelperUser(UserRBTreeNode* node, UserRBTreeNode* TNULL);
void inorderHelperGroup(GroupRBTreeNode* node, GroupRBTreeNode* TNULL);

void inorderUser(UserRBTree* tree);
void inorderGroup(GroupRBTree* tree);

void rbTransplantGroup(GroupRBTree* tree, GroupRBTreeNode* u, GroupRBTreeNode* v);
void deleteFixGroup(GroupRBTree* tree, GroupRBTreeNode* x);

GroupRBTreeNode* minimum(GroupRBTree* tree, GroupRBTreeNode* node);

void rbTransplantUser(UserRBTree* tree, UserRBTreeNode* u, UserRBTreeNode* v);
void deleteFixUser(UserRBTree* tree, UserRBTreeNode* x);

void deleteUser(UserRBTree* tree, std::string key);
void deleteGroup(GroupRBTree* tree, std::string key);

void clearUserTree(UserRBTree* tree);
void clearGroupTree(GroupRBTree* tree);

UserRBTreeNode* minimum(UserRBTree*, UserRBTreeNode*);
void clearGroupTree(UserRBTree*);

void member(UserRBTreeNode* tree, list::List& list);
void groups(GroupRBTreeNode* tree, list::List& list);


void printUserTree(UserRBTree* tree);
} // namespace tree

#endif // TREE_H

