#ifndef LISTA_H_
#define LISTA_H_

#include <fstream>
using namespace std;

class Lista{
public:
    Lista();
    bool Insertar(int);
    bool Desenlistar();
    bool ListaVacia();
    void Mostrar();
    void Buscar(int);
    void GenerarArchivo();
    ~Lista();
private:
    struct Nodo;
    typedef Nodo *Puntero;
    struct Nodo{
        int valor;
        Puntero sig;
    };
    Puntero ini,fin;
};

Lista::Lista(){
    ini=NULL;
    fin=NULL;
}

bool Lista::Insertar(int dato){
    bool error=false;
    Puntero p_aux;
    p_aux = new Nodo;
    if (p_aux==NULL){
        error=true;
        cout << "\nNo se ha podido reservar memoria."<<endl;
    }
    else{
        p_aux->valor=dato;
        p_aux->sig=NULL;
        if (ListaVacia())
            ini = p_aux;
        else
            fin->sig = p_aux;
        fin = p_aux;
    }
    return error;
}

bool Lista::Desenlistar(){
    Puntero aux;
    bool estado;
    if(ini==NULL){
        estado=false;
    }
    else{
        aux=ini;
        ini=ini->sig;
        delete aux;
        estado=true;
    }
    return estado;
}

bool Lista::ListaVacia(){
    bool error;
    if(ini==NULL)
        error=true;
    else
        error=false;
    return error;
}

void Lista::Mostrar(){
    Puntero actual;
    actual = ini;
    cout<<"\nMostrar listado de valores:"<<endl;
    while (actual != NULL)
    {
        cout<<actual->valor<<"\t";
        actual = actual->sig;
    }
}

Lista::~Lista(){
    while(Desenlistar());
}

void Lista::Buscar(int dato) {
    Puntero actual;
    actual = ini;
    bool bandera_encontrado=false;
    while (actual != NULL) {
        if(actual->valor==dato)
            bandera_encontrado=true;
        actual = actual->sig;
    }
    if(bandera_encontrado==true)
        cout<<"\nEl valor "<<dato<<" ha sido encontrado en lista. "<<endl;
    else
        cout<<"\nEl valor "<<dato<<" no ha sido encontrado en lista. "<<endl;
}

void Lista::GenerarArchivo() {
    Puntero actual;
    actual = ini;
    ofstream archivo;
    archivo.open("lista.txt");

    if (archivo.bad())
        cout << "no es posible abrir o crear el archivo" << endl;
    else {
        archivo << "-----VALORES DE LA LISTA-----" << endl;
        while (actual != NULL) {
            archivo << actual->valor<<"-";
            actual = actual->sig;
        }
    }
    archivo.close();
}

#endif /* LISTA_H_ */
