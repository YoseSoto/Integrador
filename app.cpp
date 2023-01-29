#include <iostream>
#include <string>
#include "vuelo.h"
#include <conio.h>
using namespace std;

fstream usuarios;
vector<Usuario> lista_usuarios;
vector<Usuario> usersLoggedIn;

fstream vuelos;
vector<Avion> lista_aviones;
vector<Vuelo> lista_vuelos;

bool band = false;

string _usuario, _password, _password2, in_user, in_pass;
char caracter;

bool login(){
    system("cls");
    usuarios.open("usuarios.txt",ios::in);
    cout<<"Usuario: "; 
    cin >> _usuario;
    cout<<"Password: "; 

    caracter = getch();
    while (caracter != 13){
        if(caracter != 8){
            _password.push_back(caracter);
            cout << "*";
        }
        else{
            if(_password.length() > 0){
                cout << "\b \b";
                _password = _password.substr(0, _password.length() - 1);
            }
        }
        caracter = getch();
    }

    if(usuarios.is_open()){
        int i = 1;
        while(!usuarios.eof()){
            getline(usuarios,in_user);
            getline(usuarios,in_pass);
            if( in_user == _usuario && in_pass == _password ){
                return true;
            }
        i++;
        }
    }
    usuarios.close();   
    return false;
}

void addUserToDataBase(Usuario user){
    usuarios.open("usuarios.txt", ios::app);
    usuarios << user.getUser() << endl;
    usuarios << user.getUserPass() << endl;
    usersLoggedIn.push_back(user);
    usuarios.close();
}

void registro(){ 
    system("cls");
    string temp_name, temp_last, temp_user, temp_pass; 
    int temp_id, temp_age;
    cout<<"\tRegistro\n";
    cout<<"Nombre: "; cin >> temp_name;
    cout<<"Apellido: "; cin >> temp_last;
    do{
        cout<<"Edad: "; cin >> temp_age;
        if(temp_age < 18){
            system("cls");
            cout<<"Usuario invalido.\n";
            cout<<"El usuario debe ser mayor de edad.";
            system("pause");
        }
    }while(temp_age < 18);
    cout<<"Ingrese un nombre de usuario: "; cin >> temp_user;
    
    do{
        if(_password != _password2){
            cout<<"\nLas password no coinciden\n";
        }
        cout<<"Ingrese su password: ";
        caracter = getch();
        while (caracter != 13){
            if(caracter != 8){
                _password.push_back(caracter);
                cout << "*";
            }
            else{
                if(_password.length() > 0){
                    cout << "\b \b";
                    _password = _password.substr(0, _password.length() - 1);
                }
            }
            caracter = getch();
        }
        cout<<"\nConfirmar password: "; 
        caracter = getch();
        while (caracter != 13){
            if(caracter != 8){
                _password2.push_back(caracter);
                cout << "*";
            }
            else{
                if(_password2.length() > 0){
                    cout << "\b \b";
                    _password2 = _password2.substr(0, _password2.length() - 1);
                }
            }
            caracter = getch();
        }
    }while(_password != _password2);

    temp_pass = _password2;

    Usuario user(temp_user,temp_name,temp_last,temp_age,temp_id,temp_pass);
    addUserToDataBase(user);

    system("cls");
    cout<<"Usuario agregado con exito!\n";
    usuarios.close();   
}

void addFlightToDataBase(Vuelo flight){
    vuelos.open("vuelo.txt", ios::app);
    vuelos << flight.getDest();
    vuelos << flight.getId();
    vuelos << flight.getAeroline();
    vuelos << flight.getClass();    
    vuelos << flight.getPrice();
    vuelos << flight.getKm();
    vuelos << flight.getTimeLength();
    vuelos << flight.getAvion().getName();
    vuelos << flight.getPassengers();
    lista_vuelos.push_back(flight);
    vuelos.close();
}

void listaVuelos(){

    vuelos.open("vuelos.txt",ios::in);

    char opcion;
    string temp_line;

    Avion AirbusA320 = Avion("AirbusA320",4,220);
    Avion Boeing737 = Avion("Boeing737",8,220);

    lista_aviones.push_back(AirbusA320);
    lista_aviones.push_back(Boeing737);

    Vuelo CDMXtoMTY = Vuelo(numPasajeros, 655,"Volaris",2054,"Monterrey,NL",990,lista_aviones.at(0),"1.44h","Primera Clase");
    Vuelo CDMXtoCUN = Vuelo(numPasajeros, 7263,"Viva Aerobus",1449,"Cancun",1608,lista_aviones.at(1),"2:16h","Turista");
    
    addFlightToDataBase(CDMXtoMTY);
    addFlightToDataBase(CDMXtoCUN);

    do{
        cout<<"\tLista de vuelos disponibles\n";
        while(!vuelos.eof()){
            for(int i=0; i<9;i++){
                cout<<"Detalles de vuelo "<<i+1<<"): \n";
                getline(vuelos,temp_line);
                cout<<temp_line<<endl<<endl;
            }
            vuelos.close();
        }
        cout<<"0) Regresar\n";
        cin >> opcion;
        switch(opcion){
            case '1':
                system("cls");
                CDMXtoMTY.agregar(CDMXtoMTY);
            break;
            case '2':
                system("cls");
                CDMXtoCUN.agregar(CDMXtoCUN);
            break;
            case '3':
            break;
            case '4':
            break;
            case '5':
            break;
            case '0':
                system("cls");
            break;
            default:
                system("cls");
                cout<<"Opcion inexistente...\n";

        }
    }while(opcion != 0);
    band = true;
}

void checarVuelo(){

}

void menu(){
    char opcion;
    do{
        cout<<"\tReservaciones Yose\n";
        cout<<"1) Reservar vuelo\n";
        cout<<"2) Checar vuelo\n";
        cout<<"3) Salir\n";
        cin>>opcion;
        switch(opcion){
            case '1':
                system("cls");
                if(!band){
                    listaVuelos();
                }
                else{
                    "Usted ya tiene un vuelo en reserva!\n";
                }
            break;
            case '2':
                system("cls");
                if(band){
                    checarVuelo();
                }
                else{
                    cout<<"Usted aun no tiene ningun vuelo en reserva!\n";
                }
            break;
            case '3':
                system("cls");
            break;
            default: 
                system("cls");
                cout<<"Opcion inexistente...\n";
        }
    }while(opcion != '3');
}

void app(){
    char opcion;
    do{
        cout<<"1) Iniciar sesion\n";
        cout<<"2) Registrarse\n";
        cout<<"3) Salir\n";
        cin >> opcion;
        switch(opcion){
            case '1': 
                if(login()){
                    system("cls");
                    cout<<"Bienvenido!" << endl;
                    menu();
                }
                else{
                    system("cls");
                    cout<<"Usuario o password incorrectos...\n";
                }
            break;

            case '2': 
                system("cls");
                registro(); 
            break;
            case '3':
                system("cls");
                cout<<"Adios!";
            break;
            default: 
                system("cls");
                cout<<"Opcion inexistente...\n";
        }
    }while(opcion != '3');
}