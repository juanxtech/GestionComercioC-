#include "Archivo_Vendedor.h"
#include <fstream>
#include <iostream>

using namespace std;

bool ArchivoVendedor::AgregarRegistro() {
    Vendedor obj;
    if(!obj.cargar()){
        cout<<"Vendedor no cargado."<<endl;
        return false;
    }

    FILE* p = fopen("vendedores.dat", "ab");
    if (p == nullptr) {
        cout << "No se pudo abrir el archivo para agregar." << endl;
        return false;
    }

    fwrite(&obj, sizeof(Vendedor), 1, p);
    fclose(p);
    cout << "Vendedor agregado correctamente." << endl;
    return true;
}

void ArchivoVendedor::ListarRegistros() {
    Vendedor obj;

    FILE* p = fopen("vendedores.dat", "rb");
    if (p == nullptr) {
        cout << "No se pudo abrir el archivo para lectura." << endl;
        return;
    }

    while (fread(&obj, sizeof(Vendedor), 1, p) == 1) {
        obj.mostrar();
        cout << "-----------------------------" << endl;
    }

    fclose(p);
}

bool ArchivoVendedor::BuscarVendedorLegajo(int legajo) {
    Vendedor obj;

    FILE* p = fopen("vendedores.dat", "rb");
    if (p == nullptr) return false;

    while (fread(&obj, sizeof(Vendedor), 1, p) == 1) {
        if (obj.getLegajo() == legajo && obj.getEstado()==true) {
            fclose(p);
            return true;
        }
    }

    fclose(p);
    return false;
}

bool ArchivoVendedor::BuscarVendedorMayorRecaudacion(int id) {
    // Este método necesitaría relación con ventas o recaudación (no se implementa aún).
    // De momento se deja como placeholder
    cout << "Funcionalidad no implementada: BuscarVendedorMayorRecaudacion" << endl;
    return false;
}

bool ArchivoVendedor::ModificarVendedor(int legajoBuscado) {
    Vendedor obj;
    FILE* p = fopen("vendedores.dat", "rb+");
    if (p == nullptr) return false;

    while (fread(&obj, sizeof(Vendedor), 1, p) == 1) {
        if (obj.getLegajo() == legajoBuscado) {
            fseek(p, sizeof(Vendedor), SEEK_CUR);
            cout << "Ingrese nuevos datos del vendedor:" << endl;
            obj.cargar();
            fwrite(&obj, sizeof(Vendedor), 1, p);
            fclose(p);
            return true;
        }
    }

    fclose(p);
    return false;
}

bool ArchivoVendedor::EliminarVendedor(int legajoEliminar) {
    Vendedor obj;
    FILE* pLectura = fopen("vendedores.dat", "rb");
    FILE* pEscritura = fopen("temp.dat", "wb");

    if (pLectura == nullptr || pEscritura == nullptr) {
        cout << "Error al abrir archivos." << endl;
        return false;
    }

    bool eliminado = false;

    while (fread(&obj, sizeof(Vendedor), 1, pLectura) == 1) {
        if (obj.getLegajo() != legajoEliminar) {
            fwrite(&obj, sizeof(Vendedor), 1, pEscritura);
        } else {
            eliminado = true;
        }
    }

    fclose(pLectura);
    fclose(pEscritura);

    remove("vendedores.dat");
    rename("temp.dat", "vendedores.dat");

    return eliminado;
}

bool ArchivoVendedor::EliminarVendedorLogica(int legajoEliminar) {
    Vendedor obj;
    FILE* pArchivo = fopen("vendedores.dat", "rb+");

    if (pArchivo == nullptr) {
        cout << "Error al abrir el archivo." << endl;
        return false;
    }

    int pos = 0;
    bool eliminado = false;

    while (fread(&obj, sizeof(Vendedor), 1, pArchivo) == 1) {
        if (obj.getLegajo() == legajoEliminar) {
            obj.setEstado(false);
            fseek(pArchivo, pos * sizeof(Vendedor), SEEK_SET);
            fwrite(&obj, sizeof(Vendedor), 1, pArchivo);
            eliminado = true;
            break;
        }
        pos++;
    }

    fclose(pArchivo);

    if (eliminado) {
        cout << "Vendedor eliminado de manera logica." << endl;
    } else {
        cout << "No se encontro el vendedor o ya estaba inactivo." << endl;
    }

    return eliminado;
}


int ArchivoVendedor::cantidadRegistros(){
    FILE *pvendedor;
    pvendedor=fopen("vendedores.dat", "rb");
    int cantidad;
    if(pvendedor==nullptr){
        return 0;
    }
    fseek(pvendedor,0,SEEK_END);
    cantidad=ftell(pvendedor) / sizeof(Vendedor);
    fclose(pvendedor);
    return cantidad;
 }

int ArchivoVendedor::getNewId(){
    return cantidadRegistros()+1;
}
