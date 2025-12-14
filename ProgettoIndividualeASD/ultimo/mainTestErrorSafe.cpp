// Compilare con:
// g++ -Wall -std=c++11 *cpp

#include <iostream>
#include "network.h"
//Includi tutti gli include che preferisci e di cui vorresti aver bisogno

using namespace network;
using namespace list;
using namespace std;

int main () {
	Network N; 
	bool test = false;
	List L = createEmpty();
	string comp = "";
	unsigned int i = 0;
	unsigned int j = 0;
	
	
	cout<<"Creazione di una network:"<<endl;
	cout<<"-------------------------"<<endl;
	
	cout<<"Test 1 createEmptyNetwork:"<<endl;
	N = createEmptyNetwork();
	if(N==emptyNetwork) {
		cout<<"  Result: PASSED"<<endl;
		i++;
  	}else{
    		cout<<"  Result: FAILED"<<endl;
    		j++;
  	}
  	cout<<endl;
  	
  	cout<<"Test 2 isEmpty:"<<endl;
  	test=isEmpty(N);
  	if(test) {
  		cout<<"  Result: PASSED"<<endl;
		i++;
  	}else{
    		cout<<"  Result: FAILED"<<endl;
    		j++;
  	}
  	cout<<endl;
  	
  	cout<<"Test 3 AddMember:"<<endl;
  	test=addMember("Marco", N);
  	if(test) {
  		cout<<"  Result: PASSED"<<endl;
		i++;
  	}else{
    		cout<<"  Result: FAILED"<<endl;
    		j++;
  	}
  	cout<<endl;
  	
  	cout<<"Test 4 AddMember:"<<endl;
  	test=addMember("Fausto", N);
  	if(test) {
  		cout<<"  Result: PASSED"<<endl;
		i++;
  	}else{
    		cout<<"  Result: FAILED"<<endl;
    		j++;
  	}
  	cout<<endl;
  	
  	cout<<"Test 5 AddMember:"<<endl;
  	test=addMember("Quinto", N);
  	if(test) {
  		cout<<"  Result: PASSED"<<endl;
		i++;
  	}else{
    		cout<<"  Result: FAILED"<<endl;
    		j++;
  	}
  	cout<<endl;
  	
  	cout<<"Test 6 AddMember:"<<endl;
  	test=addMember("Fragola86", N);
  	if(!test) {
  		cout<<"  Result: PASSED"<<endl;
		i++;
  	}else{
    		cout<<"  Result: FAILED"<<endl;
    		j++;
  	}
  	cout<<endl;
  	
  	cout<<"Test 7 AddMember:"<<endl;
  	test=addMember("Quinto", N);
  	if(!test) {
  		cout<<"  Result: PASSED"<<endl;
		i++;
  	}else{
    		cout<<"  Result: FAILED"<<endl;
    		j++;
  	}
  	cout<<endl;
  	
  	cout<<"Test 8 AddMember:"<<endl;
  	test=addMember("Fulvio", N);
  	if(test) {
  		cout<<"  Result: PASSED"<<endl;
		i++;
  	}else{
    		cout<<"  Result: FAILED"<<endl;
    		j++;
  	}
  	cout<<endl;
  	
  	cout<<"Test 9 AddMember:"<<endl;
  	test=addMember("Romolo", N);
  	if(test) {
  		cout<<"  Result: PASSED"<<endl;
		i++;
  	}else{
    		cout<<"  Result: FAILED"<<endl;
    		j++;
  	}
  	cout<<endl;
  	
  	cout<<"Test 10 AddMember:"<<endl;
  	test=addMember("Paolo", N);
  	if(test) {
  		cout<<"  Result: PASSED"<<endl;
		i++;
  	}else{
    		cout<<"  Result: FAILED"<<endl;
    		j++;
  	}
  	cout<<endl;
  	
  	
  	cout<<"Inserimento di amicizie nella network:"<<endl;
  	cout<<"--------------------------------------"<<endl;
  	
  	cout<<"Test 1 AddMember:"<<endl;
  	test=addMember("Leonardo", N);
  	if(test) {
  		cout<<"  Result: PASSED"<<endl;
		i++;
  	}else{
    		cout<<"  Result: FAILED"<<endl;
    		j++;
  	}
  	cout<<endl;
  	
  	cout<<"Test 2 AddMember:"<<endl;
  	test=addMember("Michelangelo", N);
  	if(test) {
  		cout<<"  Result: PASSED"<<endl;
		i++;
  	}else{
    		cout<<"  Result: FAILED"<<endl;
    		j++;
  	}
  	cout<<endl;
  	
  	cout<<"Test 3 AddMember:"<<endl;
  	test=addMember("Decimo", N);
  	if(test) {
  		cout<<"  Result: PASSED"<<endl;
		i++;
  	}else{
    		cout<<"  Result: FAILED"<<endl;
    		j++;
  	}
  	cout<<endl;
  	
  	cout<<"Test 4 AddMember:"<<endl;
  	test=addMember("Lucianoé=<$", N);
  	if(!test) {
  		cout<<"  Result: PASSED"<<endl;
		i++;
  	}else{
    		cout<<"  Result: FAILED"<<endl;
    		j++;
  	}
  	cout<<endl;
  	
  	cout<<"Test 5 isEmpty:"<<endl;
  	test=isEmpty(N);
  	if(!test) {
  		cout<<"  Result: PASSED"<<endl;
		i++;
  	}else{
    		cout<<"  Result: FAILED"<<endl;
    		j++;
  	}
  	cout<<endl;
  	
  	cout<<"Test 6 AddMember:"<<endl;
  	test=addMember("Raffaello", N);
  	if(test) {
  		cout<<"  Result: PASSED"<<endl;
		i++;
  	}else{
    		cout<<"  Result: FAILED"<<endl;
    		j++;
  	}
  	cout<<endl;
  	
  	cout<<"Test 7 becomeFriends:"<<endl;
  	test=becomeFriends("Decimo", "", N);
  	if(!test) {
  		cout<<"  Result: PASSED"<<endl;
		i++;
  	}else{
    		cout<<"  Result: FAILED"<<endl;
    		j++;
  	}
  	cout<<endl;
  	
  	cout<<"Test 8 becomeFriends:"<<endl;
  	test=becomeFriends("Marco", "Fulvio", N);
  	if(test) {
  		cout<<"  Result: PASSED"<<endl;
		i++;
  	}else{
    		cout<<"  Result: FAILED"<<endl;
    		j++;
  	}
  	cout<<endl;
  	
  	cout<<"Test 9 becomeFriends:"<<endl;
  	test=becomeFriends("Quinto", "Decimo", N);
  	if(test) {
  		cout<<"  Result: PASSED"<<endl;
		i++;
  	}else{
    		cout<<"  Result: FAILED"<<endl;
    		j++;
  	}
  	cout<<endl;
  	
  	cout<<"Test 10 areFriends:"<<endl;
  	test=areFriends("Fulvio", "Marco", N);
  	if(test) {
  		cout<<"  Result: PASSED"<<endl;
		i++;
  	}else{
    		cout<<"  Result: FAILED"<<endl;
    		j++;
  	}
  	cout<<endl;

  	
  	cout<<"Evoluzione della network e ulteriori test sulle amicizie:"<<endl;
  	cout<<"---------------------------------------------------------"<<endl;
  	
  	cout<<"Test 1 AddMember:"<<endl;
  	test=addMember("Donatello", N);
  	if(test) {
  		cout<<"  Result: PASSED"<<endl;
		i++;
  	}else{
    		cout<<"  Result: FAILED"<<endl;
    		j++;
  	}
  	cout<<endl;
  	
  	cout<<"Test 2 AddMember:"<<endl;
  	test=addMember("Remo", N);
  	if(test) {
  		cout<<"  Result: PASSED"<<endl;
		i++;
  	}else{
    		cout<<"  Result: FAILED"<<endl;
    		j++;
  	}
  	cout<<endl;
  	
  	cout<<"Test 3 AddMember:"<<endl;
  	test=addMember("£4Reano", N);
  	if(!test) {
  		cout<<"  Result: PASSED"<<endl;
		i++;
  	}else{
    		cout<<"  Result: FAILED"<<endl;
    		j++;
  	}
  	cout<<endl;
  	
  	cout<<"Test 4 AddMember:"<<endl;
  	test=addMember("Massimo", N);
  	if(test) {
  		cout<<"  Result: PASSED"<<endl;
		i++;
  	}else{
    		cout<<"  Result: FAILED"<<endl;
    		j++;
  	}
  	cout<<endl;
  	
  	cout<<"Test 5 isEmpty:"<<endl;
  	test=isEmpty(N);
  	if(!test) {
  		cout<<"  Result: PASSED"<<endl;
		i++;
  	}else{
    		cout<<"  Result: FAILED"<<endl;
    		j++;
  	}
  	cout<<endl;
  	
  	cout<<"Test 6 becomeFriends:"<<endl;
  	test=becomeFriends("Raffaello", "Reano", N);
  	if(!test) {
  		cout<<"  Result: PASSED"<<endl;
		i++;
  	}else{
    		cout<<"  Result: FAILED"<<endl;
    		j++;
  	}
  	cout<<endl;
  	
  	cout<<"Test 7 becomeFriends:"<<endl;
  	test=becomeFriends("", "34Terwo", N);
  	if(!test) {
  		cout<<"  Result: PASSED"<<endl;
		i++;
  	}else{
    		cout<<"  Result: FAILED"<<endl;
    		j++;
  	}
  	cout<<endl;
  	
  	cout<<"Test 8 becomeFriends:"<<endl;
  	test=becomeFriends("Romolo", "Remo", N);
  	if(test) {
  		cout<<"  Result: PASSED"<<endl;
		i++;
  	}else{
    		cout<<"  Result: FAILED"<<endl;
    		j++;
  	}
  	cout<<endl;
  	
  	cout<<"Test 9 areFriends:"<<endl;
  	test=areFriends("Quinto", "Romolo", N);
  	if(!test) {
  		cout<<"  Result: PASSED"<<endl;
		i++;
  	}else{
    		cout<<"  Result: FAILED"<<endl;
    		j++;
  	}
  	cout<<endl;
  	
  	cout<<"Test 10 areFriends:"<<endl;
  	test=areFriends("34Reanio", "", N);
  	if(!test) {
  		cout<<"  Result: PASSED"<<endl;
		i++;
  	}else{
    		cout<<"  Result: FAILED"<<endl;
    		j++;
  	}
  	cout<<endl;

  	
  	cout<<"Creazione dei gruppi e evoluzione della network:"<<endl;
  	cout<<"------------------------------------------------"<<endl;
  	
  	cout<<"Test 1 createGroup:"<<endl;
  	test=createGroup("Romolo", "Antica Roma", N);
  	if(test) {
  		cout<<"  Result: PASSED"<<endl;
		i++;
  	}else{
    		cout<<"  Result: FAILED"<<endl;
    		j++;
  	}
  	cout<<endl;
  	
  	cout<<"Test 2 AddMember:"<<endl;
  	test=addMember("Luciano", N);
  	if(test) {
  		cout<<"  Result: PASSED"<<endl;
		i++;
  	}else{
    		cout<<"  Result: FAILED"<<endl;
    		j++;
  	}
  	cout<<endl;
  	
  	cout<<"Test 3 AddMember:"<<endl;
  	test=addMember("Aurelio", N);
  	if(test) {
  		cout<<"  Result: PASSED"<<endl;
		i++;
  	}else{
    		cout<<"  Result: FAILED"<<endl;
    		j++;
  	}
  	cout<<endl;
  	
  	cout<<"Test 4 AddMember:"<<endl;
  	test=addMember("ServioTullio", N);
  	if(test) {
  		cout<<"  Result: PASSED"<<endl;
		i++;
  	}else{
    		cout<<"  Result: FAILED"<<endl;
    		j++;
  	}
  	cout<<endl;
  	
  	cout<<"Test 5 createGroup:"<<endl;
  	test=createGroup("ServioTullio", "Antica Roma", N);
  	if(!test) {
  		cout<<"  Result: PASSED"<<endl;
		i++;
  	}else{
    		cout<<"  Result: FAILED"<<endl;
    		j++;
  	}
  	cout<<endl;
  	
  	cout<<"Test 6 becomeFriends:"<<endl;
  	test=becomeFriends("Raffaello", "Leonardo", N);
  	if(test) {
  		cout<<"  Result: PASSED"<<endl;
		i++;
  	}else{
    		cout<<"  Result: FAILED"<<endl;
    		j++;
  	}
  	cout<<endl;
  	
  	cout<<"Test 7 becomeFriends:"<<endl;
  	test=becomeFriends("Donatello", "Leonardo", N);
  	if(test) {
  		cout<<"  Result: PASSED"<<endl;
		i++;
  	}else{
    		cout<<"  Result: FAILED"<<endl;
    		j++;
  	}
  	cout<<endl;
  	
  	cout<<"Test 8 becomeFriends:"<<endl;
  	test=becomeFriends("Michelangelo", "Leonardo", N);
  	if(test) {
  		cout<<"  Result: PASSED"<<endl;
		i++;
  	}else{
    		cout<<"  Result: FAILED"<<endl;
    		j++;
  	}
  	cout<<endl;
  	
  	cout<<"Test 9 createGroup:"<<endl;
  	test=createGroup("Leonardo", "TartarugheNinja", N);
  	if(test) {
  		cout<<"  Result: PASSED"<<endl;
		i++;
  	}else{
    		cout<<"  Result: FAILED"<<endl;
    		j++;
  	}
  	cout<<endl;
  	
  	cout<<"Test 10 areFriends:"<<endl;
  	test=areFriends("Leonardo", "Raffaello", N);
  	if(test) {
  		cout<<"  Result: PASSED"<<endl;
		i++;
  	}else{
    		cout<<"  Result: FAILED"<<endl;
    		j++;
  	}
  	cout<<endl;

  	
  	cout<<"Evoluzione della network:"<<endl;
  	cout<<"-------------------------"<<endl;
  	
  	cout<<"Test 1 createGroup:"<<endl;
  	test=createGroup("Fausto", "Solo Fausto", N);
  	if(test) {
  		cout<<"  Result: PASSED"<<endl;
		i++;
  	}else{
    		cout<<"  Result: FAILED"<<endl;
    		j++;
  	}
  	cout<<endl;
  	
  	cout<<"Test 2 AddMember:"<<endl;
  	test=addMember("Cesare", N);
  	if(test) {
  		cout<<"  Result: PASSED"<<endl;
		i++;
  	}else{
    		cout<<"  Result: FAILED"<<endl;
    		j++;
  	}
  	cout<<endl;
  	
  	cout<<"Test 3 AddMember:"<<endl;
  	test=addMember("Caio", N);
  	if(test) {
  		cout<<"  Result: PASSED"<<endl;
		i++;
  	}else{
    		cout<<"  Result: FAILED"<<endl;
    		j++;
  	}
  	cout<<endl;
  	
  	cout<<"Test 4 AddMember:"<<endl;
  	test=addMember("Cleopatra", N);
  	if(test) {
  		cout<<"  Result: PASSED"<<endl;
		i++;
  	}else{
    		cout<<"  Result: FAILED"<<endl;
    		j++;
  	}
  	cout<<endl;
  	
  	cout<<"Test 5 createGroup:"<<endl;
  	test=createGroup("Aurelio", "", N);
  	if(!test) {
  		cout<<"  Result: PASSED"<<endl;
		i++;
  	}else{
    		cout<<"  Result: FAILED"<<endl;
    		j++;
  	}
  	cout<<endl;
  	
  	cout<<"Test 6 becomeFriends:"<<endl;
  	test=becomeFriends("Cesare", "Cleopatra", N);
  	if(test) {
  		cout<<"  Result: PASSED"<<endl;
		i++;
  	}else{
    		cout<<"  Result: FAILED"<<endl;
    		j++;
  	}
  	cout<<endl;
  	
  	cout<<"Test 7 becomeFriends:"<<endl;
  	test=becomeFriends("Quinto", "Cesare", N);
  	if(test) {
  		cout<<"  Result: PASSED"<<endl;
		i++;
  	}else{
    		cout<<"  Result: FAILED"<<endl;
    		j++;
  	}
  	cout<<endl;
  	
  	cout<<"Test 8 becomeFriends:"<<endl;
  	test=becomeFriends("Quinto", "Caio", N);
  	if(test) {
  		cout<<"  Result: PASSED"<<endl;
		i++;
  	}else{
    		cout<<"  Result: FAILED"<<endl;
    		j++;
  	}
  	cout<<endl;
  	
  	cout<<"Test 9 createGroup:"<<endl;
  	test=createGroup("Quinto", "Amici di Quinto", N);
  	if(test) {
  		cout<<"  Result: PASSED"<<endl;
		i++;
  	}else{
    		cout<<"  Result: FAILED"<<endl;
    		j++;
  	}
  	cout<<endl;
  	
  	cout<<"Test 10 areFriends:"<<endl;
  	test=areFriends("Quinto", "Michelangelo", N);
  	if(!test) {
  		cout<<"  Result: PASSED"<<endl;
		i++;
  	}else{
    		cout<<"  Result: FAILED"<<endl;
    		j++;
  	}
  	cout<<endl;

  	
  	cout<<"Aggiunte ai gruppi di nuovi membri:"<<endl;
  	cout<<"-----------------------------------"<<endl;
  	
  	cout<<"Test 1 createGroup:"<<endl;
  	test=createGroup("Romolo", "I Re di Roma", N);
  	if(test) {
  		cout<<"  Result: PASSED"<<endl;
		i++;
  	}else{
    		cout<<"  Result: FAILED"<<endl;
    		j++;
  	}
  	cout<<endl;
  	
  	cout<<"Test 2 AddMember:"<<endl;
  	test=addMember("Tiberio", N);
  	if(test) {
  		cout<<"  Result: PASSED"<<endl;
		i++;
  	}else{
    		cout<<"  Result: FAILED"<<endl;
    		j++;
  	}
  	cout<<endl;
  	
  	cout<<"Test 3 AddMember:"<<endl;
  	test=addMember("Caligola", N);
  	if(test) {
  		cout<<"  Result: PASSED"<<endl;
		i++;
  	}else{
    		cout<<"  Result: FAILED"<<endl;
    		j++;
  	}
  	cout<<endl;
  	
  	cout<<"Test 4 joinGroup:"<<endl;
  	test=joinGroup("ServioTullio", "I Re di Roma", N);
  	if(test) {
  		cout<<"  Result: PASSED"<<endl;
		i++;
  	}else{
    		cout<<"  Result: FAILED"<<endl;
    		j++;
  	}
  	cout<<endl;
  	
  	cout<<"Test 5 joinGroup:"<<endl;
  	test=joinGroup("Alejandro", "Tartarughe Ninja", N);
  	if(!test) {
  		cout<<"  Result: PASSED"<<endl;
		i++;
  	}else{
    		cout<<"  Result: FAILED"<<endl;
    		j++;
  	}
  	cout<<endl;
  	
  	cout<<"Test 6 AddMember:"<<endl;
  	test=addMember("NumaPompilio", N);
  	if(test) {
  		cout<<"  Result: PASSED"<<endl;
		i++;
  	}else{
    		cout<<"  Result: FAILED"<<endl;
    		j++;
  	}
  	cout<<endl;
  	
  	cout<<"Test 7 AddMember:"<<endl;
  	test=addMember("TulloOstilio", N);
  	if(test) {
  		cout<<"  Result: PASSED"<<endl;
		i++;
  	}else{
    		cout<<"  Result: FAILED"<<endl;
    		j++;
  	}
  	cout<<endl;
  	
  	cout<<"Test 8 joinGroup:"<<endl;
  	test=joinGroup("NumaPompilio", "I Re di Roma", N);
  	if(test) {
  		cout<<"  Result: PASSED"<<endl;
		i++;
  	}else{
    		cout<<"  Result: FAILED"<<endl;
    		j++;
  	}
  	cout<<endl;
  	
  	cout<<"Test 9 joinGroup:"<<endl;
  	test=joinGroup("TulloOstilio", "I Re di Roma", N);
  	if(test) {
  		cout<<"  Result: PASSED"<<endl;
		i++;
  	}else{
    		cout<<"  Result: FAILED"<<endl;
    		j++;
  	}
  	cout<<endl;
  	
  	cout<<"Test 10 joinGroup:"<<endl;
  	test=joinGroup("Fausto", "Solo Fausto", N);
  	if(test) {
  		cout<<"  Result: PASSED"<<endl;
		i++;
  	}else{
    		cout<<"  Result: FAILED"<<endl;
    		j++;
  	}
  	cout<<endl;

  	
  	cout<<"Aggiunta di membri ai gruppi e rimozione di amicizie:"<<endl;
  	cout<<"-----------------------------------------------------"<<endl;
  	
  	cout<<"Test 1 leaveFriendship:"<<endl;
  	test=leaveFriendship("Leonardo", "Remo", N);
  	if(test) {
  		cout<<"  Result: PASSED"<<endl;
		i++;
  	}else{
    		cout<<"  Result: FAILED"<<endl;
    		j++;
  	}
  	cout<<endl;
  	
  	cout<<"Test 2 AddMember:"<<endl;
  	test=addMember("AncoMarzio", N);
  	if(test) {
  		cout<<"  Result: PASSED"<<endl;
		i++;
  	}else{
    		cout<<"  Result: FAILED"<<endl;
    		j++;
  	}
  	cout<<endl;
  	
  	cout<<"Test 3 AddMember:"<<endl;
  	test=addMember("TarquinioPrisco", N);
  	if(test) {
  		cout<<"  Result: PASSED"<<endl;
		i++;
  	}else{
    		cout<<"  Result: FAILED"<<endl;
    		j++;
  	}
  	cout<<endl;
  	
  	cout<<"Test 4 AddMember:"<<endl;
  	test=addMember("TarquinioIlSuperbo", N);
  	if(test) {
  		cout<<"  Result: PASSED"<<endl;
		i++;
  	}else{
    		cout<<"  Result: FAILED"<<endl;
    		j++;
  	}
  	cout<<endl;
  	
  	cout<<"Test 5 leaveFriendship:"<<endl;
  	test=leaveFriendship("Marco", "Fulvio", N);
  	if(test) {
  		cout<<"  Result: PASSED"<<endl;
		i++;
  	}else{
    		cout<<"  Result: FAILED"<<endl;
    		j++;
  	}
  	cout<<endl;
  	
  	cout<<"Test 6 joinGroup:"<<endl;
  	test=joinGroup("AncoMarzio", "I Re di Roma", N);
  	if(test) {
  		cout<<"  Result: PASSED"<<endl;
		i++;
  	}else{
    		cout<<"  Result: FAILED"<<endl;
    		j++;
  	}
  	cout<<endl;
  	
  	cout<<"Test 7 joinGroup:"<<endl;
  	test=joinGroup("TarquinioPrisco", "I Re di Roma", N);
  	if(test) {
  		cout<<"  Result: PASSED"<<endl;
		i++;
  	}else{
    		cout<<"  Result: FAILED"<<endl;
    		j++;
  	}
  	cout<<endl;
  	
  	cout<<"Test 8 joinGroup:"<<endl;
  	test=joinGroup("TarquinioIlSuperbo", "I Re di Roma", N);
  	if(test) {
  		cout<<"  Result: PASSED"<<endl;
		i++;
  	}else{
    		cout<<"  Result: FAILED"<<endl;
    		j++;
  	}
  	cout<<endl;
  	
  	cout<<"Test 9 areFriends:"<<endl;
  	test=areFriends("Marco", "Fulvio", N);
  	if(!test) {
  		cout<<"  Result: PASSED"<<endl;
		i++;
  	}else{
    		cout<<"  Result: FAILED"<<endl;
    		j++;
  	}
  	cout<<endl;
  	
  	cout<<"Test 10 areFriends:"<<endl;
  	test=areFriends("Fulvio", "Marco", N);
  	if(!test) {
  		cout<<"  Result: PASSED"<<endl;
		i++;
  	}else{
    		cout<<"  Result: FAILED"<<endl;
    		j++;
  	}
  	cout<<endl;

  	
  	cout<<"Rimozione di membri, gruppi e elementi dei gruppi:"<<endl;
  	cout<<"--------------------------------------------------"<<endl;
  	
  	cout<<"Test 1 leaveGroup:"<<endl;
  	test=leaveGroup("Cesare", "Amici di Quinto", N);
  	if(test) {
  		cout<<"  Result: PASSED"<<endl;
		i++;
  	}else{
    		cout<<"  Result: FAILED"<<endl;
    		j++;
  	}
  	cout<<endl;
  	
  	cout<<"Test 2 leaveGroup:"<<endl;
  	test=leaveGroup("Fausto", "Solo Fausto", N);
  	if(test) {
  		cout<<"  Result: PASSED"<<endl;
		i++;
  	}else{
    		cout<<"  Result: FAILED"<<endl;
    		j++;
  	}
  	cout<<endl;
  	
  	cout<<"Test 3 leaveGroup:"<<endl;
  	test=leaveGroup("Romolo", "TartarugheNinja", N);
  	if(test) {
  		cout<<"  Result: PASSED"<<endl;
		i++;
  	}else{
    		cout<<"  Result: FAILED"<<endl;
    		j++;
  	}
  	cout<<endl;
  	
  	cout<<"Test 4 leaveGroup:"<<endl;
  	test=leaveGroup("Sempronio", "TartarugheNinja", N);
  	if(!test) {
  		cout<<"  Result: PASSED"<<endl;
		i++;
  	}else{
    		cout<<"  Result: FAILED"<<endl;
    		j++;
  	}
  	cout<<endl;
  	
  	cout<<"Test 5 leaveGroup:"<<endl;
  	test=leaveGroup("Leonardo", "HashTableFandom", N);
  	if(!test) {
  		cout<<"  Result: PASSED"<<endl;
		i++;
  	}else{
    		cout<<"  Result: FAILED"<<endl;
    		j++;
  	}
  	cout<<endl;
  	
  	cout<<"Test 6 deleteGroup:"<<endl;
  	test=deleteGroup("Antica Roma", N);
  	if(test) {
  		cout<<"  Result: PASSED"<<endl;
		i++;
  	}else{
    		cout<<"  Result: FAILED"<<endl;
    		j++;
  	}
  	cout<<endl;
  	
  	cout<<"Test 7 deleteGroup:"<<endl;
  	test=deleteGroup("HashTableFan", N);
  	if(!test) {
  		cout<<"  Result: PASSED"<<endl;
		i++;
  	}else{
    		cout<<"  Result: FAILED"<<endl;
    		j++;
  	}
  	cout<<endl;
  	
  	cout<<"Test 8 deleteMember:"<<endl;
  	test=deleteMember("Astato", N);
  	if(!test) {
  		cout<<"  Result: PASSED"<<endl;
		i++;
  	}else{
    		cout<<"  Result: FAILED"<<endl;
    		j++;
  	}
  	cout<<endl;
  	
  	cout<<"Test 9 deleteMember:"<<endl;
  	test=deleteMember("Quinto", N);
  	if(test) {
  		cout<<"  Result: PASSED"<<endl;
		i++;
  	}else{
    		cout<<"  Result: FAILED"<<endl;
    		j++;
  	}
  	cout<<endl;
  	
  	cout<<"Test 10 deleteMember:"<<endl;
  	test=deleteMember("Remo", N);
  	if(test) {
  		cout<<"  Result: PASSED"<<endl;
		i++;
  	}else{
    		cout<<"  Result: FAILED"<<endl;
    		j++;
  	}
  	cout<<endl;

  	
  	cout<<"Ulteriori test vari:"<<endl;
  	cout<<"-------------------"<<endl;
  	
  	cout<<"Test 1 makeMoreFriends:"<<endl;
  	test=makeMoreFriends("Romolo", N);
  	if(test) {
  		cout<<"  Result: PASSED"<<endl;
		i++;
  	}else{
    		cout<<"  Result: FAILED"<<endl;
    		j++;
  	}
  	cout<<endl;
  	
  	cout<<"Test 2 makeMoreFriends:"<<endl;
  	test=makeMoreFriends("Michelangelo", N);
  	if(test) {
  		cout<<"  Result: PASSED"<<endl;
		i++;
  	}else{
    		cout<<"  Result: FAILED"<<endl;
    		j++;
  	}
  	cout<<endl;
  	
  	cout<<"Test 3 deleteMember:"<<endl;
  	test=deleteMember("", N);
  	if(!test) {
  		cout<<"  Result: PASSED"<<endl;
		i++;
  	}else{
    		cout<<"  Result: FAILED"<<endl;
    		j++;
  	}
  	cout<<endl;
  	
  	cout<<"Test 4 deleteMember:"<<endl;
  	test=deleteMember("Riccardo", N);
  	if(!test) {
  		cout<<"  Result: PASSED"<<endl;
		i++;
  	}else{
    		cout<<"  Result: FAILED"<<endl;
    		j++;
  	}
  	cout<<endl;
  	
  	cout<<"Test 5 members:"<<endl;
  	L = members(N);
  	if(toString(L) == "AncoMarzio; Aurelio; Caio; Caligola; Cesare; Cleopatra; Decimo; Donatello; Fausto; Fulvio; Leonardo; Luciano; Marco; Massimo; Michelangelo; NumaPompilio; Paolo; Raffaello; Romolo; ServioTullio; TarquinioIlSuperbo; TarquinioPrisco; Tiberio; TulloOstilio;") {
  		cout<<"  Result: PASSED"<<endl;
		i++;
  	}else{
    		cout<<"  Result: FAILED"<<endl;
    		j++;
  	}
  	cout<<endl;
  	
  	cout<<"Test 6 makeMoreFriends:"<<endl;
  	test=makeMoreFriends("RenzoPiano", N);
  	if(!test) {
  		cout<<"  Result: PASSED"<<endl;
		i++;
  	}else{
    		cout<<"  Result: FAILED"<<endl;
    		j++;
  	}
  	cout<<endl;
  	
  	cout<<"Test 7 groups:"<<endl;
  	L=groups(N);
  	if(toString(L) != "") { // TEST NON COMPLETO
  		cout<<"  Result: PASSED"<<endl;
		i++;
  	}else{
    		cout<<"  Result: FAILED"<<endl;
    		j++;
  	}
  	cout<<endl;
  	
  	cout<<"Test 8 friends:"<<endl;
  	L=friends("Romolo", N);
  	if(toString(L) != "") { // TEST NON COMPLETO
  		cout<<"  Result: PASSED"<<endl;
		i++;
  	}else{
    		cout<<"  Result: FAILED"<<endl;
    		j++;
  	}
  	cout<<endl;
  	
  	cout<<"Test 9 memberOf:"<<endl;
  	L=memberOf("Michelangelo", N);
  	if(toString(L) != "") { // TEST NON COMPLETO
  		cout<<"  Result: PASSED"<<endl;
		i++;
  	}else{
    		cout<<"  Result: FAILED"<<endl;
    		j++;
  	}
  	cout<<endl;
  	
  	cout<<"Test 10 creatorOf:"<<endl;
  	L=creatorOf("Romolo", N);
  	if(toString(L) != "") { // TEST NON COMPLETO
  		cout<<"  Result: PASSED"<<endl;
		i++;
  	}else{
    		cout<<"  Result: FAILED"<<endl;
    		j++;
  	}
  	cout<<endl;

  	
  	cout<<"Test non effettuati, settati di default su FAILED:"<<endl;
  	cout<<"-------------------------"<<endl;
  	
  	cout<<"Test 1 :"<<endl;
  	test=false;
  	if(test) { // TEST NON COMPLETO
  		cout<<"  Result: PASSED"<<endl;
		i++;
  	}else{
    		cout<<"  Result: FAILED"<<endl;
    		j++;
  	}
  	cout<<endl;
  	
  	cout<<"Test 2 :"<<endl;
  	test=false;
  	if(test) { // TEST NON COMPLETO
  		cout<<"  Result: PASSED"<<endl;
		i++;
  	}else{
    		cout<<"  Result: FAILED"<<endl;
    		j++;
  	}
  	cout<<endl;
  	
  	cout<<"Test 3 :"<<endl;
  	test=false;
  	if(test) { // TEST NON COMPLETO
  		cout<<"  Result: PASSED"<<endl;
		i++;
  	}else{
    		cout<<"  Result: FAILED"<<endl;
    		j++;
  	}
  	cout<<endl;
  	
  	cout<<"Test 4 :"<<endl;
  	test=false;
  	if(test) { // TEST NON COMPLETO
  		cout<<"  Result: PASSED"<<endl;
		i++;
  	}else{
    		cout<<"  Result: FAILED"<<endl;
    		j++;
  	}
  	cout<<endl;
  	
  	cout<<"Test 5 :"<<endl;
  	test=false;
  	if(test) { // TEST NON COMPLETO
  		cout<<"  Result: PASSED"<<endl;
		i++;
  	}else{
    		cout<<"  Result: FAILED"<<endl;
    		j++;
  	}
  	cout<<endl;
  	
  	cout<<"Test 6 :"<<endl;
  	test=false;
  	if(test) { // TEST NON COMPLETO
  		cout<<"  Result: PASSED"<<endl;
		i++;
  	}else{
    		cout<<"  Result: FAILED"<<endl;
    		j++;
  	}
  	cout<<endl;
  	
  	cout<<"Test 7 joinGroup:"<<endl;
  	test=joinGroup("Michelangelo", "I Re di Roma", N);
  	if(test) {
  		cout<<"  Result: PASSED"<<endl;
		i++;
  	}else{
    		cout<<"  Result: FAILED"<<endl;
    		j++;
  	}
  	
  	cout<<"Test 6 makeMoreFriends:"<<endl;
  	test=makeMoreFriends("Romolo", N);
  	if(!test) {
  		cout<<"  Result: PASSED"<<endl;
		i++;
  	}else{
    		cout<<"  Result: FAILED"<<endl;
    		j++;
  	}
  	cout<<endl;
  	
  	
  	cout<<"Test 8 becomeFriends:"<<endl;
  	test=becomeFriends("Romolo", "TarquinioIlSuperbo", N);
  	if(test) {
  		cout<<"  Result: PASSED"<<endl;
		i++;
  	}else{
    		cout<<"  Result: FAILED"<<endl;
    		j++;
  	}
  	cout<<endl;
  	
  	cout<<"Test 10 areFriends:"<<endl;
  	test=areFriends("Romolo", "TarquinioIlSuperbo", N);
  	if(test) {
  		cout<<"  Result: PASSED"<<endl;
		i++;
  	}else{
    		cout<<"  Result: FAILED"<<endl;
    		j++;
  	}
  	cout<<endl;

  	
  	/**/
  	
  	cout<<endl<<"================================================================================"<<endl<<endl;
  	
  	cout<<"members:"<<endl;
  	L = members(N);
  	comp = toString(L);
  	cout<<comp<<endl;
  	cout<<endl;
  	
  	cout<<"groups:"<<endl;
  	L = groups(N);
  	comp = toString(L);
  	cout<<comp<<endl;
  	cout<<endl;
  	
  	cout<<"friends (Romolo):"<<endl;
  	L = friends("Romolo", N);
  	comp = toString(L);
  	cout<<comp<<endl;
  	cout<<endl;
  	
  	cout<<"memberOf (Michelangelo):"<<endl;
  	L = memberOf("Michelangelo", N);
  	comp = toString(L);
  	cout<<comp<<endl;
  	cout<<endl;
  	
  	cout<<"creatorOf (Romolo):"<<endl;
  	L = creatorOf("Romolo", N);
  	comp = toString(L);
  	cout<<comp<<endl;
  	cout<<endl;
  	
  	cout<<"print (Romolo):"<<endl;
  	
  	comp = toString(L);
  	cout<<comp<<endl;
  	cout<<endl;
  	
  	

  	cout<<endl<<"================================================================================"<<endl<<endl;
	
	cout<<"     TEST EFFETTUATI:       "<<i+j<<endl<<endl;
	cout<<"     TEST SUPERATI:         "<<i<<endl;
  	cout<<"     TEST FALLITI:          "<<j<<endl<<endl;
  	
  	double testProgress = (100*i)/(i+j);
  	double indexProgress = (100*(i*i)/(j+i))/(i+j);
  	
  	cout<<"     PROGRESSO INDICIZZATO AI TEST SUPERATI: "<<testProgress<<"%"<<endl;
  	cout<<"     PROGRESSO INDICIZZATO AL LAVORO SVOLTO: "<<indexProgress<<"%"<<endl<<endl;
  	
  	
}
