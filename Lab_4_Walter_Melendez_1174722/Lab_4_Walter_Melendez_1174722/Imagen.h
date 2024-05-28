#pragma once
#include <string>
#include "Publicacion.h"
using namespace std;
class Imagen:public Publicacion
{
private:
	string link_Imagen;
	int ancho;
	int largo;
	string formato;
	string Titulo;
public:
	string GetLink_Imagen();
	void SetLink_Imagen(string link_Imagen);
	int GetAncho();
	void SetAncho();
	string GetFormato();
	void SetFormato();
	int GetLArgo();
	void SetLargo();
	Imagen(string, string, int, bool, string, string, int, int,string);
	string GetTitutlo();
	void SetTitulo();
	void EdtitarImagen();
};

