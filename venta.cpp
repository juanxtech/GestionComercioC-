#include <iostream>
#include "Venta.h"
#include "archivo_venta.h"
#include "detalle_venta.h"
#include "archivo_detalle_venta.h"
#include "archivo_cliente.h"
#include "archivo_vendedor.h"
#include <iomanip>
using namespace std;


Venta::Venta() {
    _idV = 0;
    _idCliente = 0;
    _idVendedor = 0;
    _importeTotal = 0.0;
    _estado = true;
}

//setters
void Venta::setidV(int idV) {
    _idV = idV;
}

void Venta::setFecha(Fecha f) {
    fecha = f;
}

void Venta::setIdCliente(int id) {
    _idCliente = id;
}

void Venta::setIdVendedor(int id) {
    _idVendedor = id;
}

void Venta::setImporteTotal(double importe) {
    _importeTotal = importe;
}

void Venta::setEstado(bool estado){
    _estado=estado;
}

//getters
int Venta::getIdV() {
    return _idV;
}

Fecha Venta::getFecha() {
    return fecha;
}

int Venta::getIdCliente() {
    return _idCliente;
}

int Venta::getIdVendedor() {
    return _idVendedor;
}

double Venta::getImporteTotal() {
    return _importeTotal;
}

bool Venta::getEstado(){
    return _estado;
}

//meotodos
bool Venta::cargar() {
    ArchivoDetalleVenta arch;
    ArchivoVenta ven;
    int cantidadDetalles;
    ArchivoCliente archCliente;
    ArchivoVendedor archVendedor;

    _idV = ven.getNewId();

    cout << "Ingrese los datos de la venta" << endl;
    cout << "-----------------------------" << endl;

    bool opc1=false;

    while(opc1==false){
    cout << "ID del cliente: ";
    cin >> _idCliente;
    if(archCliente.buscarClientePorId(_idCliente)==true){
        cout<<"Cliente encontrado."<<endl;
        opc1=true;
        }
        else{
            cout<<"Error. Cliente no encontrado."<<endl;
            return false;
        }
    }

    bool opc2=false;

    while(opc2==false){
        cout << "ID del vendedor: ";
        cin >> _idVendedor;

        if(archVendedor.BuscarVendedorLegajo(_idVendedor)==true){
            cout<<"Vendedor encontrado."<<endl;
            opc2=true;
        }
        else{
            cout<<"Error. Vendedor no encontrado."<<endl;
            return false;
        }
    }

    cout << "Fecha de la venta:" << endl;
    fecha.cargar();

    do{
        cout << "Cuantos detalles de venta queres registrar? (min: 1)"<<endl;
        cin >> cantidadDetalles;
    }while(cantidadDetalles<=0);

    for (int i=0; i<cantidadDetalles; i++) {
        DetalleVenta detalleVenta;
        if(!detalleVenta.cargar(_idV, i)){
            return false;
        }
        arch.guardarDetalle(detalleVenta);  // función que sólo guarda
        _importeTotal += detalleVenta.getImporte();  // ahora sí tenés acceso
    }

    _estado=false;

    return true;
    cout << "-----------------------------" << endl;
}

void Venta::mostrar() {
    ArchivoDetalleVenta archivoventa;
    cout << "Datos de la venta" << endl;
    cout<<"Venta numero: "<<_idV<<endl;
    cout << "-----------------------------" << endl;
    cout << "ID de venta: " << _idV << endl;
    cout << "ID del cliente: " << _idCliente << endl;
    cout << "Fecha: ";
    fecha.mostrar();
    cout << "ID del vendedor: " << _idVendedor << endl;
    cout << "Eliminado: " << (_estado ? "True" : "False") << endl;
    cout << fixed << setprecision(2);
    cout << "Importe total: $" << _importeTotal << endl;
    cout << "Detalle: "<<endl;
    archivoventa.listarRegistros(_idV);
    cout << "-----------------------------" << endl;
}


