/*                                          TAREA

- Con el uso de una lista circular:

1. Hacer una administración de una veterinaria, en donde se pida :
    -el id, 
    -nombre del dueño,
    -raza, 
    -peso, 
    -edad de la mascota

Que pueda agregar, mostrar por id, y borrar.

 */

#include "tareaLabo05.hpp"

using namespace std; 

int menu(){

    int opcion;

    cout << endl;
    cout << "\tRegistro de Veterinaria" << endl;
    cout << "1) Iniciar sesion" << endl;
    cout << "2) Mostrar pacientes registrados" << endl;
    cout << "3) Eliminar pacientes" << endl;
    cout << "4) Salir" << endl;
    cout << "Su Opcion: ";
    cin >> opcion; 
    cin.ignore();
    return opcion;
}


int main(void){
    ListaCircSimple objListaCircSimple;
    
    bool continuar = true;
    Informacion p;
    Informacion pref;
    do{
        switch(menu()){
            case 1: //Agregar un paciente
                p = solicitarInformacion();
                objListaCircSimple.insInicio(p);
                cout << endl << "El paciente ha sido registrado exitosamente" << endl;
                break;
            case 2: //Mostrar paciente de inicio a fin
                objListaCircSimple.mostrarListaCircIter(); 
                break;
            case 3: //Eliminar un paciente
                    int p;
                    cout << "Id de paciente: ";
                    cin >> p; cin.ignore();
                    objListaCircSimple.eliminarListaCircRec(p); 
                break;
            case 4: //Salir
                continuar = false;
                cout << endl << "Ha cerrado sesion exitosamente" << endl;
                break;
            default: //El paciente se equivoco
                cout << endl << "Opcion invalida" << endl;
                break;
        }
    }while(continuar);
    
    return 0;
}
