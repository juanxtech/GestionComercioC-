#pragma once
#include <iostream>
using namespace std;

class DetalleVenta {
private:
    int id;
    int idVenta;
    int idProducto;
    int cantidad;
    float precioUnitario;
    float importe;
    bool estado;

public:
    // Setters
    void setId(int _id);
    void setIdVenta(int _idVenta);
    void setIdProducto(int _idProducto);
    void setCantidad(int _cantidad);
    void setPrecioUnitario(float _precioUnitario);
    void setImporte(float _importe);
    void setEstado();

    // Getters
    int getId();
    int getIdVenta();
    int getIdProducto();
    int getCantidad();
    float getPrecioUnitario();
    float getImporte();
    bool getEstado();

    // Métodos funcionales
    bool cargar(int idVentaPadre, int num);
    void mostrar();
};
