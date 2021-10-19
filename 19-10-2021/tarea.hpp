/*                                          TAREA

1. En lugar de administrar números, deberá de generar un lista con:
    - ID
    - User name 
    - Perfil (administrador, cliente, o trabajador)

2. Debe ingresar los datos desde teclado (opcional)

 */

#include <iostream>
#include <string>

using namespace std;

struct Informacion{
    string userName, perfil;
    int id;
};
typedef struct Informacion T;
T solicitarInformacion(void){
    T p;
    cout << "Id de usuario: ";
    cin >> p.id; cin.ignore();
    cout << "User Name: ";
    getline(cin, p.userName); cin.ignore();
    cout << "Perfil (administrador, cliente, trabajador): ";
    getline(cin, p.perfil); cin.ignore();
    return p;
} 

void mostrarUsuario(Informacion p){
    cout << "User name: " << p.userName;
    cout << " (" << p.id << ")." << endl;
    cout << "Perfil: " << p.perfil;

}

//Uso de typedef para generalizar la lista doble con una plantilla

//const T noValido = {"",0};

struct Node{
    T data;
    Node *next;
    Node *previous;
};

class LinkedList{
     private:
/* Declarar los punteros que apuntan a los nodos centinela*/   // Revisar termino centinela //      
        Node *header;
    public:
        LinkedList();
        ~LinkedList();
        //void addFront(T);
        void addBack(T);
        //void printReverse(void);
        void printForward(void);
        void deleteItem(T);
/*         void deleteItem(int dt);*/        
       // bool empty(void);
        /* bool searchItem(T); */
   
};

LinkedList::LinkedList(void){
    header = NULL;
}

LinkedList::~LinkedList(){
   Node *p;
    while(header){
        p = header;
        header = header->next;
        delete p;
    }
}

void LinkedList::addBack(T data){
    Node *nd = new Node;
    nd->data = data;
     if(!header){
        header = nd;
        header->next = header->previous = NULL;
    }
    else{
        Node *saltarin = header;
        while(saltarin->next != NULL)
            saltarin = saltarin->next;
        saltarin->next = nd;
        nd->previous = saltarin;
        nd->next = NULL;
    }
}

void LinkedList::printForward(void){
    Node *saltarin = header;
    while(saltarin != NULL){
        mostrarUsuario(saltarin->data);//cout << saltarin->dato << endl;
        saltarin = saltarin->next;
    }
}

void LinkedList::deleteItem(T datoB){
    if(!header){ // Lista vacía.
        cout << "Actualmente ningun usuario ha iniciado sesion" << endl;
    }
    else{ // Si la lista no está vacía, entonces:
        Node *saltarin = header;
        while(saltarin && (saltarin->data).perfil.compare(datoB.perfil)!=0) // Saltar.
            saltarin = saltarin->next;
        if(!saltarin) // a) saltarín se salió (el dato no está en la lista).
            cout << "El usuario no ha sido ingresado" << endl;
        else{  /* Condicion para cuandosaltarin esta sibre el dato eliminar, si el nodo esta al inicio o al final, si esta entre nodos o es el unico nodo que tengamos */
            if(!saltarin->previous && saltarin->next){ 
                header = header->next;
                header->previous = NULL;
                delete saltarin;
            }
            else
                if(saltarin->previous && !saltarin->next){
                    saltarin->previous->next = NULL;
                    delete saltarin;
                }
                else
                    if(saltarin->previous && saltarin->next){
                        saltarin->previous->next = saltarin->next;
                        saltarin->next->previous = saltarin->previous;
                        delete saltarin;
                    }
                    else{
                        header = NULL;
                        delete saltarin;
                    }
            cout << "El usuario ha sido eliminado" << endl;
        }
    }
}
