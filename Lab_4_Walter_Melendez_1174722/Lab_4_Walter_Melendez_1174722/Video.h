#pragma once
#include "Publicacion.h"
using namespace std;
#include <string>
class Video: public Publicacion
{
private:
	string link;
	int duracion;
	string tipo_Video;
	string titulo;
public:
	string GetLink();
	void SetLink();
	int Getduracion();
	void SetDuracion();
	string GetTipo_video();
	void SetTipo_video();
	string GetTitulo();
	void SetTitulo();
	Video(string, string, int, bool, string, string,int,string);
	void EditorVideo();
	~Video();
};

