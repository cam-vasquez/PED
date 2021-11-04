#include <iostream>

using namespace std;


struct Informacion{
    string nombre, raza;
    int id;
    float peso, edad;
};

struct nodo{
    Informacion dato;
    nodo *sig;
};

typedef struct Informacion T;

T solicitarInformacion(void){
    T p;
    cout << endl;
    cout << "\tRegistro de paciente" << endl;
    cout << "Id de paciente: ";
    cin >> p.id; cin.ignore();
    cout << "Nombre del duenio: ";
    getline(cin, p.nombre);
    cout << "Raza: ";
    getline(cin, p.raza);
    cout << "Peso: ";
    cin >> p.peso; cin.ignore();
    cout << "Edad: ";
    cin >> p.edad; cin.ignore();
    return p;
} 

void mostrarPaciente(Informacion p){
    cout << endl;
    cout << "\tPaciente ingresado" << endl;
    cout << "Nombre del duenio: " << p.nombre << endl;
    cout << "ID: " << p.id << endl;
    cout << "Raza: " << p.raza << endl;
    cout << "Peso: " << p.peso << endl;
    cout << "Edad: " << p.edad << endl;
    cout << endl;
}

class ListaCircSimple{

    private:
        nodo *pInicio;
    
    public:
        ListaCircSimple();
        ~ListaCircSimple();
        void insInicio(T);
        void mostrarListaCircIter(void);
        void eliminarListaCircRec(int);
};

ListaCircSimple::ListaCircSimple(void)
{
    pInicio = NULL;
}

ListaCircSimple::~ListaCircSimple()
{
    nodo *del;
    if(pInicio->sig){
        
        while(pInicio->sig!=pInicio){
            del = pInicio;
            pInicio = pInicio->sig;
       }
    }
    else{
        pInicio = NULL;
    }
    delete del;
}




void ListaCircSimple::insInicio(T dato)
{
    nodo *nuevo;

    nuevo = new nodo;
    nuevo->dato = dato;
    if(!pInicio){
        pInicio = nuevo;
        pInicio->sig = pInicio;
    }
    else{
        nuevo->sig = pInicio;
        nodo *saltarin = pInicio;
        while(saltarin->sig != pInicio){
            saltarin = saltarin->sig;
        }
        saltarin->sig = nuevo;
        pInicio = nuevo;
    }
}



void ListaCircSimple::mostrarListaCircIter(void)
{
    nodo *saltarin;

    cout << endl;
    if(pInicio){
        saltarin = pInicio;
        do{
            cout << saltarin->dato.nombre << ", " << saltarin->dato.edad << endl;
            cout << ", " << saltarin->dato.id << endl;
            cout << ", " << saltarin->dato.peso << endl;
            cout << ", " << saltarin->dato.raza << endl;
            saltarin = saltarin->sig;
        }while(saltarin != pInicio);
    }
}

void ListaCircSimple::eliminarListaCircRec(int id)
{

    nodo *saltarin = pInicio;
    if(saltarin->sig == pInicio && saltarin->dato.id == id){
        pInicio = NULL;
        delete saltarin;
    }
    else if(saltarin == pInicio && saltarin->dato.id == id){
        nodo *saltarin2 = pInicio;
        while(saltarin2->sig!= pInicio)
            saltarin2 = saltarin2->sig;
        pInicio = saltarin->sig;
        saltarin2->sig = pInicio;
        delete saltarin;        
    }
    else{
        nodo *saltarin2;
        int cont = 0;
        while(saltarin->sig != pInicio){
            if(saltarin->sig->dato.id == id){
                cont++;
                saltarin2 = saltarin->sig;
                saltarin->sig = saltarin->sig->sig;
                delete saltarin2;
            }
            else if(saltarin->sig == pInicio && cont == 0){
                cout << endl << "Elemento no registrado";
            }
            saltarin = saltarin->sig;
        }
    }
    return;  
}