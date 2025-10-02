#include <iostream>
#include "fecha.h"
#include <ctime>
#include <string>

using namespace std;

// Constructor por defecto: asigna la fecha del sistema
Fecha::Fecha() {
    time_t t = time(nullptr);
    tm* tiempoLocal = localtime(&t);
    dia = tiempoLocal->tm_mday;
    mes = tiempoLocal->tm_mon + 1;
    anio = tiempoLocal->tm_year + 1900;
}

Fecha::Fecha(int d, int m, int a) {
    dia = d;
    mes = m;
    anio = a;
}

// Getters
int Fecha::GetDia() { return dia; }
int Fecha::GetMes() { return mes; }
int Fecha::GetAnio() { return anio; }

// Setters
void Fecha::SetDia(int d) {
    bool valido = false;
    switch (mes) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            valido = (d >= 1 && d <= 31);
            break;
        case 4: case 6: case 9: case 11:
            valido = (d >= 1 && d <= 30);
            break;
        case 2:
            valido = (d >= 1 && d <= 28);
            break;
    }
    if (valido) {
        dia = d;
    } else {
        cout << "Dia invalido. Ingrese un dia entre 1-31." << endl;
    }
}

void Fecha::SetMes(int m) {
    if (m >= 1 && m <= 12) {
        mes = m;
    } else {
        cout << "Mes invalido." << endl;
    }
}

void Fecha::SetAnio(int a) {
    if (a >= 1800 && a <= 2025) {
        anio = a;
    } else {
        cout << "Anio invalido. Debe estar entre 1900 y 2025." << endl;
    }
}

// Funciones auxiliares
bool esNumero(string entrada) {
    if (entrada.empty()) return false;
    for (int i = 0; i < entrada.length(); i++) {
        if (entrada[i] < '0' || entrada[i] > '9') {
            return false;
        }
    }
    return true;
}

int convertirAEntero(string entrada) {
    int valor = 0;
    for (int i = 0; i < entrada.length(); i++) {
        valor = valor * 10 + (entrada[i] - '0');
    }
    return valor;
}

// Cargar datos
void Fecha::cargar() {
    string entrada;
    int d, m, a;

    cin.ignore();

    // MES
    while (true) {
        cout << "Mes: ";
        getline(cin, entrada);
        if (entrada.empty() || !esNumero(entrada)) {
            cout << "Error: ingrese solo numeros." << endl;
            continue;
        }
        m = convertirAEntero(entrada);
        if (m < 1 || m > 12) {
            cout << "Mes invalido. Ingrese un mes entre 1-12" << endl;
            continue;
        }
        break;
    }

    // ANIO
    while (true) {
        cout << "Anio: ";
        getline(cin, entrada);
        if (entrada.empty() || !esNumero(entrada)) {
            cout << "Error: ingrese solo numeros." << endl;
            continue;
        }
        a = convertirAEntero(entrada);
        if (a < 1990 || a > 2024) {
            cout << "Anio invalido. Debe estar entre 1990 y 2024." << endl;
            continue;
        }
        break;
    }

    SetMes(m);
    SetAnio(a);

    // DIA
    while (true) {
        cout << "Dia: ";
        getline(cin, entrada);
        if (entrada.empty() || !esNumero(entrada)) {
            cout << "Error: ingrese solo numeros." << endl;
            continue;
        }
        d = convertirAEntero(entrada);
        int diaAnterior = dia;
        SetDia(d);
        if (dia == d) break;
        else dia = diaAnterior;
    }
}

void Fecha::mostrar() {
    cout << dia << "/" << mes << "/" << anio << endl;
}
