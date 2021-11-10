#include "sumaColumnas.hpp"

int main(void){
    cout << "\t\t\tBienvenido" << endl;
    bool cntn = true;
    Cnstrctr p;
    Sprdsht<string>newSprdsht(creatingsprdsht(0));
    while(cntn){
        switch(menu()){
            case 1:
                do{
                    p = creatingsprdsht(1);
                    newSprdsht.AddingCell(p);
                }while(p.col != 0 && p.row != 0);
                break;
            case 2:
                newSprdsht.ShowSS();
                break;
            case 3:
                newSprdsht.DeleteNode(creatingsprdsht(2));
                break;
            case 4:
                
                break;
            case 5:
                cout << "Sumando... " << endl;
                newSprdsht.AdditionCol(creatingsprdsht(3));
                break;
            case 6:
                cout << "Saliendo..." << endl;
                cntn = false;
                break;
            default:
                cout << "Opcion invalida" << endl;
                break;
        }

    }
    return 0;
}

int menu(){
    int op;
    cout << endl << "1) Insertar dato en celda" << endl;
    cout << "2) Mostrar celdas" << endl;
    cout << "3) Borrar celda" << endl;
    cout << "4) Mover celda" << endl;
    cout << "5) Sumar columna" << endl;
    cout << "6) Salir" << endl;
    cout << "Opcion: ";
    cin >> op;
    cout << endl;
    return op;
}