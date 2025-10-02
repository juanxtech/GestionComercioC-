#pragma once
#include "venta.h"
#include <cstring>
#define _CRT_SECURE_NO_WARNINGS


class ArchivoVenta {
private:
    char nombre[30];
    int tamanioRegistro;

public:
    ArchivoVenta(const char *n="Ventas.dat"){
        strcpy(nombre,n);
        tamanioRegistro=sizeof(Venta);
    }

    int agregarRegistro();
    bool listarRegistros(bool general);
    int BuscarVenta(int idV);
    void ListarPorAnio(int anio);
    bool ModificarVenta(int id);
    bool EliminarVenta(int id);
    int getNewId();
    int ClienteQueMasRecaudo(float &importeMax);
    int RecaudacionPorAnio(int anio);
    int CantidadRegistro();
    void EquiposMasVendidos();
};
