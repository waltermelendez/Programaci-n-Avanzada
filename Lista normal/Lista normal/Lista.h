#pragma once
#include "Nodo.h"
class Lista
{private:
	Nodo *Head;
	Nodo *Tail;
public:
	void add(int dato);
	void borrar(int dato);
	void imprimir();
	void bubble_sort();
	int contador();
	void Selection_sort();
	Lista() {
		Head = nullptr;
		Tail = nullptr;

	}

	
	
	
};

