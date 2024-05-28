#include "Lista_C.h"
using namespace std;
#include <iostream>
//Archivo .cpp de la lista circular
void Lista_C::add(char valor) {
	Nodo_C* nuevo = new Nodo_C;
	nuevo->dato = valor;
	if (Head == NULL) {
		Head = nuevo;
		Head->next = nuevo;
		Tail = nuevo;

	}
	else
	{
		Tail->next = nuevo;
		nuevo->next = Head;
		Tail = nuevo;

	}
}
void Lista_C::print() {
	Nodo_C* nuevo = new Nodo_C;
	nuevo = Head;
	if (nuevo == NULL)
	{
		cout << "Lista vacia\n";
	}
	else {
		do {
			cout << nuevo->dato << " -> ";
			nuevo = nuevo->next;

		} while (nuevo != Head);
		cout << endl;
	}

}
void Lista_C::remove(char valor) {	
	Nodo_C* actual = new Nodo_C;
	actual = Head;
	Nodo_C* anteiror = new Nodo_C;
	anteiror = NULL;
	if (Head == NULL)
	{
		cout << "LA lista esta vacia\n";
	}
	else
	{
		do
		{
			if (actual->dato == valor) {
				if (actual == Head) {
					Head = Head->next;
					Tail->next = Head;
				}
				else if (actual == Tail) {
					anteiror->next = Head;
					Tail = anteiror;
				}
				else
				{
					anteiror->next = actual->next;
				}
			}
			anteiror = actual;
			actual = actual->next;
		} while (actual != Head);
	}


}
void Lista_C::Replace(char Aremplazar, char remplazo)
{
	Nodo_C* actual = Head;
	if (actual == NULL)
	{
		cout << "Lista vacia\n";
	}
	else {
		do {
			if (actual->dato == Aremplazar) {
				actual->dato = remplazo;
			}
			actual = actual->next;
		} while (actual != Head);
		
	}

}
void Lista_C::Append(Lista_C * lista) {
	if (lista == NULL) {
		cout << "La lista esta vacia\n";
	}
	else if (lista==NULL)
	{
		Tail->next = lista->Head;
		Tail = lista->Tail;
		Tail->next = Head;
	}
	else
	{
		Head = lista->Head;
		Tail = lista->Tail;
	}
}