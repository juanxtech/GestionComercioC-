#include <iostream>
#include <cstring>
#include "archivo_equipo.h"
#include "equipo.h"
#define _CRT_SECURE_NO_WARNINGS
using namespace std;


//funcion para vaciar archivo, y no tener q borrar registros
//de a uno a mano
void ArchivoEquipo::VaciarArchivo() {
    FILE* pequipo = fopen(nombre, "wb"); // abrir en modo escritura binaria (sobrescribe todo)
    if (pequipo == nullptr) {
       cout << "No se pudo abrir el archivo para vaciarlo." << endl;
        return;
    }
    fclose(pequipo);
    cout << "Archivo vaciado correctamente." << endl;
}


int ArchivoEquipo::AgregarRegistro() {
    //solo descomentar la funcion Vaciar para pruebas de borrado de registros
    //VaciarArchivo();
    Equipo equipo;

    int nuevoId = getNewId();
    equipo.setIdEquipo(nuevoId);

    FILE *pequipo = fopen(nombre, "ab");

    if (pequipo == nullptr) {
        cout << "No se pudo abrir el archivo para escribir." << endl;
        return -1;
    }

    if(!equipo.Cargar()){
        return -1;
    }

    int escribio = fwrite(&equipo, sizeof(Equipo), 1, pequipo);

    fclose(pequipo);

    if (escribio != 1) {
        cout << "Error al escribir el registro." << endl;
        return -1;
    }
    cout << "Registro agregado correctamente." << endl;
    return 1;
}
//autogenerar id al agregar registro
int ArchivoEquipo::getNewId() {
    Equipo equipo;
    FILE *pequipo = fopen(nombre, "rb");

    if (pequipo == nullptr) {
        return 1;
    }

    int lastId = 0;
    while (fread(&equipo, tamanioRegistro, 1, pequipo) == 1) {
        if (!equipo.getEliminado()) {
            lastId = equipo.getIdEquipo();
        }
    }

    fclose(pequipo);
    return lastId + 1;
}



bool ArchivoEquipo::ListarRegistros() {
    Equipo equipo;
    FILE *pequipo = fopen(nombre, "rb");

    if (pequipo == nullptr) {
        cout << "No se pudo abrir el archivo para leer." << endl;
        return false;
    }

    while (fread(&equipo, sizeof(Equipo), 1, pequipo) == 1) {
        if (!equipo.getEliminado() && equipo.getIdEquipo() != 0) {
            equipo.Mostrar();
        }
    }

    fclose(pequipo);
    return true;
}

int ArchivoEquipo::BuscarEquipo(int id) {
    Equipo equipo;
    FILE *pequipo = fopen(nombre, "rb");

    if (pequipo == nullptr) {
        cout << "No se pudo abrir el archivo para leer." << endl;
        return -1;
    }

    int posicion = 0;

    while (fread(&equipo, tamanioRegistro, 1, pequipo) == 1) {
        if (equipo.getIdEquipo() == id) {
            fclose(pequipo);
            return posicion;
        }
        posicion++;
    }

    fclose(pequipo);
    return -1;
}

void ArchivoEquipo::ListarPorTipo(const char* _tipo) {
    Equipo equipo;
    FILE *pequipo = fopen(nombre, "rb");

    if (pequipo == nullptr) {
        cout << "No se pudo abrir el archivo (para leer)" << endl;
        return;
    }

    bool encontrado = false;

    while (fread(&equipo, tamanioRegistro, 1, pequipo) == 1) {
        //  Comparar tipo, evitar eliminados y registros inválidos (ID 0)
        if (strcmp(equipo.getTipo(), _tipo) == 0 &&
            !equipo.getEliminado() &&
            equipo.getIdEquipo() != 0) {

            equipo.Mostrar();
            encontrado = true;
        }
    }

    fclose(pequipo);

    if (!encontrado) {
        cout << "No se encontraron equipos del tipo \"" << _tipo << "\"." << endl;
    }
}


void ArchivoEquipo::ListarDisponibles() {
    Equipo equipo;
    FILE *pequipo = fopen(nombre, "rb");

    if (pequipo == nullptr) {
        cout << "No se pudo abrir el archivo(para leer)." << endl;
        return;
    }

    bool encontrado = false;

    while (fread(&equipo, tamanioRegistro, 1, pequipo) == 1) {
        if (!equipo.getEliminado() && equipo.getStock() > 0) {
            equipo.Mostrar();
            encontrado = true;
        }
    }

    fclose(pequipo);

    if (!encontrado) {
        cout << "No hay equipos disponibles en stock." << endl;
    }
}
// funcion para buscar por posucion por id
// para luego poder modificar correctamente un registro

int ArchivoEquipo::BuscarPosicionPorId(int idBuscado) {
    Equipo equipo;
    FILE *pequipo = fopen(nombre, "rb");
    if (pequipo == nullptr) return -1;

    int pos = 0;

    while (fread(&equipo, tamanioRegistro, 1, pequipo) == 1) {
        if (!equipo.getEliminado() && equipo.getIdEquipo() == idBuscado) {
            fclose(pequipo);
            return pos;
        }
        pos++;
    }

    fclose(pequipo);
    return -1;
}


bool ArchivoEquipo::ModificarEquipo(int id) {
    if (id == 0) {
        cout << "Modificacion cancelada." << endl;
        return false;
    }

    int posicion = BuscarPosicionPorId(id);
    if (posicion < 0) {
        cout << "No se encontro un equipo con ese ID." << endl;
        return false;
    }

    Equipo equipo;
    FILE *pequipo = fopen(nombre, "rb+"); // leer/escribir
    if (pequipo == nullptr) {
        cout << "No se pudo abrir el archivo para modificar." << endl;
        return false;
    }

    // Leer registro original
    fseek(pequipo, posicion * tamanioRegistro, SEEK_SET);
    fread(&equipo, tamanioRegistro, 1, pequipo);

    // pedir nuevos datos (conservar ID)
    equipo.Modificar();

    // Reposicionar para sobrescribir
    fseek(pequipo, posicion * tamanioRegistro, SEEK_SET);
    int escribio = fwrite(&equipo, tamanioRegistro, 1, pequipo);

    fclose(pequipo);

    if (escribio == 1) {
        cout << "Equipo modificado correctamente." << endl;
        return true;
    } else {
        cout << "Error al escribir en el archivo." << endl;
        return false;
    }
}


bool ArchivoEquipo::EliminarEquipo(int id) {
    Equipo equipo;
    FILE* pequipo = fopen(nombre, "rb+");

    if (pequipo == nullptr) {
        cout << "No se pudo abrir el archivo." << endl;
        return false;
    }

    int pos = 0;
    while (fread(&equipo, tamanioRegistro, 1, pequipo) == 1) {
        if (equipo.getIdEquipo() == id && !equipo.getEliminado()) {
            equipo.setEliminado(true);
            cout << "Equipo eliminado correctamente." <<endl;

            // Volver a la posicion para sobrescribir
            fseek(pequipo, pos * tamanioRegistro, SEEK_SET);
            fwrite(&equipo, tamanioRegistro, 1, pequipo);
            fclose(pequipo);
            return true;
        }
        pos++;
    }

    fclose(pequipo);
    return false;
}


float ArchivoEquipo::getPrecioId(int id){
    Equipo equipo;
    FILE *pequipo = fopen(nombre, "rb");

    if (pequipo == nullptr) {
        cout << "No se pudo abrir el archivo para leer." << endl;
        return -1;
    }


    while (fread(&equipo, tamanioRegistro, 1, pequipo) == 1) {
        if (equipo.getIdEquipo() == id) {
            fclose(pequipo);
            return equipo.getPrecio();
        }
    }
    fclose(pequipo);
    return -1;
}

int ArchivoEquipo::getStockId(int id){
    Equipo equipo;
    FILE *pequipo = fopen(nombre, "rb");

    if (pequipo == nullptr) {
        cout << "No se pudo abrir el archivo para leer." << endl;
        return false;
    }

    while (fread(&equipo, sizeof(Equipo), 1, pequipo) == 1) {
        if (!equipo.getEliminado() && equipo.getIdEquipo()==id) {
            return equipo.getStock();
        }
    }

    fclose(pequipo);
    return -1;
}

bool ArchivoEquipo::modificarStock(int id, int cant){
    Equipo equipo;
    FILE *pequipo = fopen(nombre, "rb+");

    if (pequipo == nullptr) {
        cout << "No se pudo abrir el archivo para leer." << endl;
        return false;
    }
    int pos = 0;
    while (fread(&equipo, sizeof(Equipo), 1, pequipo) == 1) {
        if (!equipo.getEliminado() && equipo.getIdEquipo()==id) {
            equipo.setStock(cant);
            fseek(pequipo, pos * tamanioRegistro, SEEK_SET);
            fwrite(&equipo, tamanioRegistro, 1, pequipo);
            fclose(pequipo);
            return true;
        }
        pos++;
    }

    fclose(pequipo);
    return false;
}
