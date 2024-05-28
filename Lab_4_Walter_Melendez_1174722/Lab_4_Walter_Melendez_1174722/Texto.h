#pragma once
#include "Publicacion.h"
#include <string>
using namespace std;
class Texto:public Publicacion
{
private:
	string titulo;
	string contenido;
public:
	string GetTitulo();
	void SetTitulo();
	void SetContenido();
	string GetContenido();
	Texto(string, string, int, bool, string, string);
	void EditarTexto();
};

