#pragma once
#include "Nodo.h"
#include <cstddef>
#include "Stack.h"
class Lista
{
private:
	int longitud;
	char caracter;
	Nodo* HEAD;
	Nodo* TAIL;
public:
	void Add(char valor);
	int GetLongitud();
	void Remove(char valor);//Borrar un elemento de la lista
	void Replace(char Aremplazar, char remplazo);
	void imprimir();
	int peek_L();
	Lista* reversa(Lista* orgi);
	Lista() {
		longitud = 0;
		HEAD = NULL;
		TAIL = NULL;
	}
	
};

