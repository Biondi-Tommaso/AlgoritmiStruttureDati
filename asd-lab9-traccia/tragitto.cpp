#include "tragitto.h"

// verifica se un Tragitto è vuoto
bool tragitto::isEmpty(Tragitto tr) {
  return (tr == tragittoVuoto);
}

// inserisce una Tappa in un Tragitto
void tragitto::insert(Tragitto &tr, Tappa t) {
  if (tr == tragittoVuoto) {
    tr = new TragittoElem;
    tr->tappa = t;
    tr->next = tragittoVuoto;
    return;
  }
  Tragitto aux = tr;
  while (aux->next != tragittoVuoto) {
    aux = aux->next;
  }
  Tragitto nuovo = new TragittoElem;
  nuovo->tappa = t;
  nuovo->next = tragittoVuoto;
  aux->next = nuovo; // fixing the missing link
}

// ritorna FALSE se il Tragitto è vuoto
// altrimenti rimuove la prima Tappa del Tragitto 
//    e la assegna al secondo parametro e ritorna TRUE
bool tragitto::extract(Tragitto &tr, Tappa &t) {
  if (isEmpty(tr)) {
    return false;
  }
  t = tr->tappa;
  Tragitto toDelete = tr;
  tr = tr->next;
  delete toDelete;
  return true;
}

// stampa un Tragitto (formato: N volte [distanza citta'])
void printTragitto(tragitto::Tragitto tr) {
  while (tr != tragitto::tragittoVuoto) {
    std::cout << "[" << tr->tappa.distanza << " " << tr->tappa.citta << "] ";
    tr = tr->next;
  }
  std::cout << std::endl;
}

