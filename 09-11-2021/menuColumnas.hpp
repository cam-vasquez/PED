#include <iostream>
#include <cstring>

using namespace std;

struct Cnstrctr{
    string data;
    int col, row;
};

template <class T>
struct Node{
    T data; 
    int cols, rows;
    Node<T> *nxtCol, *nxtRow;

    Node(){
        nxtCol = nxtRow = NULL;
    }
    Node(T data){
        this.data = data;
        nxtCol = nxtRow = NULL;
    }
};


template <class T>
class Sprdsht{
    private:
        int Tcol, Trow;
        Node<T> *SSP;
    public:
        Sprdsht(Cnstrctr);
        //~Sprdsht();
       void AddingCell(Cnstrctr);
       void DeleteNode(Cnstrctr);
       void AdditionCol(Cnstrctr);
       void ShowSS(void);
};

template <class T>
Sprdsht<T>::Sprdsht(Cnstrctr e){
    Node<T> *newNode, *p;
    SSP = new Node<T>;
    int i;
    this->Tcol = e.col;
    this->Trow = e.row;
    SSP->cols = SSP->rows = 0;
    SSP->data = e.data;

    p = SSP;
    for(i = 1; i <= Tcol; i++){
        newNode = new Node<T>;
        p->nxtCol = newNode;
        newNode->cols = i;
        newNode->rows = 0;
        newNode->data = e.data;
        newNode->nxtRow = newNode;
        p = p->nxtCol;
    }
    newNode->nxtCol = SSP;
    p = SSP;
    for(i = 1; i <= Trow; i++){
        newNode = new Node <T>;
        p->nxtRow = newNode;
        newNode->data = e.data; 
        newNode->cols = 0;
        newNode->rows = i;
        newNode->nxtCol = newNode;
        p = p->nxtRow;
    }
    newNode->nxtRow = SSP;
}


template <class T>

void Sprdsht<T>::AddingCell(Cnstrctr e){
    if((e.row > 0 && e.row <= Tcol) && (e.col > 0 && e.col <= Tcol)){
        Node<T> *newNode = new Node<T>();
        cin.ignore();
        cout << "Digite el dato a almacenar: ";
        getline(cin, newNode->data);
        newNode->cols = e.col;
        newNode->rows = e.row;

        Node <T> *auxR, *auxC;
        int i;
        auxR = auxC = SSP;

        //Encontrando el espacio en filas
        for(i = 1; i <= e.row; i ++)
            auxR = auxR->nxtRow;
        while((auxR->nxtCol->cols < e.col) && (auxR->nxtCol->cols != 0))
            auxR = auxR->nxtCol;

        //Encontrando el espacio en columnas
        for(i = 1; i <= e.col; i++)
            auxC = auxC->nxtCol;
        while((auxC->nxtRow->rows < e.row) &&(auxC->nxtRow->rows != 0))
            auxC = auxC->nxtRow;

        newNode->nxtCol = auxR->nxtCol;
        auxR->nxtCol = newNode;

        newNode->nxtRow = auxC->nxtRow;
        auxC->nxtRow = newNode;

        cout << endl << "Celda creada exitosamente!" << endl;
    }
    else if(e.col != 0 && e.row != 0){
        cout << "No se ha podido encontrar la ubicacion (" << e.col << ", " << e.row << ") en la hoja " << Tcol << " X " << Trow << endl;
    }

}

template <class T> 
void Sprdsht<T>::ShowSS(){
    cout << "Las celdas se mostraran como columna, fila, dato" << endl;
    cout << "Imprimiendo... " << endl;
    Node<T> *aux = SSP;
    int i;
    do{
        do{
            cout << "(" << aux->cols << ", " << aux->rows << ") => " << aux->data << "\t";
            aux = aux->nxtCol;
        }while(aux->cols != 0);
        cout << endl;
        aux = aux->nxtRow;
    }while(aux->rows != 0);
}
template <class T>
void Sprdsht<T>::AdditionCol(Cnstrctr e){
    int suma = 0, i;
    Node<T> *aux = SSP;
    if(e.col <= Tcol && e.col != 0){
        for(i = 1; i <= e.col; i++)
            aux = aux->nxtCol;
        aux = aux->nxtRow;
        do{
            suma += atoi(aux->data.c_str());
            aux = aux->nxtRow;
        }while(aux->rows != 0);
        cout << "El total de la columna " << e.col << " es: " << suma << endl;
    }
    else{
        cout << "Columna no encontrada"<< endl;
    }
}

template <class T>
void Sprdsht<T>::DeleteNode(Cnstrctr e){
    Node <T> *auxC, *auxR, *deleten = NULL;
    auxC = auxR = SSP;
    int i = 1;
    //movimiento en filas
    for(i; i<= e.row; i++)
        auxR = auxR->nxtRow;
    while((auxR->nxtCol->cols <= e.col) && (auxR->nxtCol->cols != 0))
        auxR = auxR->nxtCol;

    //movimiento en columnas 
    for(i; i<=e.col; i++)
        auxC = auxC->nxtCol;
    while((auxC->nxtRow->rows <=e.row) && (auxC->nxtRow->rows !=0))
        auxC = auxC->nxtRow;
    
    deleten = auxR->nxtCol;
    if(deleten->cols == e.col && deleten->rows == e.row){
        auxR->nxtCol = auxR->nxtCol->nxtCol;
        auxC->nxtRow = auxC->nxtRow->nxtRow;
        delete deleten;

        cout << "Celda (" << e.col << ", " << e.row << ") borrada"<< endl;
    }
    else{
        cout << "Celda (" << e.col << ", " << e.row << ") no encontrada en la hoja "<< Tcol << " X " << Trow << endl;
    }
}
Cnstrctr creatingsprdsht(int e){
    Cnstrctr cnstrData;
    if(e == 0){
        cout << endl << "Ingrese la cantidad de Columnas a crear: ";
        cin >> cnstrData.col;
        cout << endl << "Ingrese la cantidad de Filas a crear: ";
        cin >> cnstrData.row;
        cnstrData.data = "~";
    }
    else if(e == 1){
        cout << endl << "Para salir inserte coordenadas (0,0)";
        cout << endl << "Ingrese la columna a insertar el dato: ";
        cin >> cnstrData.col;
        cout << endl << "Ingrese la fila a insertar el dato: ";
        cin >> cnstrData.row;
        return cnstrData;
    }
    else if(e == 2){
        cout << endl << "Ingrese el numero de columna de celda a eliminar: ";
        cin >> cnstrData.col;
        cout << endl << "Ingrese el numero de fila de celda a eliminar: ";
        cin >> cnstrData.row;
    }
    else{
        cout << endl << "Ingrese el numero de columna a sumar: ";
        cin >> cnstrData.col;
    }

    return cnstrData;
}
