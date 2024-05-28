

#include <iostream>
#include <cstdlib>//libreria originacia de C, se va a usar para poder usar la funcion de numeros aleatorios Y usar "NULL"
#include <string>// libreria para poder usar los string normales
#include<ctime> //libreria originacia de C, se va a usar para poder usar la funcion de numeros aleatorios, pero tambien se usa para medir el tiempo
#include "Jugador.h"
#include "Nodo.h"
#include "Pozo.h"
#include"Mesa.h"
#include "Lista_cirular.h"


using namespace std;
int puntos_aganar = 0;
Pozo* pozo = new Pozo();
Mesa* mesa = new Mesa();
int numero_dominos = 28;
string* Dominos = new string[numero_dominos];
Lista_cirular* posicion = new Lista_cirular();
void Bubble(int* numeros, int largo) {
	//funcion para buscar quien es el juador con el doble o ficha mas grande, ademas de buscar el orden de los jugadores
	for (int i = 0; i < largo; i++)
	{
		for (int j = i + 1; j < largo; j++)
		{
			if (numeros[i] < numeros[j])
			{
				int temporal = numeros[i];
				numeros[i] = numeros[j];
				numeros[j] = temporal;
			}
		}
	}
	cout << endl;
}
void DOS(int puntos_aganar)
{
	//Declaracion de los dominos
	Dominos[0] = "0|0";
	Dominos[1] = "1|0";
	Dominos[2] = "2|0";
	Dominos[3] = "3|0";
	Dominos[4] = "4|0";
	Dominos[5] = "5|0";
	Dominos[6] = "6|0";
	Dominos[7] = "1|1";
	Dominos[8] = "1|2";
	Dominos[9] = "1|3";
	Dominos[10] = "1|4";
	Dominos[11] = "1|5";
	Dominos[12] = "1|6";
	Dominos[13] = "2|2";
	Dominos[14] = "2|3";
	Dominos[15] = "2|4";
	Dominos[16] = "2|5";
	Dominos[17] = "2|6";
	Dominos[18] = "3|3";
	Dominos[19] = "3|4";
	Dominos[20] = "3|5";
	Dominos[21] = "3|6";
	Dominos[22] = "4|4";
	Dominos[23] = "4|5";
	Dominos[24] = "4|6";
	Dominos[25] = "5|5";
	Dominos[26] = "5|6";
	Dominos[27] = "6|6";

	//Declaracion de los jugadores
	Jugador Jugador1;
	Jugador Jugador2;



	//valores para poder escojer un domino de forma aleatoria.
	int D = 7;
	int arriba = 0;
	srand(time(NULL));
	int random;
	int j = 0, inferior = 0, contador = 0, superior = 20;
	bool domino1 = false, domino2 = false;
	int j2 = 0;
	//Asignacion de dominos de jugador 1
	while (!domino1)
	{
		random = inferior + rand() % (superior - inferior);//funcion para buscar dominos de forma aleatoria

		if (Dominos[random] != "X")//Si ya fue escojido anteriormente, se va ser representado con: "X", y no va a ser agragdo a la lista.
		{
			Jugador1.add(Dominos[random]);
			Dominos[random] = "X";
			contador++;
		}
		if (contador == 7)// Si alcanza la cantidad de dominos impuesta, se sale del ciclo.
		{
			domino1 = 1;
			contador = 0;
		}

	}

	//Asignacion de dominos de jugador 2
	while (!domino2)
	{
		random = inferior + rand() % (superior - inferior);
		//cout << "random " << random << endl;
		if (Dominos[random] != "X")
		{
			Jugador2.add(Dominos[random]);
			Dominos[random] = "X";
			contador++;
		}
		if (contador == 7)
		{
			domino2 = 1;
		}
	}


	//Asignar las fichas restantes
	for (int i = 0; i < numero_dominos; i++)
	{

		if (Dominos[i] != "X") {
			pozo->Queque(Dominos[i]);//Busca todos los dominos restantes.

		}

	}

	//Valores que se van a usar para saber quien va primero.
	bool juego = false, juego2 = false;
	bool verfficar1 = false, verficar2 = 0;


	string pasar = "";
	int convert1 = 0, convert3 = 0, convertir2 = 0, convertir4 = 0;
	int Largo = 2;
	int* orden = new int[Largo];
	char* lugares = new char[Largo];
	//Buscar quien tiene el doble mayor o que tenga la ficha de mayor valor y el orden en donde se va a empezar ↓
	Lista_cirular* posicion = new Lista_cirular();
	if (Jugador1.ver_domino())
	{
		juego = Jugador1.ver_domino();
		pasar = Jugador1.buscar_doble().substr(2, 2);
		convert1 = stoi(Jugador1.buscar_doble()) + stoi(pasar);

		orden[0] = convert1;
	}
	else
	{
		orden[0] = -convert1;
	}
	if (Jugador2.ver_domino())
	{
		juego2 = Jugador2.ver_domino();
		pasar = Jugador2.buscar_doble().substr(2, 2);
		convertir2 = stoi(Jugador2.buscar_doble()) + stoi(pasar);
		orden[1] = convertir2;
	}
	else
	{
		orden[1] = -convertir2;
	}
	Bubble(orden, Largo);
	for (int i = 0; i < 2; i++)
	{
		if (orden[i] == convert1)
		{
			lugares[i] = 'A';
		}
		else if (orden[i] == convertir2)
		{
			lugares[i] = 'B';
		}
		else
		{
			if (!juego)
			{
				lugares[i] = 'A';
			}
			else if (!juego2)
			{
				lugares[i] = 'B';
			}
		}
	}
	for (int i = 0; i < 2; i++)
	{

		posicion->agregar(lugares[i]);
	}
	cout << endl;
	//Variables que se van a usar durante el juego
	bool empezar = false;
	int escojer = 0;
	int Contador = 0;
	int Lugar = 0;
	bool verificar1 = 0, verificar2 = 0;

	//Inicio del juego ↓	
	do {
		Lugar = stoi(posicion->ver(Contador));
		switch (Lugar)
		{
		case 65:
		{
			while (!verfficar1)
			{
				if (mesa->Peek() == "X")
				{
					string Respuesta1 = "si";
					while (Respuesta1 == "si" || Respuesta1 == "Si")
					{
						//Se empieza a buscar una ficha que diga el jugador.
						mesa->impirmir_M();
						cout << "-------------------------------------\n";
						Jugador1.imprimir();
						cout << "Diga la posicion de una ficha jugador 1.\n";
						cin >> escojer;
						if (escojer < 0)
						{
							break;
						}
						else
						{
							cout << "Su domino es :" << Jugador1.buscar_en(escojer) << endl;
							cout << "Desa cambiar su ficha\n";
							cin >> Respuesta1;
							cout << "++++++++++++++++++++++++++++++++++\n";
						}
					}
					mesa->Push(Jugador1.remover_en(escojer));
					if (Contador == 1)
					{
						Contador = 0;
					}
					else
					{
						Contador++;
					}
					break;
				}
				else
				{
					string Respuesta1 = "si";
					while (Respuesta1 == "si" || Respuesta1 == "Si")
					{
						//Se empieza a buscar una ficha que diga el jugador.
						mesa->impirmir_M();
						cout << "-------------------------------------\n";
						Jugador1.imprimir();
						cout << "Diga la posicion de una ficha jugaodr 1.\n";
						cin >> escojer;
						if (escojer < 0)
						{
							break;
						}
						else
						{
							cout << "Su domino es :" << Jugador1.buscar_en(escojer) << endl;
							cout << "Desa cambiar su ficha\n";
							cin >> Respuesta1;
							cout << "++++++++++++++++++++++++++++++++++\n";
						}
					}
					if (escojer < 0)// si no tiene un ficha que coincida en la mesa
					{
						//Primero pregunta si tiene fichas el pozo
						if (pozo->Peek() == "X") {
							cout << "el juego ha terminado, no hay mas fichas en el pozo\n";
							empezar = 1;
							break;
						}
						else
						{
							//Si  tiene, entonces se procede a buscar una ficha para el jugador.
							string respuesta = " ";
							cout << "Desea recoger el domino y usarla para continuar\n";
							cin >> respuesta;
							if ("si" || "Si")
							{

								respuesta = pozo->buscar(pozo, mesa->Peek());
								Jugador1.add(respuesta);
								int nuevo = Jugador1.contar();
								Jugador1.remover_en(nuevo);
								if (Contador == 1)
								{
									Contador = 0;
								}
								else
								{
									Contador++;
								}
								break;
							}
							else //Si eljugador decide perder el turno

							{
								cout << "Usted a decidido a perder el turno\n";
								cout << "-------------------------------------\n";
								pozo->imprimir();
								if (Contador == 1)
								{
									Contador = 0;
								}
								else
								{
									Contador++;
								}
								break;
							}
						}
					}
					//si la ficha que se escogio es igual
					if (mesa->Peek()[0] == Jugador1.buscar_en(escojer)[0] || mesa->Peek()[2] == Jugador1.buscar_en(escojer)[2] || mesa->Peek()[2] == Jugador1.buscar_en(escojer)[0] || mesa->Peek()[0] == Jugador1.buscar_en(escojer)[2])
					{
						cout << Jugador1.contar() << endl;
						mesa->Push(Jugador1.remover_en(escojer));
						cout << "-------------------------------------\n";
						mesa->impirmir_M();
						if (Contador == 1)
						{
							Contador = 0;
						}
						else
						{
							Contador++;
						}
						break;
					}//si intentta hacer trampa que se escogio es igual

				}
			}

		}break;
		case 66:
		{
			while (!verficar2)
			{
				if (mesa->Peek() == "X")
				{
					string Respuesta2 = "si";
					while (Respuesta2 == "si" || Respuesta2 == "Si")
					{
						mesa->impirmir_M();
						cout << "-------------------------------------\n";
						Jugador2.imprimir();
						cout << "Diga la posicion de la ficha jugador 2.\n";
						cin >> escojer;
						if (escojer < 0)
						{
							break;
						}
						else
						{
							cout << "Su domino es: " << Jugador2.buscar_en(escojer) << endl;
							cout << "Desa cambiar su ficha\n";
							cin >> Respuesta2;
							cout << "--------------------------\n";
						}
					}
					mesa->Push(Jugador2.remover_en(escojer));
					if (Contador == 1)
					{
						Contador = 0;
					}
					else
					{
						Contador++;
					}
					break;
				}
				else
				{
					string Respuesta2 = "si";
					while (Respuesta2 == "si" || Respuesta2 == "Si")
					{
						mesa->impirmir_M();
						cout << "-------------------------------------\n";
						Jugador2.imprimir();
						cout << "Diga la posicion de la ficha jugador 2.\n";
						cin >> escojer;
						if (escojer < 0)
						{
							break;
						}
						else
						{
							cout << "Su domino es: " << Jugador2.buscar_en(escojer) << endl;
							cout << "Desa cambiar su ficha\n";
							cin >> Respuesta2;
							cout << "--------------------------\n";
						}
					}
					if (escojer < 0)// si no tiene un ficha que coincida en la mesa
					{
						if (pozo->Peek() == "X") {
							cout << "El juego se ha terminado\n";
							empezar = 1;
							break;
						}
						else
						{
							if (pozo->Peek() == "X")
							{
								cout << "el juego ha terminado, no hay mas fichas en el pozo\n";
								empezar = 1;
								break;
							}
							else
							{
								string respuesta = " ";
								cout << "Desea recoger el domino y usarla para continuar\n";
								cin >> respuesta;
								if ("si" || "Si")
								{

									respuesta = pozo->buscar(pozo, mesa->Peek());//*******************
									mesa->Push(respuesta);

									cout << "---------------------------------\n";
									mesa->impirmir_M();
									if (Contador == 1)
									{
										Contador = 0;
									}
									else
									{
										Contador++;
									}
									break;
								}
								else
								{
									cout << "Usted a decidido a perder el turno\n";
									pozo->imprimir();
									if (Contador == 1)
									{
										contador = 0;
									}
									else
									{
										Contador++;
									}
									break;
								}
							}
						}

					}
					//si la ficha que se escogio es igual
					if (mesa->Peek()[0] == Jugador2.buscar_en(escojer)[0] || mesa->Peek()[2] == Jugador2.buscar_en(escojer)[2] || mesa->Peek()[2] == Jugador2.buscar_en(escojer)[0] || mesa->Peek()[0] == Jugador2.buscar_en(escojer)[2])
					{
						mesa->Push(Jugador2.remover_en(escojer));

						cout << "--------------------------\n";
						mesa->impirmir_M();
						if (Contador == 1)
						{
							Contador = 0;
						}
						else
						{
							Contador++;
						}
						break;
					}

				}
			}

		}break;
		default:
		{
			cout << "Hubo un fallo en el programa\n";
		}
		break;
		}
		system("cls");
		//Funcion para limpiar la pantalla ↑.
		//Mostrar la cantidad de puntos de cada jugador.
		cout << "el total de puntos del jugador 1 es: " << Jugador1.sumar() << endl;
		cout << "el total de puntos del jugador 1 es: " << Jugador2.sumar() << endl;
		cout << endl;
		//Esta comparacion es para saber cual jugador que tiene mayor cantidad de puntos.
	} while (!empezar);

	if (Jugador1.sumar() > puntos_aganar || Jugador1.sumar() > Jugador2.sumar())
	{
		cout << "El jugador uno ha ganado el juego.\n";
	}
	else
	{
		cout << "El jugador dos ha ganado el juego.\n";
	}
}
void TRES_CUATRO(int jugador, int puntos_aganar) {
	Dominos[0] = "0|0";
	Dominos[1] = "1|0";
	Dominos[2] = "2|0";
	Dominos[3] = "3|0";
	Dominos[4] = "4|0";
	Dominos[5] = "5|0";
	Dominos[6] = "6|0";
	Dominos[7] = "1|1";
	Dominos[8] = "1|2";
	Dominos[9] = "1|3";
	Dominos[10] = "1|4";
	Dominos[11] = "1|5";
	Dominos[12] = "1|6";
	Dominos[13] = "2|2";
	Dominos[14] = "2|3";
	Dominos[15] = "2|4";
	Dominos[16] = "2|5";
	Dominos[17] = "2|6";
	Dominos[18] = "3|3";
	Dominos[19] = "3|4";
	Dominos[20] = "3|5";
	Dominos[21] = "3|6";
	Dominos[22] = "4|4";
	Dominos[23] = "4|5";
	Dominos[24] = "4|6";
	Dominos[25] = "5|5";
	Dominos[26] = "5|6";
	Dominos[27] = "6|6";
	//Declaracion de los jugadores
	Jugador Jugador1;
	Jugador Jugador2;
	Jugador Jugador3;
	Jugador Jugador4;

	//valores para poder escojer un domino de forma aleatoria.
	int D = 7;
	int arriba = 0;

	srand(time(NULL));

	int random;
	int j = 0, inferior = 0, contador = 0, superior = 27;
	bool domino1 = false, domino2 = false, domino3 = false, domino4 = 0;


	while (!domino1)
	{
		random = inferior + rand() % (superior - inferior);//funcion para buscar dominos de forma aleatoria

		if (Dominos[random] != "X")//Si ya fue escojido anteriormente, se va ser representado con: "X", y no va a ser agragdo a la lista.
		{
			Jugador1.add(Dominos[random]);
			Dominos[random] = "X";
			contador++;
		}
		if (contador == 5)// Si alcanza la cantidad de dominos impuesta, se sale del ciclo.
		{
			domino1 = 1;
			contador = 0;
		}

	}
	while (!domino2)
	{
		random = inferior + rand() % (superior - inferior);//funcion para buscar dominos de forma aleatoria

		if (Dominos[random] != "X")//Si ya fue escojido anteriormente, se va ser representado con: "X", y no va a ser agragdo a la lista.
		{
			Jugador2.add(Dominos[random]);
			Dominos[random] = "X";
			contador++;
		}
		if (contador == 5)// Si alcanza la cantidad de dominos impuesta, se sale del ciclo.
		{
			domino2 = 1;
			contador = 0;
		}
	}

	while (!domino3)
	{
		random = inferior + rand() % (superior - inferior);//funcion para buscar dominos de forma aleatoria

		if (Dominos[random] != "X")//Si ya fue escojido anteriormente, se va ser representado con: "X", y no va a ser agragdo a la lista.
		{
			Jugador3.add(Dominos[random]);
			Dominos[random] = "X";
			contador++;
		}
		if (contador == 5)// Si alcanza la cantidad de dominos impuesta, se sale del ciclo.
		{
			domino3 = 1;
			contador = 0;
		}
	}
	if (jugador == 4)
	{
		while (!domino4)
		{
			random = inferior + rand() % (superior - inferior);//funcion para buscar dominos de forma aleatoria

			if (Dominos[random] != "X")//Si ya fue escojido anteriormente, se va ser representado con: "X", y no va a ser agragdo a la lista.
			{
				Jugador4.add(Dominos[random]);
				Dominos[random] = "X";
				contador++;
			}
			if (contador == 5)// Si alcanza la cantidad de dominos impuesta, se sale del ciclo.
			{
				domino4 = 1;
				contador = 0;
			}
		}
	}
	//Asignar las fichas restantes
	for (int i = 0; i < numero_dominos; i++)
	{

		if (Dominos[i] != "X") {
			pozo->Queque(Dominos[i]);//Busca todos los dominos restantes.

		}

	}
	Jugador1.add(pozo->Dequeque());
	Jugador1.add(pozo->Dequeque());
	Jugador2.add(pozo->Dequeque());
	Jugador2.add(pozo->Dequeque());
	Jugador3.add(pozo->Dequeque());
	Jugador3.add(pozo->Dequeque());
	if (jugador == 4)
	{
		Jugador4.add(pozo->Dequeque());
		Jugador4.add(pozo->Dequeque());
	}
	Jugador1.imprimir();
	cout << endl;
	Jugador2.imprimir();
	cout << endl;
	Jugador3.imprimir();
	cout << endl;
	Jugador4.imprimir();
	cout << endl;

	if (jugador == 4)
	{
		bool juego1 = 0;
		bool juego2 = 0;
		bool juego3 = 0;
		bool juego4 = 0;
		string pasar = "";
		int convert1 = 0, convert3 = 0, convertir2 = 0, convertir4 = 0;
		int Largo = 4;
		int* orden = new int[Largo];
		char* lugares = new char[Largo];

		if (Jugador1.ver_domino())
		{
			juego1 = Jugador1.ver_domino();
			pasar = Jugador1.buscar_doble().substr(2, 2);
			convert1 = stoi(Jugador1.buscar_doble()) + stoi(pasar);

			orden[0] = convert1;
		}
		else
		{
			orden[0] = -convert1;
		}
		if (Jugador2.ver_domino())
		{
			juego2 = Jugador2.ver_domino();
			pasar = Jugador2.buscar_doble().substr(2, 2);
			convertir2 = stoi(Jugador2.buscar_doble()) + stoi(pasar);
			orden[1] = convertir2;
		}
		else
		{
			orden[1] = -convertir2;
		}
		if (Jugador3.ver_domino())
		{
			juego3 = Jugador3.ver_domino();
			pasar = Jugador3.buscar_doble().substr(2, 2);
			convert3 = stoi(Jugador3.buscar_doble()) + stoi(pasar);
			orden[2] = convert3;
		}
		else
		{
			orden[2] = -convert3;
		}
		if (Jugador4.ver_domino())
		{
			juego4 = Jugador4.ver_domino();
			pasar = Jugador4.buscar_doble().substr(2, 2);
			convertir4 = stoi(Jugador4.buscar_doble()) + stoi(pasar);
			orden[3] = convertir4;
		}
		else
		{
			orden[3] = -convertir4;
		}

		Bubble(orden, Largo);
		for (int i = 0; i < 4; i++)
		{
			if (orden[i] == convert1)
			{
				lugares[i] = 'A';
			}
			else if (orden[i] == convertir2)
			{
				lugares[i] = 'B';
			}
			else if (orden[i] == convert3)
			{
				lugares[i] = 'C';
			}
			else if (orden[i] == convertir4)
			{
				lugares[i] = 'D';
			}
			else
			{
				if (!juego1)
				{
					lugares[i] = 'A';
				}
				else if (!juego2)
				{
					lugares[i] = 'B';
				}
				else if (!juego3) {
					lugares[i] = 'C';
				}
				else if (!juego4) {

					lugares[i] = 'D';
				}
			}
		}


		for (int i = 0; i < 4; i++)
		{
			cout << lugares[i] << " ";
			posicion->agregar(lugares[i]);
		}
		cout << endl;
		bool empezar = false;
		int escojer = 0;
		int contador = 0;
		int Lugar = 0;
		bool verificar1 = 0, verificar2 = 0, verificar3 = 0, verificar4 = 0;
		do
		{

			Lugar = stoi(posicion->ver(contador));

			switch (Lugar)
			{
			case 65://Jugador 1
			{
				if (mesa->Peek() == "X")
				{
					string Respuesta2 = "si";
					while (Respuesta2 == "si" || Respuesta2 == "Si")
					{
						Jugador1.imprimir();
						cout << "----------------------------------------\n";
						mesa->impirmir_M();
						cout << "Diga la posicion de la ficha jugador 2.\n";
						cin >> escojer;
						if (escojer < 0)
						{
							break;
						}
						else
						{
							cout << "Su domino es: " << Jugador1.buscar_en(escojer) << endl;
							cout << "Desa cambiar su ficha\n";
							cin >> Respuesta2;
							cout << "--------------------------\n";
						}
					}
					mesa->Push(Jugador1.remover_en(escojer));
					if (contador == 3)
					{
						contador = 0;
					}
					else
					{
						contador++;
					}
					break;
				}
				else
				{
					while (!verificar1)
					{
						string Respuesta2 = "si";
						while (Respuesta2 == "si" || Respuesta2 == "Si")
						{
							Jugador1.imprimir();
							cout << "----------------------------------------\n";
							mesa->impirmir_M();
							cout << "Diga la posicion de la ficha jugador 2.\n";
							cin >> escojer;
							if (escojer < 0)
							{
								break;
							}
							else
							{
								cout << "Su domino es: " << Jugador1.buscar_en(escojer) << endl;
								cout << "Desa cambiar su ficha\n";
								cin >> Respuesta2;
								cout << "--------------------------\n";
							}
						}
						//si la ficha que se escogio es igual
						if (escojer < 0)// si no tiene un ficha que coincida en la mesa
						{
							if (pozo->Peek() == "X") {
								cout << "El juego se ha terminado\n";
								empezar = 1;
							}
							else
							{
								if (pozo->Peek() == "X")
								{
									cout << "el juego ha terminado, no hay mas fichas en el pozo\n";
									empezar = 1;
								}
								else
								{
									string respuesta = " ";
									cout << "Desea recoger el domino y usarla para continuar\n";
									cin >> respuesta;
									if ("si" || "Si")
									{

										respuesta = pozo->buscar(pozo, mesa->Peek());//*******************
										Jugador2.add(respuesta);
										int nuevo = Jugador1.contar();
										Jugador2.remover_en(nuevo);

										cout << "---------------------------------\n";
										mesa->impirmir_M();
										if (contador == 3)
										{
											contador = 0;
										}
										else
										{
											contador++;
										}
										break;
									}
									else
									{
										cout << "Usted a decidido a perder el turno\n";
										pozo->imprimir();
										if (contador == 3)
										{
											contador = 0;
										}
										else
										{
											contador++;
										}
										break;
									}
								}
							}

						}
						if (mesa->Peek()[0] == Jugador1.buscar_en(escojer)[0] || mesa->Peek()[2] == Jugador1.buscar_en(escojer)[2] || mesa->Peek()[2] == Jugador1.buscar_en(escojer)[0] || mesa->Peek()[0] == Jugador1.buscar_en(escojer)[2])
						{
							mesa->Push(Jugador1.remover_en(escojer));

							cout << "--------------------------\n";
							mesa->impirmir_M();
							if (contador == 3)
							{
								contador = 0;
							}
							else
							{
								contador++;
							}
							break;
						}//si intenta hacer trampa que se escogio es igual

					}
				}

			}
			break;
			case 66: //Jugador 2
			{
				if (mesa->Peek() == "X")
				{
					string Respuesta2 = "si";
					while (Respuesta2 == "si" || Respuesta2 == "Si")
					{
						Jugador2.imprimir();
						cout << "----------------------------------------\n";
						mesa->impirmir_M();
						cout << "Diga la posicion de la ficha jugador 2.\n";
						cin >> escojer;
						if (escojer < 0)
						{
							break;
						}
						else
						{
							cout << "Su domino es: " << Jugador2.buscar_en(escojer) << endl;
							cout << "Desa cambiar su ficha\n";
							cin >> Respuesta2;
							cout << "--------------------------\n";
						}
						break;
					}
					mesa->Push(Jugador2.remover_en(escojer));
					if (contador == 3)
					{
						contador = 0;
					}
					else
					{
						contador++;
					}
					break;
				}
				else
				{
					while (!verificar2)
					{
						string Respuesta2 = "si";
						while (Respuesta2 == "si" || Respuesta2 == "Si")
						{
							Jugador2.imprimir();
							cout << "----------------------------------------\n";
							mesa->impirmir_M();
							cout << "Diga la posicion de la ficha jugador 2.\n";
							cin >> escojer;
							if (escojer < 0)
							{
								break;
							}
							else
							{
								cout << "Su domino es: " << Jugador2.buscar_en(escojer) << endl;
								cout << "Desa cambiar su ficha\n";
								cin >> Respuesta2;
								cout << "--------------------------\n";
							}
							break;
						}
						if (escojer < 0)// si no tiene un ficha que coincida en la mesa
						{
							if (pozo->Peek() == "X") {
								cout << "El juego se ha terminado\n";
								empezar = 1;
							}
							else
							{
								if (pozo->Peek() == "X")
								{
									cout << "el juego ha terminado, no hay mas fichas en el pozo\n";
									empezar = 1;
								}
								else
								{
									string respuesta = " ";
									cout << "Desea recoger el domino y usarla para continuar\n";
									cin >> respuesta;
									if ("si" || "Si")
									{

										respuesta = pozo->buscar(pozo, mesa->Peek());//*******************
										Jugador2.add(respuesta);
										int nuevo = Jugador2.contar();
										Jugador2.remover_en(nuevo);

										cout << "---------------------------------\n";
										mesa->impirmir_M();
										if (contador == 3)
										{
											contador = 0;
										}
										else
										{
											contador++;
										}
										break;
									}
									else
									{
										cout << "Usted a decidido a perder el turno\n";
										pozo->imprimir();
										if (contador == 3)
										{
											contador = 0;
										}
										else
										{
											contador++;
										}
										break;
									}
								}
							}

						}
						//si la ficha que se escogio es igual
						if (mesa->Peek()[0] == Jugador2.buscar_en(escojer)[0] || mesa->Peek()[2] == Jugador2.buscar_en(escojer)[2] || mesa->Peek()[2] == Jugador2.buscar_en(escojer)[0] || mesa->Peek()[0] == Jugador2.buscar_en(escojer)[2])
						{
							mesa->Push(Jugador2.remover_en(escojer));

							cout << "--------------------------\n";
							mesa->impirmir_M();
							if (contador == 3)
							{
								contador = 0;
							}
							else
							{
								contador++;
							}
							break;
						}

					}
				}

			}
			break;
			case 67: //Jugador 3
			{
				if (mesa->Peek() == "X")
				{
					int escojer3 = 0;
					string respuesta3 = "si";
					while (respuesta3 == "si" || respuesta3 == "Si")
					{
						Jugador3.imprimir();
						cout << "----------------------------------------\n";
						mesa->impirmir_M();
						cout << "Diga la posicion de la ficha jugaodr 3: \n";
						cin >> escojer3;
						if (escojer3 < 0)
						{
							break;
						}
						else
						{
							cout << "Su domino es: " << Jugador3.buscar_en(escojer3) << endl;
							cout << "Desa cambiar su ficha\n";
							cin >> respuesta3;
							cout << "--------------------------\n";
						}
						break;
					}
					mesa->Push(Jugador3.remover_en(escojer3));
					if (contador == 3)
					{
						contador = 0;
					}
					else
					{
						contador++;
					}
					break;
				}
				else
				{
					while (!verificar3)
					{
						int escojer3 = 0;
						string respuesta3 = "si";
						while (respuesta3 == "si" || respuesta3 == "Si")
						{
							Jugador3.imprimir();
							cout << "----------------------------------------\n";
							mesa->impirmir_M();
							cout << "Diga la posicion de la ficha jugaodr 3: \n";
							cin >> escojer3;
							if (escojer3 < 0)
							{
								break;
							}
							else
							{
								cout << "Su domino es: " << Jugador3.buscar_en(escojer3) << endl;
								cout << "Desa cambiar su ficha\n";
								cin >> respuesta3;
								cout << "--------------------------\n";
							}
							break;
						}
						if (escojer3 < 0)
						{
							if (pozo->Peek() == "X") {
								cout << "El juego se ha terminado\n";
								empezar = 1;
								break;
							}
							else
							{
								string respuesta = " ";
								cout << "Desea recoger el domino y usarla para continuar\n";
								cin >> respuesta;
								if ("si" || "Si")
								{

									respuesta = pozo->buscar(pozo, mesa->Peek());//*******************
									Jugador3.add(respuesta);
									int nuevo = Jugador3.contar();
									Jugador3.remover_en(nuevo);
									cout << "---------------------------------\n";
									mesa->impirmir_M();
									if (contador == 3)
									{
										contador = 0;
									}
									else
									{
										contador++;
									}
									break;
								}
								else
								{
									cout << "Usted a decidido a perder el turno\n";
									pozo->imprimir();
									if (contador == 3)
									{
										contador = 0;
									}
									else
									{
										contador++;
									}
									break;
								}
							}
						}
						if (mesa->Peek()[0] == Jugador3.buscar_en(escojer3)[0] || mesa->Peek()[2] == Jugador3.buscar_en(escojer3)[2] || mesa->Peek()[2] == Jugador3.buscar_en(escojer3)[0] || mesa->Peek()[0] == Jugador3.buscar_en(escojer3)[2])
						{
							mesa->Push(Jugador3.remover_en(escojer3));

							cout << "++++++++++++++++++++++++++++++++++\n";
							mesa->impirmir_M();
							if (contador == 3)
							{
								contador = 0;
							}
							else
							{
								contador++;
							}
							break;
						}


					}
				}

			}
			break;
			case 68:
			{
				if (mesa->Peek() == "X")
				{
					int escojer3 = 0;
					string respuesta3 = "si";
					while (respuesta3 == "si" || respuesta3 == "Si")
					{
						Jugador4.imprimir();
						cout << "----------------------------------------------------------" << endl;
						mesa->impirmir_M();
						cout << "Diga la posicion de la ficha jugaodr 3: \n";
						cin >> escojer3;
						if (escojer3 < 0)
						{
							break;
						}
						else
						{
							cout << "Su domino es: " << Jugador4.buscar_en(escojer3) << endl;
							cout << "Desa cambiar su ficha\n";
							cin >> respuesta3;
							cout << "--------------------------\n";
						}
						mesa->Push(Jugador4.remover_en(escojer3));
						if (contador == 3)
						{
							contador = 0;
						}
						else
						{
							contador++;
						}
						break;
					}
				}
				else
				{
					while (!verificar4)
					{
						int escojer3 = 0;
						string respuesta3 = "si";
						while (respuesta3 == "si" || respuesta3 == "Si")
						{
							Jugador3.imprimir();
							mesa->impirmir_M();
							cout << "Diga la posicion de la ficha jugaodr 3: \n";
							cin >> escojer3;
							if (escojer3 < 0)
							{
								break;
							}
							else
							{
								cout << "Su domino es: " << Jugador3.buscar_en(escojer3) << endl;
								cout << "Desa cambiar su ficha\n";
								cin >> respuesta3;
								cout << "--------------------------\n";
							}
							if (contador == 3)
							{
								contador = 0;
							}
							else
							{
								contador++;
							}
							break;
						}
						if (escojer3 < 0)
						{
							if (pozo->Peek() == "X") {
								cout << "El juego se ha terminado\n";
								empezar = 1;
								break;
							}
							else
							{
								string respuesta = " ";
								cout << "Desea recoger el domino y usarla para continuar\n";
								cin >> respuesta;
								if ("si" || "Si")
								{

									respuesta = pozo->buscar(pozo, mesa->Peek());//*******************
									Jugador3.add(respuesta);
									int nuevo = Jugador4.contar();
									Jugador3.remover_en(nuevo);
									cout << "---------------------------------\n";
									mesa->impirmir_M();
									if (contador == 3)
									{
										contador = 0;
									}
									else
									{
										contador++;
									}
									break;
								}
								else
								{
									cout << "Usted a decidido a perder el turno\n";
									pozo->imprimir();
									if (contador == 3)
									{
										contador = 0;
									}
									else
									{
										contador++;
									}
									break;
								}
							}
						}
						if (mesa->Peek()[0] == Jugador4.buscar_en(escojer3)[0] || mesa->Peek()[2] == Jugador4.buscar_en(escojer3)[2] || mesa->Peek()[2] == Jugador4.buscar_en(escojer3)[0] || mesa->Peek()[0] == Jugador4.buscar_en(escojer3)[2])
						{
							mesa->Push(Jugador4.remover_en(escojer3));

							cout << "++++++++++++++++++++++++++++++++++\n";
							mesa->impirmir_M();
							if (contador == 3)
							{
								contador = 0;
							}
							else
							{
								contador++;
							}
							break;
						}


					}
				}
			}
			break;
			default:
			{
				cout << "Hubo un fallo\n";
				break;
			}
			//Mostrar la cantidad de puntos de cada jugador.

			//Esta comparacion es para saber cual jugador que tiene mayor cantidad de puntos.

			//funcion para limpiar la pantalla.

			}
			cout << "el total de puntos del jugador 1 es: " << Jugador1.sumar() << endl;
			cout << "el total de puntos del jugador 2 es: " << Jugador2.sumar() << endl;
			cout << "el total de puntos del jugador 3 es: " << Jugador3.sumar() << endl;
			system("cls");
		} while (!empezar);
		//Parte en donde se busca quien es el ganador
		int* ganador = new int[4] {Jugador1.sumar(), Jugador2.sumar(), Jugador3.sumar(), Jugador4.sumar()};
		Bubble(ganador, 4);
		if (ganador[0] == Jugador1.sumar() && ganador[0] > puntos_aganar)
		{
			cout << "El jugador uno ha gando el juego, con un total de: " << Jugador1.sumar() << endl;
		}
		else if (ganador[0] == Jugador2.sumar() && ganador[0] > puntos_aganar)
		{
			cout << "El jugador dos ha gando el juego, con un total de: " << Jugador2.sumar() << endl;
		}
		else if (ganador[0] == Jugador3.sumar() && ganador[0] > puntos_aganar)
		{
			cout << "El jugador tres ha gando el juego, con un total de: " << Jugador3.sumar() << endl;
		}
		else
		{
			cout << "El jugador cuatro ha gando el juego, con un total de: " << Jugador4.sumar() << endl;
		}
	}
	else
	{
		Lista_cirular* posicion = new Lista_cirular();
		bool juego1 = 0;
		bool juego2 = 0;
		bool juego3 = 0;
		string pasar = " ";
		int convert1 = 0, convert3 = 0, convertir2 = 0;
		int Largo = 3;
		int* orden = new int[Largo];
		char* lugares = new char[Largo];
		if (Jugador1.ver_domino())
		{
			juego1 = Jugador1.ver_domino();
			pasar = Jugador1.buscar_doble().substr(2, 2);
			convert1 = stoi(Jugador1.buscar_doble()) + stoi(pasar);

			orden[0] = convert1;
		}
		else
		{
			orden[0] = -convert1;
		}
		if (Jugador2.ver_domino())
		{
			juego2 = Jugador2.ver_domino();
			pasar = Jugador2.buscar_doble().substr(2, 2);
			convertir2 = stoi(Jugador2.buscar_doble()) + stoi(pasar);
			orden[1] = convertir2;
		}
		else
		{
			orden[1] = -convertir2;
		}
		if (Jugador3.ver_domino())
		{
			juego3 = Jugador3.ver_domino();
			pasar = Jugador3.buscar_doble().substr(2, 2);
			convert3 = stoi(Jugador3.buscar_doble()) + stoi(pasar);
			orden[2] = convert3;
		}
		else
		{
			orden[2] = -convert3;
		}

		bool empezar = false;
		int escojer = 0;
		int contador = 0;
		int Lugar = 0;
		bool verificar1 = 0, verificar2 = 0, verificar3 = 0;
		do
		{
			Lugar = stoi(posicion->ver(contador));
			switch (Lugar)
			{
			case 65: //Jugador 1
			{
				if (mesa->Peek() == "X")
				{
					string Respuesta1 = "si";
					while (Respuesta1 == "si" || Respuesta1 == "Si")
					{
						//Se empieza a buscar una ficha que diga el jugador.
						Jugador1.imprimir();
						mesa->impirmir_M();
						cout << "Diga la posicion de una ficha jugaodr 1.\n";
						cin >> escojer;
						if (escojer < 0)
						{
							break;
						}
						else
						{
							cout << "Su domino es :" << Jugador1.buscar_en(escojer) << endl;
							cout << "Desa cambiar su ficha\n";
							cin >> Respuesta1;
							cout << "++++++++++++++++++++++++++++++++++\n";
						}
					}
					mesa->Push(Jugador1.remover_en(escojer));
					if (contador == 3)
					{
						contador = 0;
					}
					else
					{
						contador++;
					}
					break;
				}
				else
				{
					while (!verificar1)
					{
						string Respuesta1 = "si";
						while (Respuesta1 == "si" || Respuesta1 == "Si")
						{
							//Se empieza a buscar una ficha que diga el jugador.
							mesa->impirmir_M();
							cout << "------------------------------------\n";
							Jugador1.imprimir();

							cout << "Diga la posicion de una ficha jugaodr 1.\n";
							cin >> escojer;
							if (escojer < 0)
							{
								break;
							}
							else
							{
								cout << "Su domino es :" << Jugador1.buscar_en(escojer) << endl;
								cout << "Desa cambiar su ficha\n";
								cin >> Respuesta1;
								cout << "++++++++++++++++++++++++++++++++++\n";
							}
							if (contador == 2)
							{
								contador = 0;
							}
							else
							{
								contador++;
							}
							break;
						}
						if (escojer < 0)// si no tiene un ficha que coincida en la mesa
						{
							//Primero pregunta si tiene fichas el pozo
							if (pozo->Peek() == "X") {
								cout << "el juego ha terminado, no hay mas fichas en el pozo\n";
								empezar = 1;
								break;
							}
							else
							{
								//Si  tiene, entonces se procede a buscar una ficha para el jugador.
								string respuesta = " ";
								cout << "Desea recoger el domino y usarla para continuar\n";
								cin >> respuesta;
								if ("si" || "Si")
								{
									respuesta = pozo->buscar(pozo, mesa->Peek());//********************
									Jugador1.add(respuesta);
									int nuevo = Jugador1.contar();
									Jugador1.remover_en(nuevo);
									if (contador == 3)
									{
										contador = 0;
									}
									else
									{
										contador++;
									}
									break;
								}
								else //Si eljugador decide perder el turno
								{
									cout << "Usted a decidido a perder el turno\n";
									cout << "++++++++++++++++++++++++++++++++++++++\n";
									pozo->imprimir();
									if (contador == 3)
									{
										contador = 0;
									}
									else
									{
										contador++;
									}
									break;
								}
							}
						}
						//si la ficha que se escogio es igual
						if ((mesa->Peek()[0] == Jugador1.buscar_en(escojer)[0]) || ((mesa->Peek()[2] == Jugador1.buscar_en(escojer)[2])) || (mesa->Peek()[2] == Jugador1.buscar_en(escojer)[0]) || (mesa->Peek()[0] == Jugador1.buscar_en(escojer)[2]))
						{
							mesa->Push(Jugador1.remover_en(escojer));

							cout << "++++++++++++++++++++++++++++++++++\n";
							mesa->impirmir_M();
							if (contador == 3)
							{
								contador = 0;
							}
							else
							{
								contador++;
							}
							break;
						}//si intentta hacer trampa que se escogio es igual



					}
				}
			}break;
			case 66://Jugador 2
			{
				if (mesa->Peek() == "X")
				{
					string Respuesta2 = "si";
					while (Respuesta2 == "si" || Respuesta2 == "Si")
					{
						mesa->impirmir_M();
						cout << "--------------------------------\n";
						Jugador2.imprimir();

						cout << "Diga la posicion de la ficha jugador 2.\n";
						cin >> escojer;
						if (escojer < 0)
						{
							break;
						}
						else
						{
							cout << "Su domino es: " << Jugador2.buscar_en(escojer) << endl;
							cout << "Desa cambiar su ficha\n";
							cin >> Respuesta2;
							cout << "--------------------------\n";
						}
						if (contador == 2)
						{
							contador = 0;
						}
						else
						{
							contador++;
						}
						break;
					}
					mesa->Push(Jugador2.remover_en(escojer));
				}
				else
				{
					while (!verificar2)
					{
						string Respuesta2 = "si";
						while (Respuesta2 == "si" || Respuesta2 == "Si")
						{
							Jugador2.imprimir();
							mesa->impirmir_M();
							cout << "Diga la posicion de la ficha jugador 2.\n";
							cin >> escojer;
							if (escojer < 0)
							{
								break;
							}
							else
							{
								cout << "Su domino es: " << Jugador2.buscar_en(escojer) << endl;
								cout << "Desa cambiar su ficha\n";
								cin >> Respuesta2;
								cout << "--------------------------\n";
							}
						}
						//si la ficha que se escogio es igual
						if (escojer < 0)// si no tiene un ficha que coincida en la mesa
						{
							if (pozo->Peek() == "X") {
								cout << "El juego se ha terminado\n";
								empezar = 1;
							}
							else
							{
								if (pozo->Peek() == "X")
								{
									cout << "el juego ha terminado, no hay mas fichas en el pozo\n";
									empezar = 1;
								}
								else
								{
									string respuesta = " ";
									cout << "Desea recoger el domino y usarla para continuar\n";
									cin >> respuesta;
									if ("si" || "Si")
									{

										respuesta = pozo->buscar(pozo, mesa->Peek());//*******************
										Jugador2.add(respuesta);
										int nuevo = Jugador2.contar();
										Jugador2.remover_en(nuevo);

										cout << "---------------------------------\n";
										mesa->impirmir_M();
										if (contador == 3)
										{
											contador = 0;
										}
										else
										{
											contador++;
										}
										break;
									}
									else
									{
										cout << "Usted a decidido a perder el turno\n";
										pozo->imprimir();
										if (contador == 3)
										{
											contador = 0;
										}
										else
										{
											contador++;
										}
										break;
									}
								}
							}

						}
						if (mesa->Peek()[0] == Jugador2.buscar_en(escojer)[0] || mesa->Peek()[2] == Jugador2.buscar_en(escojer)[2] || mesa->Peek()[2] == Jugador2.buscar_en(escojer)[0] || mesa->Peek()[0] == Jugador2.buscar_en(escojer)[2])
						{
							mesa->Push(Jugador2.remover_en(escojer));

							cout << "--------------------------\n";
							mesa->impirmir_M();
							if (contador == 3)
							{
								contador = 0;
							}
							else
							{
								contador++;
							}
							break;
						}

					}
				}
			}break;
			case 67:
			{
				if (mesa->Peek() == "X")
				{
					int escojer3 = 0;
					string respuesta3 = "si";
					while (respuesta3 == "si" || respuesta3 == "Si")
					{
						mesa->impirmir_M();
						cout << "------------------------------------\n";
						Jugador3.imprimir();

						cout << "Diga la posicion de la ficha jugaodr 3: \n";
						cin >> escojer3;
						if (escojer3 < 0)
						{
							break;
						}
						else
						{
							cout << "Su domino es: " << Jugador3.buscar_en(escojer3) << endl;
							cout << "Desa cambiar su ficha\n";
							cin >> respuesta3;
							cout << "--------------------------\n";
						}

					}
					mesa->Push(Jugador3.remover_en(escojer3));
					if (contador == 2)
					{
						contador = 0;
					}
					else
					{
						contador++;
					}
					break;
				}
				else
				{
					while (!verificar3)
					{
						int escojer3 = 0;
						string respuesta3 = "si";
						while (respuesta3 == "si" || respuesta3 == "Si")
						{
							mesa->impirmir_M();
							cout << "------------------------------------------------\n";
							Jugador3.imprimir();
							cout << "Diga la posicion de la ficha jugaodr 3: \n";
							cin >> escojer3;
							if (escojer3 < 0)
							{
								break;
							}
							else
							{
								cout << "Su domino es: " << Jugador3.buscar_en(escojer3) << endl;
								cout << "Desa cambiar su ficha\n";
								cin >> respuesta3;
								cout << "--------------------------\n";
							}
							if (contador == 2)
							{
								contador = 0;
							}
							else
							{
								contador++;
							}
							break;

						}
						if (escojer3 < 0)
						{
							if (pozo->Peek() == "X") {
								cout << "El juego se ha terminado\n";
								empezar = 1;
							}
							else
							{
								string respuesta = " ";
								cout << "Desea recoger el domino y usarla para continuar\n";
								cin >> respuesta;
								if ("si" || "Si")
								{

									respuesta = pozo->buscar(pozo, mesa->Peek());//*******************
									Jugador3.add(respuesta);
									int nuevo = Jugador3.contar();
									Jugador3.remover_en(nuevo);

									cout << "---------------------------------\n";
									mesa->impirmir_M();
									if (contador == 2)
									{
										contador = 0;
									}
									else
									{
										contador++;
									}
									break;
								}
								else
								{
									cout << "Usted a decidido a perder el turno\n";
									pozo->imprimir();
									if (contador == 2)
									{
										contador = 0;
									}
									else
									{
										contador++;
									}
									break;
								}
							}
						}
						if (mesa->Peek()[0] == Jugador3.buscar_en(escojer3)[0] || mesa->Peek()[2] == Jugador3.buscar_en(escojer3)[2] || mesa->Peek()[2] == Jugador3.buscar_en(escojer3)[0] || mesa->Peek()[0] == Jugador3.buscar_en(escojer3)[2])
						{
							mesa->Push(Jugador3.remover_en(escojer3));

							cout << "------------------------------------\n";
							mesa->impirmir_M();
							if (contador == 2)
							{
								contador = 0;
							}
							else
							{
								contador++;
							}
							break;
						}


					}
				}
			}break;
			default:
				break;
			}
			//Mostrar la cantidad de puntos de cada jugador.
			cout << "el total de puntos del jugador 1 es: " << Jugador1.sumar() << endl;
			cout << "el total de puntos del jugador 2 es: " << Jugador2.sumar() << endl;
			cout << "el total de puntos del jugador 3 es: " << Jugador3.sumar() << endl;
			//Esta comparacion es para saber cual jugador que tiene mayor cantidad de puntos.

			//funcion para limpiar la pantalla.
			system("cls");
		} while (!empezar);
		//Parte en donde se busca quien es el ganador
		int* ganador = new int[3] {Jugador1.sumar(), Jugador2.sumar(), Jugador3.sumar()};
		if (ganador[0] == Jugador1.sumar() && ganador[0] > puntos_aganar)
		{
			cout << "El jugador uno ha gando el juego, con un total de: " << Jugador1.sumar() << endl;
		}
		else if (ganador[0] == Jugador2.sumar() && ganador[0] > puntos_aganar)
		{
			cout << "El jugador dos ha gando el juego, con un total de: " << Jugador2.sumar() << endl;
		}
		else
		{
			cout << "El jugador tres ha gando el juego, con un total de: " << Jugador3.sumar() << endl;
		}


	}

	//Ver quien gano el juego.



}
int main()
{
	int jugador = 0;
	cout << "\tJuego de Domino\n";
	cout << "Diga la cantidad de jugadores\n";
	cin >> jugador;
	do {
		switch (jugador)
		{
		case 2: {//Caso para dos jugadores
			cout << "La cantidad de puntos para ganar\n";
			cin >> puntos_aganar;
			if (puntos_aganar > 25 && puntos_aganar < 100)
			{
				DOS(puntos_aganar);
			}
			else
			{
				cout << "La cantidad de puntos es demasiado baja o muy alta para un juego\n";
			}

		}break;
		case 3:
		{//Caso para tres jugadores
			cout << "La cantidad de puntos para ganar\n";
			cin >> puntos_aganar;
			if (puntos_aganar > 25 && puntos_aganar < 100)
			{
				TRES_CUATRO(jugador, puntos_aganar);
			}
			else
			{
				cout << "La cantidad de puntos es demasiado baja o muy alta para un juego\n";
			}

		}break;
		case 4:
		{//Caso para cuatro jugadores
			cout << "La cantidad de puntos para ganar\n";
			cin >> puntos_aganar;
			if (puntos_aganar > 25 && puntos_aganar < 100)
			{
				TRES_CUATRO(jugador, puntos_aganar);
			}
			else
			{
				cout << "La cantidad de puntos es demasiado baja o muy alta para un juego\n";
			}
		};
		break;
		default: {

			cout << "Cantidad de jugadores invalidad\n";
		}
			   break;
		}
	} while (jugador < 5 && jugador>1);
	return 0;
}
