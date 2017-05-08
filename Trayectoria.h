#ifndef Trayectoria_h
#define Trayectoria_h

#include "Equipo.h"

class Trayectoria {
	private:
		Equipo *equipo[20];
		int instruccion;
		float tiempo;
		float tiempoEjecucion;

	public:
		Trayectoria();
		void agregar(Equipo *e);
		void setTiempo(float);
		float avanza();
		int getInstruccion();

};

Trayectoria::Trayectoria() {
	instruccion = 0;
	tiempo = 0;
	tiempoEjecucion = 0;
}

void Trayectoria::agregar(Equipo *e) {
	equipo[instruccion] = e;
	instruccion++;
}


void Trayectoria::setTiempo(float _tiempo) {
	tiempo = _tiempo;
}


float Trayectoria::avanza() {
	for (int i = 0; i < instruccion; i++) {
    	tiempoEjecucion += equipo[i]->avanza();
    }
    return tiempoEjecucion;
}

int Trayectoria::getInstruccion() {
	return instruccion;
}


#endif