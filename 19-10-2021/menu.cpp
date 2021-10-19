#include "tarea.hpp"

using namespace std; 

int menu(){

    int opcion;

    cout << endl;
    cout << "\tBienvenido" << endl;
    cout << "1) Iniciar sesion" << endl;
    cout << "2) Mostrar usuarios ingresados" << endl;
    cout << "3) Eliminar usuarios" << endl;
    cout << "4) Salir" << endl;
    cout << "Su Opcion: ";
    cin >> opcion; 
    cin.ignore();
    return opcion;
}

int main(void){
    LinkedList sesion;
    
    bool continuar = true;
    Informacion p;
    Informacion pref;
    do{
        switch(menu()){
            case 1: //Agregar un usuario
                p = solicitarInformacion();
                sesion.addBack(p);  
                cout << endl << "Ha ingresado sesion exitosamente" << endl;
                break;
            case 2: //Mostrar usuario de inicio a fin
                sesion.printForward(); // cambiar
                break;
            case 3: //Eliminar un usuario
                    p = solicitarInformacion(); 
                    sesion.deleteItem(p); 
                break;
            case 4: //Salir
                continuar = false;
                break;
            default: //El usuario se equivoco
                cout << endl << "Opcion invalida" << endl;
                break;
        }
    }while(continuar);
    
    return 0;
}
