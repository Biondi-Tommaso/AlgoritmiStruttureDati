// TO DO, vedi indicazioni in network.h
#include "RB-tree.h"
#include "dict.h"
#include "network.h"

#include <iostream> //Da rimuovere

namespace network{

	struct st_Network{
	/*	tree::NodeP UserList[26] = {emptyNode};
		tree::NodeP GroupList[26] = {emptyNode};
		*/
		
	};
		
		
		
		
/* FUNZIONI AUSILIARIE /////////////////////////////////////////////////////////////////////////////*/	
//restituisce True se la stringa è composta solo da caratteri alfabetici	
  bool areAlfabetic(string s){

  /*	for (unsigned int i = 0; i < s.size(); ++i){
  		if(s[i]<'a' || s[i] > 'z'){
  			return 0;
  		}
  	}
  	return 1;*/
  }
		
	
// Ritorna una network vuota
  Network createEmptyNetwork(){
  /*	Network net = new st_Network;
  	return net;
  */
  }

  // Ritorna true se la network net e' vuota, false altrimenti
  bool isEmpty(const Network& net){
  /*
  	if(net == emptyNetwork)
  		return true;
  	return net -> UserList == NULL;*/
  }


  
  
  // Aggiunge un membro alla network net con user_Login = usr_Log
  // Se usr_Log e' gia presente ritorna false
  // Se usr_Log e' uguale a "" ritorno false
  // Se usr_Log non contiene solo caratteri alfabetici, ritorna false
  // Altrimenti ritorna true
  bool addMember(string usr_Log, Network &net){
 	if(usr_Log == "") return 0;
 	if(!areAlfabetic(usr_Log)) return 0;
 	if(dict::isUser(net -> UserList, usr_Log)) return 0;
 	
 	dict::insert(net -> UserList, usr_Log);
 	
  	
  return 1;
  }

  // Rende amici nella network net i membri con user_Login usr_Log1 e usr_Log2
  // Se usr_Log1 o usr_Log2 (o entrambi) non sono presenti in net, ritorna false
  // Se usr_Log1 e' uguale a usr_Log2, ritorna false
  // Altrimenti ritorna true (anche se sono gia amici)
  bool becomeFriends(string usr_Log1, string usr_Log2, Network &net){
  /* typedef User elem;
  	if(usr_Log1 == usr_Log2) return 0;
  	if(!dict::isUser(net -> UserList, usr_Log1) || !dict::isUser(net -> UserList, usr_Log2)) return 0;
  	
  	if(areFriends(usr_Log1, usr_Log2, net)) return true;
  	
  	tree::NodeP node1 = dict::getNode(net -> UserList, usr_Log1);
  	dict::insert(node1 -> user.FriendsList, usr_Log2);
  	
  	tree::NodeP node2 = dict::getNode(net -> UserList, usr_Log2);
  	dict::insert(node2 -> user.FriendsList, usr_Log1);
  return 1;*/
  }

  // Ritorna true se i membri con user_Login usr_Log1 e usr_Log2 nella network sono amici
  //   (chiaramente devono anche gia' essere presenti entrambi in net)
  // Altrimenti ritorna false
  bool areFriends(string usr_Log1, string usr_Log2, const Network &net){
 /* typedef User elem;
  	if(usr_Log1 == usr_Log2) return 0;
  	if(!dict::isUser(net -> UserList, usr_Log1) || !dict::isUser(net -> UserList, usr_Log2)) return 0;
  	
  	tree::NodeP node1 = dict::getNode(net -> UserList, usr_Log1);
  	
  return dict::isUser(node1 -> user.FriendsList, usr_Log2);
  }

  // Aggiunge un nuovo gruppo di group_Name g_Name alla network net
  // Questo gruppo ha un unico creatore che e il membro con user_Login usr_Log
  // Tutti gli amici del creatore al momento della creazione diventano membri del gruppo
  // Se non c'e' un membro in net con user_Login usr_Log, ritorna false
  // Se g_Name esiste gia', ritorna false
  // Altrimenti ritorna true
  bool createGroup(string usr_Log, string g_Name, Network &net){
  
  //creo il gruppo e lo inserisco dentro la network
  
  dict::insert(net -> GroupList, g_Name);
  
  //accedo al gruppo appena createo
 
  return 1;
  }

  // Il membro con user_Login usr_Log, diventa membro del gruppo con group_Name = g_Name
  // Ritorna true se c'e' un membro usr_Log e un gruppo g_Name
  // Altrimenti ritorna false
  bool joinGroup(string usr_Log, string g_Name, Network &net){
  
  
  return 1;*/
  }
  
  // Cancella il membro con user_Login = usr_Log dal network net
  // Cancella anche tutti i gruppi di cui questo membro e' il creatore
  // Ritorna true se tale membro esiste
  // Altrimenti ritorna false
  bool deleteMember(string usr_Log, Network &net){
  
  return 1;
  }

  // Cancella il gruppo con group_Name = g_Name dal network net
  // Ritorna true se un tale gruppo esiste
  // Altrimenti ritorna false
  bool deleteGroup(string g_Name, Network &net){
  
  return 1;
  }

  // Cancella l'amicizia fra il membro usr_Log1 e il membro usr_Log2
  // Se non ci sono i membri usr_Log1 o usr_Log2, ritorna false
  // Se usr_Log1 e' uguale a usr_Log2, ritorna false
  // Altrimenti ritorna true (anche se non sono amici)
  bool leaveFriendship(string usr_Log1, string usr_Log2, Network &net){
  
  return 1;
  }

  // Il membro con user_Login = usr_Log viene rimosso dal gruppo con group_Name = g_Name
  // Se il membro e' il creatore, il gruppo vienne cancellato
  // Se non c'e' in net un membro usr_Log o un gruppo g_Name ritorna false
  // Altrimenti ritorna true (anche se il membro usr_Log non e' membro del gruppo)
  bool leaveGroup(string usr_Log, string g_Name, Network &net){
  
  return 1;
  }
  


  // Ritorna la lista in ordine alfabetico dei user_Login dei membri del network
  list::List members(const Network &net){
  /*
  	list::List list = list::createEmpty();
	  for(int i = 0; i < 26; ++i){
	  	scorriAlbero(net -> UserList[i], list);
	  }
  
  
  
  return list;*/
  }

  // Ritorna la lista in ordine alfabetico dei group_Name dei gruppi del network
  list::List groups(const Network &net){
  
  list::List a;
  return a;
  }
  
  // Ritorna la lista dei user_Login degli amici del membro con user_Login = usr_Log
  //  in ordine alfabetico 
  // Se non c'e membro con user_Login = usr_Log ritorna la lista vuota
  list::List friends(string usr_Log, const Network &net){
  
  list::List a;
  return a;
  }

  // Ritorna la lista dei nomi dei gruppi di cui il membro usr_Log
  //   e' membro (in ordine alfabetico)
  // (NB: un membro e' anche membro di un gruppo di cui e' il creatore)
  // Se in net non c'e' membro usr_Log ritorna la lista vuota
  list::List memberOf(string usr_Log, const Network &net){
  
  list::List a;
  return a;
  }

  // Ritorna la lista dei nomi dei gruppi di cui il membro usr_Log
  //  e' creatore in ordine alfabetico 
  // Se non c'e' membro usr_Log ritorna la lista vuota
  list::List creatorOf(string usr_Log, const Network &net){
  
  list::List a;
  return a;
  }

  // Il membro usr_Log diventa amico con tutti i membri con i
  //   quali condivide un gruppo
  // Ritorna true se c'e un membro con user_Login = usr_Log
  // Altrimenti ritorna false
  bool makeMoreFriends(string usr_Log, Network &net){
  	
  return 1;
  }
  
  
  void test(){
  /*	Network net = createEmptyNetwork();
        dict::insert(net -> UserList,"prova");
  	//dict::print(net -> UserList);
  	addMember("a", net);
  	addMember("b", net);
  	addMember("c", net);
  	addMember("d", net);
  	addMember("e", net);
  	addMember("f", net);
  	addMember("g", net);
  	addMember("h", net);
  	addMember("i", net);
  	addMember("j", net);
  	addMember("k", net);
  	addMember("l", net);
  	addMember("m", net);
  	addMember("n", net);
  	addMember("o", net);
  	addMember("p", net);
  	addMember("q", net);
  	addMember("r", net);
  	addMember("s", net);
  	addMember("t", net);
  	addMember("u", net);
  	addMember("v", net);
  	addMember("w", net);
  	addMember("x", net);
  	addMember("y", net);
  	addMember("z", net);
  	addMember("zorro", net);
  	addMember("zuzzurellone", net);
  	
  	dict::print(net -> UserList);
  	
  	cout << "are friends a , b " << areFriends("a","b",net) << endl;;
  	cout << "make friend a , b " << becomeFriends("a","b",net) << endl;
  	cout << "are friends a , b " << areFriends("a","b",net) << endl;
  	
  	//std::cout << dict::isUser(nullptr,"a");
  	/*
  	
  	std::cout << dict::isUser(net -> UserList,"prova");
  	*/
  }
}

