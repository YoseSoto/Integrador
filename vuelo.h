#include <vector>
#include "usuario.h"
using namespace std;


fstream reservaciones;

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
            return nombre + " " + apellido;
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
        vector<Pasajero*> lista_pasajeros;
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
        Vuelo(int,string,double,string,double,Avion ,string,string);
        int getPassengers();
        string getAeroline();
        string getDest();
        double getKm();
        Avion getAvion();
        string getTimeLength();
        string getClass();
        double getPrice();
        int getId();
        void setPassengers(int);
        Pasajero getPasajero(int);
        void agregar(Vuelo,Usuario);
        void comprarVuelo();
        void cancelarVuelo();
};

Vuelo::Vuelo (int idVuelo, string aerolinea, double precio, string destino, double kilometros, Avion avion, string duracion,string clase): avion("",0,0){
    //this->numPasajeros = numPasajeros;
    this->idVuelo = idVuelo;
    this->aerolinea = aerolinea;
    this->precio = precio;
    this->destino = destino;
    this->kilometros = kilometros;
    this->avion = avion;
    this->duracion = duracion;
    this->clase = clase;
}

void Vuelo::setPassengers(int passengers){
    this->numPasajeros = passengers;    
}

int Vuelo::getPassengers(){
    return numPasajeros;
}

Pasajero Vuelo::getPasajero(int i){
    return *lista_pasajeros.at(i);
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

vector<Vuelo> lista_reservaciones;

void Vuelo::agregar(Vuelo vuelo, Usuario user){
    int numPasajeros_;
    lista_reservaciones.push_back(vuelo);
    int i,j;
    string temp_nombre, temp_last;
    reservaciones.open("reservaciones.txt",ios::out);
    cout<<"Cuantos pasajeros viajaran: ";
    cin >> numPasajeros_;
    this->setPassengers(numPasajeros_);
    for(j = 0 ; j < numPasajeros ; j++){
        fflush(stdin);
        cout << "Ingrese nombre de la persona [" << j+1 << "]: ";
        cin >> temp_nombre;
        cout << "Ingrese apellido de la persona [" << j+1 << "]: ";
        cin >> temp_last;
        Pasajero *pasajero = new Pasajero(temp_nombre,temp_last);
        this->lista_pasajeros.push_back(pasajero);
    }

    while(!reservaciones.eof()){
        reservaciones<<"Reservacion" << " por usuario: " << user.getUser() << endl;
        reservaciones << lista_reservaciones.at(0).getAeroline() << " CDMX a " << lista_reservaciones.at(0).getDest() << " ID: " << lista_reservaciones.at(0).getId() << endl;
        reservaciones<<"Pasajeros: \n";
        for(j = 0; j < numPasajeros ; j++){
            reservaciones << this->lista_pasajeros.at(j)->getCompleteName() << endl;
        }
        break;
    }
    reservaciones.close();
    system("cls");
    cout<<"Tu vuelo con destino a "<< this->destino << " - " << this->idVuelo<< " ha sido agregado!\n";
    system("pause");
    system("cls");
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
