

#include <iostream>
using namespace std;
#include "Lista.h"
#include"Nodo.h"
#include "Cola.h"
#include "Stack.h"
#include "Lista_C.h"
#include <string>
int main()
{
	int uno = 10;
	int dos = 56;
	int rt = (uno > dos) ? uno : dos;
	cout << rt << endl;
    Lista* lista1 = new Lista();
	/*for (int i = 0; i < 10; i++)
	{
		lista1->Add((char)(i+60));
	}*/
	lista1->Add('A');
	lista1->Add('B');
	lista1->Add('C');
	lista1->Add('D');
	lista1->Add('E');
	cout << "Su longitud es de " << lista1->GetLongitud() << endl;
	
	
	lista1->imprimir();
	lista1->Replace('C', 'z');
	lista1->imprimir();
	cout << endl;
	//----------------------------------------------11/04/24-------------------------------
	cout << "Inicio de uso de una cola\n";
	Cola* cola1 = new Cola();
	cola1->Queque('w');
	cola1->Queque('a');
	cola1->Queque('l');
	cola1->Queque('t');
	cola1->Queque('e');
	cola1->Queque('r');
	cout << "Uso peek en colas\n";
	cout << "Primer peek en cola:" << cola1->Peek() << endl;
	cola1->Dequeue();
	cout << "segundo peek en cola:" << cola1->Peek()<<endl;
	
	//----------------------------------------------------------------------------------------------------------
	cout << "\t----Inicio de uso de las pilas\n";
	Stack* pila = new Stack();
	pila->Push('w');
	pila->Push('a');
	pila->Push('l');
	pila->Push('t');
	pila->Push('e');
	pila->Push('r');
	cout << "Uso peek en pilas \n";
	cout<<"primer peek en stack: " << pila->Peek() << endl;
	pila->Pop();
	cout << "segundo peek en stack: " << pila->Peek() << endl;
	cout << "\tInicio de la lista circular\n";
	Lista_C* circular = new Lista_C();
	circular->add('a');
	circular->add('b');
	circular->add('z');
	circular->add('c');
	circular->print();
	
	cout << "-------------------------------\n";
	circular->remove('z');
	circular->print();
	cout << "-------------------------------\n";
	circular->Replace('c','e');
	circular->print();
	cout << "\tAppend\n";
	circular->Append(circular);
	circular->print();



	string palabra = "abcdefd";
	string vo = "";
	int cun = 0;
	char a = '0';
	while (cun < palabra.length())
	{
		if (palabra[3]) {
			a = palabra[0];
			palabra[0] = palabra[3];
			palabra[3] = a;
			a = palabra[1];
			palabra[1] = palabra[2];
			palabra[2] = a;
		}
		cun++;

	}
	cout << palabra << endl;
	
	/*while (cun>0)
	{
		
		a = palabra[cun];
		if (!a[0] == palabra[3]) {
			
			vo.append(a);
		}
		
		cun--;
		a = a.empty();
	}*/
	
	///-----------------------------
	cout << "Convertir a binario\n";
	Lista* Binario = new Lista();
	Binario->Add(1);
	Binario->Add(0);
	Binario->Add(1);
	Binario->Add(0);
	
    return 0;



}

