#include <iostream>
#include <cstring>
#include "Equipo.h"
#include <string>

using namespace std;


// Constructor
Equipo::Equipo() {
    _idEquipo = 0;
    strcpy(_descripcion, "");
    strcpy(_marca, "");
    strcpy(_tipo, "");
    _stock = 0;
    _precio = 0.0;
    _eliminado = false;
}


// SETTERS
void Equipo::setIdEquipo(int idEquipo) {
    _idEquipo = idEquipo;
}

void Equipo::setDescripcion(const char* descripcion) {
    strcpy(_descripcion, descripcion);
}

void Equipo::setMarca(const char* marca) {
    strcpy(_marca, marca);
}

void Equipo::setTipo(const char* tipo) {
    strcpy(_tipo, tipo);
}

void Equipo::setStock(int stock) {
    _stock = stock;
}

void Equipo::setPrecio(float precio) {
    _precio = precio;
}

void Equipo::setEliminado(bool eliminado) {
    _eliminado = eliminado;
}

// GETTERS
int Equipo::getIdEquipo() {
    return _idEquipo;
}

char* Equipo::getDescripcion() {
    return _descripcion;
}

char* Equipo::getMarca() {
    return _marca;
}

char* Equipo::getTipo() {
    return _tipo;
}

int Equipo::getStock() {
    return _stock;
}

float Equipo::getPrecio() {
    return _precio;
}

bool Equipo::getEliminado() {
    return _eliminado;
}

// funcion para validar numero entero para el STOCK!
bool esNumero(char c) {
    return c >= '0' && c <= '9'; //hasta 9 porque mas digitos no seria carcater valido
}

int leerEntero(string mensaje) {
    string entrada;
    int valor;

    while (true) {
        cout << mensaje;
        getline(cin, entrada);

        bool esValido = true;
        size_t i = 0;

        if (entrada.empty()) {
            esValido = false;
        } else {
            if (entrada[0] == '-') {
                // no se permite stock negativo
                esValido = false;
            } else if (entrada[0] == '+') {
                i = 1;
                if (entrada.length() == 1) {
                    esValido = false;
                }
            } else {
                i = 0;
            }

            while (i < entrada.length() && esValido) {
                if (!esNumero(entrada[i])) {
                    esValido = false;
                    break;
                }
                i++;
            }
        }

        if (esValido) {
            valor = stoi(entrada);
            if(valor == 0){
                cout<<"El valor no puede ser 0."<<endl;
                continue;
            }
            return valor;
        } else {
            cout << "Entrada invalida. Ingrese un numero entero valido (sin negativos)." << endl;
        }
    }
}


//funcion para validar datos numericos numericos

float leerFloat(string mensaje) {
    float numero;

    while (true) {  // Loop infinito hasta obtener un valor valido
        cout << mensaje;

        if (cin >> numero) {
            if (numero < 0) {
                cout << "Error! No puede ingresar numeros negativos" << endl;
                cin.ignore();  // limpiar el buffer

            } else {
                cin.ignore();
                return numero;
            }
        } else {
            cout << "Error! Debe ingresar un numero valido" << endl;
            cin.clear();        // limpia error
            cin.ignore(1000, '\n');
        }
    }
}



// METODOS
bool Equipo::Cargar() {
    cout << "Ingrese los datos del equipo" << endl;
    cout << "----------------------------" << endl;

    cin.ignore();

    cout << "Tipo de equipo (ingrese 0 para cancelar): ";
    cin.getline(_tipo, 30);
    if (strcmp(_tipo, "0") == 0) {
        cout << "Carga cancelada." << endl;
        return false;
    }

     cout << "Descripcion: ";
    cin.getline(_descripcion, 100);

    cout << "Marca: ";
    cin.getline(_marca, 30);


    //cin.ignore();

    //cout << "Stock: ";
    //cin >> _stock;
    _stock = leerEntero("Stock: ");

    //cout << "Precio(pesos): $ ";
    //cin >> _precio;
    _precio = leerFloat("Precio(pesos): $ ");


    _eliminado = false;
    return true;
}

void Equipo::Modificar() {
    cout << "Ingrese los datos del equipo" << endl;
    cout << "----------------------------" << endl;

    cout << "Tipo de equipo: ";
    cin.getline(_tipo, 30);

     cout << "Descripcion: ";
    cin.getline(_descripcion, 100);

    cout << "Marca: ";
    cin.getline(_marca, 30);

    _stock = leerEntero("Stock: ");

    _precio = leerFloat("Precio(pesos): $ ");

    _eliminado = false;
}

void Equipo::Mostrar() {
    cout << "ID: " << _idEquipo << endl;
    cout << "Descripcion: " << _descripcion << endl;
    cout << "Marca: " << _marca << endl;
    cout << "Tipo: " << _tipo << endl;
    cout << "Stock: " << _stock << endl;
    cout << "Precio: $" << _precio << endl;
    cout << "Eliminado: " << (_eliminado ? "True" : "False") << endl;
    cout << "-----------------------------" << endl;
}
