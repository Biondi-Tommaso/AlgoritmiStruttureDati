// FILE DA MODIFICARE
#include <iostream>
#include <fstream>
#include "ASD-doubly-linked-list.h"

using namespace list;
using namespace std;

/*Descrizione da come e' fatta  la struttura node. */
/*I dettagli interni non saranno visibili dal main*/
struct list::node {  
  Elem info;
  node *prev;
  node *next;
};

/**************************************************/
/*      funzioni da implementare                    */
/**************************************************/
  
/* crea la lista vuota */
void list::createEmpty(List& li){
    // Allocazione dinamica del nuovo nodo sentinella e assegnazione dei puntatori prev e next a se stesso
    li = new node;
    // Assegnazione del puntatore prev e next a se stesso (lista vuota)
    li->prev = li;
    li->next = li;
}


/* "smantella" la lista (tranne la sentinella) */
void list::clear(List& li){
	//TO DO
	List aux = li -> next;
	while(aux != li){
		List prev = aux;
		aux = aux -> next;
		delete prev;
		li -> next = aux;
	}
	li -> prev = li;
	
}

/* restituisce true se la lista e' vuota */
bool list::isEmpty(const List& li){
  //TO DO
  return li == li-> next;
}

/* restituisce la dimensione della lista */
unsigned int list::size(const List& li){
	//TO DO
	List aux = li -> next;
	unsigned int counter = 0;
	while(aux != li){
		aux = aux -> next;
		counter++;
	}
  return counter;
}

/* restituisce l'elemento in posizione pos */
/* se pos non e corretta, solleva una eccezione di tipo string*/
Elem list::get(unsigned int pos, const List& li){
	//TO DO
	if (pos == 0) return li -> next -> info;
	List aux = li -> next;
	unsigned int counter = 0;
	while (aux != li){
		
		if(counter == pos)
			return aux -> info;
		aux = aux -> next;
		counter ++;
	}
	const std::string error = "Errore";
	throw error;
	return 1;
	//solleva una ecezzione di tipo string
}

/* modifica l'elemento in posizione pos */
/* se pos non e' corretta, solleva una eccezione di tipo string*/
void list::set(unsigned int pos, Elem el, const List& li){
    // TO DO
    if (pos == 0){
        li->next->info = el;
        return;
    }
    List aux = li->next;
    unsigned int counter = 0;
    while (aux != li){
        if(counter == pos){
            aux->info = el;
            return;
        }
        aux = aux->next;
        counter++;
    }
    
    throw std::string("Errore: Posizione non trovata");
}


/* inserisce l'elemento in posizione pos*/
/*shiftando a destra gli altri elementi */
/*se pos non e' corretta, solleva una eccezione di tipo string*/
void list::add(unsigned int pos, Elem el, const List& li) {
    if (pos == 0) { // Se la posizione è 0, inserisci in testa
        addFront(el, li);
        return;
    }

    // Cerca la posizione corretta nella lista
    List aux = li->next;
    unsigned int counter = 0;
    while (aux != li && counter < pos) {
        aux = aux->next;
        counter++;
    }

    if (counter != pos) { // Se la posizione non è stata trovata
        const std::string error = "Posizione non valida";
        throw error;
    }

    // Crea un nuovo nodo e inserisci l'elemento nella posizione corretta
    List newNode = new node;
    newNode->info = el;
    newNode->next = aux;
    newNode->prev = aux->prev;
    aux->prev->next = newNode;
    aux->prev = newNode;
}


/* inserisce l'elemento alla fine della lista */
void list::addRear(Elem el, const List& li){
	//TO DO
	List aux = new node;
	aux -> next = li;
	aux -> prev = li -> prev;
	li -> prev -> next = aux;
	li -> prev = aux;
	aux -> info = el;
}

/* inserisce l'elemento all'inizio della lista */
void list::addFront(Elem el, const List& li) {
	//TO DO
	List aux = new node;
	aux -> next = li -> next;
	li -> next= aux;
	aux -> next -> prev = aux;
	aux -> prev = li;
	aux -> info = el;
	
}

/* cancella l'elemento in posizione pos dalla lista */
/* se pos non e' corretta, solleva una eccezione di tipo string*/
void list::removePos(unsigned int pos,const List& li){
    if (pos == 0) { // Rimuovi il primo elemento
        if (isEmpty(li)) { // Controlla se la lista è vuota
            return;
        }
        List toRemove = li->next;
        li->next = toRemove->next;
        toRemove->next->prev = li;
        delete toRemove;
        return;
    }

    // Trova il nodo da rimuovere
    List aux = li->next;
    unsigned int counter = 0;
    while (aux != li && counter < pos) {
        aux = aux->next;
        counter++;
    }

    if (counter != pos || aux == li) { // Se la posizione non è stata trovata o se il nodo da rimuovere è la sentinella
        const std::string error = "Posizione non valida";
        throw error;
    }

    // Rimuovi il nodo corretto
    aux->prev->next = aux->next;
    aux->next->prev = aux->prev;
    delete aux;
}


/* cancella tutte le occorrenze dell'elemento elem*/
/*se presenti, dalla lista */
void list::removeEl(Elem el,const List& li){
    List aux = li->next;
    while (aux != li) {
        if (aux->info == el) {
            List toRemove = aux;
            aux = aux->next;
            toRemove->prev->next = toRemove->next;
            toRemove->next->prev = toRemove->prev;
            delete toRemove;
        } else {
            aux = aux->next;
        }
    }
}


/**************************************************/
/*      funzioni implementate                    */
/**************************************************/
  
/* riempie una lista da file */
void list::readFromFile(string name_file, const List& li){
  ifstream infile;
  string read_data;
  infile.open(name_file);
  while (getline (infile,read_data)){
    if(read_data.length()>0){
      addRear(stoi(read_data),li);
    }
  }
}

/* riempie una lista da standard input */
void list::readFromStdin(const List& li){
  cout << "Inserire una sequenza di numeri separati da spazi seguiti da END per terminare\n";
  string read_data;
  cin>>read_data;
  while(read_data!="END"){
    addRear(stoi(read_data),li);
    cin>>read_data;
  }
}

/* stampa la lista */
void list::print(const List& li){
  if(li==li->next){
    cout<<"vuota";
  }
  List cur = li->next;  // q "salta la sentinella" e va alla testa della lista
  while (cur != li) {   
    cout << cur->info;
    cur= cur->next;
    if(cur!=li) cout<<" <-> ";
  }
  cout<<endl;
}

/* produce una string contenendo la lista*/
std::string list::tostring(const List& li){
  string out="";
  if(li==li->next){
    out+="vuota";
  }
  List cur = li->next;  // q "salta la sentinella" e va alla testa della lista
  while (cur != li) {   
    out+=to_string(cur->info);
    cur= cur->next;
    if(cur!=li) out+=" <-> ";
  }
  return out;
}
