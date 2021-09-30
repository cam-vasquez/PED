/*EJERCICIO OPCIONAL EN LUGAR DEL EJERCICIO 7

Ingresar la cantidad de pupusas que los clientes desean, si quiere que sean de arroz o de maíz, si las quieren con Coca-Cola o no, y de que ingredientes las quieren, que permita agregarlas a las lista y mostrar las ordenes.*/

#include <iostream>

using namespace std;

struct nodo{
	int dato;
	nodo *sig;
	char nombre[20];
	int cantidad = 0;
	char tipo[20];
	char ingredientes[20];
    char bebida[20];
	
};

typedef struct nodo *PLista;

class ListaSimple{

	private:
    	nodo *pInicio;
	
	public:
    	ListaSimple();
    	void menu(void);
    	void ingresarDatos(PLista &lista);
    	void mostrarLista(PLista q);

};

ListaSimple::ListaSimple(void){
	pInicio = NULL;
}

void menu(void){

    cout << endl << endl;
	cout <<"\t\t\tMenu" << endl << endl;
	cout << "\tPupusas de maiz y arroz" << endl;
    cout << "- Frijol con queso" << endl;
    cout << "- Queso" << endl;
    cout << "- Revueltas" << endl;
	cout << "\tBebidas: " << endl;
    cout << "- Sodas" << endl;
    cout << "- Chocolate" << endl;
    cout << "- Cafe" << endl;
    cout << "- Jugos naturales" << endl;
}


void ListaSimple::ingresarDatos(PLista &lista)
{
   
   PLista t, q = new(struct nodo);
  
	cout<<"\tOrdenes de Pupuseria";
    cout << endl << endl;
	cout<<"\tPedidos";
    cout << endl << endl;
	cin.ignore();
    cout << "Nombre: "; cin.getline(q->nombre, 20);
    cout << "Num. pupusas: "; 
    cin >> q->cantidad;
    cout << "Arroz o Maiz: "; 
    cin.ignore();
    cin.getline(q->tipo, 20);
    cout << "Bebida: "; 
    cin.getline(q->bebida, 20);
    cout <<"Ingrediente: "; 
    cin.getline(q->ingredientes, 20);
    cout << endl;

	q->sig = NULL;

	if(lista==NULL){
    	lista = q;
	} 
    else{
    	t = lista;

    	while(t->sig!=NULL){
            	t = t->sig;
    	}
    	t->sig = q;
	}
}

void ListaSimple::mostrarLista(PLista q){

	int i = 1;

	while( q!= NULL){

        cout << endl << endl;
    	cout << "\tPupuseria" << endl;
        cout << "----------- Orden Num. " << i << "-----------";
    	cout << endl;
    	cout << "\tNombre;"<< q->nombre << endl;
    	cout << "\tNum. Pupusas "<< q->cantidad << endl;
    	cout << "\tArroz o Maiz: "<< q->tipo << endl;
    	cout << "\tBebida " << q->bebida << endl;
    	cout << "\tingredientes: " << q->ingredientes << endl;
    	q=q->sig;
    	i++;
	}
}

int main(void){

 PLista lista = NULL;
 ListaSimple objListaSimple;

   menu();

   int cantidad = 0;
   cout << endl;
   cout << "Ingrese las ordenes de pupusas: ";
   cin >> cantidad;
   for(int i = 1; i <= cantidad; i++){
       objListaSimple.ingresarDatos(lista);
    }
    objListaSimple.mostrarLista(lista);
    cout << endl << endl;

	return 0;
}

