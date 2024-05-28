#include "Stack.h"
void Stack::Push(int dato) {
	Nodo* nuevo = new Nodo();
	nuevo->dato = dato;
	if (Head== nullptr)
	{
		nuevo->next = nullptr;
		Head = nuevo;
		Tail = nuevo;
	}
	else
	{
		
		nuevo->next = Head;
		Head = nuevo;
	}
}
int Stack::Peek() {
	if (Head == nullptr)
	{
		return 0;
	}
	else {
		int Dato = Head->dato;
		return Dato;
	}
}
int Stack::Pop() {
	if (Head==nullptr)
	{
		return 0;
	}
	else
	{
		int dato = Head->dato;
		Nodo* nuevo = Head;
		Head = Head->next;
		delete nuevo;
		return dato;
	}
}