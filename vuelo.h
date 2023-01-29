#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "usuario.cpp"
using namespace std;

fstream reservaciones;
const int numPasajeros = 0;

class Pasajero{
    private:
        string nombre;
        string apellido;
    public:
        Pasajero(string nombre,string apellido){
            this->nombre = nombre;
            this->apellido = apellido;
        }
        string getCompleteName(){
            return nombre, apellido;
        }
};

class Avion{
    private:
        int numPuertas;
        int capacidad;
        string name;
    public:
        Avion();
        Avion(string,int,int);
        string getName();
        int getNumPuertas();
        int getCapacidad();
};

class Vuelo{
    private:
        vector<Pasajero> lista_pasajeros;
        int numPasajeros;
        int idVuelo;
        string aerolinea;
        double precio;
        string destino;
        double kilometros;
        Avion avion;
        string duracion;
        string clase;
        
    public:
        Vuelo(int,int,string,double,string,double,Avion,string,string);
        int getPassengers();
        string getAeroline();
        string getDest();
        double getKm();
        Avion getAvion();
        string getTimeLength();
        string getClass();
        double getPrice();
        int getId();
        void agregar(Vuelo);
        void comprarVuelo();
        void cancelarVuelo();
};