#pragma once

class Fecha {
private:
    int dia;
    int mes;
    int anio;
public:

    Fecha();
    Fecha(int dia, int mes, int anio);

    int GetDia();
    int GetMes();
    int GetAnio();

    void SetDia(int dia);
    void SetMes(int mes);
    void SetAnio(int anio);

    void cargar();
    void mostrar();



};
