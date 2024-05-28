#pragma once
#include <cstddef>
class Nodo
{
public:
	Nodo* next;
	char Dato;
	Nodo* previus;
	Nodo() {
		Dato = '\0';//Null
		next = NULL;
		previus = NULL;
	}
};

