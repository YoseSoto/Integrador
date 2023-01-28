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
