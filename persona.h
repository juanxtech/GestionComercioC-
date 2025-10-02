#pragma once
#include "Fecha.h"

class Persona {
private:

    char _nombres[50];
    char _apellidos[50];
    Fecha _fechaNac;
    char _telefono[20];
    char _email[50];
    char _direccion[100];
    bool _estado;

public:
    // Constructores
    Persona();
    Persona(const char* nombres, const char* apellidos, Fecha fechaNac,
            const char* telefono, const char* email, const char* direccion, bool estado);

    // Setters
    void setNombres(const char* nombres);
    void setApellidos(const char* apellidos);
    void SetFecha(Fecha fechaNac);
    void setTelefono(const char* telefono);
    void setEmail(const char* email);
    void setDireccion(const char* direccion);
    void setEstado(bool estado);

    // Getters
    const char* getNombres();
    const char* getApellidos();
    Fecha GetFechaNac();
    const char* getTelefono();
    const char* getEmail();
    const char* getDireccion();
    bool getEstado();

    // Métodos
    bool Cargar();
    void Mostrar();
};
