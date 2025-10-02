#include<iostream>
#include <string>
#include "archivo_equipo.h"
#include "archivo_detalle_venta.h"
#include "equipo.h"

using namespace std;

int leerEntero(string mensaje);

void menuEquipos(){



    ArchivoEquipo archEquipo;
    ArchivoDetalleVenta archDetalle;
    archDetalle.EquiposMasVendidos();
    int valor;

    char tipoBuscado[30];
    while(true){
        system("cls");
        cout << "***********************" << endl;
        cout << "*  Gestion de Equipos *" << endl;
        cout << "***********************" << endl<<endl;

        cout << "1. Alta Equipo"<<endl;
        cout << "2. Baja Equipo"<<endl;
        cout << "3. Modificar Equipo"<<endl;
        cout << "4. Listar Equipos"<<endl;
        cout << "5. Consultar por tipo de equipo." <<endl;
        cout << "6. Consultar equipos disponibles."<<endl;
        cout << "7. Informe equipos mas vendidos."<<endl <<endl;
        cout << "0. Volver" << endl<<endl;
        cout << "**************************" << endl;
        cout << "SELECCIONAR OPCION " << endl;
        cin>>valor;
        system("cls");
        switch(valor){
        case 1:
            if(archEquipo.AgregarRegistro()==-1){
                cout<<"Error cargando el registro."<<endl;
            }
            system("pause");
            break;
        case 2:
            int id;
            cout << "Ingrese el ID del equipo a eliminar: ";
            cin >> id;
            archEquipo.EliminarEquipo(id);
            system("pause");
            break;

        case 3:
            cin.ignore();
            id = leerEntero("Ingrese el ID del equipo a modificar (0 para cancelar): ");
            archEquipo.ModificarEquipo(id);
            system("pause");
            break;

        case 4:
            archEquipo.ListarRegistros();
            system("pause");
            break;
        case 5:
            cin.ignore();
            cout << "Ingrese el tipo de equipo a buscar: ";
            cin.getline(tipoBuscado, 30);
            archEquipo.ListarPorTipo(tipoBuscado);
            system("pause");
            break;
        case 6:
            cin.ignore();
            cout << "Equipos con stock disponible" <<endl;
            archEquipo.ListarDisponibles();
            system("pause");
            break;
        case 7:
            cin.ignore();
            archDetalle.EquiposMasVendidos();
            system("pause");
            break;

        case 0:
            return;
            break;
        default:
            cout << "Opcion no valida." << endl;
        }
    }
 system("pause");
}
