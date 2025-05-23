#include "Diccionari.hpp"
#include <stdexcept>
using namespace std;

//*********************************************************
// Constructores
//*********************************************************

/* Pre: cierto.
   Post: genera un diccionario vacío, por lo que 'this->dictionary'
   será un BST vacío debido a su constructor por defecto.
*/
Diccionari::Diccionari() {};

//*********************************************************
// Destructor
//*********************************************************

/* Borra automáticamente el objeto al salir de un ámbito de
visibilidad local. */
Diccionari::~Diccionari() {};

//*********************************************************
// Modificadores
//*********************************************************

/* Pre: 'this->dictionary' es un BST<ParFreq> vacío.
   Post: 'this->dictionary' contendrá un BST balanceado con las
   palabras leidas del diccionario al que apunta la ruta 'path'.
*/
void Diccionari::loadDictionary(const string &path)
{
    // El BST ya estará creado vacío por el constructor por defecto.

    vector<ParFreq> words_and_freqs;

    fillVectorFromFile(path, words_and_freqs);

    if (words_and_freqs.size() > 1)
        sort(words_and_freqs.begin(), words_and_freqs.end());

    buildDictionary(dictionary, words_and_freqs, 0, int(words_and_freqs.size()) - 1);
}

//*********************************************************
// Consultores
//*********************************************************


/* IMPORTANTE: Tanto para la busqueda (si existe una palabra)
   como la obtención de datos en el BST usamos el métod 'find()',
   por lo que la implementación de un método 'has()' que busque si una palabra
   existe es innecesario, ya que tendrá la misma eficiencia que 'getFreq()'.

   Si la frecuencia devuelta es 0 (valor asignado por defecto en el método), 
   la palabra no existe en el diccionario.

   Pre: cierto.
   Post: devuelve la frecuencia de la palabra encontrada en
   el diccionario. Si no existe la palabra, devolverá 0. No existen
   palabras cuya frecuencia sea igual o menor a 0.
*/
int Diccionari::getFreq(const string &word) const
{
    /* IMPLEMENTACIÓN TEMPRANA: no tiene en cuenta si
    coinciden en frecuencia en hacer la búsqueda. */
    ParFreq pf(word, 0);
    return this->dictionary.find(pf).second.getFreq();
}

//*********************************************************
// Lectura y escritura
//*********************************************************

/* Pre: Cierto.
   Post: Si el path recibido per parámetro está asociado a un
   archivo, lee el archivo de pares (palabra, frecuencia), los ordena
   alfabéticamente y los distribuye en un BST balanceado.
*/
void Diccionari::fillVectorFromFile(const string &path, vector<ParFreq> &words_and_freqs)
{
    ifstream fitxer(path);
    if (not fitxer.is_open())
    {
        throw runtime_error("Error en obrir el fitxer-diccionari: " + path);
    }

    string paraula;
    int frequencia;
    while (fitxer >> paraula >> frequencia)
    {
        ParFreq pf(paraula, frequencia);
        words_and_freqs.push_back(pf);
    }
}

//*********************************************************
// Métodos auxiliares
//*********************************************************

/* Pre: Cierto.
   Post: t contiene todos los elementos de v en una estructura BST
   balanceada.
*/
void Diccionari::buildDictionary(BST<ParFreq> &t, vector<ParFreq> &v, int inicial, int final)
{
    // CD: en el caso de que el subvector esté vacío (inicial > final),
    // no hace falta hacer nada
    if (inicial <= final)
    {
        // CR: insertar el elemento central
        int central = inicial + (final - inicial) / 2;
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
