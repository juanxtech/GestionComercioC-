#include <iostream>
#include <cstring>
#include "Persona.h"

using namespace std;

// Constructores
Persona::Persona() {
    strcpy(_nombres, "");
    strcpy(_apellidos, "");
    _fechaNac = Fecha();
    strcpy(_telefono, "");
    strcpy(_email, "");
    strcpy(_direccion, "");
    _estado = false;
}

Persona::Persona(const char* nombres, const char* apellidos, Fecha fechaNac,
                 const char* telefono, const char* email, const char* direccion, bool estado) {

    strcpy(_nombres, nombres);
    strcpy(_apellidos, apellidos);
    _fechaNac = fechaNac;
    strcpy(_telefono, telefono);
    strcpy(_email, email);
    strcpy(_direccion, direccion);
    _estado = estado;
}

// Getters


const char* Persona::getNombres() {
    return _nombres;
}

const char* Persona::getApellidos() {
    return _apellidos;
}

Fecha Persona::GetFechaNac() {
    return _fechaNac;
}

const char* Persona::getTelefono() {
    return _telefono;
}

const char* Persona::getEmail() {
    return _email;
}

const char* Persona::getDireccion() {
    return _direccion;
}

bool Persona::getEstado() {
    return _estado;
}

// Setters

void Persona::setNombres(const char* nombres) {
    strcpy(_nombres, nombres);
}

void Persona::setApellidos(const char* apellidos) {
    strcpy(_apellidos, apellidos);
}

void Persona::SetFecha(Fecha fechaNac) {
    _fechaNac = fechaNac;
}

void Persona::setTelefono(const char* telefono) {
    strcpy(_telefono, telefono);
}

void Persona::setEmail(const char* email) {
    strcpy(_email, email);
}

void Persona::setDireccion(const char* direccion) {
    strcpy(_direccion, direccion);
}

void Persona::setEstado(bool estado) {
    _estado = estado;
}

// Métodos
bool Persona::Cargar() {
    cout << "Cargue sus datos personales" << endl;
    cout << "---------------------------" << endl;
    cin.ignore();

    cout << "Nombres: (Ingrese 0 para cancelar la carga): ";
    cin.getline(_nombres,50);
    if (strcmp(_nombres, "0") == 0) {
        cout << "Carga cancelada." << endl;
        return false;
    }
    cout << "Apellidos: ";
    cin>>_apellidos;

    cout << "Fecha de nacimiento: "<<endl;
    _fechaNac.cargar();  // asegurate de tener este método en la clase Fecha
    cout << "Telefono: ";
    cin>>_telefono;
    cout << "Email: ";
    cin>>_email;
    cin.ignore();
    cout << "Direccion: ";
    cin.getline(_direccion, 100);
    _estado=true;
    return true;
}

void Persona::Mostrar() {
    cout << "Nombre completo: " << _nombres << " " << _apellidos << endl;
    cout << "Fecha de nacimiento: ";
    _fechaNac.mostrar(); // asegurate que exista mostrar() en Fecha
    cout << "Telefono: " << _telefono << endl;
    cout << "Email: " << _email << endl;
    cout << "Direccion: " << _direccion << endl;
    cout << "Estado: ";
    if(_estado==true){
        cout<<"activo"<<endl;
    }else{
        cout<<"inactivo"<<endl;
    }
}
