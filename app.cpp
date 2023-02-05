#include "vuelo.h"
using namespace std;

vector<Usuario> usuarioActivo;
vector<Usuario> usersLoggedIn;

fstream vuelos;
vector<Vuelo> lista_vuelos;

bool band = false;

string _usuario, _password, _password2;

Avion AirbusA320 = Avion("AirbusA320",4,220);
Avion Boeing737 = Avion("Boeing737",8,220);
Avion Boeing747 = Avion("Boeing747",10,400);

Vuelo CDMXtoMTY = Vuelo( 655,"Volaris",2054,"Monterrey,NL",990,AirbusA320,"1.44h","Primera Clase");
Vuelo CDMXtoCUN = Vuelo( 7263,"Viva Aerobus",1449,"Cancun",1608,Boeing737,"2:16h","Turista");
Vuelo CDMXtoGDL = Vuelo( 2142,"Aeromexico",1922,"Guadalajara",536,AirbusA320,"1:22","Turista");
Vuelo CDMXtoMADRID = Vuelo(133,"Aeromexico",15924,"Madrid",9057,Boeing747,"10:24","Primera Clase");
Vuelo CDMXtoLondres = Vuelo(9029,"British Airways",15263,"Londres",8982,Boeing747,"14:15","Turista");


bool login(){
    system("cls");
    string in_user, in_pass;
    string temp_user, temp_pass, temp_name, temp_last, temp_age, fileSpace;

    while(usuarioActivo.size() != 0){
        usuarioActivo.pop_back();
    }

    userData.open("userData.txt",ios::in);

    cout<<"Usuario: "; 
    cin >> in_user;
    cout<<"Password: "; 

    caracter = getch();
    while (caracter != 13){
        if(caracter != 8){
            in_pass.push_back(caracter);
            cout << "*";
        }
        else{
            if(in_pass.length() > 0){
                cout << "\b \b";
                in_pass = in_pass.substr(0, in_pass.length() - 1);
            }
        }
        caracter = getch();
    }
    while(!userData.eof()){
        getline(userData,temp_user);
        getline(userData,temp_pass);
        getline(userData,temp_name);
        getline(userData,temp_last);
        getline(userData,temp_age);
        getline(userData,fileSpace);
        //cout<< endl << temp_user << " " << temp_user << " " << temp_pass << " " << temp_name << " " << temp_last << " " << temp_age << " " << fileSpace << endl;
        if( "Usuario: " + in_user == temp_user && "Password: " + in_pass == temp_pass ){
            Usuario usuario = Usuario(temp_name, in_pass);   
            usuario.setName(temp_name);
            usuario.setUser(in_user);
            usuario.setPass(in_pass);
            usuarioActivo.push_back(usuario);  
            userData.close();
            return true;
        }
    }
    userData.close();    
    return false;
}

void addUserToDataBase(Usuario user){
    userData.open("userData.txt",ios::app);
    userData << "Usuario: " << user.getUser() << endl;
    userData << "Password: " << user.getUserPass() << endl;
    userData << "Nombre: " << user.getName() << endl;
    userData << "Apellido: " << user.getLast() << endl;
    userData << "Edad: " << user.getAge() << endl << endl;
    usersLoggedIn.push_back(user);
    userData.close();
    userData.close();
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

    int i;
    char opcion;
    string temp_line;
    
    do{
        vuelos.open("vuelos.txt",ios::in);
        int j = 0;
        //system("cls");
        cout<<"\n\tLista de vuelos disponibles\n";
        while(!vuelos.eof() && j<5){
            cout<<"Detalles de vuelo "<<j+1<<"): \n";
            for(i=0; i<8;i++){
                getline(vuelos,temp_line);
                cout<<"   "<<temp_line<<endl;
            }
            cout<<endl;
            j++;
        }
        cout<<"   0) Regresar\n";
        cin >> opcion;
        switch(opcion){
            case '1':
                system("cls");
                CDMXtoMTY.agregar(CDMXtoMTY,usuarioActivo.at(0));
            break;
            case '2':
                system("cls");
                CDMXtoCUN.agregar(CDMXtoCUN,usuarioActivo.at(0));
            break;
            case '3':
                system("cls");
                CDMXtoGDL.agregar(CDMXtoGDL,usuarioActivo.at(0));
            break;
            case '4':
                system("cls");
                CDMXtoMADRID.agregar(CDMXtoMADRID,usuarioActivo.at(0));
            break;
            case '5':
                system("cls");
                CDMXtoLondres.agregar(CDMXtoLondres,usuarioActivo.at(0));
            break;
            case '0':
                system("cls");
            break;
            default:
                system("cls");
                cout<<"Opcion inexistente...\n";
        }
        opcion = '0';
        vuelos.close();
    }while(opcion!='0');
    band = true;
}

void checarVuelo(){
    string temp;
    reservaciones.open("reservaciones.txt",ios::in);
    cout << "\tDetalles de su vuelo:\n";
    while(!reservaciones.eof()){
        getline(reservaciones,temp);
        cout<<temp<<endl;
    }
    reservaciones.close();
}

void menu(){
    char opcion;
    do{
        cout<<"\n\tReservaciones Yose\n";
        cout<<"1) Reservar vuelo\n";
        cout<<"2) Checar vuelo\n";
        //cout<<"3) Cambiar password\n";
        cout<<"3) Salir\n";
        cin>>opcion;
        switch(opcion){
            case '1':
                system("cls");
                if(!band){
                    listaVuelos();
                }
                else{
                    cout<<"Usted YA tiene un vuelo en reserva!\n";
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
            //case '3':
                //system("cls");
                //usuarioActivo.at(0).changePass();
            //break;
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
        addFlightToDataBase(CDMXtoGDL);
        addFlightToDataBase(CDMXtoMADRID);
        addFlightToDataBase(CDMXtoLondres);
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
                    cout << usuarioActivo.at(0).getName() << ", bienvenido!" << endl;
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
