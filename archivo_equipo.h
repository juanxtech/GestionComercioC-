#pragma once
#include "equipo.h"
#include <cstring>

class ArchivoEquipo {
private:
    char nombre[30];
    int tamanioRegistro;

public:
    ArchivoEquipo(const char* n = "Equipo.dat") {
        strcpy(nombre, n);
        tamanioRegistro = sizeof(Equipo);
    }

    int AgregarRegistro();
    bool ListarRegistros();
    int BuscarEquipo(int id);
    int BuscarPosicionPorId(int id);
    void ListarPorTipo(const char* tipo);
    void ListarDisponibles();
    bool ModificarEquipo(int posicion); //modifica un euqipo en una posicion determinada
    bool EliminarEquipo(int id);
    void VaciarArchivo();//solo usar para borrar todos los registros
    int getNewId();
    float getPrecioId(int id);
    int getStockId(int id);
    bool modificarStock(int id, int cant);
};
