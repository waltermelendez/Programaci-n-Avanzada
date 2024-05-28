#pragma once
#include "Nodo.h"
class Stack
{
public:
	Nodo* Head;
	Nodo* Tail;
	void Push(char x);
	char Pop();
	Stack() {
		Head = NULL;
		Tail = NULL;
	}
	char Peek();
	int min();
};

