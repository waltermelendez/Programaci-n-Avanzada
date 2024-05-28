#pragma once

#include <string>
using namespace std;
class Publicacion
{private:
	string fecha;
	string usuario;
	int reacciones;
	bool visibilidad;
	
public:
	Publicacion(string, string, int, bool);
	int Aumentar_disminurReacciones();
	bool Visibilidad();
	void Editar();
	string GetFecha();
	void SetFecha();
	string GetUsuario();
	void SetUsusario();
	int GetReacciones();
	void SetReacciones();
	bool GetVisibilidad();
	void SetVisibilidad();
	

	
};


