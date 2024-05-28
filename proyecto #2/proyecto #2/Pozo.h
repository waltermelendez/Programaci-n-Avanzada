#pragma once
#include "Nodo.h"
class Pozo
	// El pozo va a ser el lujar en donde se va aguarda el resto de las fichas despues de ser repartidas entre los 
	//jugadores, en este caso va ha ser una cola.
{private:
	Nodo* Head;
	Nodo* Tail;
public:
	
	//Constructor del pozo.
	Pozo() {
		Head = NULL;
		Tail = NULL;
	}
	void Queque(string domino);
	string Dequeque();
	string Peek();
	void imprimir();
	string buscar(Pozo *nueva, string domino);
	int contador();
};

