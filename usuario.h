#include <fstream>
#include <conio.h>
#include <iostream>
#include <string.h>
using namespace std;

fstream userData;
fstream usuarios;
char caracter;

class Usuario{
    private:
        string usuario;
        string nombre;
        string apellido;
        int edad;
        int id;
        string password;
    public:
        Usuario(string,string);  
        Usuario(string,string,string,int,int,string);
        string getUser();  
        string getUserPass(); 
        int getAge();
        string getName();
        string getLast();
        int getUserId();    
        void setName(string);
        void setUser(string);
        void setPass(string);
        void changePass();
};

Usuario::Usuario(string nombre, string password){
    setName(nombre);
    setPass(password);
}

Usuario::Usuario(string usuario, string nombre, string apellido, int edad, int id, string pass){
    this->usuario = usuario;
    this->nombre = nombre;
    this->apellido = apellido;
    this->edad = edad;
    this->id = id;
    this->password = pass;
}

string Usuario::getName(){
    return this->nombre;
}

string Usuario::getLast(){
    return this->apellido;
}

int Usuario::getAge(){
    return this->edad;
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

void Usuario::setUser(string username){
    this->usuario = username;
}

void Usuario::setPass(string pass){
    this->password = pass;
}

void Usuario::setName(string name){
    this->nombre = name;
}

void Usuario::changePass(){
    string temp_pass,temp_pass2,temp;
    while(!usuarios.eof()){
        getline(usuarios,temp);
        if(temp == this->password){
            break;
        }
    }
    do{
        cout<<"Ingrese antigua password: ";

        caracter = getch();
        while (caracter != 13){
            if(caracter != 8){
                temp_pass.push_back(caracter);
                cout << "*";
            }
            else{
                if(temp_pass.length() > 0){
                    cout << "\b \b";
                    temp_pass = temp_pass.substr(0, temp_pass.length() - 1);
                }
            }
        caracter = getch();
        }

        if(temp_pass != password){
                cout<<"\nPassword incorrecta\n";
                cout<<this->getUserPass()<<endl;
            }     
    }while(temp_pass != this->password);
    usuarios.open("usuarios.txt", ios::app);
    do{  
        if(temp_pass != temp_pass2){
            cout<<"Las password no coinciden\n";
        }
        cout<<"Ingrese nueva password: ";

        caracter = getch();
        while (caracter != 13){
            if(caracter != 8){
                temp_pass.push_back(caracter);
                cout << "*";
            }
            else{
                if(temp_pass.length() > 0){
                    cout << "\b \b";
                    temp_pass = temp_pass.substr(0, temp_pass.length() - 1);
                }
            }
        caracter = getch();
        }

        cout<<"Confirme nueva password: ";

        caracter = getch();
        while (caracter != 13){
            if(caracter != 8){
                temp_pass2.push_back(caracter);
                cout << "*";
            }
            else{
                if(temp_pass2.length() > 0){
                    cout << "\b \b";
                    temp_pass2 = temp_pass2.substr(0, temp_pass2.length() - 1);
                }
            }
        caracter = getch();
        }
        
    }while(temp_pass != temp_pass2);
    this->password = temp_pass;
    system("cls");
    cout<<"Su password ha cambiado con exito!\n";
    usuarios.close();
}