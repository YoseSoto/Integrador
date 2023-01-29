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

Avion AirbusA320 = Avion("AirbusA320",4,220);
Avion Boeing737 = Avion("Boeing737",8,220);
Vuelo CDMXtoMTY = Vuelo(numPasajeros, 655,"Volaris",2054,"Monterrey,NL",990,AirbusA320,"1.44h","Primera Clase");
Vuelo CDMXtoCUN = Vuelo(numPasajeros, 7263,"Viva Aerobus",1449,"Cancun",1608,Boeing737,"2:16h","Turista");

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
    vuelos.open("vuelos.txt", ios::app);
    vuelos << "Destino: "<< flight.getDest() << endl;
    vuelos << "Id: " << flight.getId() << endl;
    vuelos << "Aerolinea: " << flight.getAeroline() << endl;
    vuelos << "Clase: " << flight.getClass() << endl;    
    vuelos << "Precio: " << flight.getPrice() << endl;
    vuelos << "Kilometros: " << flight.getKm() << endl;
    vuelos << "Tiempo estimado: " << flight.getTimeLength() << endl;
    vuelos << "Avion: " << flight.getAvion().getName() << endl;
    lista_vuelos.push_back(flight);
    vuelos.close();
}

void listaVuelos(){

    vuelos.open("vuelos.txt",ios::in);
    int i,j=0;
    char opcion;
    string temp_line;

    lista_aviones.push_back(AirbusA320);
    lista_aviones.push_back(Boeing737);
    
    do{
        system("cls");
        cout<<"\n\tLista de vuelos disponibles\n";
        while(!vuelos.eof()){
            cout<<"Detalles de vuelo "<<j+1<<"): \n";
            for(i=0; i<9;i++){
                getline(vuelos,temp_line);
                cout<<"   "<<temp_line<<endl;
            }
            j++;
        }
        cout<<"    0) Regresar\n";
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
    }while(opcion != '0');
    vuelos.close();
    band = true;
}

void checarVuelo(){

}

void menu(){
    char opcion;
    do{
        cout<<"\n\tReservaciones Yose\n";
        cout<<"1) Reservar vuelo\n";
        cout<<"2) Checar vuelo\n";
        cout<<"3) Salir\n";
        cin>>opcion;
        switch(opcion){
            case '1':
                system("cls");
                listaVuelos();
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
    if(!vuelos.fail()){
        vuelos.open("vuelos.txt",ios::out);
        vuelos.close();
        addFlightToDataBase(CDMXtoMTY);
        addFlightToDataBase(CDMXtoCUN);
    }
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