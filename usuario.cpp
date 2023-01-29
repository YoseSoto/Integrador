#include <iostream>
#include <string>
#include "usuario.h"
using namespace std;



Usuario::Usuario(string usuario, string nombre, string apellido, int edad, int id, string pass){
    this->usuario = usuario;
    this->nombre = nombre;
    this->apellido = apellido;
    this->edad = edad;
    this->id = id;
    this->password = pass;
}

string Usuario::getUser(){
    return this->usuario;
}

string Usuario::getUserPass(){
    return this->password;
}

int Usuario::getUserId(){
    return this->id;
}

void Usuario::setPass(){
    cout<<"Ingrese nueva contraseña: ";
    cin>>this->password;
}