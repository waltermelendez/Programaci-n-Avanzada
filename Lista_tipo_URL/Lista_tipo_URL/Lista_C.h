#pragma once
#include "Nodo_C.h"
#include <cstddef>
//Archivo .h de la lista circular
class Lista_C
{private:
	Nodo_C* Head;
	Nodo_C* Tail;
public:
	Lista_C() {
		Head = NULL;
		Tail = NULL;
	}
	void add(char valor);
	void remove(char valor);
	void print();
	void Replace(char Aremplazar, char remplazo);
	void Append(Lista_C * lista);
};

