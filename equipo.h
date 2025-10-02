#pragma once

class Equipo {
   private:
       int _idEquipo;
       char _descripcion[100];
       char _marca[30];
       char _tipo[30];
       int _stock;
       float _precio;
       bool _eliminado;

   public:
       Equipo();  // Constructor por defecto
        //GETTERES Y SETTERS
        void setIdEquipo(int _idEquipo);
        void setDescripcion(const char* _descripcion);
        void setMarca(const char* _marca);
        void setTipo(const char* _tipo);
        void setStock(int _stock);
        void setPrecio(float _precio);
        void setEliminado(bool _eliminado);

        int getIdEquipo();
        char* getDescripcion();
        char* getMarca();
        char* getTipo();
        int getStock();
        float getPrecio();
        bool getEliminado();

        //metodos

        bool Cargar();
        void Mostrar();
        void Modificar();

};
