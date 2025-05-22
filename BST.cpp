#include "BST.hpp"
//*********************************************************
// Mètodes privats auxiliars
//*********************************************************
template <typename T>
void BST<T>::clear(Item *node)
{
	if (node != nullptr)
	{
		clear(node->left);
		clear(node->right);
		delete node;
	}
}
//*********************************************************

/* Pre: Cert */
/* Post: Afegeix un node nou amb el valor
   rebut per paràmetre a la jerarquia de
   nodes apuntada per 'node', mantenint
   les propietats de BST */
template <typename T>
typename BST<T>::Item *BST<T>::insert(Item *node, const T &d)
{
	/* Caso base 1: 'node' apunta a nullptr. Creamos un nuevo nodo
	   cuya raiz tiene valor 'd' y tiene ramas vacías.
	*/
	if (node == nullptr)
	{
		node = new Item(d, nullptr, nullptr);
	}

	/* Caso recursivo: 'node' no apunta a nullptr. Seguimos explorando
	   los nodos del arbol llamando recursivamente a las ramas de 'node'.

	   Cuando se hayan resuelto las llamadas, actualizaremos los punteros
	   de 'node' con las referencias devueltas por las llamadas recursivas.
	*/
	else
	{
		// Decididimos si explorar la rama izquierda o la derecha.

		if (d < node->data)
		{
			node->left = insert(node->left, d);
			/* H.I: 'node->left' apuntará al subarbol en 'node->left' el cual ahora
			   contendrá un nuevo nodo con valor 'd' en alguna de sus ramas.

			   Fita: el número de nodos del arbol 'node->left'.
			*/
		}
		/* En un BST no hay valores repetidos, por lo que 'd' debe ser
		   estrictamente mayor a 'node->data'.
		*/
		else
		{
			node->right = insert(node->right, d);
			/* H.I: 'node->right' apuntará al subarbol en 'node->right' el cual ahora
			   contendrá un nuevo nodo con valor 'd' en alguna de sus ramas.

			   Fita: el número de nodos del arbol 'node->right'.
			*/
		}
	}

	/* Como siempre devolvemos el puntero del nodo en el que estamos, solo hace falta
	   cambiar 'node' en el CASO BASE para que ya no apunte a la nada y apunte a el nuevo
	   nodo. En el CASO RECURSIVO solo queremos hacer reasignaciones de punteros. Las asignaciones 
	   de punteros son muy baratas y no merece la pena hacer un 'if' para comprobar si el anterior 
	   y el nuevo puntero apuntan al mismo sitio.
	*/
	return node;
}
//*********************************************************

/* Pre: Cierto */
/* Post: El resultado es el nodo de la jerarquia de nodos apuntada
   por 'node', con el mismo valor recibido por parámetro. Si no existe
   el nodo, entonces devolverá 'nullptr' como referencia.
*/
template <typename T>
typename BST<T>::Item *BST<T>::find(Item *node, const T &d) const
{

	Item *res = nullptr;

	//Caso base 1: 'node' == nullptr, devolvemos nullptr.

	if (node != nullptr)
	{
		// Caso base 2: 'node->data' == 'd'. Hemos encontrado el nodo.
		if (node->data == d)
			res = node;

		/* Caso recursivo: dependiendo de 'd' buscamos en la rama izquierda
		   o derecha del arbol apuntado por 'node' de forma recursiva.
		*/
		else
		{
			if (d < node->data)
			{
				res = find(node->left, d);
				/* H.I: 'res' contendrá la dirección de memoria donde
				   está el nodo 'd' en 'node->left'. En caso de que no exista, 
				   'res' contendrá 'nullptr'.

				   Fita: el número de nodos del arbol 'node->left'.
				*/
			}
			else
			{
				res = find(node->right, d);
				/* H.I: 'res' contendrá la dirección de memoria donde
				   está el nodo 'd' en 'node->right'. En caso de que no exista, 
				   'res' contendrá 'nullptr'.

				   Fita: el número de nodos del arbol 'node->right'.
				*/
			}
		}
	}

	return res;
}

//*********************************************************
// Constructors
//*********************************************************
template <typename T>
BST<T>::BST()
{
	root = nullptr;
}

//*********************************************************
// Destructor
//*********************************************************
template <typename T>
BST<T>::~BST()
{
	clear(root);
}

//*********************************************************
// Modificadors
//*********************************************************
template <typename T>
void BST<T>::insert(const T &d)
{
	root = insert(root, d);
}

//*********************************************************
// Consultors
//*********************************************************
template <typename T>
pair<bool, T> BST<T>::find(const T &d) const
{
	pair<bool, T> res = make_pair(false, d);

	// Buscamos en el BST con la versión privada de 'find()'.
	Item *node = find(root, d);
	if (node != NULL)
	{
		res.first = true;
		res.second = node->data;
	}
	return res;
}
