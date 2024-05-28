#pragma once
#include <string>
using namespace std;
class Nodo
{
public:
	Nodo *next;
	string domino;
	//Constructor de nodos
	Nodo() {
		domino = " ";
		next = NULL;
	}

};

