#include "Jugador.h"
#include <iostream>
#include <string>
using namespace std;
void Jugador::add(string domino) {
	Nodo* auxiliar = new Nodo();
	auxiliar->domino = domino;
	if (Head == NULL) {//Caso en el que no hay elementos en la lista

		auxiliar->next = NULL;
	}
	else//caso 2, cuando hay un dato en la lista
	{

		auxiliar->next = Head;

	}
	Head = auxiliar;
}
void Jugador::remove(string domino) {
	//Funcion para quitar un domino
	if (Head == NULL) {
		cout << "No tiene mas dominios dispobibles\n";
	}
	Nodo* aux1 = new Nodo;
	aux1 = Head;
	Nodo* aux2 = new Nodo;
	while (aux1->domino != domino && aux1->next != NULL)
	{
		aux2 = aux1;
		aux1 = aux1->next;
		//avanza para encontrar el domino
	}
	if (aux1->domino == domino) {//si es la cabeza
		Nodo* temporal = aux1;
		if (Head == aux1) {
			Head = Head->next;
		}
		else// si otro nodo
		{
			aux2->next = aux1->next;
		}
		cout << "Se ha eliminado: " << temporal->domino << endl;
		delete temporal;
	}

}
void Jugador::imprimir() {
	Nodo* Actual = Head;
	//Funcion para imprimir los dominos del jugador.
	if (Actual == NULL)
	{
		cout << "\n";
	}
	else
	{
		cout << "Sus dominos son: \n";
		while (Actual != NULL)
		{
			cout << Actual->domino << " -> ";
			Actual = Actual->next;
		}
		cout << "||\n";
	}
}
string Jugador::buscar_doble() {
	Nodo* buscar = Head;
	Nodo* buscar2 = buscar->next;
	string comparar1 = "", comparara2 = "";
	int primero = 0, segundo = 0;
	bool ver = 0, ver2 = 0;
	//Esta funcion consinte en buscar si un domino es un doble cuando el primer numero es igual al segundo numero
	while (buscar != nullptr)
	{


		//Busca el primer doble
		if (buscar->domino[0] == buscar->domino[2])
		{
			comparar1 = buscar->domino;
			ver = 0;
			break;

		}
		buscar = buscar->next;
		ver = 1;
	}
	if (ver)
	{
		//Si no hay doble, devuelve el primer domino
		buscar = Head;
		comparar1 = buscar->domino;
	}
	//Busca el segundo doble, si es que el jugador tiene
	while (buscar2 != NULL)
	{
		if (buscar2->domino[0] == buscar2->domino[2])
		{
			comparara2 = buscar2->domino;
			if (comparar1 == comparara2)
			{
				buscar2 = buscar2->next;
			}
			else
			{
				comparara2 = buscar2->domino;
				ver2 = 0;
				break;
			}


		}
		//Esto es para evitar fallos 
		if (buscar2 == NULL)
		{
			break;
		}
		else
		{
			buscar2 = buscar2->next;
			ver2 = 1;
		}

	}
	if (ver2)
	{
		//Si no hay doble, devuelve el segundo domino
		buscar2 = Head->next;
		comparara2 = buscar2->domino;
	}
	//Busca si hay o no hay dobles.
	if (comparar1[0] == comparar1[2] && comparara2[0] == comparara2[2])
	{
		primero = stoi(comparar1) + stoi(comparar1.substr(2, 2));
		segundo = stoi(comparara2) + stoi(comparara2.substr(2, 2));
		//Busca cual es doble de mayor valor.
		if (primero > segundo)
		{
			return comparar1;
		}
		else
		{
			return comparara2;
		}
	}
	//Casos en donde solo hay un doble
	else if (comparar1[0] == comparar1[2])
	{
		return comparar1;
	}
	else if (comparara2[0] == comparara2[2]) {
		return comparara2;
	}
	else
	{
		//Caso en donde no hay ningun doble
		return buscar_mayor();
	}

}
string Jugador::buscar_mayor() {
	//Esat funcion esta vinculada con la funcion de "buscar doble".
	//Consiste en buscar el domino de mayor si se da el caso en donde el jugador
	// no tiene una ficha doble.
	// Nodos. 
	Nodo* buscar = Head;
	Nodo* buscar2 = Head->next;
	//Valores de las fichas.
	int buscador = 0;
	int buscador2 = 0;
	//Variables para convertir
	string convertir = "";
	string convetir2 = "";
	while (buscar2 != nullptr)
	{
		//Funcion .subsrt, sirve para buscar una parte en especifico de la cadena
		//La fucnion stoi, sierve para convertir un numero de una cadena de caracteres en un numero usable
		convertir = buscar->domino.substr(2, 2);
		buscador = stoi(buscar->domino) + stoi(convertir);

		convetir2 = buscar2->domino.substr(2, 2);

		buscador2 = stoi(buscar2->domino) + stoi(convetir2);
		//si siguiente domino es mayor que el anterior.
		if (buscador < buscador2) {
			buscar = buscar2;
			buscar2 = buscar2->next;
		}
		//si no es mayor al siguiente.
		else
		{
			buscar2 = buscar2->next;
		}


	}
	//Devuelve el domino de mayor valor
	return buscar->domino;
}
int Jugador::contar() {
	//Funcion para poder contar la cantidad de dominos que posee el jugador.
	int cantidad = 0;
	Nodo* contador = new Nodo;
	contador = Head;
	if (contador == NULL) {

		return 0;
	}
	else
	{

		while (contador != NULL)
		{
			cantidad++;
			contador = contador->next;
			
		}
		return cantidad;
	}
}
string Jugador::buscar_en(int posicion) {
	//Esta fucnion consiste en buscar un domino en especifio, en especifico en su posicion
	if (Head == NULL) {
		return "X";
	}
	else if (posicion == 0) {
		//Caso en donde es la cabeza de la lista de dominos en la 
		return Head->domino;
	}
	else if (contar() < posicion || posicion < 0) {
		//Caso en donde el numero de referencia es mayor o menor que la cantidad de la lista
		return NULL;
	}
	else
	{
		//Aqui es donde se busca el domino con el numero de referencia
		int  lugar = 1;
		Nodo* auxilizar = new Nodo;
		auxilizar = Head->next;
		while (auxilizar != NULL)
		{
			if (lugar == posicion) {
				return auxilizar->domino;
			}
			auxilizar = auxilizar->next;
			lugar++;


		}

	}
}
string Jugador::remover_en(int posicion) {
	//Funcion para borrar un nodo en una posicion en especifico
	if (Head == NULL) {
		//Caso en donde no hay dominos.
		cout << "No hay dominos\n";
		return "X";
	}
	if (contar() < posicion || posicion < 0) {//si esta fuera de la cantidad de elementos
		cout << "Numero invalido para la lista\n";
		return Head->domino;
	}
	else if (posicion == 0)
		//si es el head
	{
		Nodo* borrar = Head;
		string dato = borrar->domino;
		Head = Head->next;
		delete borrar;
		return dato;
	}
	else
	{
		//Caso para los demas nodos
		Nodo* aux1 = new Nodo;
		aux1 = Head->next;
		Nodo* aux2 = new Nodo;

		int contar = 1;
		//Consiste en empezar desde el siguiente, osea que no sea el "Head".
		while (contar != posicion && aux1->next != NULL)
		{

			aux2 = aux1;
			aux1 = aux1->next;
			contar++;
		}
		Nodo* guardar = aux1;
		if (contar == posicion)
		{
			//Caso en donde es el ultimo nodo/domino.
			aux2->next = aux1->next;

		}
		//Devuelve el domino/nodo que sea borrado.
		
		return guardar->domino;


	}
}
string Jugador::buscar_igual(string domnio) {
	//Funcion para buscar un domino que sea compatible en la mesa.
	Nodo* buscar = Head;
	int contar = 0;
	while (buscar != NULL)
	{
		if (buscar->domino[0] == domino[0] || buscar->domino[2] == domino[2])
		{
			return remover_en(contar);
		}
		contar++;
		buscar = buscar->next;
	}
	return "X";
}
int Jugador::sumar() {
	//Funcion para poder sumar el valor de cada domino del jugador
	if (Head == NULL)
	{
		return 0;
	}
	else
	{
		Nodo* sum1 = Head;

		int numero1 = 0, total = 0;
		string convertir1 = "";
		while (sum1 != nullptr)
		{
			convertir1 = sum1->domino.substr(2, 2);
			numero1 = stoi(sum1->domino) + stoi(convertir1);
			total = numero1 + total;
			sum1 = sum1->next;
		}
		return total;
	}

}
bool Jugador::ver_domino() {
	//Esta funcion es para saber si un jugador tiene un doble
	string ver = buscar_doble();
	if (ver[0] == ver[2])
	{
		return 1;
	}
	else
	{
		return 0;
	}
}