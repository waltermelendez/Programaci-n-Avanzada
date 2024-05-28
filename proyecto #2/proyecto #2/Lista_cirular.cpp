#include "Lista_cirular.h"
#include <iostream>
using namespace std;
void Lista_cirular::agregar(int posicion) {
	string convertir = to_string(posicion);
	Nodo* Agregar = new Nodo;
	Agregar->domino = convertir;
	if (Head==NULL)
	{
		Head = Agregar;
		Head->next = Agregar;
		Tail = Agregar;
	}
	else
	{
		Tail->next = Agregar;
		Agregar->next = Head;
		Tail = Agregar;
	}
}
void Lista_cirular::eliminar(string posicion) {
	Nodo* actual = new Nodo;
	actual = Head;
	Nodo* anterior = new Nodo;
	anterior = NULL;

	if (Head==NULL)
	{
		cout << "litsa vacia\n";
	}
	else
	{
		do {
			if (actual->domino==posicion)
			{
				if (actual==Head)
				{
					Head = Head->next;
					Tail->next = Head;
				}
				else if(actual==Tail)
				{
					anterior->next = Head;
					Tail = anterior;
				}
				else
				{
					anterior->next = actual->next;
				}
			}
			anterior = actual;
			actual = actual->next;
		
		} while (actual!=Head);
	}
}
string Lista_cirular::ver(int posicion) {
	Nodo* actual = new Nodo;
	actual = Head;
	int contar = 0;
	if (Head==NULL)
	{
		return " ";
	}
	else
	{
		do {
			if (contar == posicion)
			{
				return actual->domino;
			}
			contar++;
				actual = actual->next;
		
		} while (actual!=Head);
		return " " ;
	}
}