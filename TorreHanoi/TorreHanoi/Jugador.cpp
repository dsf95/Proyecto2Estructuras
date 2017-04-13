#include "Jugador.h"

int Jugador::autoGenerateListaJugador = 1;

Jugador::Jugador() {}

Jugador::Jugador(string pnombre) {
	setNombre(pnombre);
	setCodigo();
}
void Jugador::setCodigo() {

	std::string autoGenerateListJugador = std::to_string(autoGenerateListaJugador);
	codigo = "player-" + autoGenerateListJugador;
	autoGenerateListaJugador++;
}

string Jugador::getCodigo() {
	return this->codigo;
}
void Jugador::setNombre(string pnombre) {
	nombre = pnombre;
}
string Jugador::getNombre() {
	return this->nombre;
}
string Jugador::toString() {
	string result = "Nombre: " + getNombre() + "\n"; 
	result += "Codigo: " + getCodigo() + "\n";
	return result;
}