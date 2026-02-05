#include <iostream>
#include <fstream>
#include <string>

#include "ASD-queue-list.h"

using namespace queue;
using namespace std;

// Implementazione di una doubly linked list
struct queue::cell {
  Elem el;
  cell *next;
  cell *prev;
};

/**************************************************/
/*     funzioni da implementare                 */
/**************************************************/

/* Restituisce la coda vuota */
Queue queue::createEmpty() {
  Queue q;
  q.li = EMPTYLIST;
  q.end = EMPTYLIST;
  return q;
}

/* Restituisce true se la coda è vuota */
bool queue::isEmpty(const Queue& q) {
  return q.li == EMPTYLIST;
}

/* Inserisce l'elemento "da una parte" della coda */
void queue::enqueue(Elem e, Queue& q) {
  cell *new_cell = new cell;
  new_cell->el = e;
  new_cell->next = EMPTYLIST;

  if (isEmpty(q)) {
    q.li = new_cell;
    q.end = new_cell;
  } else {
    // Modifica: inseriamo il nuovo elemento all'inizio della lista
    new_cell->next = q.li;
    q.li->prev = new_cell;
    q.li = new_cell;
  }
}

/* Cancella l'elemento (se esiste) "dall'altra parte */
/* della coda" e lo restituisce; se la coda è vuota solleva */
/* una eccezione di tipo string*/
Elem queue::dequeue(Queue& q) {
  if (isEmpty(q)) {
    throw string("Coda vuota!");
  }

  cell *to_delete = q.end;
  Elem ret = to_delete->el;

  if (q.li == q.end) {
    q.li = EMPTYLIST;
    q.end = EMPTYLIST;
  } else {
    q.end = q.end->prev;
    q.end->next = EMPTYLIST;
  }

  delete to_delete;
  return ret;
}

/* Restituisce l'elemento in prima posizione (se esiste) senza cancellarlo*/
/* se la coda è vuota solleva una eccezione di tipo string*/
Elem queue::first(Queue& q) {
  if (isEmpty(q)) {
    throw string("Coda vuota!");
  }

  return q.li->el;
}

/**************************************************/
/*     funzioni implementate                   */
/**************************************************/

/* Riempie una coda da file */
Queue queue::readFromFile(std::string name_file) {
  ifstream infile;
  string read_data;
  infile.open(name_file);
  Queue qret = createEmpty();
  while (getline(infile, read_data)) {
    if (read_data.length() > 0) {
      enqueue(stoi(read_data), qret);
    }
  }
  return qret;
}

/* Legge il contenuto di una coda da standard input */
Queue queue::readFromStdin() {
  cout << "Inserire una sequenza di numeri separati da spazi seguiti da END per terminare\n";
  Queue qret = createEmpty();
  string read_data;
  cin >> read_data;
  while (read_data != "END") {
    enqueue(stoi(read_data), qret);
    cin >> read_data;
  }
  return qret;
}

/* Stampa la coda*/
void queue::print(const Queue& q) {
  cout << tostring(q) << endl;
}

/* Produce una string contenente la coda*/
std::string queue::tostring(const Queue& q) {
  string out = "";
  out += "{";
  cell *l = q.li;
  while (l != EMPTYLIST) {
    out += to_string(l->el);
    if (l != q.end) {
      out += ",";
    }
    l = l->next;
  }
  out += "}";
  return out;
}

