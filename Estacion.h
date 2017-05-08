#ifndef Estacion_h
#define Estacion_h

class Estacion : public Equipo {
	private:
		float tiempo;
		string tipo;
		string estacion;

	public:
		Estacion(string);
		~Estacion();
		float avanza();
};

Estacion::Estacion(string name) : Equipo(name) {
	setNombre(name);
	tiempo = 0;
}

float Estacion::avanza() {

	if (getEstacion() == "1") {
		tiempo = 9;
		estacion = "Motoman";
	} else if (getEstacion() == "2") {
		tiempo = 15;
		estacion = "Desoldering";
	} else if (getEstacion() == "3") {
		tiempo = 12;
		estacion = "Verification";
	} else if (getEstacion() == "4") {
		tiempo = 20;
		estacion = "Destructor";
	}

	cout << estacion << " station starts work for Pallet1" << endl;
	this_thread::sleep_for(milliseconds(1000));
	cout << estacion << " station finished work for Pallet1" << endl;

	return tiempo;
}

Estacion::~Estacion() {
	cout << "Destruyendo Estacion: " << getNombre() << endl;
}


#endif