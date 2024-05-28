

#include <iostream>
#include <string>
using namespace std;
#include"Publicacion.h"
#include"Texto.h"
#include"Video.h"
#include"Imagen.h"
int* nombre(int a) {
    cout << "hola mundo\n";
    int* b = &a;
    return b;
}
int main()
{
    /*Texto* Uno = new Texto("8/02/2024","Walter",100,true,"Primera publicacion","askndaoinbdiancinacskjacsx");
    cout << Uno->GetTitulo()<<endl;
    cout << Uno->GetContenido()<<endl;
    cout << Uno->GetReacciones()<<endl;
    Uno->Aumentar_disminurReacciones();
    cout << Uno->GetReacciones()<<" reacciones\n";
    Uno->Visibilidad();
    Video* Dos = new Video("9/0.2/2024","Francsico",250,false,"Link: aksdnasdiauhdaksbd",".MP4",120,"titulo Primer video");
    cout << Dos->GetFecha() << endl;
    cout << Dos->GetUsuario() << endl;
    cout << Dos->GetTipo_video() << endl;
    Uno->EditarTexto();
    cout << Uno->GetTitulo() << endl;
    cout << Uno->GetReacciones() << endl;*/
    int arr[4] = {1,2,3,4};
    int le = *(&arr + 1) - arr;
    int *ptr;
    ptr = nombre(15);
    cout << *ptr<<endl;
    Imagen* TRes = new Imagen("09/02/2024", "Juan", 30, true, "link: anosaibxiabxabsuasbdas", "PNG", 1080, 1080, "MEME");
    cout << TRes->GetLink_Imagen() << endl;
    cout << TRes->GetFormato()<<endl;
    cout << TRes->GetTitutlo() << endl;
    TRes->SetLink_Imagen("abedecacasocnaosicnaoic");
    cout << TRes->GetLink_Imagen() << endl;
    return 0;
}
