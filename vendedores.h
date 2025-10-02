#pragma once
#include "persona.h"
#include "fecha.h"

class Vendedor : public Persona {
private:
    int legajo;
    float sueldo;
    Fecha ingreso;
public:
    Vendedor();
    float getSueldo();
    Fecha getIngreso();
    int getLegajo();

    void setSueldo(float s);
    void setIngreso(Fecha f);
    void setLegajo(int leg);

    bool cargar();
    void mostrar();
};
