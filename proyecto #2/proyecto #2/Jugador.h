#pragma once
#include "Nodo.h"
#include <string>
using namespace std;
class Jugador
{
private:
	string domino;
	Nodo* Head;
	
public:
	
	//Contructor del jugador
	Jugador() {
		Head = NULL;
	}
	void add(string domino);
	void remove(string domino);
	void imprimir();
	string buscar_doble();
	string buscar_mayor();
	string buscar_en(int posicion);
	int contar();
	string remover_en(int posicion);
	string buscar_igual(string domino);
	int sumar();
	bool ver_domino();
};

