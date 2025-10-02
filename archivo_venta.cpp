#include <iostream>
#include "archivo_venta.h"
#include "archivo_cliente.h"
#define _CRT_SECURE_NO_WARNINGS


using namespace std;

int ArchivoVenta::agregarRegistro() {
    Venta ven;
    FILE *pcventa = fopen(nombre, "ab");

    if(pcventa==nullptr){
        cout<<"No se pudo abrir el archivo para escribir."<<endl;
        return -1;
    }

    if(ven.cargar() == false){
        return -1;
    }

    int escribio = fwrite(&ven, sizeof(Venta), 1, pcventa);

    if(escribio != 1){
        cout<<"Error al escribir el registro."<<endl;
    }

    fclose(pcventa);

    return escribio; // si escribio = 1, es un OK.
}

bool ArchivoVenta::listarRegistros(bool general){
    Venta ven;
    FILE *pcventa = fopen(nombre, "rb");

    if(pcventa==nullptr){
        return false;
    }
    int pos=0;
    while(fread(&ven,tamanioRegistro,1,pcventa)==1){
        if(ven.getEstado()==0 || general==true){
            ven.mostrar();
        }
        pos++;
    }
    fclose(pcventa);
    return true;
}

int ArchivoVenta::BuscarVenta(int idV) {
    Venta ven;
    FILE *pcventa = fopen(nombre, "rb");

    if (pcventa == nullptr) {
        return -1;
    }

    // Contar cuántos registros hay
    int cantidad = 0;
    while (fread(&ven, tamanioRegistro, 1, pcventa) == 1) {
        cantidad++;
    }

    rewind(pcventa); // volver al inicio

    for (int i = 0; i < cantidad; i++) {
        fseek(pcventa, i * tamanioRegistro, 0);
        fread(&ven, tamanioRegistro, 1, pcventa);

        if (ven.getIdV() == idV) {
            ven.mostrar();
            fclose(pcventa);
            return 1;
        }
    }

    fclose(pcventa);
    return 0;
}

void ArchivoVenta::ListarPorAnio(int a){
    Venta ven;
    FILE *pcventa = fopen(nombre, "rb");

    if (pcventa == nullptr) {
        return;
    }

    // Contar cuántos registros hay
    int cantidad = 0;
    while (fread(&ven, tamanioRegistro, 1, pcventa) == 1) {
        cantidad++;
    }

    rewind(pcventa); // volver al inicio

    for (int i = 0; i < cantidad; i++) {
        fseek(pcventa, i * tamanioRegistro, 0);
        fread(&ven, tamanioRegistro, 1, pcventa);

        if (ven.getFecha().GetAnio() == a) {
            ven.mostrar();
            fclose(pcventa);
            return;
        }
    }

    fclose(pcventa);
    return;
}

bool ArchivoVenta::EliminarVenta(int idV){
    Venta ven;
    FILE *pcventa = fopen(nombre, "r+b");

    if (pcventa == nullptr) {
        return false;
    }

    int pos = 0;
    while (fread(&ven, tamanioRegistro, 1, pcventa) == 1) {
        if (ven.getIdV() == idV && ven.getEstado() == true) {
            ven.setEstado(false);
            fseek(pcventa, pos * tamanioRegistro, SEEK_SET);
            fwrite(&ven, tamanioRegistro, 1, pcventa);
            fclose(pcventa);
            return true;
        }
        pos++;
    }

    fclose(pcventa);
    return false;
}


bool ArchivoVenta::ModificarVenta(int idV){
    Venta ven;
    FILE *pcventa = fopen(nombre, "r+b");

    if (pcventa == nullptr) {
        return false;
    }

    // Contar registros
    int cantidad = 0;
    while (fread(&ven, tamanioRegistro, 1, pcventa) == 1) {
        cantidad++;
    }

    rewind(pcventa);

    for (int i = 0; i < cantidad; i++) {
        fseek(pcventa, i * tamanioRegistro, SEEK_SET);
        fread(&ven, tamanioRegistro, 1, pcventa);

        if (ven.getIdV() == idV) {
            ven.cargar();
            ven.setidV(idV);
            fseek(pcventa, i * tamanioRegistro, SEEK_SET);
            fwrite(&ven, tamanioRegistro, 1, pcventa);
            fclose(pcventa);
            return true;
        }
    }

    fclose(pcventa);
    return false;  // no encontró el idV
}



int ArchivoVenta::getNewId(){
    Venta ven;

    FILE *pcven = fopen(nombre,"rb");

    if(pcven==nullptr){
        return -1;
    }

    int lastId=0;
    while(fread(&ven,tamanioRegistro,1,pcven)==1){
        lastId=ven.getIdV();
    }
    fclose(pcven);
    return lastId+1;
}

int ArchivoVenta::RecaudacionPorAnio(int anio){
    Venta venta;

    FILE* pventa= fopen(nombre,"rb");

    if(pventa==nullptr){
        return -1;
    }

    int pos=0;
    int AcumAnio=0;

    while(fread(&venta,tamanioRegistro,1,pventa)==1){
        if(venta.getFecha().GetAnio()==anio){
            AcumAnio+=venta.getImporteTotal();
        }
        pos++;
    }
    fclose(pventa);

    if(AcumAnio>0){
        return AcumAnio;
    }else{
        return -1;
    }
}

int ArchivoVenta::CantidadRegistro(){
    FILE *pventa;
    pventa=fopen(nombre, "rb");

    int cantidad;

    if(pventa==nullptr){
        return 0;
    }

    fseek(pventa,0,SEEK_END);

    cantidad=ftell(pventa) / sizeof(Venta);

    fclose(pventa);

    return cantidad;
}


int ArchivoVenta::ClienteQueMasRecaudo(float &importeMax){
    ArchivoCliente archivocliente;
    Venta venta;

    FILE* pventa= fopen(nombre,"rb");

    if(pventa==nullptr){
        importeMax=0;
        return -1;
    }

    int pos=0;
    int idMax=-1;

    while(fread(&venta,tamanioRegistro,1,pventa)==1){
        if(archivocliente.buscarClientePorId(venta.getIdCliente())&&venta.getImporteTotal()>importeMax){
            idMax=venta.getIdCliente();
            importeMax=venta.getImporteTotal();
        }
        pos++;
    }

    fclose(pventa);
    return idMax;
}
