#include "Gestor.h"

Gestor::Gestor(){}

void Gestor::agregarJugador(string pnombre){
	Jugador jugador(pnombre);
	listaJugadores.agregarJugador(jugador);
}

string Gestor::mostrarJugadores(){

	return listaJugadores.mostrarJugadores();
} 

/*bool Gestor::validarSiHayJugadores()
{
	return listaJugadores.jugadoresVacio();
}*/



	
