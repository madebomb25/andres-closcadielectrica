#ifndef PARFREQ_HPP
#define PARFREQ_HPP
#include <string>
using namespace std;

class ParFreq
{
	// Tipo de módulo: datos
	// Descripción del tipo: Representa una palabra con su frecuencia
	//						de aparición en un corpus grande.

public:

	//*********************************************************
	// Constructores
	//*********************************************************

	/*
	Pre: cierto.
	Post: crea un objeto ParFreq con el primer atributo como una string vacía
	y el segundo atributo inicializado a 0.
	*/
	ParFreq();

	/*
	Pre: cierto.
	Post: crea un objeto de tipo ParFreq con los atributos pasados por
	parámetro.
	*/
	ParFreq(const string &word, int freq);

	//*********************************************************
	// Destructores
	//*********************************************************

	/*
	 Borra automáticamente el objeto al salir de un ámbito de
	 visibilidad local.
	*/
	~ParFreq();

	//*********************************************************
	// Modificadores
	//*********************************************************

	/* Pre: cierto
	   Post: se asigna a 'this->word' el string que referencia 'word'.
	*/
	void setWord(const string &word);

	/* Pre: cierto
	   Post: se asigna a 'this->freq' el entero 'freq'.
	*/
	void setFreq(int freq);

	//*********************************************************
	// Consultores
	//*********************************************************

	/* Pre: Cierto */
	/* Post: El resultado es la palabra del parámetro implícito */
	string getWord() const;

	/* Pre: Cierto */
	/* Post: El resultado es la frecuencia del parámetro implícito */
	int getFreq() const;

	/* Pre: Cierto  */
	/* Post: El resultado indica si la palabra del parámetro implícito
	es igual a la palabra del ParFreq recibido por parámetro */
	bool operator==(const ParFreq &pf) const;

	/* Pre: Cierto. */
	/* Post: El resultado indica si la palabra del parámetro implícito
	es menor a la palabra del ParFreq recibido por parámetro */
	bool operator<(const ParFreq &pf) const;

private:
	string word;
	int freq;
};
#endif
