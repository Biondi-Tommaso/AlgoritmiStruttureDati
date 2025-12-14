#include "dictionary.h"

#include <math.h> // sqrt()

using namespace dict;

struct dict::cell {
    Elem elem;
    cell* next;
};


/****************************************************************/
/*              FUNZIONE NON IMPLEMENTATA                       */
/****************************************************************/
int h1(Key s) // funzione di hash che considera unicamente il valore ascii del primo carattere della chiave (se esiste) e restituisce il resto della divisione di tale valore per tableDim 
{
 // implementare la funzione richiesta e modificare il return 
 return s[0]%tableDim;
}


/****************************************************************/
/*              FUNZIONE NON IMPLEMENTATA                       */
/****************************************************************/
int h2(Key s) // funzione di hash che somma il codice ascii di ogni carattere nella chiave e restituisce il resto della divisione di tale somma per tableDim 
{
 // implementare la funzione richiesta e modificare il return 
	int somma = 0;
	for(unsigned int i = 0; i < s.length(); ++i){
		somma += int(s[i]);
	}			   

 return somma%tableDim;
}


/****************************************************************/
/*              FUNZIONE NON IMPLEMENTATA                       */
/****************************************************************/
int h3(string str) {
  // Valore hash iniziale
  unsigned int hash = 0;

  // Per ogni carattere nella stringa
  for (char c : str) {
    // Combina il valore hash con il codice ASCII del carattere
    hash = ((hash * 31) + c) % tableDim;
  }

  // Restituisci il valore hash nel range 0-1000
  return hash%(tableDim);
}



/****************************************************************/
/*    FUNZIONE DA MODIFICARE PER FARE ESPERIMENTI DIVERSI       */
/****************************************************************/
int h(Key s)
{
   return h3(s); // modificare questa chiamata per sperimentare l'utilizzo delle funzioni di hash h1, h2, h3, definite prima
}


/****************************************************************/
/*              FUNZIONE NON IMPLEMENTATA                       */
/****************************************************************/
Error dict::deleteElem(const Key k, Dictionary &s) {
    // Trova l'indice corrispondente nella tabella hash
    int index = h(k);
    Bucket lista = s[index];
    Bucket prev = nullptr;

    // Cerca l'elemento da eliminare nella lista
    while (lista != nullptr && lista->elem.key != k) {
        prev = lista;
        lista = lista->next;
    }

    // Se l'elemento non è stato trovato
    if (lista == nullptr)
        return FAIL;

    // Se l'elemento da eliminare è il primo della lista
    if (prev == nullptr) {
        s[index] = lista->next;
    } else {
        prev->next = lista->next;
    }

    // Libera la memoria della cella eliminata
    delete lista;

    return OK;
}

Error dict::insertElem(const Key k, const Value v, Dictionary &s) {
    // Trova l'indice corrispondente nella tabella hash
    int index = h(k);
    Bucket lista = s[index];

    // Cerca valori duplicati nella lista e restituisci FAIL se l'elemento è già presente
    while (lista != nullptr) {
        if (lista->elem.key == k)
            return FAIL;
        lista = lista->next;
    }

    // Se non è ancora presente l'elemento
    // Crea la struct Elem
    Elem e;
    e.key = k;
    e.value = v;

    // Crea la nuova cella
    cell *nuovo = new cell;
    nuovo->elem = e;
    nuovo->next = s[index];
    s[index] = nuovo;

    return OK;
}




/****************************************************************/
Dictionary dict::createEmptyDict()
{
   Bucket* d = new Bucket[tableDim];
   for (int i=0; i < tableDim; ++i)
      d[i]=emptyBucket;
   return d;
}


Value dict::search(const Key k, const Dictionary &s)
{
	Bucket lista = s[h(k)];
   	while(lista != nullptr){
   		if(lista->elem.key == k)
   			return lista->elem.value;
   		lista = lista->next;
   	}
  return emptyValue;  	
}

/****************************************************************/
Dictionary readFromFile(string nome_file)
{
    ifstream ifs(nome_file.c_str()); // apertura di uno stream associato ad un file, in lettura
    if (!ifs) {cout << "\nErrore apertura file, verificare di avere inserito un nome corretto\n"; return createEmptyDict();}  
    return readFromStream(ifs);
}


/****************************************************************/
Dictionary readFromStdin()
{
    cout << "\nInserire una sequenza di linee che rispettano la sintassi key: value.<enter>\nDigitare CTRL^ D per terminare l'inserimento\n";
    Dictionary d = readFromStream((std::cin));
    // Questa serve per aggirare un bug di alcune versioni attuali di glibc.
    clearerr(stdin);
    return d;
}


/****************************************************************/
Dictionary readFromStream(istream& str)
{
    Dictionary d = createEmptyDict();     
    string key, kcopy;
    string value;
    getline (str, key, ':'); 
    getline (str, value); 
    while (!str.eof())  
        {     
        kcopy = key;
        removeBlanksAndLower(kcopy);   
        insertElem(kcopy, value, d); // FINCHE' NON IMPLEMENTATE LA INSERTELEM, NON PUO' FUNZIONARE CORRETTAMENTE: la insertElem e' la prima funzione che dovete implementare
        getline (str, key, ':'); 
        getline (str, value); 
        }
    str.clear();
    return d;
}


/****************************************************************/
int printBucket(Bucket b) // stampa il contenuto di un bucket e restituisce il numero di elementi contenuti nel bucket stesso
{  
   int counter = 0;
   while(b!=emptyBucket) {
        counter++;
        cout << (b->elem).key << ": " << (b->elem).value << "\n"; 
	b=b->next;
	}
   return counter;	
}


/****************************************************************/
void print(const Dictionary &s)
// stampa il contenuto del dizionario ed anche informazioni su come sono stati organizzati gli elementi
{
int bucketDim[tableDim];
int totalElem = 0;
for (unsigned int i=0; i<tableDim; ++i)
   {
    cout << "\nBucket " << i << "\n\n";
    bucketDim[i] = printBucket(s[i]);
    totalElem += bucketDim[i]; 
   }
float means = totalElem/(float)tableDim;
float standardDevSum = 0;
for (unsigned int i=0; i<tableDim; ++i)
     standardDevSum += (bucketDim[i]-means)*(bucketDim[i]-means);
   
/* Lo scarto tipo, deviazione standard, o scarto quadratico medio e' un indice di dispersione statistico, vale a dire una stima della variabilita' di una popolazione di dati o di una variabile casuale.
Lo scarto tipo e' uno dei modi per esprimere la dispersione dei dati intorno ad un indice di posizione, quale puo' essere, ad esempio, la media aritmetica. */

cout << "\n===STATISTICHE SULL'ORGANIZZAZIONE DEL DIZIONARIO===\n";

for (unsigned int i=0; i<tableDim; ++i)
   cout << "\nBucket " << i << ": " << bucketDim[i] << " elementi";

cout << "\nIl numero totale di elementi memorizzati e' " << totalElem;
cout << "\nIl numero di bucket nel dizionario e' " << tableDim;
if (tableDim != 0) cout << "\nIl numero atteso di elementi per bucket e' " << means << "\nLa deviazione standard e' " << sqrt(standardDevSum/tableDim);
}
