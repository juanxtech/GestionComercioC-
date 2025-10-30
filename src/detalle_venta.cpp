#include <iostream>
#include "detalle_venta.h"
#include "archivo_equipo.h"

// Setters
void DetalleVenta::setId(int _id) {
    id = _id;
}

void DetalleVenta::setIdVenta(int _idVenta) {
    idVenta = _idVenta;
}

void DetalleVenta::setIdProducto(int _idProducto) {
    idProducto = _idProducto;
}

void DetalleVenta::setCantidad(int _cantidad) {
    cantidad = _cantidad;
}

void DetalleVenta::setPrecioUnitario(float _precioUnitario) {
    precioUnitario = _precioUnitario;
}

void DetalleVenta::setImporte(float _importe) {
    importe = _importe;
}

void DetalleVenta::setEstado(){
    estado = !estado;
}

// Getters
int DetalleVenta::getId() {
    return id;
}

int DetalleVenta::getIdVenta() {
    return idVenta;
}

int DetalleVenta::getIdProducto() {
    return idProducto;
}

int DetalleVenta::getCantidad() {
    return cantidad;
}

float DetalleVenta::getPrecioUnitario() {
    return precioUnitario;
}

float DetalleVenta::getImporte() {
    return importe;
}

bool DetalleVenta::getEstado(){
    return estado;
}

// Método para cargar datos
bool DetalleVenta::cargar(int idVentaPadre, int num) {
    ArchivoEquipo reg;

    id = num+1; // id_detalle automatico.

    do {
        cout << "ID Producto: ";
        cin >> idProducto;
        if(idProducto==0 || reg.BuscarEquipo(idProducto) == -1){
            cout<<"Error. Ingrese un ID valido."<<endl;
            return false;
        }
    } while (idProducto == 0);

    idVenta = idVentaPadre;
    precioUnitario = reg.getPrecioId(idProducto);
    int stockActual = reg.getStockId(idProducto);
    if(stockActual == 0){
        cout<<"El stock de este producto es 0, por lo que no puede registrar una venta con este producto."<<endl;
        return false;
    }

    do{
        cout << "Cantidad: ";
        cin >> cantidad;

        if(cantidad < 0){
            cout<<"Debe ingresar una cantidad valida mayor a 0."<<endl;
        }
        else if(cantidad > stockActual){
            cout << "Stock insuficiente. Disponible actualmente: "<<stockActual<<endl;
        }
    } while (cantidad <=0 || cantidad > stockActual);

    importe = cantidad * precioUnitario;

    int nuevoStock = stockActual - cantidad;

    if(!reg.modificarStock(idProducto, nuevoStock)){
        cout<<"Error al actualizar el stock."<<endl;
        return false;
    }
    return true;
}

// Método para mostrar datos
void DetalleVenta::mostrar() {
    cout << "-----------------------------" << endl;
    cout << "ID Detalle: " << id << endl;
    cout << "ID Venta: " << idVenta << endl;
    cout << "ID Producto: " << idProducto << endl;
    cout << "Cantidad: " << cantidad << endl;
    cout << "Precio Unitario: $" << precioUnitario << endl;
    cout << "Importe Total: $" << importe << endl;
}
