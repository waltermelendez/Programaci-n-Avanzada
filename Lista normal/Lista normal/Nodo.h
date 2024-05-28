#pragma once
class Nodo
{
public:
	Nodo* next;
	int dato;
	Nodo() {
		next = nullptr;
		dato = 0;
	}
};

