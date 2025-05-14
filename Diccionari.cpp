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

    sort(dictionary_vector.begin(), dictionary_vector.end()); 
    construeixArbre(dictionary, dictionary_vector); 
}


//*********************************************************
//Métodos auxiliares
//*********************************************************

/* Pre: ? */
/* Post: t contiene todos los elementos de v en una estructura BST 
balanceada */
void Diccionari::construeixArbre(BST<ParFreq> &t, vector<ParFreq> &v) {

}
