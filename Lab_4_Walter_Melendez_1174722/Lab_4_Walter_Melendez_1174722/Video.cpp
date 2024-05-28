#include "Video.h"
#include <iostream>
string Video::GetLink() {
	return link;
}
void Video::SetLink() {
	this->link = link;
}
string Video::GetTipo_video() {
	return tipo_Video;
}
void Video::SetTipo_video() {
	this->tipo_Video = tipo_Video;
}
int Video::Getduracion() {
	return duracion;
}
void Video::SetDuracion() {
	this->duracion = duracion;
}
string Video::GetTitulo() {
	return titulo;
}
void Video::SetTitulo() {
	this->titulo = titulo;
}
Video::Video(string FEcha, string Usuario, int REaciones, bool visibilidad, string link, string tipo_video, int duracion,string titulo) :Publicacion(FEcha, Usuario,REaciones,visibilidad) {
	this->duracion = duracion;
	this->tipo_Video = tipo_video;
	this->link = link;
	this->titulo = titulo;
}
void Video::EditorVideo() {
	Editar();

	cout << "diga el nuevo link del video\n";
	cin >> this->link;
	cout << "diga el nuevo tipo de video\n";
	cin >> this->tipo_Video;
	cout << "diga la nueva duracion del video\n";
	cin >> this->duracion;
	cout << "diga el nuevo titulo de la publicacion\n";
	cin >> this->titulo;
}
Video::~Video() {

}