#pragma once
#include "cliente.h"
#include <cstring>



class ArchivoCliente {
private:
    char nombre[30];
    int tamanioRegistro;

public:
    ArchivoCliente(const char *n="Cliente.dat"){
        strcpy(nombre,n);
        tamanioRegistro=sizeof(Cliente);
    }


    int agregarRegistro(char* _nuevoCuit);
    bool listarRegistro(); //lista activos
    bool listarInactivos();
    int cantidadRegistros();
    int getNewId();
    bool buscarClientePorCuit(const char* _cuit);
    bool  buscarCliente(const char* _cuit);
    bool bajaLogica(const char* _cuit);
    bool altaLogica(const char* _cuit);
    bool ListarClienteInactivo();
    bool modificarCliente(const char* _cuit);
    bool buscarClientePorId(int id);
    void ClienteQueMasRecaudo();
};
