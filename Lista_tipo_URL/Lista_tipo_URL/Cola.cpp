#include "Cola.h"
void Cola::Queque(char valor) {
	Nodo* auxiliar = new Nodo;
	auxiliar->Dato = valor;
	if (Head == NULL) {
		auxiliar->next = NULL;
		auxiliar->previus = NULL;
		Head = auxiliar;
		Tail = auxiliar;
	}
	else
	{
		auxiliar->next = NULL;
		auxiliar->previus = Tail;
		Tail->next = auxiliar;
		Tail = auxiliar;
	}

}
char Cola::Dequeue() {
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
char Cola::Peek() {
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



