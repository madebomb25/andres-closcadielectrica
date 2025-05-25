#ifndef BST_HPP
#define BST_HPP
#include <iostream>
using namespace std;

/*  
 * Representación de un árbol binario de búsqueda o
 * BST (binary search tree).
 * Un árbol binario de búsqueda es un árbol binario
 * en el que el subárbol izquierdo de cualquier nodo
 * (si no está vacío) contiene valores menores que el
 * que contiene este nodo, y el subárbol derecho
 * (si no está vacío) contiene valores mas grandes.
 */ 

template <typename T>
class BST  {
	
	private:
		struct Item {
			T data;
			Item *left;
			Item *right;
			Item(const T& d, Item *l, Item *r) {
				data = d;
				left = l;
				right = r;
			}
		};

		Item *root;
	
	
		//*********************************************************
		// Mètodos privados auxiliares
		//*********************************************************
		
		/* Pre: Cierto */
		/* Post: No hace nada si 'node' es NULL, sinó 
		   libera espacio de la jerarquía de nodos
		   apuntada por 'node' */
		void clear(Item *node);

		/* Pre: Cierto */
		/* Post: Añade un nodo nuevo con el valor
		   recibido por parámetro a la jerarquía de
		   nodos apuntada per 'node', manteniendo
		   las propiedades de BST */
		Item* insert(Item *node, const T& d);
		
		/* Pre: Cierto */
		/* Post: El resultado es el nodo de la jerarquía de nodos apuntada
		por 'node', con el mismo valor recibido por parámetro. Si no existe
		el nodo, entonces devolverá 'nullptr' como referencia.
		*/
		Item* find(Item *node, const T& d) const;
	
	
	public:

		//*********************************************************
		// Constructores
		//*********************************************************
	
		/* Pre: Cierto */
		/* Post: El resultado es un BST sin ningún elemento */	
		BST();


		//*********************************************************
		// Destructor
		//*********************************************************
	
		/* Borra automáticamente los objectos locales
		   al salir de un ámbito de visibilidad */
		~BST();

		//*********************************************************
		// Modificadores
		//*********************************************************

		/* Pre: Cierto */
		/* Post: Añade un elemento, con el valor recibido
		   per parámetro, al BST parámetro implícito */
		void insert(const T& d);
	

		//*********************************************************
		// Consultores
		//*********************************************************
	
		/* Pre: Cierto */
		/* Post: El primer componente del resultado indica
		   si el BST parámetro implícito contiene un elemento
		   con el valor recibido por parámetro; en caso afirmativo,
		   el segundo componente contiene el elemento del parámetro
		   implícito con este valor, si no, contiene un
		   elemento vacío */
		pair<bool, T> find(const T& d) const;
	
};

#include "BST.cpp"

#endif
