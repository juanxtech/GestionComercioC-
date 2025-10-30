#include <iostream>
#include "archivo_cliente.h"
#include "cliente.h"
#include "archivo_venta.h"
#define _CRT_SECURE_NO_WARNINGS


using namespace std;

int ArchivoCliente::agregarRegistro(char* _nuevoCuit){
    Cliente cli;

    int escribio=0;

    FILE *pcliente = fopen(nombre, "ab");

    if(cli.Cargar(_nuevoCuit)){
        if(pcliente==nullptr){
            return -1;
        }
        escribio=fwrite(&cli, tamanioRegistro, 1, pcliente);
    }

    fclose(pcliente);

    return escribio;
}

bool ArchivoCliente::listarRegistro(){

    Cliente cliente;

    FILE *pcliente;
    pcliente=fopen(nombre,"rb");

    if(pcliente==nullptr){
        return false;
    }
    int pos=0;
    while(fread(&cliente,tamanioRegistro,1,pcliente)==1){
        if(cliente.getEstado()){
            cliente.Mostrar();
        }
        pos++;
    }

    fclose(pcliente);
    return true;

 }

 bool ArchivoCliente::buscarClientePorId(int id){
    Cliente cliente;

    FILE* pcliente=fopen(nombre,"rb");

    if(pcliente==nullptr){
        return false;
    }

    while(fread(&cliente,tamanioRegistro,1,pcliente)==1){
        if(cliente.getIdCliente()==id && cliente.getEstado()==true){
            fclose(pcliente);
            return true;

        }
    }

    fclose(pcliente);
    return false;
 }

 int ArchivoCliente::cantidadRegistros(){
    FILE *pfile;
    pfile=fopen(nombre, "rb");
    int cantidad;
    if(pfile==nullptr){
        return 0;
    }
    fseek(pfile,0,SEEK_END);
    cantidad=ftell(pfile) / sizeof(Cliente);
    fclose(pfile);
    return cantidad;
 }

 bool ArchivoCliente::buscarCliente(const char* _cuit){

    Cliente cliente;

    FILE *pcliente;

    pcliente=fopen(nombre,"rb");

    if(pcliente==nullptr){
        return false;
    }


    while(fread(&cliente,tamanioRegistro,1,pcliente)==1){
        if(strcmp(cliente.getCUIT(),_cuit)==0 && cliente.getEstado()==true){
            return true;
            fclose(pcliente);
        }
    }

    fclose(pcliente);
    return false;
}

bool ArchivoCliente::buscarClientePorCuit(const char* _cuit){
    Cliente cliente;

    FILE *pcliente;

    pcliente=fopen(nombre,"rb");

    if(pcliente==nullptr){
        return false;
    }

    while(fread(&cliente,tamanioRegistro,1,pcliente)==1){
        if(strcmp(cliente.getCUIT(),_cuit)==0){
            cliente.Mostrar();
            return true;
        }
    }

    fclose(pcliente);
    return false;

}

int ArchivoCliente::getNewId(){
    return cantidadRegistros()+1;
}

bool ArchivoCliente::bajaLogica(const char* _cuit){
    int pos=0;
    Cliente cliente;

    FILE* pcliente=fopen(nombre,"rb+");

    if (pcliente == nullptr) {
        cout << "No se pudo abrir el archivo." << endl;
        return false;
    }
    while(fread(&cliente,tamanioRegistro,1,pcliente)==1){
            if(strcmp(cliente.getCUIT(),_cuit)==0 && cliente.getEstado()==true){
                cliente.setEstado(false);

            //sobreescribir
            fseek(pcliente,pos *tamanioRegistro,0);
            fwrite(&cliente,tamanioRegistro,1,pcliente);
            fclose(pcliente);
            return true;
            }
        pos++;
    }

    fclose(pcliente);
    return false;

}

 bool ArchivoCliente::altaLogica(const char* _cuit){
    int pos=0;

    Cliente cliente;

    FILE* pcliente=fopen(nombre,"rb+");

     if (pcliente == nullptr) {
        cout << "No se pudo abrir el archivo." << endl;
        return false;
    }

    while(fread(&cliente,tamanioRegistro,1,pcliente)==1){
        if(strcmp(cliente.getCUIT(),_cuit)==0 && !cliente.getEstado()){
            cliente.setEstado(true);

            fseek(pcliente,pos*tamanioRegistro,SEEK_SET);
            fwrite(&cliente,tamanioRegistro,1,pcliente);
            fclose(pcliente);
            return true;
        }
        pos++;
    }


    fclose(pcliente);
    return false;

}

bool ArchivoCliente::listarInactivos(){
    Cliente cliente;

    FILE *pcliente;
    pcliente=fopen(nombre,"rb");

    if(pcliente==nullptr){
        return false;
    }

    while(fread(&cliente,tamanioRegistro,1,pcliente)==1){
        if(cliente.getEstado()==false){
            cliente.Mostrar();
        }
    }

    fclose(pcliente);
    return true;

}

bool ArchivoCliente::modificarCliente(const char* _cuit){
    int pos=0;
    Cliente cliente;

    FILE* pcliente=fopen(nombre,"rb+");

    if (pcliente == nullptr) {
        cout << "No se pudo abrir el archivo." << endl;
        return false;
    }

    while(fread(&cliente,tamanioRegistro,1,pcliente)==1){
        if(strcmp(cliente.getCUIT(),_cuit)==0 && cliente.getEstado()==true){
            cliente.CargarMod(_cuit,cliente.getIdCliente());

            fseek(pcliente,pos*tamanioRegistro,SEEK_SET);
            fwrite(&cliente,tamanioRegistro,1,pcliente);
            fclose(pcliente);
            return true;
        }
        pos++;
    }

    fclose(pcliente);
    return false;
}

void ArchivoCliente::ClienteQueMasRecaudo(){

    ArchivoVenta archivoVenta;
    ArchivoCliente archivoCliente;
    Cliente cliente;
    float importeMax=0;
    int idMax=archivoVenta.ClienteQueMasRecaudo(importeMax);

    FILE* pcliente= fopen(nombre,"rb");

    int pos=0;

    while(fread(&cliente,tamanioRegistro,1,pcliente)==1){
        if(cliente.getIdCliente()==idMax){
            cout<<"El nombre del cliente que mas recaudo es: ";
            cout<<cliente.getNombres()<<" "<<cliente.getApellidos()<<" con un total de: "<<importeMax<<"$"<<endl;
        }
        pos++;
    }

    fclose(pcliente);

}



