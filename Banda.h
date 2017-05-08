#ifndef Banda_h
#define Banda_h

class Banda : public Equipo {
	private:
		float longC;
		float longT;
		float velocidad;
		float tiempo;
		string tipo;

	public:
		Banda(string);
		~Banda();
		float avanza();
};

Banda::Banda(string name) : Equipo(name) {
	setNombre(name);
	longC = 70;
	longT = 40;
	velocidad = 0.05;
	tiempo = 0;
}

float Banda::avanza() {

	if (getTipo() == "C")
		tiempo = longC*velocidad;
	else if (getTipo() == "T")
		tiempo = longT*velocidad;

	cout << "Pallet1 entering conveyor " << getNombre() << endl;
	this_thread::sleep_for(milliseconds(1000));
	cout << "Pallet1 at the end of conveyor " << getNombre() << endl;

	return tiempo;
}

Banda::~Banda() {
	cout << "Destruyendo Banda: " << getNombre() << endl;
}

#endif