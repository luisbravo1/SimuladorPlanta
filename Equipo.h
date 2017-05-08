#ifndef Equipo_h
#define Equipo_h

class Equipo {
	private:
		string Nombre;
		float ejecucion;
		float tiempos[20];
		int instrucciones;
	public:
		Equipo(string);
		virtual ~Equipo();
		virtual float avanza()=0;
		string getNombre();
		string getTipo();
		string getEstacion();
		void setNombre(string);
		void agregaTiempo(float, int);
		void tiempoEjecucion();
		float getTiempo(int);
};

Equipo::Equipo(string _nombre) {
	Nombre = _nombre;
	ejecucion = 0;
}

string Equipo::getNombre() {
  return Nombre;
}

string Equipo::getTipo() {
	return Nombre.substr(0,1);
}

string Equipo::getEstacion() {
	return Nombre.substr(1,1);
}

void Equipo::setNombre(string name) {
  Nombre = name;
}

Equipo::~Equipo() {
  cout << "Destruyendo Equipo" << endl;
}

#endif