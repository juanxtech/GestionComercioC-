#include<iostream>
#include "menu_vendedores.h"
#include "archivo_vendedor.h"
using namespace std;

void menuVendedores(){
    ArchivoVendedor obj;
    int legajo;
    int valor;
    while(true){
        system("cls");
        cout << "***************************" << endl;
        cout << "*  Gestion de Vendedores  *" << endl;
        cout << "***************************" << endl<<endl;

        cout << "1. Alta Vendedor"<<endl;
        cout << "2. Baja Vendedor"<<endl;
        cout << "3. Modificar Vendedor"<<endl;
        cout << "4. Listar Vendedor"<<endl<<endl;
        cout << "0. Volver" << endl<<endl;
        cout << "**************************" << endl;
        cout << "SELECCIONAR OPCION " << endl;
        cin>>valor;
        system("cls");
        switch(valor){
            case 1:
                obj.AgregarRegistro();
                system("pause");
                break;
            case 2:
                cout << "Ingrese el legajo del vendedor a modificar: ";
                cin >> legajo;
                obj.EliminarVendedorLogica(legajo);
                system("pause");
                break;
            case 3:
                cout << "Ingrese el legajo del vendedor a modificar: ";
                cin >> legajo;
                if (obj.ModificarVendedor(legajo)){
                    cout << "Vendedor modificado correctamente." << endl;
                }
                else{
                    cout << "Error al modificar el modificar el vendedor, asegurese que el legajo ingresado es correcto." << endl;
                }
                system("pause");
                break;
            case 4:
                obj.ListarRegistros();
                system("pause");
                break;
            case 0:
                   return;
                   break;
            default: cout<<"Opcion no valida, porfavor ingrese un valor valido"<<endl;

        }
    }
}
