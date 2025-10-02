#include <iostream>
#include "archivo_detalle_venta.h"
#include "detalle_venta.h"
#include "venta.h"
#define _CRT_SECURE_NO_WARNINGS


using namespace std;

int ArchivoDetalleVenta::agregarRegistro(int idV) {
    DetalleVenta detalleVenta;
    FILE *pcventa = fopen(nombre, "ab");

    if(pcventa==nullptr){
        cout<<"No se pudo abrir el archivo para escribir."<<endl;
        return -1;
    }

    // detalleVenta.cargar(idV); corregir !!!

    int escribio = fwrite(&detalleVenta, tamanioRegistro, 1, pcventa);

    if(escribio != 1){
        cout<<"Error al escribir el registro."<<endl;
    }

    fclose(pcventa);

    return escribio; // si escribio = 1, es un OK.
}

void ArchivoDetalleVenta::listarRegistros(int idV){
    DetalleVenta detalleVenta;
    Venta venta;
    FILE *pcventa = fopen(nombre, "rb");

    if(pcventa==nullptr){
        return;
    }

    while(fread(&detalleVenta,tamanioRegistro,1,pcventa)==1){
        if(detalleVenta.getIdVenta()==idV){
            detalleVenta.mostrar();
        }
    }
    fclose(pcventa);
}

int ArchivoDetalleVenta::BuscarPorId(int idDetalleVenta) {
    DetalleVenta detalleVenta;
    FILE *pcventa = fopen(nombre, "rb");

    if (pcventa == nullptr) {
        return -1;
    }

    // Contar cuántos registros hay
    int cantidad = 0;
    while (fread(&detalleVenta, tamanioRegistro, 1, pcventa) == 1) {
        cantidad++;
    }

    rewind(pcventa); // volver al inicio

    for (int i = 0; i < cantidad; i++) {
        fseek(pcventa, i * tamanioRegistro, 0);
        fread(&detalleVenta, tamanioRegistro, 1, pcventa);

        if (detalleVenta.getId() == idDetalleVenta) {
            detalleVenta.mostrar();
            fclose(pcventa);
            return 1;
        }
    }

    fclose(pcventa);
    return 0;
}

bool ArchivoDetalleVenta::Eliminar(int idC){
    DetalleVenta detalleVenta;
    FILE *pcventa = fopen(nombre, "rb");

    if (pcventa == nullptr) {
        return false;
    }

    // Contar cuántos registros hay
    int cantidad = 0;
    while (fread(&detalleVenta, tamanioRegistro, 1, pcventa) == 1) {
        cantidad++;
    }

    rewind(pcventa); // volver al inicio

    for (int i = 0; i < cantidad; i++) {
        fseek(pcventa, i * tamanioRegistro, 0);
        fread(&detalleVenta, tamanioRegistro, 1, pcventa);

        if (detalleVenta.getEstado() == true) {
            detalleVenta.setEstado();
        }
    }

    fclose(pcventa);
    return true;
}

bool ArchivoDetalleVenta::Modificar(int idDV){
    DetalleVenta detalleVenta;
    FILE *pcventa = fopen(nombre, "r+b"); // Modo lectura + escritura binaria

    if (pcventa == nullptr) {
        return false;
    }

    // Contar registros
    int cantidad = 0;
    while (fread(&detalleVenta, tamanioRegistro, 1, pcventa) == 1) {
        cantidad++;
    }

    rewind(pcventa); // Volver al inicio

    for (int i = 0; i < cantidad; i++) {
        fseek(pcventa, i * tamanioRegistro, 0); // Ir al registro i
        fread(&detalleVenta, tamanioRegistro, 1, pcventa); // Leer el registro

        if (detalleVenta.getId() == idDV) {
            detalleVenta.cargar(detalleVenta.getIdVenta(),detalleVenta.getId());
            fseek(pcventa, i * tamanioRegistro, 0); // Volver a la posición original del registro
            fwrite(&detalleVenta, tamanioRegistro, 1, pcventa); // Sobrescribir
            return true;
        }
    }

    fclose(pcventa);
    return false;
}

bool ArchivoDetalleVenta::guardarDetalle(const DetalleVenta& d) {
    FILE* p = fopen(nombre, "ab");
    if (p == nullptr) return false;
    bool ok = fwrite(&d, sizeof(DetalleVenta), 1, p) == 1;
    fclose(p);
    return ok;
}

void ArchivoDetalleVenta::EquiposMasVendidos() {
    const int MAX = 50;
    int idEquipos[MAX];
    int cantidades[MAX];
    int totalEquipos = 0;

    DetalleVenta detalle;
    FILE* p = fopen(nombre, "rb");
    if (p == nullptr) {
        cout << "No se pudo abrir el archivo de detalles." << endl;
        return;
    }

    while (fread(&detalle, sizeof(DetalleVenta), 1, p) == 1) {
        //if (!detalle.getEstado()) continue;  // descomentar para excluir inactivos

        int id = detalle.getIdProducto();
        int cant = detalle.getCantidad();

        if (id <= 0) continue;

        bool encontrado = false;
        for (int i = 0; i < totalEquipos; i++) {
            if (idEquipos[i] == id) {
                cantidades[i] += cant;
                encontrado = true;
                break;
            }
        }

        if (!encontrado && totalEquipos < MAX) {
            idEquipos[totalEquipos] = id;
            cantidades[totalEquipos] = cant;
            totalEquipos++;
        }
    }

    fclose(p);

    if (totalEquipos == 0) {
        cout << "No hay ventas registradas." << endl;
        return;
    }

    // ordenar por cantidad vendida de forma descendente
    for (int i = 0; i < totalEquipos - 1; i++) {
        for (int j = i + 1; j < totalEquipos; j++) {
            if (cantidades[j] > cantidades[i]) {
                // intercambiar cantidades
                int tempCant = cantidades[i];
                cantidades[i] = cantidades[j];
                cantidades[j] = tempCant;

                // intercambiar IDs en paralelo
                int tempId = idEquipos[i];
                idEquipos[i] = idEquipos[j];
                idEquipos[j] = tempId;
            }
        }
    }

    // --- Mostrar resultados ---
    cout << "Equipos mas vendidos:"<<endl<<endl;
    for (int i = 0; i < totalEquipos; i++) {
        cout << "ID equipo: " << idEquipos[i]
             << " - Cantidad vendida: " << cantidades[i] << endl;
    }
}

