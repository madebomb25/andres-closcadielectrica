#ifndef DICCIONARI_HPP
#define DICCIONARI_HPP
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include "BST.hpp"
#include "ParFreq.hpp"
using namespace std;

class Diccionari
{
	// Tipus de mòdul: dades
	// Descripció del tipus: Representa el conjunt d'entrades (paraules i freqüència)
	// d'un diccionari.

private:
	// IMPLEMENTACIÓ DE LA CLASSE Diccionari
	// (definició del nom i tipus de cada atribut)
	// (poden definir-se mètodes privats que actuïn com a funcions auxiliars)
	BST<ParFreq> dictionary;

	//*********************************************************
	// Métodos auxiliares
	//*********************************************************

	/* Pre: Cierto
	   Post: t contiene todos los elementos de v en una estructura BST
	   balanceada 
	*/
	void buildDictionary(BST<ParFreq> &t, vector<ParFreq> &v, int inicial, int final);

public:
	//*********************************************************
	// Modificadors
	//*********************************************************

	/* ELIMINADO EL MÉTODO insereix de FORMA PROVISIONAL */

	//*********************************************************
	// Consultors
	//*********************************************************

	/* Pre: Cierto */
	/* Post: El resultado indica si el diccionario contiene la
	 palabra recibida por parámetro */
	bool conte(const string &paraula) const; // cerca en el BST

	/* Pre: La palabra recibida por parámetro está en el
	 diccionario */
	/* Post: El resultado es la frecuencia que aparece en el
	 diccionario de la palabra recibida por parámetro */
	int getFrequencia(const string &paraula) const;

	//*********************************************************
	// Lectura y escritura
	//*********************************************************

	/* Pre: Cierto
	   Post: Si el path recibido per parámetro está asociado a un
	   archivo, lee el archivo de pares (palabra, frecuencia), los ordena
	   alfabéticamente y los distribuye en un BST balanceado.
	*/
	void fillVectorFromFile(const string &path, vector<ParFreq> &words_and_freqs);

	//*********************************************************
	// Constructores
	//*********************************************************

	/* Pre: Cierto
	   Post: Crea un objeto de la clase Diccionari con un BST
	   creado en base al archivo al que apunta 'path'. 
	*/
	Diccionari(const string &path);

	//*********************************************************
	// Destructor
	//*********************************************************

	/* Borra automáticamente el objeto al salir de un ámbito de
	 visibilidad local. */
	~Diccionari();
};
#endif
