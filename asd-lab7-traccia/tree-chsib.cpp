#include "tree-chsib.h"

using namespace tree;

/* Nota: nei commenti usiamo "albero" e "puntatore a un nodo" come sinonimi, scegliendo di volta in volta
la formulazione più adatta a dare la specifica di una funzione. 
Dal punto di vista tecnico, usiamo sempre il tipo Tree sia quando operiamo su un albero, sia quando operiamo, 
a livello concettuale, su un puntatore a un nodo dell'albero. 
Questo approccio e' corretto in quanto un albero (o sottoalbero) è un puntatore a una struct di tipo treeNode:
un albero è identificato univocamente dal puntatore alla sua radice */ 



/*******************************************************************************************************/
// il nodo di un albero è caratterizzato dall'etichetta, il puntatore al primo figlio e il puntatore al prossimo fratello
// NON manteniamo il puntatore al padre, anche se sarebbe comodo per alcune funzioni (ma del tutto inutile per altre)
struct tree::treeNode {
    Label label;    
    treeNode *firstChild;
    treeNode *nextSibling;
};



/*******************************************************************************************************/
// isEmpty restituisce true se l'albero t e' vuoto, false altrimenti
bool tree::isEmpty(const Tree& t)
{ 
	
   return t == emptyTree;
}



/*******************************************************************************************************/
// addElem aggiunge il nodo etichettato con labelOfNodeToAdd come
// figlio del nodo etichettato con labelOfNodeInTree.
// Caso particolare: aggiunta della radice, che si ottiene
// con labelOfNodeInTree uguale a emptyLabel (= nessun padre), e ha successo
// solo se l'albero e' vuoto (in caso contrario restituisce FAIL 
// e non aggiunge nulla).
// Restituisce FAIL se non esiste un nodo nell'albero etichettato 
// con labelOfNodeInTree oppure se nell'albero esiste gia' un nodo 
// etichettato con labelOfNodeToAdd; aggiunge e restituisce OK altrimenti
// Definizione della struttura TreeNode


// Funzione per creare un nuovo nodo con una data etichetta
Tree createNode(const Label label) {
    // Alloca memoria per un nuovo nodo
    Tree newNode = new treeNode;


    // Imposta l'etichetta del nuovo nodo
    newNode->label = label;

    // Imposta i puntatori firstChild e nextSibling su emptyTree (o nullptr)
    newNode->firstChild = emptyTree; // oppure newNode->firstChild = nullptr;
    newNode->nextSibling = emptyTree; // oppure newNode->nextSibling = nullptr;

    // Restituisci il puntatore al nuovo nodo
    return newNode;
}


Tree getNode(const Label l, const Tree& t)
{
    // Se l'albero è vuoto o l'etichetta cercata è vuota, restituisco emptyTree
    if (isEmpty(t) || l == emptyLabel)
        return emptyTree;

    // Se l'etichetta di t è quella cercata, restituisco t
    if (t->label == l)
        return t;

    // Chiamo ricorsivamente getNode sul primo figlio di t
    Tree result = getNode(l, t->firstChild);
    if (result != emptyTree)
        return result; // Se il risultato è trovato, lo restituisco

    // Se non ho trovato il nodo cercato nel primo figlio, chiamo ricorsivamente getNode sul prossimo fratello
    return getNode(l, t->nextSibling);
}





Error tree::addElem(const Label labelOfNodeInTree, const Label labelOfNodeToAdd, Tree& t)
{
    // Controlli iniziali
    if ( labelOfNodeToAdd == emptyLabel)
        return FAIL;

    if ((labelOfNodeInTree == emptyLabel || labelOfNodeInTree=="$#$#$") && isEmpty(t)){
    	t = createNode(labelOfNodeToAdd);
    	return OK;
    }

    // Se l'albero è vuoto, aggiungi un nuovo nodo come radice con l'etichetta labelOfNodeToAdd
    if (isEmpty(t))
    {
        t = createNode(labelOfNodeToAdd);
        if (t == emptyTree)
            return FAIL; // Fallisce la creazione della radice
        return OK; // Radice aggiunta con successo
    }

    // Verifica se l'etichetta labelOfNodeToAdd è già presente nell'albero
    if (getNode(labelOfNodeToAdd, t) != emptyTree)
        return FAIL;

    // Recupero del nodo con etichetta labelOfNodeInTree
    Tree auxT = getNode(labelOfNodeInTree, t);
    if (auxT == emptyTree)
        return FAIL;

    // Crea un nuovo nodo con l'etichetta labelOfNodeToAdd
    Tree newNode = createNode(labelOfNodeToAdd);
    if (newNode == emptyTree)
        return FAIL;

  
    // Aggiungi il nuovo nodo come figlio di auxT
    if (auxT->firstChild == emptyTree)
    {
     
     	
        // Se auxT non ha figli, aggiungi il nuovo nodo come primo figlio
        auxT->firstChild = newNode;
    }
    else
    {
    	
        // Se auxT ha figli, trova l'ultimo figlio
        Tree current = auxT->firstChild;
        while (current->nextSibling != emptyTree)
        {
            current = current->nextSibling;
        }
        // Aggiungi il nuovo nodo come prossimo fratello dell'ultimo figlio
        current->nextSibling = newNode;
    }

    return OK;
}




/*******************************************************************************************************/
// deleteElem (versione iterativa) rimuove dall'albero il nodo etichettato con la Label l
// e collega al padre di tale nodo tutti i suoi figli
// Restituisce FAIL se si tenta di cancellare la radice e questa ha 
// dei figli (non si saprebbe a che padre attaccarli) oppure se non esiste 
// un nodo nell'albero etichettato con la Label; cancella e restituisce OK altrimenti
Error tree::deleteElemI(const Label l, Tree& t) {
    //verifico che il nodo da eliminare esista
    if(!member(l,t))
        return FAIL;
    Tree fatherTree = getNode(father(l, t), t);
    if (isEmpty(fatherTree)) {
        // Se il padre è vuoto, sto tentando di rimuovere la radice
        if (t->firstChild == emptyTree) {
            delete t;
            t = emptyTree;
            return OK;
        }
        else{
            return FAIL;
        }
    } else {
        // Se rimuovo un nodo
        Tree nodeToRemove = getNode(l, t);
        

    //Se il nodo da rimuovere ha figli
    if(nodeToRemove -> firstChild != emptyTree ){
       
        Tree auxSon = nodeToRemove -> firstChild;
        while(auxSon -> nextSibling != emptyTree)
            auxSon = auxSon -> nextSibling;
        auxSon -> nextSibling = nodeToRemove -> nextSibling;
        nodeToRemove -> nextSibling = nodeToRemove -> firstChild;
        nodeToRemove -> firstChild = emptyTree;
    }






        //il nodo non ha piu figli.
       
            //Se è il primo figlio
            if(fatherTree -> firstChild == nodeToRemove){
                fatherTree -> firstChild = nodeToRemove->nextSibling;
            }
            //se non è il primo figlio
            else{
               Tree aux = fatherTree -> firstChild;
                while(aux -> nextSibling != nodeToRemove){
                    aux = aux -> nextSibling;
                }
                aux -> nextSibling = nodeToRemove -> nextSibling;
            }


            delete nodeToRemove;
            return OK; 
       
    }
    return OK;
}



Error deleteElemAux(const Label l, Tree& t) {
    // CASO 1: Se l'albero è vuoto, non c'è nulla da cancellare, restituisco FAIL
    if (isEmpty(t)) {
        return FAIL;
    }

    // CASO 2: Se t ha un figlio con etichetta l, lo rimuovo e restituisco OK
    if (t->firstChild != emptyTree && t->firstChild->label == l) {
        Tree temp = t->firstChild;
        t->firstChild = temp->nextSibling;
        delete temp;
        return OK;
    }

    // Controllo i figli di t per trovare l'etichetta da cancellare
    Tree current = t->firstChild;
    while (current != emptyTree) {
        if (current->label == l) {
            
            ////////////////////////////////////////////////////////////////////////////
             if(current -> firstChild != emptyTree ){
       
        Tree auxSon = current -> firstChild;
        while(auxSon -> nextSibling != emptyTree)
            auxSon = auxSon -> nextSibling;
        auxSon -> nextSibling = current -> nextSibling;
        current -> nextSibling = current -> firstChild;
        current -> firstChild = emptyTree;
    }






        //il nodo non ha piu figli.
       
            //Se è il primo figlio
            Tree fatherTree = getNode(father(l, t), t);
            if(fatherTree -> firstChild == current){
                fatherTree -> firstChild = current->nextSibling;
            }
            //se non è il primo figlio
            else{
               Tree aux = fatherTree -> firstChild;
                while(aux -> nextSibling != current){
                    aux = aux -> nextSibling;
                }
                aux -> nextSibling = current -> nextSibling;
            }


            delete current;
            return OK;
            /////////////////////////////////////////////////////////////////////////////
        }
       
        current = current->nextSibling;
    }

    // CASO 3: Nessuno dei figli diretti di t ha l'etichetta cercata, richiamo ricorsivamente deleteElemAux sui figli di t
    current = t->firstChild;
    while (current != emptyTree) {
        Error result = deleteElemAux(l, current);
        if (result == OK) {
            return OK;
        }
        current = current->nextSibling;
    }

    // Se nessun figlio ha l'etichetta cercata, restituisco FAIL
    return FAIL;
}







/*******************************************************************************************************/
// deleteElem (versione ricorsiva): stesso comportamento della versione iterativa, ma implementata ricorsivamente
// (può anche non essere ricorsiva la deleteElemR, ma deve fare uso di funzioni ausiliarie ricorsive)
Error tree::deleteElemR(const Label l, Tree& t)
{
/* ....deleteElemR viene sempre chiamata a partire dalla radice;
se t non è vuoto e t->label è uguale a l, vuole dire che voglio cancellare la radice.
Questo è possibile solo se la radice non ha figli, nel qual caso la rimuovo e restituisco OK, altrimenti restituisco FAIL: 
devo gestire questo caso con opportuni controlli.... */
    Tree fatherTree = getNode(father(l, t), t);
    if (isEmpty(fatherTree)) {
        // Se il padre è vuoto, sto tentando di rimuovere la radice
        if (t->firstChild == emptyTree) {
            delete t;
            t = emptyTree;
        }
        else{
            return FAIL;
        }
    } 


/* se non sono nella situazione di tentativo di rimozione della
radice, allora chiamo una funzione ausiliaria deleteElemAux
definita ricorsivamente; in deleteElemAux posso fare l'assunzione
di non essere nel caso di tentativo di rimozione della radice, già
trattato prima */
return deleteElemAux(l, t);
}




/*******************************************************************************************************/
// father restituisce l'etichetta del padre del nodo con etichetta l se il nodo esiste nell'albero 
// (o sottoalbero) t e se il padre esiste. 
// Restituisce la costante emptyLabel altrimenti

Label fatherAux(const Label l, const Tree t, Label f){
 Label risultato;
   //se il nodo è la radice
   if(t != emptyTree){
   if(t -> label == l)
   		return f;
   
   		
  

   if(t -> firstChild != emptyTree){
   if(t -> firstChild -> label == l)
   		return t -> label;
   	
   //Se ho un figlio
   	   
   	   Label risultato = fatherAux(l, t->firstChild, t->label); 
	   if(risultato != emptyLabel)
	   		return risultato;
	   }

		risultato = fatherAux(l, t->nextSibling, f);
	   	   if( risultato != emptyLabel)
	   		return risultato;	
	   return emptyLabel;
   }
   
   return emptyLabel;

}


Label tree::father(const Label l, const Tree& t)
{ 
	if( t == emptyTree || t->firstChild == emptyTree){
		return emptyLabel;
	}
	
	return fatherAux(l, t->firstChild, t->label);
	
}



/*******************************************************************************************************/
// children restituisce una lista di Label, contenente le etichette 
// di tutti i figli nell'albero t del nodo etichettato con l
// La lista può essere implementata usando una qualunque delle strutture dati viste a lezione
// (non un Vector!!!): si riusi una implementazione del TDD list, adattandola 
// a elementi di tipo string (nelle precedenti esercitazioni gli elementi erano int)
list::List tree::children(const Label l, const Tree& t)
{


	Tree aux = getNode(l,t);
    list::List lst = list::createEmpty();  
    if(aux -> firstChild == emptyTree)
   		 return lst;
     aux = aux ->firstChild;
    while(aux != emptyTree){
       addBack(aux -> label, lst);
       aux = aux -> nextSibling;
    }
    return lst;
}



/*******************************************************************************************************/
// degree restituisce il numero di archi uscenti dal nodo etichettato con l; restituisce -1 se non esiste 
// nessuna etichetta l nell'albero
int tree::degree(const Label l, const Tree& t)
{
   Tree Aux = getNode(l,t);
   if(Aux -> firstChild == emptyTree)
  	 return -1;
 
  Aux = Aux -> firstChild;
  unsigned int deg = 1;
  while(Aux -> nextSibling != emptyTree){
  	deg++;
  	Aux = Aux -> nextSibling;
  }
  
  return deg;
}



/*******************************************************************************************************/
// ancestors (versione ricorsiva) restituisce una lista di Label, contenente le etichette 
// di tutti gli antenati del nodo l ESCLUSA l'etichetta del nodo stesso
// La lista può essere implementata usando una delle strutture dati viste a lezione
// (non un Vector)
// (può anche non essere ricorsiva la ancestorsR, ma deve fare uso di funzioni ausiliarie ricorsive)
list::List tree::ancestorsR(const Label l, const Tree& t)
{
   list::List lst = list::createEmpty();
   
   if(t == emptyTree)
   		return lst;
   if(father(l, t) == t -> label)
   	  return lst;
   string aux = father(l, t);
   addBack(aux, lst);
   return ancestorsR(aux, t);
}




/*******************************************************************************************************/
// ancestors (versione iterativa) restituisce una lista di Label, contenente le etichette 
// di tutti gli antenati del nodo l ESCLUSA l'etichetta del nodo stesso
// La lista può essere implementata usando una delle strutture dati viste a lezione
// (non un Vector)
list::List tree::ancestorsI(const Label l, const Tree& t)
{
   list::List lst = list::createEmpty();
   string aux = l;
   while(aux != t -> label){
   		aux = father(aux , t);
   		addBack(aux, lst);
   		
   }
   
   return lst;
}



/*******************************************************************************************************/
// leastCommonAncestor restituisce l'etichetta del minimo antenato comune 
// ai nodi etichettati con label1 e label2
Label tree::leastCommonAncestor(const Label label1, const Label label2, const Tree& t)
{
	list::List lst1 = list::createEmpty();
	list::List lst2 = list::createEmpty();
	
	lst1 = ancestorsI(label1, t);
	lst2 = ancestorsI(label2, t);
	
	int size1 = size(lst1);
	int size2 = size(lst2);
	
	for(int i = 0; i < size1; ++i){
		for(int j=0; j < size2; ++j){
			if(get(i,lst1) == get(j,lst2))
				return get(i,lst1);
		}
	}
   return emptyLabel;
}



/*******************************************************************************************************/
// member restituisce true se il nodo etichettato con la label l appartiene all'albero t e false altrimenti
bool tree::member(const Label l, const Tree& t)
{ 
	Tree Aux = getNode(l,t);
	if(Aux == emptyTree)
   		return false;
   	return true;  
}



/*******************************************************************************************************/
// numNodes restituisce il numero di nodi nell'albero t mediante una visita ricorsiva in depthfirst

int numNodesAux(const Tree& t){
	if(isEmpty(t))
    	return -1;
    	
    return  numNodesAux(t -> firstChild) + numNodesAux(t -> nextSibling) + 2;
}


int tree::numNodes(const Tree& t)
{
	if(isEmpty(t))
    	return -1;

    	return numNodesAux(t) +1;
    
}



/*******************************************************************************************************/
// createEmptyTree restituisce l'albero vuoto
Tree tree::createEmpty()
{
   return emptyTree;
}



/*******************************************************************************************************/
// Visualizzazione possibilmente strutturata come visto a lezione


void printTreeAux(const Tree& t, int indent = 0) {
    // Verifica se l'albero è vuoto
    if (t == nullptr) {
        return;
    }

    // Crea l'indentazione basata sul livello corrente
    std::string indentation;
    for (int i = 0; i < indent; ++i) {
        indentation += "| ";
    }

    // Stampa l'indentazione seguita dall'etichetta del nodo corrente
    std::cout << indentation << t->label << '\n';

    // Stampa il primo figlio con un livello di indentazione incrementato
    if (t->firstChild != nullptr) {
        printTreeAux(t->firstChild, indent + 1);
    }

    // Stampa il prossimo fratello con lo stesso livello di indentazione
    if (t->nextSibling != nullptr) {
        printTreeAux(t->nextSibling, indent);
    }
}



void printTree(const Tree& t) {
 printTreeAux(t,0);
    
}




/****************************************************************/
// Questa funzione NON richiede di conoscere come e' fatta la struttura dati che implementa l'albero: usa solo addElem e quindi e' ad 
// un alto livello di astrazione
// Vantaggi: codice compatto, leggibile, riutilizzabile per qualunque implementazione del TDD Tree
// Svantaggi: inefficiente: la addElem cerca ogni volta il nodo con etichetta fatherLabel, mentre basterebbe una chiamata sola per 
// trovarlo e poi si potrebbero attaccare tutti i figli a esso, senza ripetere la dispendiosa ricerca nell'albero; per renderla 
// efficiente dovrei pero' accedere direttamente alla struttura dati chiamando qualche funzione ausiliaria che operi 
// sui nodi dell'albero, rinunciando a scrivere codice modulare, chiaro e ad un ragionevole livello di astrazione... 
// Non esiste un'opzione migliore tra le due: se il codice deve essere efficiente, è opportuno scrivere una funzione ad hoc per 
// una determinata implementazione; se il codice deve essere riutilizzabile, bisogna limitarsi a usare le funzioni offerte dall'
// interfaccia del TDD in modo che la funzione continui ad andare bene anche se cambia l'implementazione
Tree readFromStream(istream& str)
{
    Tree t = createEmpty(); 
    string line;
    Label rootLabel, fatherLabel, childLabel;
    getline(str, line);  
    istringstream instream;            // uso una variabile di tipo istringstream per poter scandire i pezzi di ogni riga usando >>
    instream.clear();
    instream.str(line);
    instream >> rootLabel;             // il primo elemento che si incontra nel file e' l'etichetta della radice, per convenzione su come deve essere fatto il file
    addElem(emptyLabel, rootLabel, t); // la si inserisce nell'albero vuoto, indicando che il padre non c'e' (primo argomento emptyLabel)
    getline(str, line);                // poi si iniziano a scansionare le righe seguenti
    instream.clear();
    instream.str(line);
    while (!str.eof())  
        {        
	instream >> fatherLabel; // in ogni riga del file, il primo elemento e' l'etichetta del nodo padre e gli altri sono le etichette dei figli
        removeBlanksAndLower(fatherLabel); // normalizzo l'etichetta del padre
        while (!instream.eof())            // finche' la riga corrente non e' terminata
            { 
            instream >> childLabel;              // leggo la prossima etichetta
            removeBlanksAndLower(childLabel);    // la normalizzo
            addElem(fatherLabel, childLabel, t); // e la attacco al padre
            }
        getline(str, line);  
        instream.clear();
        instream.str(line);
        }
    str.clear();
    return t;
}



/****************************************************************/
Tree readFromFile(string nome_file)
{
    ifstream ifs(nome_file.c_str()); // apertura di uno stream associato ad un file, in lettura
    if (!ifs) {cout << "\nErrore apertura file, verificare di avere inserito un nome corretto\n"; return createEmpty();}  
    return readFromStream(ifs);
}

