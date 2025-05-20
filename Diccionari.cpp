#include "Diccionari.hpp"
#include <stdexcept>
using namespace std;

/*
Hemos declarado primero los métodos de la clase antes que los constructores
debido a que estos requieren métodos de apoyo para simplificar la clase.
*/

//*********************************************************
// Consultores
//*********************************************************

/* Pre: Cierto  */
/* Post: El resultado indica si el diccionario contiene la
palabra recibida por parámetro */	   
bool Diccionari::conte(const string &paraula) const { 
    /* IMPLEMENTACIÓN TEMPRANA: no tiene en cuenta
    si coinciden en frecuencia en hacer la búsqueda. */
    ParFreq pf(paraula, 0);
    return this->dictionary.find(pf).first; 
}

/* Pre: La palabra recibida por parámetro está en el
diccionario */
/* Post: El resultado es la frecuencia que aparece en el
diccionario de la palabra recibida por parámetro */	 
int Diccionari::getFrequencia(const string &paraula) const {
    /* IMPLEMENTACIÓN TEMPRANA: no tiene en cuenta si 
    coinciden en frecuencia en hacer la búsqueda. */
    ParFreq pf(paraula, 0); 
    return this->dictionary.find(pf).second.getFrequencia(); 
}

//*********************************************************
//Lectura y escritura
//*********************************************************

/* Pre: Cierto */
/* Post: Si el path recibido per parámetro está asociado a un
archivo, lee el archivo de pares (palabra, frecuencia), los ordena
alfabéticamente y los distribuye en un BST balanceado. */
void Diccionari::fillVectorFromFile(const string &path, vector<ParFreq> &words_and_freqs)
{
    ifstream fitxer(path);
    if (not fitxer.is_open()) {
        throw runtime_error("Error en obrir el fitxer-diccionari: " + path);
    }

    string paraula;
	int frequencia;
    while (fitxer >> paraula >> frequencia) {  
        ParFreq pf(paraula, frequencia);
        words_and_freqs.push_back(pf);        
    }
}

//*********************************************************
//Métodos auxiliares
//*********************************************************

/* Pre: Cierto */
/* Post: t contiene todos los elementos de v en una estructura BST 
balanceada */
void Diccionari::buildDictionary(BST<ParFreq> &t, vector<ParFreq> &v, int inicial, int final) 
{
    // CD: en el caso de que el subvector esté vacío (inicial > final),
    // no hace falta hacer nada 
    if (inicial <= final) {
        // CR: insertar el elemento central
        int central = inicial + (final-inicial) / 2;
        t.insert(v[central]);

        buildDictionary(t, v, inicial, central - 1); 
        /* HI: se han insertado siguiendo la lógica de un BST todos
        los elementos de v[inicial..central] en el hijo izquierdo de t */
        /* Fita: número de elementos del subvector v[inicial..central - 1] */
        buildDictionary(t, v, central + 1, final); 
        /* HI: se han insertado siguiendo la lógica de un BST todos
        los elementos de v[inicial..central] en el hijo derecho de t */
        /* Fita: número de elementos del subvector v[central + 1..final] */
    }
}

//*********************************************************
// Constructores
//*********************************************************

/* Pre: el archivo al que apunta 'path' debe contener las palabras
   junto a su frecuencia.
   Post: Crea un objeto de la clase Diccionari con un BST 
   vacío. 
*/
Diccionari::Diccionari(const string &path) {

    // El BST ya estará creado vacío por el constructor por defecto.

    vector<ParFreq> words_and_freqs;

    fillVectorFromFile(path, words_and_freqs);

    if (words_and_freqs.size() > 1) 
        sort(words_and_freqs.begin(), words_and_freqs.end());

    buildDictionary(dictionary, words_and_freqs, 0, int(words_and_freqs.size())-1);
}

//*********************************************************
// Destructor
//*********************************************************

/* Borra automáticamente el objeto al salir de un ámbito de 
visibilidad local. */   
Diccionari::~Diccionari() {}; 

