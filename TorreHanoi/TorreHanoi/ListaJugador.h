#ifndef LISTAJUGADORES_H
#define LISTAJUGADORES_H
#include "NodoJugadores.h"
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

class ListaJugadores {
public:
	ListaJugadores();
	void setLongitud();
	int getLongitud();
	void setCabeza(NodoJugadores*);  
	NodoJugadores *getCabeza();

	void agregarJugador(Jugador pjugador);
	bool jugadoresVacio();
	string mostrarJugadores();
	string buscarInfoDelJugador(string pjugador);
	Jugador buscarJugador(string pjugador);
	bool seEncuentraJugador(string pcodigo);
	bool listaJugadorVacio();
	string toUppercase(string pcodigo);
private:
	int longitud;
	NodoJugadores *cabeza;
};
#endif // !LISTAJUGADORES_H


