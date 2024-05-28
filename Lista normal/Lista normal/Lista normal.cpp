

#include <iostream>
#include "Lista.h"
#include"Cola.h"
#include "Nodo.h"
#include "Stack.h"
#include<ctime>
#include<cstdlib>
using namespace std;
void Bubble(int* numeros, int largo) {//14/05/24- tipo de la clase

	for (int i = 0; i < largo; i++)
	{
		for (int j = i + 1; j < largo; j++)
		{
			if (numeros[i] < numeros[j]) {
				continue;//si cumple
			}
			else
			{
				int temporal = numeros[i];
				numeros[i] = numeros[j];
				numeros[j] = temporal;
			}
		}
	}
	cout << "Imprimir Bubble\n";
	for (int i = 0; i < largo; i++)
	{
		cout << numeros[i] << " ";
	}
	cout << endl;
}
void Bubble_I(int* numeros, int largo) {

	for (int i = 0; i < largo; i++)
	{
		for (int j = i + 1; j < largo; j++)
		{
			cout << numeros[i] << " > " << numeros[j] << endl;
			if (numeros[i] > numeros[j])
			{
				cout << "true\n";
				int temporal = numeros[i];
				numeros[i] = numeros[j];
				numeros[j] = temporal;
			}
			else
			{
				cout << "false\n";
			}
		}
	}
	cout << "Imprimir Bubble, de orgien de internet\n";
	for (int i = 0; i < largo; i++)
	{
		cout << numeros[i] << " ";
	}
	cout << endl;
}
void Selection(int* numeros, int largo) {//14/05/24- tipo de la clase

	for (int i = 0; i < largo; i++)
	{
		int indice_menor = i;
		for (int j = i + 1; j < largo; j++)
		{
			if (numeros[indice_menor] < numeros[j]) {
				continue;//si cumple
			}
			else
			{
				indice_menor = j;

			}

		}
		int temporal = numeros[indice_menor];
		numeros[indice_menor] = numeros[i];
		numeros[i] = temporal;
	}
	cout << "Imprimir Selection\n";
	for (int i = 0; i < largo; i++)
	{
		cout << numeros[i] << " ";
	}
	cout << endl;
}
void Selection_I(int* arreglo, int largo) {
	int auxiliar = -1, minimo = -1;
	for (int i = 0; i < largo; i++)
	{
		minimo = i;
		for (int j = i + 1; j < largo; j++)
		{
			if (arreglo[j] < arreglo[minimo])
			{
				minimo = j;
			}
		}
		auxiliar = arreglo[i];
		arreglo[i] = arreglo[minimo];
		arreglo[minimo] = auxiliar;
	}
	cout << "Imprimir Selection, origen de internet\n";
	for (int i = 0; i < largo; i++)
	{
		cout << arreglo[i] << " ";
	}
	cout << endl;
}
void Insertion_I(int* numeros, int largo) {

	int auxiliar = -1, posicion = -1;
	for (int i = 0; i < largo; i++)
	{
		posicion = i;
		auxiliar = numeros[i];
		while (posicion > 0 && (numeros[posicion - 1] > auxiliar))
		{
			numeros[posicion] = numeros[posicion - 1];
			posicion--;
		}
		numeros[posicion] = auxiliar;
	}
	cout << "Insertion, de origen de internet\n";
	for (int i = 0; i < largo; i++)
	{
		cout << numeros[i] << " ";
	}
	cout << endl;
}
//Quick sort
int partition(int* a, int start, int end) {
	int pivot = a[start];
	cout << pivot << endl;	
	// Contamos cuantos valores son mas pequenios que el pivote
	int count = 0;
	for (int i = start + 1; i <= end; ++i) {
		cout << a[i] << endl;	
		if (a[i] < pivot) {
			count++;
		}
	}
	// pivotIndex sera la posicion que el valor del pivote
	// debe ocupar en el arreglo (en este punto ya lo sabemos)
	int pivotIndex = start + count;
	// Ordenamos el pivot en su posicion correcta (pivotIndex)
	int t = a[pivotIndex];
	a[pivotIndex] = a[start];
	a[start] = t;

	// empieza el ordenamiento por subgrupos
	int _menoresIndex = start;
	int _mayoresIndex = end;

	while (_menoresIndex < pivotIndex && _mayoresIndex >  pivotIndex) {
		// buscar el primer elemento que sea mayor al pivote
		while (a[_menoresIndex] < pivot) {
			_menoresIndex++;
		}

		// buscar el primer elemento que sea menor al pivote
		while (a[_mayoresIndex] > pivot) {
			_mayoresIndex--;
		}

		// aca encontre un par de numeros que estan de los datos
		// incorrectos
		if (_menoresIndex < pivotIndex && _mayoresIndex >  pivotIndex) {
			t = a[_menoresIndex];
			a[_menoresIndex] = a[_mayoresIndex];
			a[_mayoresIndex] = t;
			_menoresIndex++;
			_mayoresIndex--;
		}
	}
	return pivotIndex;
}

void quicksort(int* a, int start, int end) {
	if (start >= end) return;
	int pivotIndex = partition(a, start, end);
	// ordenar el lado izquierdo, los menores
	quicksort(a, start, pivotIndex - 1);

	// ordenar el lado derecho, los mayores
	quicksort(a, pivotIndex + 1, end);
}
//Quick sort_I

void Quick_Sort_I(int* arreglo, int inicio, int fin) {
	int izq, der, aux, pivote;
	izq = inicio;
	der = fin;
	pivote = arreglo[(izq-der) / 2];
	//cout << pivote << " " << arreglo[pivote] << endl;
	do 
	{
		while (arreglo[izq]<pivote&&izq<fin)
		{
			izq++;

		}
		while (arreglo[der]>pivote&& der> inicio)
		{
			der--;
		}
		if (izq<=der)
		{
			aux = arreglo[izq];
			arreglo[izq] = arreglo[der];
			arreglo[der] = aux;
			izq++;
			der--;
		}
	} while (izq <= der);
	if (inicio<=der)
	{
		Quick_Sort_I(arreglo, inicio, der);
	}
	if (fin>izq)
	{
		Quick_Sort_I(arreglo, izq, fin);
	}
}
void Merge_I(int* arreglo, int inicio, int mitad, int fin) {
	int i, j, k;
	int elementosIzq = mitad - inicio + 1;
	int elementosDer = fin - mitad;
	int* arregloI = new int[elementosIzq];
	int* arregloD = new int[elementosDer];
	for (int i = 0; i < elementosIzq; i++)
	{
		arregloI[i] = arreglo[inicio + i];
	}
	for (int j = 0; j < elementosDer; j++)
	{
		arregloD[j] = arreglo[mitad + 1 + j];
	}
	i = 0;
	j = 0;
	k = inicio;
	while (i < elementosIzq && j < elementosDer)
	{
		if (arregloI[i] <= arregloD[j])
		{
			arreglo[k] = arregloI[i];
			i++;
		}
		else
		{
			arreglo[k] = arregloD[j];
			j++;
		}
		k++;
	}
	while (j < elementosDer)
	{
		arreglo[k] = arregloD[j];
		i++;
		k++;
	}
	while (i < elementosIzq)
	{
		arreglo[k] = arregloI[i];
		i++;
		k++;
	}
}
void Merge_Sort_I(int * arreglo, int inicio, int fin) {
	if (inicio<fin)
	{
		int mitad = inicio + ((fin - inicio) / 2);
		Merge_Sort_I(arreglo, inicio, mitad);
		Merge_Sort_I(arreglo,mitad+1,fin);
		Merge_I(arreglo, inicio, mitad, fin);
	}

}
int main()
{

	srand(time(NULL));
	int largo = 5;
	int random;
	int  inferior=0, contador=0,superiror=256;
	int* datos = new int[largo];
	for (int i = 0; i < largo; i++)
	{
		random = inferior + rand() % (superiror - inferior);
		datos[i] = random;
	}
	for (int i = 0; i < largo; i++)
	{
		cout << datos[i] << " ";
	}
	cout << endl;
	Bubble_I(datos,largo);

	//cout << "---------------------------\n";
	
	
	//Bubble_I(as,4);
	
	//14/05/24
	int* buble = new int[10];
	buble[0] = 109;
	buble[1] = 19;
	buble[2] = 1;
	buble[3] = 9;
	buble[4] = 29;
	buble[5] = 176;
	buble[6] = 17;
	buble[7] = 845;
	buble[8] = 546;
	buble[9] = 235;

	/*Bubble(buble, 10);
	cout << endl;
	Selection(buble, 10);
	cout << endl;
	Insertion_I(buble, 10);
	cout << endl;
	Selection_I(buble, 10);
	cout << endl;
	Bubble_I(buble, 10);*/
	
	
	int* hia = new int[largo] {15,9,8,100,26};
	
	/*quicksort(buble, 0, 10 - 1);
	cout << "Quick\n";
	for (int i = 0; i < 10; i++)
	{
		cout << buble[i] << " ";
	}*/
	cout << endl;
	cout << "Quick sort, origen de internet\n";
	quicksort(hia,0,largo-1);
	for (int i = 0; i < largo; i++)
	{
		cout << hia[i] << " ";
	}
	cout << endl;
	
	cout << endl;
	//Busqueda binaria
	int* yy = new int[5] {12,65,88,90,123};
	int sup, inf, mitad, dato;
	inf = 0;
	sup = 5;
	bool find = false;
	cout << "Diga su numero a encontrar\n";
	cin >> dato;
	while (inf<=sup)
	{
		mitad = (inf + sup) / 2;
		if (yy[mitad]==dato)
		{
			find = 1;
			break;
		}
		if (yy[mitad]>dato)
		{
			sup = mitad;
			mitad = (inf + sup) / 2;
		}
		if (yy[mitad]<dato)
		{
			inf = mitad;
			mitad = (inf + sup) / 2;
		}
	}
	if (find)
	{
		cout << "Dato en contrado, posicion: " << mitad << endl;
	}
	else
	{
		cout << "Dato no encontrado\n";
	}
	return 0;
}
