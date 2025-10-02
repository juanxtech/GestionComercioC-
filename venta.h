#pragma once
#include "Fecha.h"

class Venta {

  private:
      int _idV;
      int _idCliente;
      Fecha fecha;
      int _idVendedor;
      double _importeTotal;
      bool _estado;


  public:
    Venta();
    //getters
    int getIdV();
    Fecha getFecha();
    int getIdCliente();
    int getIdVendedor();
    double getImporteTotal();
    bool getEstado();

    //Setters
    void setidV(int idV);
    void setFecha(Fecha f);
    void setIdCliente(int id);
    void setIdVendedor(int id);
    void setImporteTotal(double importe);
    void setEstado(bool estado);

    bool cargar();
    void mostrar();

};
