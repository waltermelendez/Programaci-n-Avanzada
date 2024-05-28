#include "Cola.h"
void Cola::Queque(int dato) {
	Nodo* nuevo = new Nodo();
	nuevo->dato = dato;
	if (Head==nullptr)
	{
		nuevo->next = nullptr;
		Head = nuevo;
		Tail = nuevo;
	}
	else
	{
		nuevo->next = nullptr;
		Tail->next = nuevo;
		Tail = nuevo;
	}
}
int Cola::Peek() {
	if (Head==nullptr)
	{
		return 0;
	}
	else {
		int Dato = Head->dato;
		return Dato;
	}
}
int Cola::Dequeque() {
	if (Head==nullptr)
	{
		return 0;
	}
	else
	{
		int dato = Head->dato;
		Nodo* borrar = Head;
		Head = Head->next;
		delete borrar;
		return dato;
	}
}
int Cola::largo() {
	if (Head==nullptr)
	{
		return 0;
	}
	else
	{
		Nodo* contar = new Nodo;
		int i = 0;
		while (contar!=nullptr)
		{
			i++;
			contar = contar->next;
		}
	}
}
Cola *Cola::reverse(Cola *entrada) {
	Cola* nueva = new Cola();
	int contar = largo();
	if (!vacia())
	{
		return entrada;
	}
	else
	{
		while (contar>=0)
		{
			nueva->Queque(nueva->Dequeque());
			contar--;

		}
		return nueva;
	}
}
bool Cola::vacia() {
	if (Head== nullptr)
	{
		return false;
	}
	else
	{
		return 1;
	}
}
