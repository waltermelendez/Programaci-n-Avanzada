#pragma once
#include "Nodo.h"

class Mesa // este va ser el lugar en donde se va a guardar cada ficha de cada jugador, en este caso es una pila
{private:

	Nodo* Head;
public:
	//Constructor de la mesa
	Mesa() {
		Head = NULL;

	}
	void Push(string domino);
	string Pop();
	string Peek();
	void impirmir_M();
	
};

