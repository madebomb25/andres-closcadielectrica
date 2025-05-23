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
ParFreq::ParFreq()
{
    word = "";
    freq = 0;
}

/*
Pre: cierto.
Post: crea un objeto ParFreq con los atributos pasados por
parámetro.
*/
ParFreq::ParFreq(const string &word, int freq)
{
    this->word = word;
    this->freq = freq;
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

/* Pre: cierto
   Post: se asigna a 'this->word' el string que referencia 'word'.
*/
void ParFreq::setWord(const string &word)
{
    this->word = word;
}

/* Pre: cierto
   Post: se asigna a 'this->freq' el entero 'freq'.
*/
void ParFreq::setFreq(int freq)
{
    this->freq = freq;
}

//*********************************************************
// Consultors
//*********************************************************

/* Pre: Cierto */
/* Post: El resultado es la palabra del parámetro implícito */
string ParFreq::getWord() const
{
    return word;
}

/* Pre: Cierto */
/* Post: El resultado es la frecuencia del parámetro implícito */
int ParFreq::getFreq() const
{
    return freq;
}

/* Pre: Cierto  */
/* Post: El resultado indica si la palabra del parámetro implícito
es igual a la palabra del ParFreq recibido por parámetro */
bool ParFreq::operator==(const ParFreq &pf) const
{
    return word == pf.word;
}

/* Pre: Cierto. */
/* Post: El resultado indica si la palabra del parámetro implícito
es menor a la palabra del ParFreq recibido por parámetro */
bool ParFreq::operator<(const ParFreq &pf) const
{
    return word < pf.word;
}
