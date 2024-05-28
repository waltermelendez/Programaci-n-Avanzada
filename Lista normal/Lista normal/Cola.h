#pragma once
#include "Nodo.h"
class Cola
{private:
	Nodo* Head;
	Nodo* Tail;
public:
	void Queque(int);
	Cola() {
		Head = nullptr;
		Tail = nullptr;
	}
	int Dequeque();
	int Peek();
	int largo();
	Cola *reverse(Cola* R);
	bool vacia();
};

