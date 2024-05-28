#pragma once
#include "Nodo.h"
class Stack
{
private:
	Nodo* Head;
	Nodo* Tail;
public:
	void Push(int dato);
	int Pop();
	int Peek();
	Stack() {
		Head = nullptr;
		Tail = nullptr;
	}
};

