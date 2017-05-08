#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
#include <thread>
#include <stdlib.h>
#include <time.h> 
#include <thread>

using namespace std::chrono;
using namespace std;

#include "Trayectoria.h"
#include "Equipo.h"
#include "Banda.h"
#include "Estacion.h"

int main() {

	srand(time(NULL));

	Trayectoria trayectoria;
	Equipo *equipo[20];
	ifstream archivoEntrada;
	string linea, instruccion;
	int pos;
	int numInstruccion=0;
	float tiempo;

	archivoEntrada.open("trayectoria.txt");
	getline(archivoEntrada, linea);

	while (linea.length() > 2) {
		pos = linea.find(">");
		instruccion = linea.substr(0,pos);
		linea.erase(0,pos+1);
		if (linea.length() == 2)
			instruccion = linea;
		if (instruccion.substr(0,1)=="C")
			equipo[numInstruccion] = new Banda(instruccion);
		else if (instruccion.substr(0,1)=="S")
			equipo[numInstruccion] = new Estacion(instruccion);
		trayectoria.agregar(equipo[numInstruccion]);
		numInstruccion++;
	}

	archivoEntrada.close();

	tiempo = trayectoria.avanza();

	cout << "Execution time: " << tiempo << endl;

	return 0;
}