#include "Texto.h"
#include <string>
#include <iostream>
using namespace std;
string Texto::GetContenido() {
	return contenido;
}
void Texto::SetContenido() {
	this->contenido = contenido;
}
string Texto::GetTitulo() {
	return titulo;
}
void Texto::SetTitulo() {
	this->titulo = titulo;
}
Texto::Texto(string FEcha, string Usuario, int REaciones, bool visibilidad, string Titulo ,string contnido):Publicacion( FEcha,  Usuario,  REaciones,  visibilidad) {
	this->titulo = titulo;
	this->contenido = contnido;
}
void Texto::EditarTexto() {
	Editar();
	cout << "\n";
	cout << "diga el nuevo titulo de la publicacion\n";
	cin >> this->titulo;
	cout << "diga el nuevo contenido de la publicacion\n";
	cin >> this->contenido;
}

