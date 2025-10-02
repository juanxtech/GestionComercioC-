#include <iostream>
#include "menu_clientes.h"
#include "cliente.h"
#include "archivo_cliente.h"
#include <cstring>


using namespace std;

ArchivoCliente registro;
char cuit[20];
Cliente cliente;
int pos2=0;

void AgregarCliente(){
    char* _nuevoCuitt = nullptr;
    if(registro.agregarRegistro(_nuevoCuitt)==1){
            cout<<"Registro cargado."<<endl;
    }else{
        cout<<"Error al cargar el cliente."<<endl;
    }
}

void ListarClientes(){
    if(registro.listarRegistro()==false){
        cout<<"Error al listar."<<endl;
    }
}

void BuscarPorCuit(){
    cout<<"Ingrese CUIT: ";
    cin>>cuit;
    if(registro.buscarClientePorCuit(cuit)==false){
        cout<<"Cliente no encontrado."<<endl;
    }

}

void BajaLogica(){
    cout<<"Ingrese el cuit del cliente a eliminar."<<endl;
    cin>>cuit;
    if(registro.bajaLogica(cuit)==true){
        cout<<"Cliente eliminado correctamente."<<endl;
    }else{
        cout<<"El cliente no exite o ya fue eliminado con anterioridad."<<endl;
    }

}

void AltaLogica(){
    cout<<"Ingrese el cuit del cliente a dar de alta."<<endl;
    cin>>cuit;
    if(registro.altaLogica(cuit)==true){
        cout<<"Cliente dado de alta correctamente."<<endl;
    }else{
        cout<<"El cliente no existe o ya fue dado de alta con anterioridad."<<endl;
    }
}

void ListarInactivos(){
    if(registro.listarInactivos()==false){
        cout<<"Error al listar clientes."<<endl;
    }

}

void ModificarCliente(){
    cout<<"Ingrese el cuit del cliente a modificar."<<endl;
    cin>>cuit;
    if(registro.modificarCliente(cuit)==true){
        cout<<"modificacion realizada con exito"<<endl;
    }else{
        cout<<"error al modificar"<<endl;
    }

}


void menuClientes(){
    int valor;
    while(true){
        system("cls");

        cout << "*************************" << endl;
        cout << "*  Gestion de Clientes  *" << endl;
        cout << "*************************" << endl<<endl;

        cout << "1. Ingresar Cliente"<<endl;
        cout << "2. Baja Cliente"<<endl;
        cout << "3. Alta cliente"<<endl;
        cout << "4. Modificar Cliente"<<endl;
        cout << "5. Listar Clientes"<<endl;
        cout << "6. Listar Clientes inactivos"<<endl;
        cout << "7. Buscar cliente"<<endl;
        cout << "8. Cliente que mas recaudo"<<endl<<endl;
        cout << "0. Volver" << endl<<endl;
        cout << "**************************" << endl;
        cout << "SELECCIONAR OPCION " << endl;
        cin>>valor;
        system("cls");
        switch(valor){
            case 1:
                    AgregarCliente();
                    break;
            case 2:
                    BajaLogica();
                    break;
            case 3:
                    AltaLogica();
                    break;
            case 4:
                    ModificarCliente();
                    break;
            case 5:
                    ListarClientes();
                    break;
            case 6:
                    ListarInactivos();
                    break;
            case 7:
                    BuscarPorCuit();
                    break;
            case 8:
                    registro.ClienteQueMasRecaudo();
                    break;
            case 0:
                   return;
                   break;
            default: cout<<"Opcion no valida, porfavor ingrese un valor valido"<<endl;

        }
        system("pause");
    }
}
