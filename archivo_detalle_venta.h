#pragma once
#include "detalle_venta.h"
#include <cstring>

class ArchivoDetalleVenta {
private:
    char nombre[30];
    int tamanioRegistro;

public:
    ArchivoDetalleVenta(const char *n="Detalle_ventas.dat"){
        strcpy(nombre,n);
        tamanioRegistro=sizeof(DetalleVenta);
    }

    int agregarRegistro(int idV);
    void listarRegistros(int idV);
    int BuscarPorId(int idV);
    bool Modificar(int id);
    bool Eliminar(int id);
    bool guardarDetalle(const DetalleVenta& d);
    void EquiposMasVendidos();
};
