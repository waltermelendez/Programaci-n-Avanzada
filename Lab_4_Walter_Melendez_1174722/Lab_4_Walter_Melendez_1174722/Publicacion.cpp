#include "Publicacion.h"
using namespace std;
#include <string>
#include <iostream>
Publicacion::Publicacion(string FEcha, string Usuario, int REaciones, bool visibilidad) {
	fecha = FEcha;
	usuario = Usuario;
	reacciones = REaciones;
	visibilidad = visibilidad;
}
string Publicacion::GetFecha() {
	return fecha;
}
void Publicacion::SetFecha(){
	this->fecha = fecha;
}
string Publicacion::GetUsuario() {
	return usuario;
}
void Publicacion::SetUsusario() {
	this->usuario = usuario;
}
void Publicacion::SetVisibilidad() {
	this->visibilidad = visibilidad;
}
bool Publicacion::GetVisibilidad() {
	return visibilidad;
}
int Publicacion::GetReacciones() {
	return reacciones;
}
void Publicacion::SetReacciones() {
	this->reacciones = reacciones;
	
}

int Publicacion::Aumentar_disminurReacciones() {

	bool R;
	cout <<"Desea aumentar o disminuir reacciones, si(1)  no(0)\n";
	cin >> R;
	if (R) {
		this->reacciones = reacciones * 10;
		
		return reacciones;
	}
	else {
		this->reacciones = reacciones / 10;
		return reacciones;
	}
}
bool Publicacion::Visibilidad() {
	cout << "Desea cambiar la visiblidad de la publicacion, si(1)  no(0)\n";
	cin >> this->visibilidad;
	if (this->visibilidad) {
		cout << "La publicacion se ha puesto en privado\n";
		return visibilidad;
	}
	else {
		cout << "La publicacion se ha puesto en publico\n";
		return visibilidad;
	}
}
void Publicacion::Editar() {
	cout << "diga la nueva fecha\n";
	cin >> this->fecha;
	cout << "diga el nuevo nombre de usuario\n";
	cin >> this->usuario;
	cout << "diga el nuevo numero de racciones\n";
	cin >> this->reacciones;
	cout << "diga la visibilidad de la publicacion, privado(1) publico(0)\n";
	cin >> this->visibilidad;
	cout << endl;
}


