#include "Lista.h"
#include <cstddef>
#include <iostream>
using namespace std;
int Lista::GetLongitud() {
	return longitud;
}
void Lista::Add(char valor) {
	longitud++;
	Nodo* auxiliar = new Nodo;
	auxiliar->Dato = valor;
	if(HEAD==NULL){//Caso en el que no hay elementos en la lista
		
		auxiliar->next = NULL;
		auxiliar->previus = NULL;
		HEAD = auxiliar;
		TAIL = auxiliar;
		
	}
	else//caso 2, cuando hay un dato en la lista
	{
		/*
		nuevo->siguiente= nulltpr;
		nuveo
	 */
		auxiliar->next = NULL;
		auxiliar->previus = TAIL;
		TAIL->next = auxiliar;
		TAIL = auxiliar;
		
	}
	
}
void Lista::imprimir() {// Forma iterativa
	Nodo* Actual = HEAD;

	if (Actual==NULL)
	{
		cout << "La lista esta vacia\n";
	}
	else
	{
		cout << "Los elementos de la lista son: \n";
		while (Actual!= NULL)
		{
			cout << Actual->Dato << " ->";
			Actual = Actual->next;	
		}
		cout << "NULL\n";
	}

}
void Lista::Remove(char valor) {
	
	Nodo* Actual = HEAD;
	while (Actual != NULL)
	{
		Nodo* temporal = Actual->next;//nodo temporal para guarda la direccion
		if (Actual->Dato==valor)
		{
			if(Actual==HEAD){
				//Caso 2: Remover HEAD
				Nodo* siguiente = HEAD->previus;
			
				if (siguiente != NULL) {
					siguiente->previus = NULL;
				}
				delete HEAD;
				HEAD = siguiente;
			}
			else if (Actual==TAIL) {
				//Caso 1: Remover TAIL
				Nodo* Anterior = TAIL->previus;
				if (Anterior != NULL)
				{
					Anterior->next = NULL;
				}
				
				delete TAIL;
				TAIL = Anterior;
				Actual->next = NULL;
			}
			else
			{
				//Caso 3: Remover otros nodos
				Nodo* Anterior = Actual->previus;
				Nodo* siguiente = Actual->next;
				if (Anterior != NULL) {
					Anterior->next = siguiente;
				}
				if (siguiente != NULL) {
					siguiente->previus = Anterior;
				}
				delete Actual;
				Actual = temporal;
			}
		}
		Actual = Actual->next;
	}

}
void Lista::Replace(char Aremplazar, char remplazo) {
	Nodo* actual = HEAD;
	while (actual != NULL)
	{
		Nodo* Temporal = actual->next;//nodo temporal para guarda la direccion
		if (actual->Dato == Aremplazar)
		{
			if (actual == HEAD) {
				//Caso 2: Replace HEAD
				Nodo* ayuda = new Nodo;
				ayuda->Dato = remplazo;
				ayuda->next = actual->next;
				actual = ayuda;
				
				delete HEAD;
				HEAD = actual;
			}
			else if (actual == TAIL) {
				//Caso 1: Repalce TAIL
				TAIL->Dato = remplazo;
			}
			else
			{
				//Caso 3: Replace  nodos centrales
				if (actual->Dato == Aremplazar) {
					actual->Dato = remplazo;

				}
				else
				{
					cout << "Valor no enconetrado\n";
				}
			}
		}
		actual = actual->next;
	}
}
int Lista::peek_L() {
	if (HEAD == NULL) {
		return NULL;

	}
	else
	{
		int dato = 0;
		dato = HEAD->Dato;
		return dato;
	}
}
Lista* Lista::reversa(Lista* orgi) {
	if (orgi->HEAD==NULL)
	{
		return orgi;
	}
	else {
		Stack* orde = new Stack();
		char dato = '0';
		Lista* reve = new Lista();
		while (orgi->HEAD!=NULL)
		{
			dato = HEAD->Dato;
			
			orde->Push(dato);
			HEAD = HEAD->next;
		}
		while (orde->Peek()!=NULL)
		{
			cout << orde->Peek();
			dato = orde->Pop();
			reve->Add(dato);
			
		}
		return reve;
	}
}