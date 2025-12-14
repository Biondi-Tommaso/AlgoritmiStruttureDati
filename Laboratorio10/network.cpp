#include <string>
#include "list-array.h"
#include "dictionary.h"
using namespace list;

namespace network{

  	const int bucketDim = 52;
 
  struct st_Network{
  	dict::Dictionary UserList[bucketDim];
  	dict::Dictionary GroupList[bucketDim];
  
  };

  typedef st_Network* Network;
	const Network emptyNetwork = nullptr;

  /**********************************************************************/
  /*               Funzione da implementare                             */
  /**********************************************************************/
  
  // NB: - ogni membro (utente del social network) e' contraddistinto univocamente
  //           da un user_Login rappresentato con una stringa
  //     - ogni gruppo (gruppo di utenti del social network) e' contraddistinto 
  //           univocamente da un group_Name rappresentato con una stringa
  
  //Funzioni ausiliari
  //ritorna l'indirizzo per la hash table
  int hashFunction(const std::string& str) {
  	if(str[0] >= 'a' && str[0] <='z')
  		return str[0] - 'a';
  	if(str[0] >= 'A' && str[0] <='Z')
  		return str[0] - 'A';
       return -1;
    }

  //ritorna true se la stringa è composta solo da caratteri alfabetici	
  bool isAlphabeticString(const std::string& str) {
    for (char c : str) {
        if (!isalpha(c) || isspace(c)) {
            return false;
        }
    }
    return true;
}

    

 //funzioni da implementare
  
  
  // Ritorna una network vuota
  Network createEmptyNetwork(){
  	return emptyNetwork;
  }

  // Ritorna true se la network net e' vuota, false altrimenti
  bool isEmpty(const Network& net){
 		return net == emptyNetwork;	 
  }

  // Aggiunge un membro alla network net con user_Login = usr_Log
  // Se usr_Log e' gia presente ritorna false
  // Se usr_Log e' uguale a "" ritorno false
  // Se usr_Log non contiene solo caratteri alfabetici, ritorna false
  // Altrimenti ritorna true
 bool addMember(string usr_Log, Network &net) {
    // If the network is empty, initialize it
    if (isEmpty(net)) {
        net = new st_Network;
        for (int i = 0; i < bucketDim; ++i) {
            net->UserList[i] = dict::createEmptyDict();
            net->GroupList[i] = dict::createEmptyDict();
        }
    }
    
    
    if (usr_Log.empty() || !isAlphabeticString(usr_Log)) 
    	return false;
    
    
    int index = hashFunction(usr_Log);
    if (index < 0 || index >= bucketDim) 
    	return false;
    
    
    if (dict::search(usr_Log, net->UserList[index]) != dict::emptyDictionary) 
    	return false;
  
    dict::insertElem(usr_Log,  net->UserList[index]);
    return true;
}

  

  // Rende amici nella network net i membri con user_Login usr_Log1 e usr_Log2
  // Se usr_Log1 o usr_Log2 (o entrambi) non sono presenti in net, ritorna false
  // Se usr_Log1 e' uguale a usr_Log2, ritorna false
  // Altrimenti ritorna true (anche se sono gia amici)
  bool becomeFriends(string usr_Log1, string usr_Log2, Network &net) {  
    if (usr_Log1 == usr_Log2) return false;
    
    dict::Dictionary usr1 = dict::search(usr_Log1, net->UserList[hashFunction(usr_Log1)]);
    dict::Dictionary usr2 = dict::search(usr_Log2, net->UserList[hashFunction(usr_Log2)]);
    
    
    if (usr1 != dict::emptyDictionary && usr2 != dict::emptyDictionary) {
        if (dict::search(usr_Log2, usr1->elem.tree) != dict::emptyDictionary) 
        	return true;
     
        dict::insertElem(usr_Log2,  usr1->elem.tree);
        dict::insertElem(usr_Log1,  usr2->elem.tree);
        return true;
    }
    
    
    return false;
}



  // Ritorna true se i membri con user_Login usr_Log1 e usr_Log2 nella network sono amici
  //   (chiaramente devono anche gia' essere presenti entrambi in net)
  // Altrimenti ritorna false
  bool areFriends(string usr_Log1, string usr_Log2, const Network &net) {
    dict::Dictionary usr1 = dict::search(usr_Log1, net->UserList[hashFunction(usr_Log1)]);
    dict::Dictionary usr2 = dict::search(usr_Log2, net->UserList[hashFunction(usr_Log2)]);
    //Se esistono due utenti con usr_Log rispettivament eusr_Log1 e usr_Log2 verifico se sono amici
    if (usr1 != dict::emptyDictionary && usr2 != dict::emptyDictionary) {
        return dict::search(usr_Log2, usr1->elem.tree) != dict::emptyDictionary;
    }//altrimenti restituisco false
    return false;
}

  
  //funzione ausiliaria di createGroup per far si che tutti gli amici del creatore del gruppo partecipino al gruppo
  void friendsJoinGroup(dict::Dictionary &amici, dict::Dictionary &d, string g, Network &n) {
    if (dict::isEmpty(amici)) return;
    friendsJoinGroup(amici->ch1, d, g, n);
    dict::insertElem(amici->elem.name, d);
    dict::insertElem(g,  dict::search(amici->elem.name, n->UserList[hashFunction(amici->elem.name)])->elem.memberOf);
    friendsJoinGroup(amici->ch2, d, g, n);
}

  
  
  

  // Aggiunge un nuovo gruppo di group_Name g_Name alla network net
  // Questo gruppo ha un unico creatore che e il membro con user_Login usr_Log
  // Tutti gli amici del creatore al momento della creazione diventano membri del gruppo
  // Se non c'e' un membro in net con user_Login usr_Log, ritorna false
  // Se g_Name esiste gia', ritorna false
  // Altrimenti ritorna true
  bool createGroup(string usr_Log, string g_Name, Network &net){
  	//se il network è vuoto lo inizializzo
  	if(isEmpty(net)){
  		net = new st_Network;
  		for(int i = 0; i < bucketDim; ++i){
  			net -> UserList[i] = dict::createEmptyDict();
  			net -> GroupList[i] = dict::createEmptyDict();	
  		}
  	}
  	//se il nome del gruppo non è valido ritorno false
  	if (g_Name.empty() || !isAlphabeticString(g_Name)) return false;
  	
  	//altrimenti verifico se sia già resente un utente con nome = usr_Log e un gruppo con nome = a g_Name
  	if(dict::search(usr_Log, net -> UserList[hashFunction(usr_Log)]) != dict::emptyDictionary){
  		if(dict::search(g_Name, net -> GroupList[hashFunction(g_Name)]) == dict::emptyDictionary){
  			print(net -> GroupList[hashFunction(g_Name)]);
  			cout << g_Name;
  			 //Creo il gruppo
  			 dict::insertElem(g_Name, net -> GroupList[hashFunction(g_Name)]);
  			 //inserisco l'utente usr_Log nel gruppo
  			 dict::insertElem(usr_Log, dict::search(g_Name, net -> GroupList[hashFunction(g_Name)])->elem.tree);
  			 //inserisco il gruppo nell'elenco di gruppi di cui usr_Log è leader
  			 dict::insertElem(g_Name, dict::search(usr_Log, net -> UserList[hashFunction(usr_Log)])->elem.leaderOf);
  			 //inserisco il gruppo nell'elenco di gruppi di cui usr_Log è membro
  			 dict::insertElem(g_Name, dict::search(usr_Log, net -> UserList[hashFunction(usr_Log)])->elem.memberOf);
  			 //inserisco ricorsivamente tutti gli amici di usr_Log in gruppo
  			 friendsJoinGroup(dict::search(usr_Log, net -> UserList[hashFunction(usr_Log)])->elem.tree,  dict::search(g_Name, net -> GroupList[hashFunction(g_Name)])->elem.tree, g_Name, net);
  			return true;
  		}
  	}
  	return false;
  	
  	
  }

  // Il membro con user_Login usr_Log, diventa membro del gruppo con group_Name = g_Name
  // Ritorna true se c'e' un membro usr_Log e un gruppo g_Name
  // Altrimenti ritorna false
bool joinGroup(string usr_Log, string g_Name, Network &net) {
    if (isEmpty(net)) return false;

    // verifico se usr_Log e g_Name esistono
    dict::Dictionary userDict = dict::search(usr_Log, net->UserList[hashFunction(usr_Log)]);
    dict::Dictionary groupDict = dict::search(g_Name, net->GroupList[hashFunction(g_Name)]);
    
    if (userDict == dict::emptyDictionary || groupDict == dict::emptyDictionary) return false;

    // controllo se user_Log è gia presente nel gruppo
    if (dict::search(usr_Log, groupDict->elem.tree) != dict::emptyDictionary) return true;

    // aggiungo il membro al gruppo
    dict::insertElem(usr_Log, groupDict->elem.tree);
    
    // aggiungo il gruppo alla lista di gruppi di cui l'utente fa parte
    dict::insertElem(g_Name, userDict->elem.memberOf);
    
    return true;
}



  // Cancella il gruppo con group_Name = g_Name dal network net
  // Ritorna true se un tale gruppo esiste
  // Altrimenti ritorna false
  void recursiveLeaveGroup(dict::Dictionary d, Network &net, string g_Name) {
    if (dict::isEmpty(d)) return;
    
   
    recursiveLeaveGroup(d->ch1, net, g_Name);
    recursiveLeaveGroup(d->ch2, net, g_Name);

    dict::Dictionary userDict = dict::search(d->elem.name, net->UserList[hashFunction(d->elem.name)]);
    if (userDict != dict::emptyDictionary) {
        dict::deleteElem(g_Name, userDict->elem.memberOf);
    }

    dict::Dictionary groupDict = dict::search(g_Name, net->GroupList[hashFunction(g_Name)]);
    if (groupDict != dict::emptyDictionary) {
        dict::deleteElem(d->elem.name, groupDict->elem.tree);
    }
}

  
  // Cancella il gruppo con group_Name = g_Name dal network net
  // Ritorna true se un tale gruppo esiste
  // Altrimenti ritorna false
  bool deleteGroup(string g_Name, Network &net) {
    if (isEmpty(net)) return false;

    dict::Dictionary groupDict = dict::search(g_Name, net->GroupList[hashFunction(g_Name)]);
    if (groupDict == dict::emptyDictionary) return false;

		string user = dict::search(g_Name, net->GroupList[hashFunction(g_Name)])->elem.tree -> elem.name; 
		dict::deleteElem(g_Name, dict::search(user, net->UserList[hashFunction(user)])->elem.leaderOf);
    
    recursiveLeaveGroup(groupDict->elem.tree, net, g_Name);
    dict::deleteElem(g_Name, net->GroupList[hashFunction(g_Name)]);
		
    return true;
}


  // Cancella l'amicizia fra il membro usr_Log1 e il membro usr_Log2
  // Se non ci sono i membri usr_Log1 o usr_Log2, ritorna false
  // Se usr_Log1 e' uguale a usr_Log2, ritorna false
  // Altrimenti ritorna true (anche se non sono amici)
  bool leaveFriendship(string usr_Log1, string usr_Log2, Network &net) {
    if (isEmpty(net)) return false;
    if (usr_Log1 == usr_Log2) return false;
    dict::Dictionary usr1 = dict::search(usr_Log1, net->UserList[hashFunction(usr_Log1)]);
    dict::Dictionary usr2 = dict::search(usr_Log2, net->UserList[hashFunction(usr_Log2)]);
    if (usr1 == dict::emptyDictionary || usr2 == dict::emptyDictionary) return false;
    dict::deleteElem(usr_Log1, usr2->elem.tree);
    dict::deleteElem(usr_Log2, usr1->elem.tree);
    return true;
}



	//funzinoe ausiliaria che scorre un albero e inserisce tutti i nodi in una lista
	void insertFromTree(list::List& l, dict::Dictionary d){
	 	if(dict::isEmpty(d)) return;
  	insertFromTree(l, d -> ch1);
  	list::addBack(d->elem.name, l);
  	insertFromTree(l, d -> ch2);
	
	}


  // Il membro con user_Login = usr_Log viene rimosso dal gruppo con group_Name = g_Name
  // Se il membro e' il creatore, il gruppo vienne cancellato
  // Se non c'e' in net un membro usr_Log o un gruppo g_Name ritorna false
  // Altrimenti ritorna true (anche se il membro usr_Log non e' membro del gruppo)

  bool leaveGroup(string usr_Log, string g_Name, Network &net){
  
  
  
 	 if(dict::search(usr_Log, net -> UserList[hashFunction(usr_Log)]) == dict::emptyDictionary || dict::search( g_Name, net -> GroupList[hashFunction(g_Name)]) == dict::emptyDictionary)return false;
 	 
 	 //Se usr è il creatore del gruppo elimino il gruppo
 	 if(dict::search(g_Name, dict::search( usr_Log, net -> UserList[hashFunction(usr_Log)])->elem.leaderOf) != dict::emptyDictionary){
 	 	
 	 	deleteGroup(g_Name, net);
 	 }
 	 //altrimenti
 	 else{
 	 	dict::deleteElem( usr_Log, dict::search(g_Name, net -> GroupList[hashFunction(g_Name)])->elem.tree);
 	  dict::deleteElem( g_Name, dict::search(usr_Log, net -> UserList[hashFunction(usr_Log)])->elem.memberOf);
 	 }
  
  
  
  	return true;
  }

	  
  // Cancella il membro con user_Login = usr_Log dal network net
  // Cancella anche tutti i gruppi di cui questo membro e' il creatore
  // Ritorna true se tale membro esiste
  // Altrimenti ritorna false
  void deleteMembersAux(Network& n, dict::Dictionary& d){
  	if(dict::isEmpty(d)) return;
  	deleteMembersAux(n, d -> ch1);
  	deleteMembersAux(n, d -> ch2);
  	deleteGroup(d->elem.name, n);
	
  }
  
  void deleteMembersAuxFriends(string usr_Log1, Network& n, dict::Dictionary& d){
  	if(dict::isEmpty(d)) return;
  	deleteMembersAuxFriends(usr_Log1, n, d -> ch1);
  	deleteMembersAuxFriends(usr_Log1, n, d -> ch2);
  	leaveFriendship(usr_Log1, d->elem.name,  n);
	
  }
  
  //elimina il membro da network
  bool deleteMember(string usr_Log, Network &net) {
    if (isEmpty(net)) return false;

    dict::Dictionary userDict = dict::search(usr_Log, net->UserList[hashFunction(usr_Log)]);
    if (userDict == dict::emptyDictionary) return false;

    // elimino tutti i gruppi di cui usr_Log è membro
    deleteMembersAux(net, userDict->elem.leaderOf);

    // alimina tutte le amicizie dell'utente
    deleteMembersAuxFriends(usr_Log, net, userDict->elem.tree);

    // Elimino l'utente da Network
    dict::deleteElem(usr_Log, net->UserList[hashFunction(usr_Log)]);
    
    return true;
}



  // Ritorna la lista in ordine alfabetico dei user_Login dei membri del network
  list::List members(const Network &net){
  	list::List l = list::createEmpty();
  	if(isEmpty(net)) return l;
  	for(int i = 0; i < bucketDim; ++i)
  		insertFromTree(l,net->UserList[i]);
  	return l;
  }

  // Ritorna la lista in ordine alfabetico dei group_Name dei gruppi del network
  list::List groups(const Network &net){
  	list::List l = list::createEmpty();
  	if(isEmpty(net)) return l;
  	for(int i = 0; i < bucketDim; ++i)
  		insertFromTree(l,net->GroupList[i]);
  	return l;
  }
  
  // Ritorna la lista dei user_Login degli amici del membro con user_Login = usr_Log
  //  in ordine alfabetico 
  // Se non c'e membro con user_Login = usr_Log ritorna la lista vuota
  // Ritorna la lista dei user_Login degli amici del membro con user_Login = usr_Log
//  in ordine alfabetico 
// Se non c'e membro con user_Login = usr_Log ritorna la lista vuota
list::List friends(string usr_Log, const Network &net) {
    list::List l = list::createEmpty();
    
   
    if (isEmpty(net)) return l;
    
    // cerco l'utente nel network
    dict::Dictionary userDict = dict::search(usr_Log, net->UserList[hashFunction(usr_Log)]);
    
    // se non trovo l'utente ritorno emptyList
    if (userDict == dict::emptyDictionary) return l;
    
    // inserisco la lita negli amici
    insertFromTree(l, userDict->elem.tree);
    
    return l;
}


  // Ritorna la lista dei nomi dei gruppi di cui il membro usr_Log
  //   e' membro (in ordine alfabetico)
  // (NB: un membro e' anche membro di un gruppo di cui e' il creatore)
  // Se in net non c'e' membro usr_Log ritorna la lista vuota
  list::List memberOf(string usr_Log, const Network &net) {
    list::List l = list::createEmpty();
    if (isEmpty(net)) return l;

    dict::Dictionary userDict = dict::search(usr_Log, net->UserList[hashFunction(usr_Log)]);
    if (userDict == dict::emptyDictionary) return l;

    insertFromTree(l, userDict->elem.memberOf);
    
    return l;
}


  // Ritorna la lista dei nomi dei gruppi di cui il membro usr_Log
  //  e' creatore in ordine alfabetico 
  // Se non c'e' membro usr_Log ritorna la lista vuota
  list::List creatorOf(string usr_Log, const Network &net) {
    list::List l = list::createEmpty();
    if (isEmpty(net)) return l;

    dict::Dictionary userDict = dict::search(usr_Log, net->UserList[hashFunction(usr_Log)]);
    if (userDict == dict::emptyDictionary) return l;

    insertFromTree(l, userDict->elem.leaderOf);
    return l;
}






 
  //Funzione ausiliaria per rendere usr_Log amico di tutti gli utenti in un sottoalbero
  void makeFriendsWithSubTree(string usr_Log, Network &net, dict::Dictionary &subTree) {
    if (dict::isEmpty(subTree)) return;
    if (usr_Log != subTree->elem.name) {
      becomeFriends(usr_Log, subTree->elem.name, net);
    }
    makeFriendsWithSubTree(usr_Log, net, subTree->ch1);
    makeFriendsWithSubTree(usr_Log, net, subTree->ch2);
  }

  //Funzione ricorsiva che elabora tutti i gruppi associati ad un albero di gruppi
  void processGroups(string usr_Log, Network &net, dict::Dictionary &groupTree) {
    if (dict::isEmpty(groupTree)) return;
    dict::Dictionary group = dict::search(groupTree->elem.name, net->GroupList[hashFunction(groupTree->elem.name)]);
    if (group != dict::emptyDictionary) {
      makeFriendsWithSubTree(usr_Log, net, group->elem.tree);
    }
    processGroups(usr_Log, net, groupTree->ch1);
    processGroups(usr_Log, net, groupTree->ch2);
  }


  // Funzione che permette ad un utente di fare amicizia con i membri dei gruppi a cui appartiene.
  bool makeMoreFriends(string usr_Log, Network &net) {
    if (isEmpty(net)) return false;
    dict::Dictionary user = dict::search(usr_Log, net->UserList[hashFunction(usr_Log)]);
    if (user == dict::emptyDictionary) return false;
    processGroups(usr_Log, net, user->elem.memberOf);
    return true;
  }

}






