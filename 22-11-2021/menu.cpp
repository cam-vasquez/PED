#include "tareaOrden.hpp"

int main(){
    
    int opcion;
    bool continuar = true;

    BinarySearchTree objBinarySearchTree;

    while(continuar){

    cout << "\t\t\tBienvenido" << endl;
    cout << "1) Agregar dato" << endl;
    cout << "2) Imprimir en Pre-Orden" << endl;
    cout << "3) Imprimir dato en In-Orden" << endl;
    cout << "4) Imprimir dato en Post-Orden" << endl;
    cout << "5) Buscar" << endl;
    cout << "6) Eliminar" << endl;
    cout << "7) Salir" << endl;
    cout << "Su opcion: ";
    cin >> opcion;
    cout << endl;

    switch(opcion){
            case 1:
            cout << "Insertar datos en el arbol:" <<  endl;
            objBinarySearchTree.insertar();
            break;
        case 2:
            cout << "Mostrar Pre-orden: " << endl;
            objBinarySearchTree.showPreorder();
            cout << endl;
            break;
        case 3:
            cout << "Mostrar In-Orden: " << endl;
            objBinarySearchTree.showInorder();
            cout << endl;
            break;
        case 4:
            cout << "Mostrar Post-Orden: " << endl;
            objBinarySearchTree.showPostOrder();
            cout << endl;
            break;
        case 5:
            cout << endl << "Buscando..." << endl;
            break;
        case 6:
            cout << endl << "Eliminado " << endl;
            break;
        case 7:
            continuar = false;
            cout << "Saliendo" << endl;
            break;
        default:
            cout << "Opcion no disponible";
            break;
        }
    }

        return 0;

}
