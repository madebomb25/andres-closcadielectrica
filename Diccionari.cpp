#include "Diccionari.hpp"
#include <stdexcept>
using namespace std;

//*********************************************************
// Constructores
//*********************************************************

/* Pre: Cierto */
/* Post: Crea un objeto de la clase Diccionari con un BST 
vacío. */
Diccionari::Diccionari() {
    BST<ParFreq>(); 
}
//*********************************************************
// Destructor
//*********************************************************

/* Borra automáticamente el objeto al salir de un ámbito de 
visibilidad local. */   
Diccionari::~Diccionari() {}; 


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
    return dictionary.find(pf).first; 
}

/* Pre: La palabra recibida por parámetro está en el
diccionario */
/* Post: El resultado es la frecuencia que aparece en el
diccionario de la palabra recibida por parámetro */	 
int Diccionari::getFrequencia(const string &paraula) const {
    /* IMPLEMENTACIÓN TEMPRANA: no tiene en cuenta si 
    coinciden en frecuencia en hacer la búsqueda. */
    ParFreq pf(paraula, 0); 
    return dictionary.find(pf).second.getFrequencia(); 
}

//*********************************************************
//Lectura y escritura
//*********************************************************

/* Pre: Cierto */
/* Post: Si el path recibido per parámetro está asociado a un
archivo, lee el archivo de pares (palabra, frecuencia), los ordena
alfabéticamente y los distribuye en un BST balanceado. */
void Diccionari::construeixDiccionari(const string &path)
{
    ifstream fitxer(path);
    if (not fitxer.is_open()) {
        throw runtime_error("Error en obrir el fitxer-diccionari: " + path);
    }

    string paraula;
	int frequencia;
    while (fitxer >> paraula >> frequencia) {  
        ParFreq pf(paraula, frequencia);
        dictionary_vector.push_back(pf);        
    }
    if (dictionary_vector.size() > 1) 
        sort(dictionary_vector.begin(), dictionary_vector.end()); 
    construeixArbre(dictionary, dictionary_vector); 
}


//*********************************************************
//Métodos auxiliares
//*********************************************************

/* Pre: Cierto */
/* Post: t contiene todos los elementos de v en una estructura BST 
balanceada */
void Diccionari::construeixBST(BST<ParFreq> &t, vector<ParFreq> &v, int inicial, int final) {
    // CD: en el caso de que el subvector esté vacío (inicial > final),
    // no hace falta hacer nada 
    if (inicial <= final) {
        // CR: insertar el elemento central
        int central = inicial + (final-inicial) / 2;
        t.insert(v[central]);

        construeixBST(t, v, inicial, central - 1); 
        /* HI: se han insertado siguiendo la lógica de un BST todos
        los elementos de v[inicial..central] en el hijo izquierdo de t */
        /* Fita: número de elementos del subvector v[inicial..central - 1] */
        construeixBST(t, v, central + 1, final); 
        /* HI: se han insertado siguiendo la lógica de un BST todos
        los elementos de v[inicial..central] en el hijo derecho de t */
        /* Fita: número de elementos del subvector v[central + 1..final] */
    }
}

/* Pre: v no es un vector vacío */
/* Post: t contiene todos los elementos de v en una estructura BST 
balanceada */
void Diccionari::construeixArbre(BST<ParFreq> &t, vector<ParFreq> &v) {
    construeixBST(t, v, 0, int(v.size())-1); // Método auxiliar
}
