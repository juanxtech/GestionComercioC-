#pragma once
#include "Vendedores.h"

class ArchivoVendedor {
private:
    char nombre[30];
    int tamanioRegistro;

public:
    bool AgregarRegistro();
    void ListarRegistros();
    bool BuscarVendedorLegajo(int legajo);
    bool BuscarVendedorMayorRecaudacion(int id);
    bool ModificarVendedor(int legajoBuscado);
    bool EliminarVendedor(int legajoEliminar);
    bool EliminarVendedorLogica(int legajoEliminar);
    int getNewId();
    int cantidadRegistros();

};
