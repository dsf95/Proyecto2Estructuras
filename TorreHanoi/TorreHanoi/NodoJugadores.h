#ifndef NODOJUGADORES_H
#define NODOJUGADORES_H
#include "Jugador.h"
#include <iostream>

using namespace std;
class NodoJugadores
{
public:
	NodoJugadores(Jugador jugador);
	void setSig(NodoJugadores*);
	void setJugador(Jugador pjugador);
	NodoJugadores* getSig();
	Jugador getJugador();
	string toString(); 
	
private:
	NodoJugadores* sig;
	Jugador jugador;
};

#endif // !NODOJUGADORES_H

