#include <iostream>
#include "menu_ventas.h"
#include "archivo_venta.h"
#include <cstring>

using namespace std;

ArchivoVenta registros;

void menuVentas(){

    int valor;
    int idventa;
    while(true){
        system("cls");

        cout << "*************************" << endl;
        cout << "*  Gestion de Ventas    *" << endl;
        cout << "*************************" << endl<<endl;
        cout << "1. Agregar Venta"<<endl;
        cout << "2. Bajar Venta"<<endl;
        cout << "3. Modificar Venta"<<endl;
        cout << "4. Listar Ventas Disponibles"<<endl;
        cout << "5. Filtrar Venta"<<endl;
        cout << "6. Listar todas las ventas"<<endl<<endl;
        cout << "0. Volver" << endl<<endl;
        cout << "**************************" << endl;
        cout << "SELECCIONAR OPCION " << endl;
        cin>>valor;
        system("cls");
        switch(valor){
            case 1:
                    if(registros.agregarRegistro()==1){
                        cout<<"Venta registrada correctamente."<<endl;
                    }else{
                        cout<<"Error al registrar la venta."<<endl;
                    }
                    system("pause");
                    break;
            case 2:
                    cout<<"Ingrese el ID de la venta a eliminar:"<<endl;
                    cin>>idventa;
                    if(registros.EliminarVenta(idventa)){
                       cout<<"Venta eliminada."<<endl;
                    }else{
                        cout<<"No se pudo eliminar."<<endl;
                    }
                    system("pause");
                    break;
            case 3:
                    cout<<"Ingrese el ID de la venta a modificar:"<<endl;
                    cin>>idventa;
                    if(registros.ModificarVenta(idventa)){
                        cout<<"Modificacion realizada."<<endl;
                    }else{
                        cout<<"Error al modificar."<<endl;
                    }
                    system("pause");
                    break;
            case 4:
                    if(!registros.listarRegistros(false)){
                        cout<<"Error al listar."<<endl;
                    }
                    system("pause");
                    break;
            case 5:
                    cout<<"Ingrese el ID de la venta a buscar:"<<endl;
                    cin>>idventa;
                    registros.BuscarVenta(idventa);
                    system("pause");
                    break;
            case 6:
                    if(!registros.listarRegistros(true)){
                        cout<<"Error al listar."<<endl;
                    }
                    system("pause");
                    break;
            case 0:
                   return;
                   break;
            default: cout<<"Opcion no valida, porfavor ingrese un valor valido."<<endl;

        }
    }
}
