#include <iostream>
#include <cstring>

using namespace std;

struct nodo{
    string nombre, apellido, correo, carnet;
    int edad, celular;
    nodo *sig;
};

class registro{
    private:
        nodo *iNodo;
    public:
        registro();
        void menu(void);
        void ingresoDatos(void);
        void datos(string, string, string, int, int, string, int);
        void borrar();
        void borrar(string, string);
        void borrarTodo();
        void imprimirLista(void);
        void salir();
};

registro::registro(){
    iNodo = NULL;
}

void registro::menu(void){
    int opcion;
    cout << endl << "Registro" << endl;
    cout << "1. Ingresar datos" << endl;
    cout << "2. Mostrar los datos ingresados" << endl;
    cout << "3. Eliminar un registro" << endl;
    cout << "4. Salir" << endl;
    cout << "Su opcion: ";
    cin >> opcion;
    cin.clear();
    switch (opcion)
    {
    case 1:
        ingresoDatos();
        break;
    case 2:
        imprimirLista();
        break;
    case 3:
        borrar();
        break;
    case 4:
        salir();
        break;
    default:
        cout << "Opcion invalida";
        menu();
        break;
    }
}

void registro::ingresoDatos(void){
    int opcion;
    string nombre, apellido, correo, carnet;
    int edad, celular;
    cin.ignore();
    cout << endl << endl;
    do{
    cout << "Ingrese nombre: ";
    getline(cin, nombre); cin.clear();

    cout << endl << "Ingrese apellido: ";
    getline(cin, apellido);

    cout << endl << "Ingrese edad: ";
    cin >> edad; cin.ignore();

    cout << endl << "Ingrese correo electronico: ";
    getline(cin, correo);

    cout << endl << "Ingrese su numero de celular(sin guiones): ";
    cin >> celular; cin.ignore();

    cout << endl << "Ingrese numero de carnet: ";
    cin >> carnet;

    //cout << nombre << " " << apellido << " " << correo << " " << edad << " " << celular << " " << carnet;
    cout << "¿Desea ingresar mas datos? (1: si) (2: no)";
    cin >> opcion; cin.ignore();

    datos(nombre, apellido, correo, edad, celular, carnet, opcion);
    cin.clear();
    }
    while(opcion == 1);
}

void registro::datos(string nombre, string apellido, string correo, int edad, int celular, string carnet, int opcion){
    nodo *salto, *nuevosDato = new nodo;
    nuevosDato->nombre = nombre;
    nuevosDato->apellido = apellido;
    nuevosDato->carnet = carnet;
    nuevosDato->correo = correo;
    nuevosDato->edad = edad;
    nuevosDato->celular = celular;
    
    if(!iNodo){
        iNodo = nuevosDato;
        nuevosDato->sig = NULL;
    }
    else{
        salto = iNodo;
        while(salto->sig){
            salto = salto->sig;
        }
        salto->sig = nuevosDato;
        nuevosDato->sig = NULL;
    }
    if(opcion != 1)
        menu();
    return;
}

/* ------------------------------------------------------------ */

void registro::borrar(void){
    cin.clear();
    string nombre, apellido;

    cout << "Ingrese el nombre de la persona a borrar: ";
    cin.ignore(); getline(cin, nombre); 
    cout << "Ingrese el apellido de la persona a borrar: ";
    cin.ignore(); getline(cin, apellido);
    borrar(nombre, apellido);
}


void registro::borrar(string nombre, string apellido){
    nodo *borrar, *salto;
    if(!iNodo)
        cout << "No hay elementos que borrar" << endl;
    else{
        while(iNodo != NULL && iNodo->nombre == nombre && iNodo->apellido == apellido){
            iNodo = iNodo->sig;
        }
        borrar = iNodo;
        iNodo = iNodo->sig;
        delete borrar;
    }   
    menu();
}

/*                  COMENTARIO                  
Eliminar dentro de una lista simmple en C++ nos permite pues borrar un nodo dentro de la misma.
Es un poco complicado al principio pero es algo intuitivo su función. Por lo que he vito del ejemplo que nos han dado, para eliminar tenemos que:
Hacer que el nodo apunte al nodo que queremos borrar, asignar el nodo que sigue al que va despues del que queremos eliminar y por último liberar la memoria asignada al nodo que queriamos eliminar.

*/

/* ------------------------------------------------------------ */

void registro::imprimirLista(void){
    nodo *salto = iNodo;
    if(!salto)
        cout << "No hay nada que imprimir, el registro esta vacio";
    else{
        do{
            cout << endl << "Nombre: " << salto->nombre;
            cout << ", Apellido: " << salto->apellido;
            cout << ", Edad: " << salto->edad;
            cout << ", Carnet: " << salto->carnet;
            cout << ", Correo: " << salto->correo;
            cout << ", Numero de celular: " << salto->celular;
            salto = salto->sig;
        }
        while(salto != NULL);
    }
    menu(); 
}

void registro::salir(void){
    return;
}