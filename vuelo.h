#include <vector>
#include "usuario.h"
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
        Vuelo(int,int,string,double,string,double,Avion ,string,string);
        int getPassengers();
        string getAeroline();
        string getDest();
        double getKm();
        Avion getAvion();
        string getTimeLength();
        string getClass();
        double getPrice();
        int getId();
        void agregar();
        void comprarVuelo();
        void cancelarVuelo();
};



vector<Vuelo> lista_reservaciones;
Vuelo::Vuelo(int numPasajeros, int idVuelo, string aerolinea, double precio, string destino, double kilometros, Avion avion, string duracion,string clase): avion("",0,0){
    this->numPasajeros = numPasajeros;
    this->idVuelo = idVuelo;
    this->aerolinea = aerolinea;
    this->precio = precio;
    this->destino = destino;
    this->kilometros = kilometros;
    this->avion = avion;
    this->duracion = duracion;
    this->clase = clase;
}

int Vuelo::getPassengers(){
    return numPasajeros;
}

int Vuelo::getId(){
    return idVuelo;
}

string Vuelo::getAeroline(){
    return aerolinea;
}

string Vuelo::getDest(){
    return destino;
}

double Vuelo::getKm(){
    return kilometros;
}

Avion Vuelo::getAvion(){
    return avion;
}

string Vuelo::getTimeLength(){
    return duracion;
}

string Vuelo::getClass(){
    return clase;
}

double Vuelo::getPrice(){
    return precio;
}

//
void Vuelo::comprarVuelo(){

}
//
void Vuelo::cancelarVuelo(){
    
}

void Vuelo::agregar(){
    int i=0,j;
    string temp_nombre, temp_last;
    reservaciones.open("reservaciones.txt",ios::app);

    cout<<"Cuantos pasajeros viajaran: ";
    cin >> numPasajeros;
    
    for(j = 0 ; j < numPasajeros ; j++){
        fflush(stdin);
        cout << "Ingrese nombre y apellido de la persona [" << j+1 << "]: ";
        cin >> temp_nombre, temp_last;
        Pasajero pasajero = Pasajero(temp_nombre, temp_last);
        this->lista_pasajeros.push_back(pasajero);
    }

    while(!reservaciones.eof()){
        for(j = 0; j < numPasajeros ; j++){
            reservaciones << lista_reservaciones.at(j).lista_pasajeros.at(j).getCompleteName();
        }  
        reservaciones << lista_reservaciones.at(i).getId();
        i++;
    }
    reservaciones.close();
    cout<<"Tu vuelo con destino a "<< this->destino << this->idVuelo<< " ha sido agregado!\n";
}

Avion::Avion(string name, int numPuertas, int capacidad){
    this->name = name;
    this->numPuertas = numPuertas;
    this->capacidad = capacidad;
}

int Avion::getCapacidad(){
    return capacidad;
}

int Avion::getNumPuertas(){
    return numPuertas;
}

string Avion::getName(){
    return name;
}
