#include "cliente.h"
#include "archivo_cliente.h"
#include <iostream>
#include <cstring>
#define _CRT_SECURE_NO_WARNINGS


using namespace std;



// GETTERS
int Cliente::getIdCliente(){
    return idCliente;
}

const char* Cliente::getCUIT(){
    return cuit;
}

int Cliente::getTipoCliente(){
    return tipoCliente;
}

// SETTERS

void Cliente::setIdCliente(int id) {
    idCliente = id;
}

void Cliente::setCUIT(const char* valor) {
    if(strlen(valor) > 9){
        strcpy(cuit, valor);
    }
}

void Cliente::setTipoCliente(int tipo) {
    tipoCliente = tipo;
}

// MÉTODOS
bool Cliente::Cargar(char* _nuevoCuit) {
    cout << "\n--- Cargando datos del cliente ---" << endl;
    ArchivoCliente cli;

    if (_nuevoCuit == nullptr) {
        // Entrada manual con validación
        do {
            cout << "Ingrese su CUIT: ";
            cin >> cuit;

            bool esValido = true;

            // Verificar que sean solo números
            for (int i = 0; cuit[i] != '\0'; i++) {
                if (!isdigit(cuit[i])) {
                    esValido = false;
                    break;
                }
            }

            // Verificar longitud
            if (strlen(cuit) != 11) {
                esValido = false;
            }

            if (!esValido) {
                cout << "CUIT invalido. Debe contener solo numeros y tener 11 digitos." << endl;
            } else {
                break; // salir del bucle si es válido
            }

        } while (true);
    } else {
        strcpy(cuit, _nuevoCuit);
    }

    if (cli.buscarCliente(cuit)) {
        cout << "Ya existe el usuario." << endl;
        return false;
    }

    idCliente = cli.getNewId();
    cout << "ID: " << idCliente << endl;

    if(!Persona::Cargar()){ // método heredado
        return false;
    }
    return true;
}



void Cliente::CargarMod(const char* _cuit, int id){
    strcpy(cuit,_cuit);
    idCliente=id;
    Persona::Cargar();
}

void Cliente::Mostrar() {

    cout << "\n--- Datos del cliente ---" << endl;
    cout << "ID: " << idCliente << endl;
    cout << "CUIT: " << cuit << endl;

    Persona::Mostrar(); // Usamos el método heredado de Persona
}
