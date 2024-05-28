#include "Imagen.h"
#include <iostream>
string Imagen::GetLink_Imagen() {
	return link_Imagen;
}
string Imagen::GetFormato() {
	return formato;
}
int Imagen::GetAncho() {
	return ancho;
}
int Imagen::GetLArgo() {
	return largo;
}
void Imagen::SetLink_Imagen(string link_Imagen) {
	this->link_Imagen = link_Imagen;
}
void Imagen::SetFormato() {
	this->formato = formato;
}
void Imagen::SetAncho() {
	this->ancho = ancho;
}
void Imagen::SetLargo() {
	this->largo = largo;
}
string Imagen::GetTitutlo() {
	return Titulo;
}
void Imagen::SetTitulo() {
	this->Titulo = Titulo;
}
Imagen::Imagen(string FEcha, string Usuario, int REaciones, bool visibilidad, string LINk, string formato, int ancho, int largo,string titulo) :Publicacion(FEcha,Usuario,REaciones,visibilidad) {
	this->ancho = ancho;
	this->largo = largo;
	this->formato = formato;
	this->link_Imagen = LINk;
	this->Titulo = titulo;
}
void Imagen::EdtitarImagen() {
	Editar();
	cout << "diga el nuevo link del video\n";
	cin >> this->link_Imagen;
	cout << "diga el nuevo formato de la imagen\n";
	cin >> this->formato;
	cout << "diga el nuevo ancho de la imagen\n";
	cin >> this->ancho;
	cout << "diga el nuevo largo de la imagen\n";
	cin >> this->largo;
	cout << "diga el nuevo titulo de la publicacion de la imagen\n";
	cout << this->Titulo;
}