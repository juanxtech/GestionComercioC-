#include <iostream>
#include "menu_clientes.h"
#include "menu_vendedores.h"
#include "menu_equipos.h"
#include "menu_ventas.h"
using namespace std;

int main()
{

    int opc;
    while(true){
        system("cls");
        cout << "**************************" << endl;
        cout << "* BIENVENIDO AL SISTEMA  *" << endl;
        cout << "**************************" << endl<<endl;
        cout << "1. Menu Clientes"<<endl;
        cout << "2. Menu Vendedores"<<endl;
        cout << "3. Menu Equipos"<<endl;
        cout << "4. Menu Ventas"<<endl;
        cout << "0. FIN DEL PROGRAMA" << endl<<endl;
        cout << "*************************" << endl;
        cout << "SELECCIONAR OPCION " << endl;
        cin>>opc;
        system("cls");
        switch(opc){
            case 1: menuClientes();
                    break;

            case 2: menuVendedores();
                    break;

            case 3: menuEquipos();
                    break;
            case 4:
                    menuVentas();
                    break;
            case 0: cout<<"Gracias por utilizar el software."<<endl;
                   system("pause");
                   return 0;
                   break;
            default: cout<<"Opcion no valida, porfavor ingrese un valor valido"<<endl;
        }
    }
    cout<<endl;
    return 0;
}
