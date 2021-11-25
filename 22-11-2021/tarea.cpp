#include <iostream>

using namespace std;

struct nodo {
    int dato;
    nodo *subLeft;
    nodo *subRight;
};

class BinarySearchTree{
    private:
        nodo *pBinarySearchTree;
    public:
    BinarySearchTree();
    ~BinarySearchTree();
    void insertar(void);
    void insertarBST(nodo **, int);
    void showPreorder(nodo *);
    void showInorder(void);
    void showIn(nodo *);
    void showPost(nodo *);
    void showPostOrder(void);
    void showPreorder(void);
    void showPre(nodo *);
    void deleteNode(int);
    void deleteNode(nodo **, int);
};

BinarySearchTree::BinarySearchTree(void)
{
    pBinarySearchTree = NULL;
}

BinarySearchTree::~BinarySearchTree()
{
    cout << "Program Execution" << endl;
}

void BinarySearchTree::insertar(void)
{
    int dato;
    char resp;

    do{
        cout << endl;
        cout << "Escriba y para continuar" << endl;
        cout << "Desea digitar un dato? ";
        cin >> resp;
        if(resp == 'y'){
            cout << "Elemento que desea ingresar: ";
            cin >> dato;
            insertarBST(&pBinarySearchTree, dato);
        }

    }while(resp == 'y');
}

void BinarySearchTree::insertarBST(nodo **p, int dato)
{
    if(!(*p)){
        *p = new nodo;
        (*p)->dato = dato;
        (*p)->subLeft = NULL;
        (*p)->subRight = NULL; 
    }
    else{
        if(dato < (*p)->dato)
            insertarBST(&((*p)->subLeft), dato);
        else
            if(dato > (*p)->dato)
                insertarBST(&((*p)->subRight), dato);
            else
                cout << "El dato ya esta ingresado" << endl << endl;
    }
}

void BinarySearchTree::showInorder(void)
{
    showIn(pBinarySearchTree);
}

void BinarySearchTree::showIn(nodo *p)
{
    if(p){
        showIn(p->subLeft);
        cout << p->dato << " ";
        showIn(p->subRight);
    }
    cout << endl;
}

void BinarySearchTree::showPreorder(void)
{
    showPre(pBinarySearchTree);
}

void BinarySearchTree::showPre(nodo *p)
{
    if(p){
        cout << p->dato << " ";
        showPre(p->subLeft);
        showPre(p->subRight);
    }
    cout << endl;
}

void BinarySearchTree::showPostOrder(void)
{
    showPost(pBinarySearchTree);
}

void BinarySearchTree::showPost(nodo *p)
{
    if(p)
    {
        showPost(p->subLeft);
        showPost(p->subRight);
        cout << p->dato << " ";
    }
    cout << endl;
}

void BinarySearchTree::deleteNode(int e){
    if(pBinarySearchTree)
        deleteNode(&pBinarySearchTree, e);
    else
        cout << "Arbol vacio" << endl;
}

void BinarySearchTree::deleteNode(nodo **p, int dato){
    nodo *borrador;
    if(!*p)
        cout << "Dato no encontrado" << endl;
    else if(dato < (*p)->dato)
        deleteNode(&(*p)->subLeft, dato);
    else if(dato > (*p)->dato)
        deleteNode(&(*p)->subRight, dato);
    else{
        if((!(*p)->subLeft) && (!(*p)->subRight)){
            borrador = *p;
            *p = NULL;
        }
        else if((!(*p)->subLeft) && ((*p)->subRight)){
            borrador = *p;
            *p = (*p)->subRight;
        }
        else if((!(*p)->subRight) && ((*p)->subLeft)){
            borrador = *p;
            *p = (*p)->subLeft;
        }
        else if(((*p)->subRight) && ((*p)->subLeft)){
            borrador = (*p)->subLeft;
            if(!borrador->subRight){
                (*p)->dato = borrador->dato;
                (*p)->subLeft = borrador->subLeft;
            }
            else{
                nodo *p2;
                while(borrador->subRight){
                    p2 = borrador;
                    borrador = borrador->subRight;
                }
                (*p)->dato = borrador->dato;
                borrador->subRight = borrador->subLeft;
            }
        }
    delete borrador;
    }

}

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
            int e;
            cout << "Numero a eliminar: ";
            cin >> e;
            objBinarySearchTree.deleteNode(e);
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