// TO DO, vedi indicazioni in network.h
#include <iostream>

using namespace std;


#include "list-array.h"
#include <cstddef>
#include <string>   

#include "tree.h"











namespace network {
    struct st_Network{
		
		tree::GroupRBTree* GroupList[26];
		tree::UserRBTree* UserList[26];
		
	};
    typedef st_Network* Network;

    // Funzione hash per ottenere un indice a partire dalla prima lettera del nome (convertita in minuscolo)
    int hashFunction(const std::string& str) {
        return tolower(str[0]) - 'a';
    }

    bool isAlphabeticString(const std::string& str) {
        for (char c : str) {
            if (!isalpha(c)) {
                return false;
            }
        }
        return true;
    }
    
    
     Network createEmptyNetwork(){
  	Network net = new st_Network;
  	
  	for(int i = 0; i < 26; ++i){
  			net -> GroupList[i] = new tree::GroupRBTree;
  			net -> UserList[i] = new tree::UserRBTree;
			tree::createEmptyGroup(net -> GroupList[i]);
  			tree::createEmptyUser(net -> UserList[i]);
		}
	return net;
  }

    // Aggiunge un membro alla network net con user_Login = usr_Log
    bool addMember(string usr_Log, Network& net) {
        if (usr_Log.empty() || !isAlphabeticString(usr_Log)) return false;

        int index = hashFunction(usr_Log);
        if (tree::searchUser(net->UserList[index], usr_Log)->data.user_Log != tree::EmptyUser) {
            return false;
        }

        tree::User newUser;
        newUser.user_Log = usr_Log;
        newUser.friend_List = new tree::UserRBTree;
        tree::createEmptyUser(newUser.friend_List);
        newUser.LeaderOf = new tree::GroupRBTree;
        tree::createEmptyGroup(newUser.LeaderOf);

        tree::insertUser(net->UserList[index], newUser);
        return true;
    }

    // Rende amici nella network net i membri con user_Login usr_Log1 e usr_Log2
    bool becomeFriends(string usr_Log1, string usr_Log2, Network& net) {
    	std::cout << "usr1: "<<usr_Log1<<"usr2: "<<usr_Log2<<endl;
    
        if (usr_Log1 == usr_Log2) return false;
        if (usr_Log1 == tree::EmptyUser || usr_Log2 == tree::EmptyUser) return false;
        if ( !isAlphabeticString(usr_Log1) || !isAlphabeticString(usr_Log2)) return false;
	
        int index1 = hashFunction(usr_Log1);
        int index2 = hashFunction(usr_Log2);

        tree::UserRBTreeNode* userNode1 = tree::searchUser(net->UserList[index1], usr_Log1);
        tree::UserRBTreeNode* userNode2 = tree::searchUser(net->UserList[index2], usr_Log2);

        if (userNode1->data.user_Log == tree::EmptyUser || userNode2->data.user_Log == tree::EmptyUser) {
            return false;
        }

        tree::insertUser(userNode1->data.friend_List, userNode2->data);
        tree::insertUser(userNode2->data.friend_List, userNode1->data);
  
        return true;
    }

    // Ritorna true se i membri con user_Login usr_Log1 e usr_Log2 nella network sono amici
    bool areFriends(string usr_Log1, string usr_Log2, const Network& net) {
        if (usr_Log1 == usr_Log2) return false;
        if (usr_Log1 == tree::EmptyUser || usr_Log2 == tree::EmptyUser) return false;
        if ( !isAlphabeticString(usr_Log1) || !isAlphabeticString(usr_Log2)) return false;

        int index1 = hashFunction(usr_Log1);
        int index2 = hashFunction(usr_Log2);

        auto userNode1 = tree::searchUser(net->UserList[index1], usr_Log1);
        auto userNode2 = tree::searchUser(net->UserList[index2], usr_Log2);

        if (userNode1->data.user_Log == tree::EmptyUser || userNode2->data.user_Log == tree::EmptyUser) {
            return false;
        }

        return tree::searchUser(userNode1->data.friend_List, usr_Log2)->data.user_Log != tree::EmptyUser;
    }

    // Aggiunge un nuovo gruppo di group_Name g_Name alla network net
    bool createGroup(string usr_Log, string g_Name, Network& net) {
        if (usr_Log == tree::EmptyUser || g_Name == tree::EmptyGroup) return false;
        if ( !isAlphabeticString(usr_Log)) return false;
    
    
        int userIndex = hashFunction(usr_Log);
        int groupIndex = hashFunction(g_Name);

        auto userNode = tree::searchUser(net->UserList[userIndex], usr_Log);
        if (userNode->data.user_Log == tree::EmptyUser) return false;
        if (tree::searchGroup(net->GroupList[groupIndex], g_Name)->data.nome != tree::EmptyGroup) {
            return false;
        }

        tree::Group newGroup;
        newGroup.nome = g_Name;
        newGroup.partecipanti = new tree::UserRBTree;
        tree::createEmptyUser(newGroup.partecipanti);

        tree::insertGroup(net->GroupList[groupIndex], newGroup);
        tree::insertGroup(userNode->data.LeaderOf, newGroup);

        // Aggiungere tutti gli amici del creatore come membri del gruppo
        auto addFriendsToGroup = [&](tree::UserRBTreeNode* node, auto& addFriendsToGroup) -> void {
            if (node != userNode->data.friend_List->TNULL) {
                tree::insertUser(newGroup.partecipanti, node->data);
                addFriendsToGroup(node->left, addFriendsToGroup);
                addFriendsToGroup(node->right, addFriendsToGroup);
            }
        };

        addFriendsToGroup(userNode->data.friend_List->root, addFriendsToGroup);

        return true;
    }

    bool joinGroup(string usr_Log, string g_Name, Network &net) {
	    int userIndex = hashFunction(usr_Log);
	    int groupIndex = hashFunction(g_Name);

	    auto userNode = tree::searchUser(net -> UserList[userIndex], usr_Log);
	    auto groupNode = tree::searchGroup(net -> GroupList[groupIndex], g_Name);

	    if (userNode->data.user_Log == tree::EmptyUser || groupNode->data.nome == tree::EmptyGroup) {
		return false;
	    }

	    tree::insertUser(groupNode->data.partecipanti, userNode->data);

	    // Add the group to the user's LeaderOf tree
	    if (userNode->data.MemberOf == nullptr) {
		userNode->data.MemberOf = new tree::GroupRBTree;
		tree::createEmptyGroup(userNode->data.MemberOf);
	    }
	    tree::insertGroup(userNode->data.MemberOf, groupNode->data);

	    return true;
}

    
    
    
   
    
    

    // Cancella il membro con user_Login = usr_Log dal network net
    bool deleteMember(string usr_Log, Network& net) {
    	if(usr_Log == tree::EmptyUser) return false;
    	if(!isAlphabeticString(usr_Log)) return false;
      
        int userIndex = hashFunction(usr_Log);
        auto userNode = tree::searchUser(net->UserList[userIndex], usr_Log);

        if (userNode->data.user_Log == tree::EmptyUser) return false;

        // Rimuovere i gruppi creati dal membro
        auto removeGroups = [&](tree::GroupRBTreeNode* node, auto& removeGroups) -> void {
            if (node != userNode->data.LeaderOf->TNULL) {
                tree::deleteGroup(net->GroupList[hashFunction(node->data.nome)], node->data.nome);
                removeGroups(node->left, removeGroups);
                removeGroups(node->right, removeGroups);
            }
        };
        removeGroups(userNode->data.LeaderOf->root, removeGroups);

        // Rimuovere l'amicizia con gli amici
        
        bool leaveFriendship(string usr_Log1, string usr_Log2, Network& net);
        auto removeFriendship = [&](tree::UserRBTreeNode* node, auto& removeFriendship) -> void {
            if (node != userNode->data.friend_List->TNULL) {
                leaveFriendship(usr_Log, node->data.user_Log, net);
                removeFriendship(node->left, removeFriendship);
                removeFriendship(node->right, removeFriendship);
            }
        };
        removeFriendship(userNode->data.friend_List->root, removeFriendship);

        // Rimuovere l'utente dal network
        tree::deleteUser(net->UserList[userIndex], usr_Log);
        return true;
    }

    // Cancella il gruppo con group_Name = g_Name dal network net
    bool deleteGroup(string g_Name, Network& net) {
        int groupIndex = hashFunction(g_Name);
        auto groupNode = tree::searchGroup(net->GroupList[groupIndex], g_Name);

        if (groupNode->data.nome == tree::EmptyGroup) return false;

        // Rimuovere il gruppo dalla lista dei gruppi creati da ogni membro
        auto removeGroupFromUsers = [&](tree::UserRBTreeNode* node, auto& removeGroupFromUsers) -> void {
            if (node != groupNode->data.partecipanti->TNULL) {
                tree::deleteGroup(node->data.LeaderOf, g_Name);
                removeGroupFromUsers(node->left, removeGroupFromUsers);
                removeGroupFromUsers(node->right, removeGroupFromUsers);
            }
        };
        removeGroupFromUsers(groupNode->data.partecipanti->root, removeGroupFromUsers);

        // Rimuovere il gruppo dal network
        tree::deleteGroup(net->GroupList[groupIndex], g_Name);
        return true;
    }

    // Cancella l'amicizia fra il membro usr_Log1 e il membro usr_Log2
    bool leaveFriendship(string usr_Log1, string usr_Log2, Network& net) {
        if (usr_Log1 == usr_Log2) return false;

        int index1 = hashFunction(usr_Log1);
        int index2 = hashFunction(usr_Log2);

        auto userNode1 = tree::searchUser(net->UserList[index1], usr_Log1);
        auto userNode2 = tree::searchUser(net->UserList[index2], usr_Log2);

        if (userNode1->data.user_Log == tree::EmptyUser || userNode2->data.user_Log == tree::EmptyUser) {
            return false;
        }

        tree::deleteUser(userNode1->data.friend_List, usr_Log2);
        tree::deleteUser(userNode2->data.friend_List, usr_Log1);
        return true;
    }

    // Un membro usr_Log esce dal gruppo con group_Name = g_Name
    bool leaveGroup(string usr_Log, string g_Name, Network& net) {
        int userIndex = hashFunction(usr_Log);
        int groupIndex = hashFunction(g_Name);

        auto userNode = tree::searchUser(net->UserList[userIndex], usr_Log);
        auto groupNode = tree::searchGroup(net->GroupList[groupIndex], g_Name);

        if (userNode->data.user_Log == tree::EmptyUser || groupNode->data.nome == tree::EmptyGroup) {
            return false;
        }

        tree::deleteUser(groupNode->data.partecipanti, usr_Log);
        return true;
    }

    // Inizializza una network vuota
    void createEmpty(Network& net) {
        net = new st_Network;
        for (int i = 0; i < 26; ++i) {
            net->UserList[i] = new tree::UserRBTree;
            tree::createEmptyUser(net->UserList[i]);
            net->GroupList[i] = new tree::GroupRBTree;
            tree::createEmptyGroup(net->GroupList[i]);
        }
    }

    // Ritorna true se la network è vuota
    bool isEmpty(const Network& net) {
        for (int i = 0; i < 26; ++i) {
            if (net->UserList[i]->root != net->UserList[i]->TNULL) {
                return false;
            }
            if (net->GroupList[i]->root != net->GroupList[i]->TNULL) {
                return false;
            }
        }
        return true;
    }

    // Dealloca la memoria usata dalla network
    void clear(Network& net) {
        for (int i = 0; i < 26; ++i) {
            tree::clearUserTree(net->UserList[i]);
            tree::clearGroupTree(net->GroupList[i]);
            delete net->UserList[i];
            delete net->GroupList[i];
        }
        delete net;
    }
    
    
    list::List groups(const Network &net){ 
	    list::List list = list::createEmpty();
			  for (int i = 0; i < 26; ++i){
			  	tree::groups(net -> GroupList[i] -> root, list);
			  }
			  return list;
		  }
		
    
    
    
  
  // Ritorna la lista dei user_Login degli amici del membro con user_Login = usr_Log
  //  in ordine alfabetico 
  // Se non c'e membro con user_Login = usr_Log ritorna la lista vuota
  

  // Ritorna la lista dei nomi dei gruppi di cui il membro usr_Log
  //   e' membro (in ordine alfabetico)
  // (NB: un membro e' anche membro di un gruppo di cui e' il creatore)
  // Se in net non c'e' membro usr_Log ritorna la lista vuota

  // Ritorna la lista dei nomi dei gruppi di cui il membro usr_Log
  //  e' creatore in ordine alfabetico 
  // Se non c'e' membro usr_Log ritorna la lista vuota
  list::List creatorOf(string usr_Log, const Network &net){
   	int index = hashFunction(usr_Log);
    	tree::UserRBTreeNode* User = tree::searchUser(net->UserList[index], usr_Log);
  	list::List list = list::createEmpty();
	tree::groups(User -> data.LeaderOf -> root, list);  
	return list;
   }



    
  list::List members(const Network &net){
  
	  list::List list = list::createEmpty();
		  for (int i = 0; i < 26; ++i){
		  	tree::member(net -> UserList[i] -> root, list);
		  }
		  return list;
	  }
	  
 // Ritorna la lista dei nomi dei gruppi di cui il membro usr_Log è membro (in ordine alfabetico)
// Se in net non c'è membro usr_Log ritorna la lista vuota
list::List memberOf(string usr_Log, const Network &net) {
    int index = hashFunction(usr_Log);
    tree::UserRBTreeNode* userNode = tree::searchUser(net->UserList[index], usr_Log);
    list::List list = list::createEmpty();

    if (userNode->data.user_Log == tree::EmptyUser) return list;

    tree::groups(userNode->data.MemberOf->root, list); // Naviga l'albero MemberOf dell'utente e aggiungi i nomi dei gruppi alla lista
    return list;
}

// Ritorna la lista dei user_Login degli amici del membro con user_Login = usr_Log in ordine alfabetico
// Se non c'è membro con user_Login = usr_Log ritorna la lista vuota
list::List friends(string usr_Log, const Network &net) {
    int index = hashFunction(usr_Log);
    tree::UserRBTreeNode* userNode = tree::searchUser(net->UserList[index], usr_Log);
    list::List list = list::createEmpty();

    if (userNode->data.user_Log == tree::EmptyUser) return list;
    tree::member(userNode->data.friend_List->root, list); // Naviga l'albero friend_List dell'utente e aggiungi i nomi degli amici alla lista
    return list;
}


  // Il membro usr_Log diventa amico con tutti i membri con i
  //   quali condivide un gruppo
  // Ritorna true se c'e un membro con user_Login = usr_Log
  // Altrimenti ritorna false
  // Il membro usr_Log diventa amico con tutti i membri con i
//   quali condivide un gruppo
// Ritorna true se c'e un membro con user_Login = usr_Log
// Altrimenti ritorna false
bool makeMoreFriends(string usr_Log, Network &net) {

    //verififo se l'utente sia valido
    if (!isAlphabeticString(usr_Log)) return false;
    if(usr_Log == "") return false;
    
    //ottengo l'utente
    int userIndex = hashFunction(usr_Log);
    tree::UserRBTreeNode* userNode = tree::searchUser(net->UserList[userIndex], usr_Log);
    //se l'utente non esiste ritorno false
    if (userNode->data.user_Log == tree::EmptyUser) {
        return false;
        
        
    list::List  membro = memberOf(usr_Log, net);
    list::List  leader = creatorOf(usr_Log, net);
    
    for(int i = 0; i < list::size(membro); ++i){
    	list::Elem nome = get(i,membro);
    	if(nome != tree::EmptyGroup){
    	int groupIndex = hashFunction(nome);
    	tree::GroupRBTreeNode* gruppo = tree::searchGroup(net->GroupList[groupIndex], nome);
    		if(gruppo -> data.nome != tree::EmptyGroup){
    			//ottengo la lista di tutti i partecipanti al gruppo
    			list::List partecipanti = list::createEmpty();
    			tree::groups(gruppo, partecipanti);
    			
    			//per ogni partecipante
    			for(int j = 0; j < list::size(partecipanti); ++j){
    				list::Elem analizzo = list::get(j,partecipanti);
    				if(! areFriends(analizzo,usr_Log, net)){
    					becomeFriends(analizzo,usr_Log, net);
    				}
    			
    			}
    		}
    	
    	}
    }
    
    
    
    
    for(int i = 0; i < list::size(leader); ++i){
    	list::Elem nome = get(i,leader);
    	if(nome != tree::EmptyGroup){
    	int groupIndex = hashFunction(nome);
    	tree::GroupRBTreeNode* gruppo = tree::searchGroup(net->GroupList[groupIndex], nome);
    		if(gruppo -> data.nome != tree::EmptyGroup){
    			//ottengo la lista di tutti i partecipanti al gruppo
    			list::List partecipanti = list::createEmpty();
    			tree::groups(gruppo, partecipanti);
    			
    			//per ogni partecipante
    			for(int j = 0; j < list::size(partecipanti); ++j){
    				list::Elem analizzo = list::get(j,partecipanti);
    				if(! areFriends(analizzo,usr_Log, net)){
    					becomeFriends(analizzo,usr_Log, net);
    				}
    			
    			}
    		}
    	
    	}
    	return true;
    }
    
    
    
    
    
    
    
    
    
        
    }
return 0;

}



void print (Network n){
	for ( int i = 0; i < 26; ++i)
	  	tree::printUserTree(n -> UserList[i]);
}
	}
