#include "Vendedores.h"
#include <iostream>
#include "archivo_vendedor.h"

using namespace std;

// Constructor

Vendedor::Vendedor(){
    legajo = 0;
    sueldo = 0.0;
}

// GETTERS
float Vendedor::getSueldo() {
    return sueldo;
}

Fecha Vendedor::getIngreso() {
    return ingreso;
}

int Vendedor::getLegajo() {
    return legajo;
}

// SETTERS
void Vendedor::setSueldo(float s) {
    sueldo = s;
}

void Vendedor::setIngreso(Fecha f) {
    ingreso = f;
}

void Vendedor::setLegajo(int leg) {
    if(leg>0){
        legajo = leg;
    }
    else{
        cout << "Legajo invalido. Debe ser mayor a 0." << endl;
    }
}

// MÉTODOS
bool Vendedor::cargar() {
    ArchivoVendedor vendedor;
    cout << "\n--- Cargando datos del vendedor ---" << endl;

    // Usamos el método heredado de Persona
    if(!Persona::Cargar()){
        return false;
    }

    legajo=vendedor.getNewId();

    cout << "Ingrese sueldo: ";
    cin >> sueldo;

    cout << "Ingrese fecha de ingreso:" << endl;
    ingreso.cargar();  // usamos el método cargar() de la clase Fecha
    return true;
}

void Vendedor::mostrar() {
    cout << "\n--- Datos del vendedor ---" << endl;

    // Usamos el método heredado de Persona
    Persona::Mostrar();

    cout << "Legajo: " << legajo << endl;
    cout << "Sueldo: $" << sueldo << endl;
    cout << "Fecha de ingreso: ";
    ingreso.mostrar();  // usamos el método mostrar() de la clase Fecha
}
