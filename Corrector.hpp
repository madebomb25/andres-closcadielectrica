#ifndef CORRECTOR_HPP
#define CORRECTOR_HPP
#include "Diccionari.hpp"
#include "ParFreq.hpp"
using namespace std;

class Corrector
{
	// Tipus de mòdul: dades
	// Descripció del tipus: Emmagatzema un diccionari de parells (paraula, freqüència)
	//						 i proporciona mètodes per llegir un text pla d'un fitxer de
	//						 text, corregir-lo ortogràficament i escriure'l corregit en
	//						 un fitxer de text. La correcció ortogràfica d'una paraula
	//						 s'obté generant paraules candidates a distància d'edició 1,
	//						 que es trobin en el diccionari i donant com a resultat la
	//						 de major freqüència.
	//						 També emmagatzema i escriu en un fitxer de registre els
	//						 canvis fets en el fitxer original.

public:
	//*********************************************************
	// Constructors
	//*********************************************************

	/* Pre: Cert
	   Post: Si 'path' està associat a un fitxer, llegeix
	   les entrades del fitxer i omple el diccionari del corrector
	   que crea; altrament, mostra un missatge d'error.
	*/
	Corrector(const string &path); // carrega el diccionari (BST)

	//*********************************************************
	// Métodos auxiliares
	//*********************************************************

	/* Pre: cierto.
	   Post: si la frecuencia de la palabra variante es mayor a la frecuencia
	   contenida en el objeto 'current_best', entonces modificamos el objeto
	   cambiando la palabra contenida por 'v_word' y la frecuencia por 'v_freq'.
	*/
	void setIfBestVariant(PairFreq &current_best, const string &v_word, int v_freq);

	/* Pre: cierto.
   	   Post: se generan variantes de 'word' insertando letras del alfabeto
       'this->alphabet'. Para cada variante, se busca en el diccionario
       y en caso de que exista se guarda temporalmente, donde al final del método
       devolveremos un PairFreq con la palabra encontrada que tuviese mayor frecuencia.

       Si para todas las variantes no hemos encontrado ninguna palabra en el diccionario,
       devolvemos un ParFreq cuya palabra será la original y con frecuencia 0.
	*/
	PairFreq insert(const string &word);

	/* Pre: cierto.
   	   Post: se generan variantes de 'word' borrando de esta alguna de sus letras. 
       Cada variante se busca en el diccionario y en caso de que exista se guarda 
       temporalmente, donde al final del método devolveremos un PairFreq con 
       la palabra encontrada que tuviese mayor frecuencia.

       Si para todas las variantes no hemos encontrado ninguna palabra en el diccionario,
       devolvemos un ParFreq cuya palabra será la original y con frecuencia 0.
	*/
	PairFreq delLetter(const string &word);

	/* Pre: cierto.
   	   Post: se generan variantes de 'word' sustituyendo cada letra por letras del alfabeto
       'this->alphabet'. Cada variante se busca en el diccionario y en caso de que exista 
   	   se guarda temporalmente, donde al final del método devolveremos un PairFreq con 
	   la palabra encontrada que tuviese mayor frecuencia.

   	   Si para todas las variantes no hemos encontrado ninguna palabra en el diccionario,
   	   devolvemos un ParFreq cuya palabra será la original y con frecuencia 0.
	*/
	PairFreq subs(const string &word);

	/* Pre: cierto.
   	   Post: se generan variantes de 'word' intercambiando pares de letras adyacentes. 
	   Cada variante se busca en el diccionario y en caso de que exista se guarda 
   	   temporalmente, donde al final del método devolveremos un PairFreq con la palabra 
   	   encontrada que tuviese mayor frecuencia.

   	   Si para todas las variantes no hemos encontrado ninguna palabra en el diccionario,
   	   devolvemos un ParFreq cuya palabra será la original y con frecuencia 0.
	*/
	PairFreq trans(const string &word);

	/* Pre: la palabra no contiene los caracteres: ".,!?;".
   	   Post: se busca si la palabra existe en el diccionario. Si existe, no se
	   hace nada y se devuelve la misma palabra. En caso de no existir, se
   	   generan variantes de la palabra original para buscar la coincidencia en el
   	   diccionario con la mayor frecuencia y devolver
	*/
	string fixWord(const string &word)

	//*********************************************************
	// Modificadors
	//*********************************************************

	/* Pre: Cert */
	/* Post: Si rutaInput està associat a un fitxer, llegeix el
	 text del fitxer línia a línia, corregeix cadascuna de les
	 paraules de cada línia, les escriu al fitxer associat a
	 rutaOutput i escriu al fitxer associat a rutaLog els canvis
	 que hagi fet; altrament, mostra un missatge d'error */
	void processaText(const string &rutaInput, const string &rutaOutput, const string &rutaLog);

	//...

	//...

	//*********************************************************
	// Lectura y escritura
	//*********************************************************

	/* Pre: Cert */
	/* Post: S'han escrit al fitxer associat a rutaLog totes
	 les correccions fetes al text d'entrada sent el format de
	 cada línia paraula_original -> paraula_corregida */
	void bolcaRegistre(const string &rutaLog);

private:
	// IMPLEMENTACIÓ DE LA CLASSE Corrector
	// (definició del nom i tipus de cada atribut)
	// (poden definir-se mètodes privats que actuïn com a funcions auxiliars)

	Diccionari dictionary;
	string alphabet;
};

#endif