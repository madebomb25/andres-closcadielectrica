#ifndef CORRECTOR_HPP
#define CORRECTOR_HPP
#include "Diccionari.hpp"
#include "ParFreq.hpp"
#include "sstream"
#include "fstream"
using namespace std;

class Corrector
{
	// Tipo de módulo: datos
	// Descripción del tipo: Almacena un diccionario de pares (palabra, frecuencia)
	//						 y proporciona métodos para leer un texto plano de un archivo de
	//						 texto, corregirlo ortográficamente y escribirlo corregido en
	//						 un archivo de texto. La corrección ortográfica de una palabra
	//						 se obtiene generando palabras candidatas a distancia d'edición 1,
	//						 que se encuentren en el diccionario y dando como resultado la
	//						 de mayor frecuencia.
	//						 También almacena y escribe en un archivo de registro los
	//						 cambios realizados en el archivo original.

public:
	//*********************************************************
	// Constructores
	//*********************************************************

	/* Pre: Cierto 
	   Post: Si 'path' está associado a un archivo, lee
	   las entradas del archivo y llena el diccionario del corrector
	   que crea; si no, muestra un mensaje d'error.
	*/
	Corrector(const string &path); 

	//*********************************************************
	// Métodos auxiliares
	//*********************************************************

	/* Pre: cierto.
	   Post: si la frecuencia de la palabra variante es mayor a la frecuencia
	   contenida en el objeto 'current_best', entonces modificamos el objeto
	   cambiando la palabra contenida por 'v_word' y la frecuencia por 'v_freq'.
	*/
	void setIfBestVariant(ParFreq &current_best, const string &v_word, int v_freq);

	/* Pre: cierto.
   	   Post: se generan variantes de 'word' insertando letras del alfabeto
       'this->alphabet'. Para cada variante, se busca en el diccionario
       y en caso de que exista se guarda temporalmente, donde al final del método
       devolveremos un PairFreq con la palabra encontrada que tuviese mayor frecuencia.

       Si para todas las variantes no hemos encontrado ninguna palabra en el diccionario,
       devolvemos un ParFreq cuya palabra será la original y con frecuencia 0.
	*/
	ParFreq insert(const string &word);

	/* Pre: cierto.
   	   Post: se generan variantes de 'word' borrando de esta alguna de sus letras. 
       Cada variante se busca en el diccionario y en caso de que exista se guarda 
       temporalmente, donde al final del método devolveremos un PairFreq con 
       la palabra encontrada que tuviese mayor frecuencia.

       Si para todas las variantes no hemos encontrado ninguna palabra en el diccionario,
       devolvemos un ParFreq cuya palabra será la original y con frecuencia 0.
	*/
	ParFreq delLetter(const string &word);

	/* Pre: cierto.
   	   Post: se generan variantes de 'word' sustituyendo cada letra por letras del alfabeto
       'this->alphabet'. Cada variante se busca en el diccionario y en caso de que exista 
   	   se guarda temporalmente, donde al final del método devolveremos un PairFreq con 
	   la palabra encontrada que tuviese mayor frecuencia.

   	   Si para todas las variantes no hemos encontrado ninguna palabra en el diccionario,
   	   devolvemos un ParFreq cuya palabra será la original y con frecuencia 0.
	*/
	ParFreq subs(const string &word);

	/* Pre: cierto.
   	   Post: se generan variantes de 'word' intercambiando pares de letras adyacentes. 
	   Cada variante se busca en el diccionario y en caso de que exista se guarda 
   	   temporalmente, donde al final del método devolveremos un PairFreq con la palabra 
   	   encontrada que tuviese mayor frecuencia.

   	   Si para todas las variantes no hemos encontrado ninguna palabra en el diccionario,
   	   devolvemos un ParFreq cuya palabra será la original y con frecuencia 0.
	*/
	ParFreq trans(const string &word);

	/* Pre: la palabra no contiene los caracteres: ".,!?;".
   	   Post: se busca si la palabra existe en el diccionario. Si existe, no se
	   hace nada y se devuelve la misma palabra. En caso de no existir, se
   	   generan variantes de la palabra original para buscar la coincidencia en el
   	   diccionario con la mayor frecuencia y devolver
	*/
	string fixWord(const string &word);

	//*********************************************************
	// Modificadores
	//*********************************************************

	/* Pre: Cierto */
	/* Post: Si rutaInput está associado a un archivo, lee el
	 texto del archivo línea a línea, corrige cadauna de las
	 palabras de cada línea, las escribe en el archivo associado a
	 rutaOutput i escribe en el archivo associado a rutaLog los cambios
	 que haya hecho; si no, muestra un mensaje de error */
	void processaText(const string &rutaInput, const string &rutaOutput, const string &rutaLog);

	//...

	//...

	//*********************************************************
	// Lectura y escritura
	//*********************************************************

	/* Pre: Cierto */
	/* Post: Se han escrito en el archivo associado a rutaLog todas
	 las correcciones hechas al texto de entrada siendo el formato de
	 cada línea palabra_original -> palabra_corregida */
	void bolcaRegistre(const string &rutaLog);

private:
	// IMPLEMENTACIÓ DE LA CLASSE Corrector
	// (definició del nom i tipus de cada atribut)
	// (poden definir-se mètodes privats que actuïn com a funcions auxiliars)

	Diccionari dictionary;
	string alphabet;
};

#endif