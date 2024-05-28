#pragma once
#include "Nodo.h"
class Cola
{public:
	Nodo* Head;
	Nodo* Tail;
	void Queque(char);
	char Dequeue();
	Cola() {
		Head = NULL;
		Tail = NULL;
	}
	char Peek();
};

