#include "Corrector.hpp"
using namespace std;

// IMPLEMENTACIÓ DE LA CLASSE Corrector
// (implementació de tots els mètodes especificats en el fitxer Corrector.hpp)

//*********************************************************
// Constructores
//*********************************************************

/* Pre: Cierto 
Post: Si 'path' está associado a un archivo, lee
las entradas del archivo y llena el diccionario del corrector
que crea; si no, muestra un mensaje d'error.
*/
Corrector::Corrector(const string &path)
{
	// Cargamos el diccionario con las palabras del archivo diccionario.
	this->dictionary.loadDictionary(path);
	this->alphabet = "abcdefghijklmnopqrstuvwxyz";
}

//*********************************************************
// Métodos auxiliares
//*********************************************************

/* Pre: cierto.
   Post: si la frecuencia de la palabra variante es mayor a la frecuencia
   contenida en el objeto 'current_best', entonces modificamos el objeto
   cambiando la palabra contenida por 'v_word' y la frecuencia por 'v_freq'.
*/
void Corrector::setIfBestVariant(ParFreq &current_best, const string &v_word, int v_freq)
{
	if (v_freq != 0 and current_best.getFreq() < v_freq)
	{
		current_best.setWord(v_word);
		current_best.setFreq(v_freq);
	}
}

/* Pre: cierto.
   Post: se generan variantes de 'word' insertando letras del alfabeto
   'this->alphabet'. Para cada variante, se busca en el diccionario
   y en caso de que exista se guarda temporalmente, donde al final del método
   devolveremos un PairFreq con la palabra encontrada que tuviese mayor frecuencia.

   Si para todas las variantes no hemos encontrado ninguna palabra en el diccionario,
   devolvemos un ParFreq cuya palabra será la original y con frecuencia 0.
*/
ParFreq Corrector::insert(const string &word)
{
	ParFreq best_word(word, 0);

	for (unsigned int i = 0; i < this->alphabet.size(); ++i)
	{
		/* Inv: hemos generado para 'i' letras del alfabeto las
		   variantes de 'word', donde hemos descartado aquellas no
		   existentes o con menor frecuencia que 'best_word'.

		   Fita: this->alphabet.size() - i.
		*/

		// Generamos las variantes de 'word' para la letra 'this->alphabet[i]'.
		for (unsigned int j = 0; j <= word.size(); ++j)
		{
			/* Inv: se han generado 'j' variantes de 'word'
			   por inserción.

			   Fita: word.size() - j.
			*/
			/* IMPORTANTE:
			   En substr() cuando word.size() == j no hay desbordamiento, sino que
			   devuelve una cadena vacía. Solo hay error si word.size() < j.
			*/
			string variant = word.substr(0, j) + this->alphabet[i] + word.substr(j);

			// Si 'variante' no existiera, su frecuencia sería 0 y no se modificaría 'best_word'.
			setIfBestVariant(best_word, variant, this->dictionary.getFreq(variant));
		}
	}

	return best_word;
}

/* Pre: cierto.
   Post: se generan variantes de 'word' borrando de esta alguna de sus letras.
   Cada variante se busca en el diccionario y en caso de que exista se guarda
   temporalmente, donde al final del método devolveremos un PairFreq con
   la palabra encontrada que tuviese mayor frecuencia.

   Si para todas las variantes no hemos encontrado ninguna palabra en el diccionario,
   devolvemos un ParFreq cuya palabra será la original y con frecuencia 0.
*/
ParFreq Corrector::delLetter(const string &word)
{
	ParFreq best_word(word, 0);

	for (unsigned int i = 0; i < word.size(); ++i)
	{
		/* Inv: hemos para todos los indices 'i' recibidos hasta el
		   momento una variante de 'word' por eliminación de la letra
		   que posicionada en el indice 'i'.

		   Fita: this->alphabet.size() - i.
		*/

		string variant = word;
		variant.erase(i, 1);

		// Si 'variante' no existiera, su frecuencia sería 0 y no se modificaría 'best_word'.
		setIfBestVariant(best_word, variant, this->dictionary.getFreq(variant));
	}

	return best_word;
}

/* Pre: cierto.
   Post: se generan variantes de 'word' sustituyendo cada letra por letras del alfabeto
   'this->alphabet'. Cada variante se busca en el diccionario y en caso de que exista
   se guarda temporalmente, donde al final del método devolveremos un PairFreq con
   la palabra encontrada que tuviese mayor frecuencia.

   Si para todas las variantes no hemos encontrado ninguna palabra en el diccionario,
   devolvemos un ParFreq cuya palabra será la original y con frecuencia 0.
*/
ParFreq Corrector::subs(const string &word)
{
	ParFreq best_word(word, 0);

	for (unsigned int i = 0; i < this->alphabet.size(); ++i)
	{
		/* Inv: hemos generado para 'i' letras del alfabeto las
		   variantes de 'word', donde hemos descartado aquellas no
		   existentes o con menor frecuencia que 'best_word'.

		   Fita: this->alphabet.size() - i.
		*/

		// Generamos las variantes de 'word' para la letra 'this->alphabet[i]'.
		for (unsigned int j = 0; j < word.size(); ++j)
		{
			/* Inv: se han generado 'j' variantes de 'word'
			   por inserción.

			   Fita: word.size() - j.
			*/

			string variant = word;
			variant[j] = this->alphabet[i];

			// Si 'variante' no existiera, su frecuencia sería 0 y no se modificaría 'best_word'.
			setIfBestVariant(best_word, variant, this->dictionary.getFreq(variant));
		}
	}

	return best_word;
}

/* Pre: cierto.
   Post: se generan variantes de 'word' intercambiando pares de letras adyacentes.
   Cada variante se busca en el diccionario y en caso de que exista se guarda
   temporalmente, donde al final del método devolveremos un PairFreq con la palabra
   encontrada que tuviese mayor frecuencia.

   Si para todas las variantes no hemos encontrado ninguna palabra en el diccionario,
   devolvemos un ParFreq cuya palabra será la original y con frecuencia 0.
*/
ParFreq Corrector::trans(const string &word)
{
	ParFreq best_word(word, 0);

	for (unsigned int i = 0; i < word.size() - 1; ++i)
	{
		/* Inv: hemos generado para 'i' variantes de 'word' mediante
		   la transposición de pares de letras, donde hemos descartado
		   aquellas no existentes o con menor frecuencia que 'best_word'.

		   Fita: word.size()-1 - i.
		*/

		string variant = word;
		variant[i] = word[i+1];
		variant[i+1] = word[i];

		// Si 'variante' no existiera, su frecuencia sería 0 y no se modificaría 'best_word'.
		setIfBestVariant(best_word, variant, this->dictionary.getFreq(variant));
	}

	return best_word;
}

/* Pre: la palabra no contiene los caracteres: ".,!?;".
   Post: se busca si la palabra existe en el diccionario. Si existe, no se
   hace nada y se devuelve la misma palabra. En caso de no existir, se
   generan variantes de la palabra original para buscar la coincidencia en el
   diccionario con la mayor frecuencia y devolver
*/
string Corrector::fixWord(const string &word)
{
	ParFreq best_word(word, this->dictionary.getFreq(word));

	/* Si no es 0, la palabra existe y es correcta. Si es 0, entonces
	   hay que intentar corregir la palabra.
	*/
	if (best_word.getFreq() == 0)
	{
		ParFreq candidate;

		// Generamos candidatos y encontramos la mejor variante.
		candidate = insert(word);
		setIfBestVariant(best_word, candidate.getWord(), candidate.getFreq());

		candidate = subs(word);
		setIfBestVariant(best_word, candidate.getWord(), candidate.getFreq());

		candidate = delLetter(word);
		setIfBestVariant(best_word, candidate.getWord(), candidate.getFreq());

		candidate = trans(word);
		setIfBestVariant(best_word, candidate.getWord(), candidate.getFreq());
	}

	return best_word.getWord();
}

//*********************************************************
// Modificadores
//*********************************************************

/* Pre: Cierto */
/* Post: Si rutaInput está associado a un archivo, lee el
texto del archivo línea a línea, corrige cadauna de las
palabras de cada línea, las escribe en el archivo associado a
rutaOutput i escribe en el archivo associado a rutaLog los cambios
que haya hecho; si no, muestra un mensaje de error */
void Corrector::processaText(const string &rutaInput, const string &rutaOutput, const string &rutaLog)
{

	ifstream raw_text_file(rutaInput);
	if (not raw_text_file.is_open())
	{
		throw runtime_error("Error en obrir el fitxer amb el text a corretgir: " + rutaInput);
	}

	ofstream out_file(rutaOutput);
	if (not out_file.is_open()) {
		throw runtime_error("Error en obrir el fitxer output: " + rutaOutput);
	}

	ofstream log(rutaLog, ios_base::app);
	if (not log.is_open()) {
		throw runtime_error("Error en obrir el fitxer de registre: " + rutaLog);
	}

	string line;

	while (getline(raw_text_file, line))
	{
		/* Inv: hemos leido, corregido y escrito en los archivos de salida
		   'rutaOutput' y 'rutaLog' las líneas corregidas y los cambios realizados
		   de las líneas 'line' recibidas hasta el momento.

		   Fita: la cantidad de líneas por leer de 'raw_text_file'.
		*/

		istringstream ss(line);

		string word, corrected_line = "";
		while (ss >> word)
		{
			/* Inv: se han corregido y escrito en los archivos de log y salida (si era necesario)
			   las palabras incorrectas 'word' leidas hasta el momento.

			   Fita: la cantidad de palabras por leer en el canal de entrada 'ss'.
			*/

			// Alex: falta que en base a la palabra devuelta (si es igual a la original o está cambiada)
			// la escribamos en el archivo de salida y en el Log si fue cambiada.
			string fixed_word = fixWord(word);  
			if (word != fixed_word) {
				log << word << " -> " << fixed_word << endl; 
			}
			corrected_line += fixed_word + " "; 
		}
		out_file << corrected_line << endl; 
	}
	raw_text_file.close();
	out_file.close();
	log.close(); 
}

//*********************************************************
// Lectura y escritura
//*********************************************************
/* Pre: Cierto */
/* Post: Se han escrito en el archivo associado a rutaLog todas
las correcciones hechas al texto de entrada siendo el formato de
cada línea palabra_original -> palabra_corregida */
void Corrector::bolcaRegistre(const string &rutaLog)
{
	ofstream fitxerLog(rutaLog);

	// escriure el contingut de l'estructura que emmagatzema
	// els registres a fitxerLog

	// fitxerLog << original << " -> " << corregida << endl;
}
