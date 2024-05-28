#include "Pozo.h"
#include <iostream>
using namespace std;
void Pozo::Queque(string domino) {
	//agregar dominos en el "pozo"
	Nodo* nuevo = new Nodo();
	nuevo->domino = domino;
	if (Head==nullptr)
	{
		//Si el primer nodo.
		nuevo->next = NULL;
	
		Head = nuevo;
		Tail = nuevo;
	}
	else
	{
		// Si es otro nodo.
		nuevo->next = NULL;
		Tail->next = nuevo;
		Tail = nuevo;

	}
}
string Pozo::Dequeque() {
	//Esta funcion sirve para poder borrar un nodo del pozo.
	if (Head == NULL) {

		return "X";//esta es la representacion de un espacio vacio.
	}
	else
	{
		string domino = Head->domino;
		//borrar dato en Heap
		Nodo* Borrar = Head;

		Head = Head->next;
		delete Borrar;//liberar memoria
		return domino;
	}
}
string Pozo::Peek() {
	//Esta funcion sirve para poder ver la cabeza del pozo.
	if (Head == NULL) {
		return "X";
	}
	else
	{
		string domino;
		domino = Head->domino;
		return domino;
	}
}
void Pozo::imprimir() {
	//Funcion para imprimir los dominos en el pozo.
	if (Head == NULL)
	{
		cout << "No hay mas fichas en el pozo\n";
	}
	else
	{
		Nodo* contar = new Nodo;
		contar = Head;
		cout << "Las fichas del pozo son:\n";
		while (contar!=NULL)
		{
			cout << contar->domino << " -> ";
			contar = contar->next;
		
		}
		cout << "||\n";
	}
}
string Pozo::buscar(Pozo* nueva, string domino) {
	Pozo* auxiliar = new Pozo();
	auxiliar = nueva;
	//Verificar si el pozo ya no tiene dominos.
	if (Head == NULL)
	{
		cout << "No hay mas fichas en el pozo\n";
		return domino;
	}
	else
	{
		int contar = contador();
		//Se declara una nueva clases para poder acceder las funciones "Peek", "Queque" y "Dequeque", para que sea mas facil.
		while (contar >= 0)
		{
			if (nueva->Peek()[0] == domino[0] || nueva->Peek()[2] == domino[2])
			{
				//si encuetra un domino que coincide en alguno de los dos lados
				return nueva->Dequeque();
			}
			
			nueva->Queque(nueva->Dequeque());

		}
			//Si no hay un domino que le sea util al jugador.
		cout << "No hay domino que usted pueda usar para jugar, usted a perdido el turno\n";
		return domino;
	}
}
int Pozo::contador() {
	//funcion para poder contar cuantos dominos/nodos tiene el pozo/cola.
	if (Head == NULL)
	{
		return 0;
	}
	else
	{
		int cantidad = 0;
		Nodo* contar = Head;
		while (contar != NULL)
		{
			cantidad++;
			contar = contar->next;
		}
		return cantidad;
	}
}
