#include "ParFreq.hpp"
using namespace std;

//*********************************************************
// Constructores
//*********************************************************

/* 
Pre: cierto. 
Post: crea un objeto ParFreq con el primer atributo como una string vacía
y el segundo atributo inicializado a 0.
*/
ParFreq::ParFreq() {
	word = "";
	frequency = 0; 
}

/* 
Pre: cierto. 
Post: crea un objeto ParFreq con los atributos pasados por 
parámetro. 
*/
ParFreq::ParFreq(string word, int frequency) {
    this->word = word; 
    this->frequency = frequency; 
}

//*********************************************************
// Destructores
//*********************************************************
	   
/* 
Borra automáticamente el objeto al salir de un ámbito de 
visibilidad local.   
*/
ParFreq::~ParFreq() {};

//*********************************************************
// Modificadores
//*********************************************************
	   
//...


//*********************************************************
// Consultors
//*********************************************************

/* Pre: Cierto */
/* Post: El resultado es la palabra del parámetro implícito */
string ParFreq::getParaula() const {
    return word; 
}

/* Pre: Cierto */
/* Post: El resultado es la frecuencia del parámetro implícito */
int ParFreq::getFrequencia() const {
    return frequency;
}

/* Pre: Cierto  */
/* Post: El resultado indica si la palabra del parámetro implícito
es igual a la palabra del ParFreq recibido por parámetro */ 	   
bool ParFreq::operator==(const ParFreq &pf) const {
    return word == pf.word;
}

/* Pre: Cierto. */
/* Post: El resultado indica si la palabra del parámetro implícito 
es menor a la palabra del ParFreq recibido por parámetro */
bool ParFreq::operator<(const ParFreq &pf) const {
    return word < pf.word; 
}
