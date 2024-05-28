#include "Mesa.h"
#include <iostream>
using namespace std;
string Mesa::Pop() {
	//Esta funcion sirve para eliminar un nodo.
	if (Head == NULL) {
		return "X";
	}
	else
	{
		string domino = "";
		domino = Head->domino;
		Nodo* borrar = Head;
		Head = Head->next;

		delete borrar;
		return domino;
	}
}
void Mesa::Push(string domino) {
	//Este funcion es para poder agregar dominos a la mesa
	Nodo* nuveo = new Nodo();
	nuveo->domino = domino;
	if (Head==NULL)
	{
		//En este caso es cuando se agrega el primer domino en la mesa.
		Head = nuveo;

	}
	else
	{
		//Caso en donde se agrega otro domino en donde que no sea el primero.
		nuveo->next = Head;
		Head = nuveo;
	}
}
string Mesa::Peek() {
	//Se usa para poder ver la cabeza de la pila
	if (Head==NULL)
	{
		return "X";
	}
	else
	{
		string ficha = Head->domino;
		return ficha;
	}

}
void Mesa::impirmir_M() {
	//Funcion para poder imprimir la mesa
	if (Head==NULL)
	{
		cout << "No hay ningun domino en la mesa\n";
	}
	else
	{
		Nodo* contar = Head;
		cout << "Las fichas en la mesa son:\n";
		while (contar!= NULL)
		{
			cout << contar->domino << " <-> ";
			contar = contar->next;
		}
		cout << endl;
	}
}

