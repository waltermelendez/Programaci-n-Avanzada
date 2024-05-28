#pragma once
#include "Nodo.h"
class Lista_cirular
{
private:
	Nodo *Head;
	Nodo *Tail;
public:
	void agregar(int posicion);
	void eliminar(string posicion);
	string ver(int posicion);
	Lista_cirular() {
		Head = NULL;
		Tail = NULL;

	}
};

