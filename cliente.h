#pragma once
#include "Persona.h"

class Cliente : public Persona{
private:
    int idCliente;
    char cuit[20];
    int tipoCliente;


public:
    //GETTERS Y SETTERS
    void setIdCliente(int id);
    void setCUIT(const char* valor);
    void setTipoCliente(int tipo);

    int getIdCliente();
    const char* getCUIT();
    int getTipoCliente();

    bool Cargar(char* _nuevoCuit = (char*) "NADA");
    void CargarMod(const char* _cuit, int id);
    void Mostrar();
};
