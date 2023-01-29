#include <iostream>
#include <string>
using namespace std;

class Usuario{
    private:
        string usuario;
        string nombre;
        string apellido;
        int edad;
        int id;
        string password;
    public:
        Usuario();  
        Usuario(string,string,string,int,int,string);
        string getUser();  
        string getUserPass(); 
        int getUserId();    
        void setPass();
};

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
    string temp_pass,temp_pass2;
    do{
        cout<<"Ingrese nueva password: ";
        cin>>temp_pass;
        cout<<"Confirme nueva password: ";
        cin>>temp_pass2;
        
    }while(temp_pass != temp_pass2);
    this->password = temp_pass;
}