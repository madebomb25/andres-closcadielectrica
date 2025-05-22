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
	string alphabet;

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
	// Constructores
	//*********************************************************

	/* Pre: Cierto
	   Post: Crea un objeto de la clase Diccionari con un BST
	   vacío.
	*/
	Diccionari();

	//*********************************************************
	// Destructor
	//*********************************************************

	/* Borra automáticamente el objeto al salir de un ámbito de
	 visibilidad local. */
	~Diccionari();

	//*********************************************************
	// Modificadors
	//*********************************************************

	void loadDictionary(const string &path);

	//*********************************************************
	// Consultors
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
	int getFreq(const string &word) const;

	//*********************************************************
	// Lectura y escritura
	//*********************************************************

	/* Pre: Cierto
	   Post: Si el path recibido per parámetro está asociado a un
	   archivo, lee el archivo de pares (palabra, frecuencia), los ordena
	   alfabéticamente y los distribuye en un BST balanceado.
	*/
	void fillVectorFromFile(const string &path, vector<ParFreq> &words_and_freqs);
};
#endif
