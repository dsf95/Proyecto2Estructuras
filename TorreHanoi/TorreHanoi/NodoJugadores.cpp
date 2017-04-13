#include "NodoJugadores.h"

NodoJugadores::NodoJugadores(Jugador pjugador) {
	setJugador(pjugador);
}
void NodoJugadores::setJugador(Jugador pjugador) {
	jugador = pjugador;
}
Jugador NodoJugadores::getJugador() {
	return jugador;
}

NodoJugadores * NodoJugadores::getSig() {
	return this->sig;
}
void NodoJugadores::setSig(NodoJugadores* psig) {
	sig = psig;
}
string NodoJugadores::toString(){
	string resul = "Nombre del jugador: " + jugador.getNombre() + "\n";
	resul += "Codigo: " + jugador.getCodigo() + "\n";
	return resul; 
	
}
