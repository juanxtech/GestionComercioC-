# include<iostream>
using namespace std;


void menuReportesFiltradoInformes(){

    int valor;
    while(true){
        system("cls");
        cout << "********************************************" << endl;
        cout << "*  Gestion de Reportes/Filtrados/Informes  *" << endl;
        cout << "********************************************" << endl<<endl;
        cout << "1. Reportes"<<endl;
        cout << "2. Informes"<<endl;
        cout << "3. Filtrados"<<endl<<endl;
        cout << "0. Volver" << endl<<endl;
        cout << "**************************" << endl;
        cout << "SELECCIONAR OPCION " << endl;
        cin>>valor;
        system("cls");
        switch(valor){
            case 1:
                    break;
            case 2:
                    break;
            case 3:
                    break;

            case 0:
                   return;
                   break;
            default: cout<<"Opcion no valida, porfavor ingrese un valor valido"<<endl;

        }
    }
}
