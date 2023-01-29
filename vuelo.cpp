#include <iostream>
#include <string>
#include "vuelo.h"
using namespace std;

vector<Vuelo> lista_reservaciones;

Vuelo::Vuelo(int numPasajeros, int idVuelo, string aerolinea, double precio, string destino, double kilometros, Avion, string duracion,string clase){
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

void Vuelo::agregar(Vuelo vuelo){
    int i,j;
    string temp_nombre, temp_last;
    reservaciones.open("reservaciones.txt",ios::app);

    cout<<"Cuantos pasajeros viajaran: ";
    cin >> numPasajeros;
    
    for(j = 0 ; j < numPasajeros ; i++){
        cout << "Ingrese nombre y apellido de la persona [" << i+1 << "]: ";
        cin >> temp_nombre, temp_last;
        Pasajero pasajero = Pasajero(temp_nombre, temp_last);
        lista_pasajeros.push_back(pasajero);
    }
    lista_reservaciones.push_back(vuelo);

    while(!reservaciones.eof()){
        for(j = 0; j < lista_pasajeros.size() ; j++){
            reservaciones << lista_reservaciones.at(i).lista_pasajeros.at(i).getCompleteName();
        }  
        reservaciones << lista_reservaciones.at(i).getId();
        i++;
    }
    reservaciones.close();
    cout<<"Tu vuelo id "<< this->idVuelo << "ha sido agregado!\n";
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