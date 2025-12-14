#include <iostream>
#include "graph.h"

using namespace graph;

struct Edge{
    Label label;
    Weight w;
    Edge* edge;
};
typedef Edge * edgeP;
const edgeP emptyEdge = nullptr;

struct graph::vertexNode {
    Label label;
    bool isVisited = false;
    list::List adiacente;
    Graph next;
    Edge* edge;
};



/**********************************************************************/
/*               Funzione da implementare                             */
/**********************************************************************/

Graph getNode(Label l, Graph g) {
    // Se il grafo è vuoto, restituisci nullptr
    if (isEmpty(g)) {
        return emptyGraph;
    }

    // Cerca il vertice con l'etichetta specificata
    while (g != emptyGraph) {
        if (g->label == l) {
            return g;
        }
        g = g->next;
    }

    // Se l'etichetta non è stata trovata, restituisci nullptr o gestisci il caso secondo le tue esigenze
    return emptyGraph; // o nullptr;
}





// Restituisce il grafo vuoto
Graph graph::createEmptyGraph() {
    return emptyGraph;
}

// Aggiunge nuovo vertice con etichetta la stringa.
// Se non è gia presente, ritorna true, altrimenti fallisce e ritorna false 
bool graph::addVertex(Label l, Graph& g) {
    // Se il grafo è vuoto, aggiungi il primo vertice
    if (isEmpty(g)) {
        Graph nuovo = new vertexNode();
        nuovo->label = l;
        nuovo->isVisited = false;
        nuovo->adiacente = list::createEmpty();
        nuovo->next = emptyGraph;
        nuovo->edge = emptyEdge;
        g = nuovo;
        return true;
    }

    // Scorri la lista per controllare se il vertice esiste già
    Graph aux = g;
    while (aux != emptyGraph) {
        if (aux->label == l) // Se il nodo è già presente
            return false;
        aux = aux->next;
    }

    // Crea il nuovo vertice e aggiungilo in testa alla lista dei vertici
    Graph nuovo = new vertexNode();
    nuovo->label = l;
    nuovo->isVisited = false;
    nuovo->adiacente = list::createEmpty();
    nuovo->next = g;
    nuovo->edge = emptyEdge;
    g = nuovo;

    return true;
}

// Aggiunge nuovo arco tra i due vertici con etichette le due stringe e peso
// l'intero. Fallisce se non sono presenti tutti e due i nodi o se l'arco
// tra i due e' gia' presente. Se fallisce ritorna false,
// altrimenti ritorna true
bool graph::addEdge(Label from, Label to, Weight w, Graph& g) {
    Graph aux = g;
    short found = 0;



    while (aux != emptyGraph) {
        // Se trovo uno dei nodi che devo collegare
        if (aux->label == from || aux->label == to) {
            found++;
        }
        aux = aux->next;
    }

    // Controllo se ho trovato entrambi i nodi
    if (found != 2) {
        return false;
    }

    // Scorro tutti i nodi
    aux = g;
    while (aux != emptyGraph) {
        // Se trovo uno dei nodi che devo collegare
        if (aux->label == from) {
            // Controllo se l'arco è già presente
            edgeP auxEdge = aux->edge;
            while (auxEdge != nullptr) {
                if (auxEdge->label == to) {
                    return false;
                }
                auxEdge = auxEdge->edge;
            }
            // Aggiungo il nuovo arco
            auxEdge = new Edge;
            auxEdge->label = to;
            auxEdge->w = w;
            auxEdge->edge = aux->edge;
            aux->edge = auxEdge;
        }

        // Se trovo uno dei nodi che devo collegare
        if (aux->label == to) {
            // Controllo se l'arco è già presente
            edgeP auxEdge = aux->edge;
            while (auxEdge != nullptr) {
                if (auxEdge->label == from) {
                    return false;
                }
                auxEdge = auxEdge->edge;
            }
            // Aggiungo il nuovo arco
            auxEdge = new Edge;
            auxEdge->label = from;
            auxEdge->w = w;
            auxEdge->edge = aux->edge;
            aux->edge = auxEdge;
        }

        aux = aux->next;
    }
    return true;
}

// Restituisce true se il grafo e' vuoto, false altrimenti
bool graph::isEmpty(const Graph& g) {
    return g == emptyGraph;
}

// Ritorna il numero di vertici del grafo
unsigned int graph::numVertices(const Graph& g) {
    // Implementazione mancante
    unsigned int answer = 0;
    Graph aux = g;
    while(aux != emptyGraph){
      answer ++;
      aux = aux -> next;
    }
    return answer;
}

// Ritorna il numero di archi del grafo
unsigned int graph::numEdges(const Graph& g) {
    unsigned int answer = 0;
    Graph aux = g;
    while (aux != emptyGraph) {
        edgeP edge = aux->edge;
        while (edge != emptyEdge) {
            answer++;
            edge = edge->edge;
        }
        aux = aux->next;
    }
    return answer/2;
}


// Calcola e ritorna (nel secondo parametro) il grado del vertice.
// Restituisce un valore falso se il vertice non esiste,
// altrimenti ritorna true
bool graph::nodeDegree(Label l, unsigned int& degree, const Graph& g) {
    // Implementazione mancante

    //individuo il nodo da analizzare
    Graph aux = g;
    while(aux -> label != l){
      
      aux = aux -> next;
      if(aux == emptyGraph )
        return false;
    }
    degree = 0;

  

  
   edgeP p = aux -> edge;

   while(p != emptyEdge ){
      degree++;
      p = p -> edge;
   }

    return true;
}

// Verifica se due vertici sono adiacenti (ovvero se esiste un arco)
bool graph::areAdjacent(Label v1, Label v2, const Graph& g) {
    // Implementazione mancante
    unsigned int dV1;
    unsigned int dV2;
  if(!nodeDegree(v1,dV1,g) || !nodeDegree(v2,dV2,g))
    return 0;
  Label max = v1;
  Label min = v2;
  if(dV1 > dV2){
     min = v2;
     max = v1;
  }
  else{
     min = v1;
     max = v2;
  }

  Graph aux = g;
  while(aux -> label != min){
    aux = aux -> next;
    if(aux == emptyGraph)
      return 0;
  }

  edgeP EdgeAux= aux -> edge;

  while(EdgeAux != emptyEdge){
    if(EdgeAux -> label == max)
      return 1;
    EdgeAux = EdgeAux ->edge;
  }


return 0;
}


// Ritorna la lista di adiacenza di un vertice
// corrispondente alla lista dei label dei vertici adiacenti
list::List graph::adjacentList(Label v1, const Graph& g) {
    // Implementazione mancante
    list::List l = list::createEmpty();
    Graph nodeAux = getNode(v1, g);
    if (nodeAux != emptyGraph) {
        edgeP aux = nodeAux->edge;
        list::List tempList = list::createEmpty(); // Lista temporanea per memorizzare i label dei vertici adiacenti

        // Scorro gli archi e memorizzo i label dei vertici adiacenti nella lista temporanea
        while (aux != emptyEdge) {
            list::addBack(aux->label, tempList);
            aux = aux->edge;
        }

        // Ordinamento a bolle della lista temporanea
        for (int i = 0; i < tempList.size - 1; ++i) {
            for (int j = 0; j < tempList.size - i - 1; ++j) {
                if (tempList.list[j] > tempList.list[j + 1]) {
                    // Scambia i label se non sono in ordine
                    Label temp = tempList.list[j];
                    tempList.list[j] = tempList.list[j + 1];
                    tempList.list[j + 1] = temp;
                }
            }
        }

        // Copio i label ordinati nella lista di adiacenza da restituire
        for (int i = 0; i < tempList.size; ++i) {
            list::addBack(tempList.list[i], l);
        }
    }
    return l;
}




// Calcola, se esiste, un cammino tra due vertici
// Il primo argomento e il vertice di partenza
// Il secondo argomento e il vertice di arrivo
// Il terzo argomento conterrà la lista delle etichette degli
// vertici visitati sul cammino (senza il vertice di partenza, ne il vertice
// di arrivo)
// Si assume che il chiamante fornisca inizialmente una lista vuota.
// Il quarto argomento è il peso del cammino
// La funziona ritorna false, se il vertice di partenza e uguale al vertice
// di arrivo, o se non c'e un cammino tra i due vertici, altrimenti
// ritorna true4
int getIndexOf(list::Elem elem, const list::List& list) {
    for (int i = 0; i < list.size; ++i) {
        if (list::get(i,list) == elem) {
            return i;
        }
    }
    return -1; // Se l'elemento non è presente nella lista, ritorna -1
}



list::List removeDuplicates(const list::List& lst) {
    list::List newList = list::createEmpty();

    for (int i = 0; i < lst.size; ++i) {
        list::Elem current = lst.list[i];
        bool found = false;

        // Check if current element is already in newList
        for (int j = 0; j < newList.size; ++j) {
            if (newList.list[j] == current) {
                found = true;
                break;
            }
        }

        // If not found, add it to newList
        if (!found) {
            list::addBack(current, newList);
        }
    }

    return newList;
}




// Funzione ausiliaria ricorsiva per trovare il cammino
bool findPathRecursive(Graph currentNode, Graph endNode, list::List& path, Weight& weight, list::List& visited) {
    if (currentNode == nullptr) {
        return false; // Evita la dereferenziazione di un puntatore nullo
    }

    // Aggiungo il nodo corrente alla lista dei visitati
    list::addBack(currentNode->label, visited);

    // Se il nodo corrente è quello di arrivo, ho trovato il cammino
    if (currentNode == endNode) {
        // Costruisco la lista del cammino (senza il nodo di partenza e di arrivo)
        list::List tempPath = visited;
        list::removePos(0, tempPath); // rimuove il nodo di partenza
        list::removePos(list::size(tempPath) - 1, tempPath); // rimuove il nodo di arrivo
        path = tempPath;
        return true;
    }

    // Scorro gli archi uscenti dal nodo corrente
    edgeP edge = currentNode->edge;
    while (edge != nullptr) { // Assumendo che nullptr rappresenti l'assenza di archi
        // Controllo se il vertice adiacente non è stato visitato
        if (getIndexOf(edge->label, visited) == -1) {
            // Calcolo il peso totale del cammino
            weight += edge->w;

            // Chiamata ricorsiva sul nodo adiacente
            Graph nextNode = getNode(edge->label, currentNode); // Assumendo che getNode ritorni il nodo adiacente
            if (nextNode == nullptr) {
                // Se il nodo adiacente non esiste, ignora questo arco
                weight -= edge->w;
                edge = edge->edge;
                continue;
            }

            bool found = findPathRecursive(nextNode, endNode, path, weight, visited) || findPathRecursive(endNode, nextNode, path, weight, visited);

            // Se ho trovato il cammino, aggiorno la lista del cammino e ritorno true
            if (found) {
                list::addFront(currentNode->label, path);
                return true;
            }
          

            // Se non ho trovato il cammino, tolgo il peso dell'arco attuale dal peso totale del cammino
            weight -= edge->w;
        }

        // Passo all'arco successivo
        edge = edge->edge; // Supponendo che edge->next punti all'arco successivo
    }

    // Rimuovo il nodo corrente dalla lista dei visitati, poiché non porta alla soluzione
    list::removePos(list::size(visited) - 1, visited);

    // Se arrivo qui, significa che non ho trovato il cammino partendo da questo nodo
    return false;
}

bool graph::findPath(Label v1, Label v2, list::List& path, Weight& weight, const Graph& g) {
    // Controllo se i vertici sono validi
    if (v1 == v2) {
        weight = 0;
        return true;
    }

    // Cerco i nodi corrispondenti alle etichette v1 e v2
    Graph startNode = getNode(v1, g);
    Graph endNode = getNode(v2, g);

    // Se uno dei due vertici non esiste, non c'è alcun cammino
    if (startNode == nullptr || endNode == nullptr) // Supponendo che nullptr rappresenti l'assenza di nodi
        return false;

    // Azzero il peso del cammino
    weight = 0;

    // Inizializzo la lista dei vertici visitati
    list::List visited = list::createEmpty();

    // Inizializzo la lista del cammino
    path = list::createEmpty();

    // Chiamo la funzione ricorsiva per trovare il cammino
    bool found = findPathRecursive(startNode, endNode, path, weight, visited);
    if(found)
    	return 1;
    list::clear(path);
    if( findPathRecursive(endNode, startNode, path, weight, visited)){
    	path = removeDuplicates(path);
    	return 1;
    }
    return 0;
}


// Svuota un grafo


void graph::clear(graph::Graph& g) {
    while (g != emptyGraph) {
        Graph temp = g;
        g = g->next;
        delete temp;
    }
}


// Stampa il grafo
// Per ogni vertice stampa su una riga l'etichetta del vertice seguito di ':'
// poi le etichette dei vertici adiacenti con fra parentesi il peso associato,
// separate da virgole
void graph::printGraph(const graph::Graph& g) {
    // Implementazione mancante
Graph aux = g;
while(aux != emptyGraph){
    cout << aux -> label<<" : ";
    edgeP auxEdge = aux -> edge;
    if(auxEdge != emptyEdge){
    while (auxEdge ->edge!= emptyEdge){
        cout<<auxEdge -> label << " (" <<auxEdge -> w << "), ";
       auxEdge= auxEdge -> edge;
    }
    }
     if(auxEdge != emptyEdge){
        cout<<auxEdge -> label << " (" <<auxEdge -> w << ")";
     }
     aux = aux -> next;
     cout <<endl;
}



}
