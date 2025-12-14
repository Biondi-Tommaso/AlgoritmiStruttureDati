#ifndef NETWORK_H
#define NETWORK_H

#include "list-array.h"
#include <cstddef>
#include <string>   

namespace network{
  struct st_Network;

  typedef st_Network* Network;

  const Network emptyNetwork = nullptr;

  /**********************************************************************/
  /*               Funzione da implementare                             */
  /**********************************************************************/
  
  // NB: - ogni membro (utente del social network) e' contraddistinto univocamente
  //           da un user_Login rappresentato con una stringa
  //     - ogni gruppo (gruppo di utenti del social network) e' contraddistinto 
  //           univocamente da un group_Name rappresentato con una stringa
  
  // Ritorna una network vuota
  Network createEmptyNetwork();

  // Ritorna true se la network net e' vuota, false altrimenti
  bool isEmpty(const Network& net);

  // Aggiunge un membro alla network net con user_Login = usr_Log
  // Se usr_Log e' gia presente ritorna false
  // Se usr_Log e' uguale a "" ritorno false
  // Se usr_Log non contiene solo caratteri alfabetici, ritorna false
  // Altrimenti ritorna true
  bool addMember(string usr_Log, Network &net);

  // Rende amici nella network net i membri con user_Login usr_Log1 e usr_Log2
  // Se usr_Log1 o usr_Log2 (o entrambi) non sono presenti in net, ritorna false
  // Se usr_Log1 e' uguale a usr_Log2, ritorna false
  // Altrimenti ritorna true (anche se sono gia amici)
  bool becomeFriends(string usr_Log1, string usr_Log2, Network &net);

  // Ritorna true se i membri con user_Login usr_Log1 e usr_Log2 nella network sono amici
  //   (chiaramente devono anche gia' essere presenti entrambi in net)
  // Altrimenti ritorna false
  bool areFriends(string usr_Log1, string usr_Log2, const Network &net);

  // Aggiunge un nuovo gruppo di group_Name g_Name alla network net
  // Questo gruppo ha un unico creatore che e il membro con user_Login usr_Log
  // Tutti gli amici del creatore al momento della creazione diventano membri del gruppo
  // Se non c'e' un membro in net con user_Login usr_Log, ritorna false
  // Se g_Name esiste gia', ritorna false
  // Altrimenti ritorna true
  bool createGroup(string usr_Log, string g_Name, Network &net);

  // Il membro con user_Login usr_Log, diventa membro del gruppo con group_Name = g_Name
  // Ritorna true se c'e' un membro usr_Log e un gruppo g_Name
  // Altrimenti ritorna false
  bool joinGroup(string usr_Log, string g_Name, Network &net);
  
  // Cancella il membro con user_Login = usr_Log dal network net
  // Cancella anche tutti i gruppi di cui questo membro e' il creatore
  // Ritorna true se tale membro esiste
  // Altrimenti ritorna false
  bool deleteMember(string usr_Log, Network &net);

  // Cancella il gruppo con group_Name = g_Name dal network net
  // Ritorna true se un tale gruppo esiste
  // Altrimenti ritorna false
  bool deleteGroup(string g_Name, Network &net);

  // Cancella l'amicizia fra il membro usr_Log1 e il membro usr_Log2
  // Se non ci sono i membri usr_Log1 o usr_Log2, ritorna false
  // Se usr_Log1 e' uguale a usr_Log2, ritorna false
  // Altrimenti ritorna true (anche se non sono amici)
  bool leaveFriendship(string usr_Log1, string usr_Log2, Network &net);

  // Il membro con user_Login = usr_Log viene rimosso dal gruppo con group_Name = g_Name
  // Se il membro e' il creatore, il gruppo vienne cancellato
  // Se non c'e' in net un membro usr_Log o un gruppo g_Name ritorna false
  // Altrimenti ritorna true (anche se il membro usr_Log non e' membro del gruppo)
  bool leaveGroup(string usr_Log, string g_Name, Network &net);

  // Ritorna la lista in ordine alfabetico dei user_Login dei membri del network
  list::List members(const Network &net);

  // Ritorna la lista in ordine alfabetico dei group_Name dei gruppi del network
  list::List groups(const Network &net);
  
  // Ritorna la lista dei user_Login degli amici del membro con user_Login = usr_Log
  //  in ordine alfabetico 
  // Se non c'e membro con user_Login = usr_Log ritorna la lista vuota
  list::List friends(string usr_Log, const Network &net);

  // Ritorna la lista dei nomi dei gruppi di cui il membro usr_Log
  //   e' membro (in ordine alfabetico)
  // (NB: un membro e' anche membro di un gruppo di cui e' il creatore)
  // Se in net non c'e' membro usr_Log ritorna la lista vuota
  list::List memberOf(string usr_Log, const Network &net);

  // Ritorna la lista dei nomi dei gruppi di cui il membro usr_Log
  //  e' creatore in ordine alfabetico 
  // Se non c'e' membro usr_Log ritorna la lista vuota
  list::List creatorOf(string usr_Log, const Network &net);

  // Il membro usr_Log diventa amico con tutti i membri con i
  //   quali condivide un gruppo
  // Ritorna true se c'e un membro con user_Login = usr_Log
  // Altrimenti ritorna false
  bool makeMoreFriends(string usr_Log, Network &net);
}

#endif
