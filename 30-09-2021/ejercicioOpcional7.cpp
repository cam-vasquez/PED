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
    char bebida[10];
	
};

typedef struct nodo *PLista;

class ListaSimple{

	private:
    	nodo *pInicio;
	
	public:
    	ListaSimple();
    	void menu(void);
    	void ingresarDatos(PLista &lista);
    	void mostrarLista(PLista f);

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
	cout << "\tBebida: " << endl;
    cout << "- Coca Cola" << endl;
}

void ListaSimple::ingresarDatos(PLista &lista)
{
   
   PLista c, f = new(struct nodo);
  
	cout<<"\tOrdenes de Pupuseria";
    cout << endl << endl;
	cout<<"\tPedidos";
    cout << endl << endl;
	cin.ignore();
    cout << "Nombre: "; cin.getline(f->nombre, 20);
    cout << "Num. pupusas: "; 
    cin >> f->cantidad;
    cout << "Arroz o Maiz: "; 
    cin.ignore();
    cin.getline(f->tipo, 20);
    cout <<"Ingrediente: "; 
    cin.getline(f->ingredientes, 20);
	cout << "Bebida (Coca Cola/ Ninguna): "; 
    cin.getline(f->bebida, 10);
    cout << endl;

	f->sig = NULL;

	if(lista==NULL){
    	lista = f;
	} 
    else{
    	c = lista;

    	while(c->sig!= NULL){
            	c = c->sig;
    	}
    	c->sig = f;
	}
}

void ListaSimple::mostrarLista(PLista f){

	int i = 1;

	while( f!= NULL){

        cout << endl << endl;
    	cout << "\t\tPupuseria" << endl << endl;
        cout << "----------- Orden Num. " << i << "-----------";
    	cout << endl;
    	cout << "\tNombre: "<< f->nombre << endl;
    	cout << "\tNum. Pupusas "<< f->cantidad << endl;
    	cout << "\tArroz o Maiz: "<< f->tipo << endl;
    	cout << "\tingredientes: " << f->ingredientes << endl;
		cout << "\tBebida: " << f->bebida << endl;
    	f=f->sig;
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

