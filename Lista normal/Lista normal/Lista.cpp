#include "Lista.h"
#include <iostream>
#include <cstddef>
using namespace std;
void Lista::add(int dato) {
	Nodo* nuevo = new Nodo();
	nuevo->dato = dato;
	if (Head == nullptr)
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
void Lista::imprimir() {
	Nodo* nuevo = Head;
	if (nuevo == nullptr)
	{
		cout << "\n";
	}
	else
	{
		while (nuevo != NULL)
		{
			cout << nuevo->dato << " -> ";
			nuevo = nuevo->next;
		}
		cout << endl;
	}

}
void Lista::borrar(int dato) {
	Nodo* nuevo1 = new Nodo();
	nuevo1 = Head;
	Nodo* nuevo2 = new Nodo();
	while (nuevo1 != NULL)
	{
		//nuevo2 = nuevo1->next;
		if (nuevo1->dato == dato)
		{
			if (nuevo1 == Head) {
				Nodo* nuevo3 = Head;
				Head = Head->next;
				delete nuevo3;
				nuevo1 = Head;
			}
			else if (nuevo1 == Tail)
			{
				Nodo* nuevo3 = Head;
				Nodo* nuevo4 = new Nodo();
				while (nuevo3 != nuevo1)
				{
					nuevo4 = nuevo3;
					nuevo3 = nuevo3->next;
				}
				nuevo4->next = NULL;
				Tail = nuevo4;
				delete nuevo1;
				nuevo1 = Tail;
			}
			else
			{
				Nodo* nuevo3 = nuevo1->next;
				Nodo* nuevo4 = new Nodo();
				Nodo* nuevo5 = Head;
				while (nuevo5 != nuevo1)
				{
					nuevo4 = nuevo5;
					nuevo5 = nuevo5->next;
				}
				delete nuevo1;
				nuevo4->next = nuevo3;
				nuevo1 = nuevo3;

			}
		}

		nuevo1 = nuevo1->next;

	}
}
int Lista::contador() {
	if (Head == NULL)
	{
		return 0;
	}
	else
	{
		Nodo* contar = Head;
		int cantidad = 0;
		while (contar != NULL)
		{
			cantidad++;
			contar = contar->next;
		}
		return cantidad;
	}
}
void Lista::bubble_sort() {
	if (Head == NULL)
	{
		cout << "Lista vacia\n";
	}
	else
	{
		int K = -1;
		Nodo* I = Head;
		Nodo* J = I->next;
		int limite = contador();
		for (int i = 0; i < limite; i++)
		{
			for (int j = i + 1; j < limite; j++)
			{
				if (I->dato > J->dato) {
					K = I->dato;
					I->dato = J->dato;
					J->dato = K;
					I = I->next;
					J = J->next;
				}
				else
				{
					I = I->next;
					J = J->next;
				}

			}
			I = Head;
			J = I->next;
		}
	}
	cout << "Blubble Sort\n";
	imprimir();
}
void Lista::Selection_sort() {
	if (Head == NULL)
	{
		cout << "Lista vacia\n";
	}
	else
	{
		
		
		int largo = contador();
		Nodo* I = Head;
		Nodo* J = I->next;
		int temporal = -1;
		int  minio = -1;
		for (int i = 0; i < largo; i++)
		{
			minio = I->dato;
			for (int j = i+1; j < largo; j++)
			{
				if (J->dato<minio)
				{
					minio = J->dato;
					J = J->next;
				}
				else
				{
					J = J->next;
				}
				
			}
			temporal = I->dato;
			I->dato = minio;
			minio = temporal;

			J = I->next;
			J->dato = minio;
			
			//I = I->next;
		}
		/*while (I!=NULL)
		{
			minio = I->dato;
			J = I->next;
			while (J!=NULL)
			{
				if (J->dato< minio)
				{
					minio = J->dato;
				}
				J = J->next;
			}
			auxiliar = I->dato;
			I->dato = minio;
			minio = auxiliar;
			I = I->next;
		}*/
	}

	cout << "Selection sort\n";
	imprimir();
}