#include "Stack.h"
#include <cstddef>
void Stack::Push(char x) {
	Nodo* nuevo = new Nodo();
	nuevo->Dato = x;
	if (Head == NULL) {
		Head = nuevo;
		Tail = nuevo;
	
	}
	else
	{
		nuevo->next = Head;
		Head = nuevo;

	}
}
char Stack::Pop() {
	if (Head == NULL) {
		return '\0';
	}
	else
	{
		char r = Head->Dato;
		//borrar dato en Heap
		Nodo* Borarr = Head;

		Head = Head->next;
		delete Borarr;
		return r;
	}
}
char Stack::Peek() {
	if (Head == NULL) {
		return '/0';
	}
	else
	{
		char dato;
		dato = Head->Dato;
		return dato;
	}
}

int Stack::min() {
	if (Head == nullptr)
	{
		return 0;
	}
	else if (Head->Dato == Tail->Dato) {
		return Head->Dato;
	}
	else
	{
		Nodo* buscar = Head;
		Nodo* buscar2 = Head->next;

		while (buscar2 != nullptr)
		{
			if (buscar->Dato > buscar2->Dato) {
				buscar = buscar2;
				buscar2 = buscar2->next;
			}
			else
			{
				buscar2 = buscar2->next;
			}


		}	
		return (int)buscar->Dato;
	}
}