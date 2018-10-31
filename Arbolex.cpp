#include <iostream>
#include <cstdlib>
using namespace std;

struct nodo{
     char nro;
     struct nodo *izq, *der;
};

typedef struct nodo *ABB;

ABB crearNodo(int x)
{
     ABB nuevoNodo = new(struct nodo);
     nuevoNodo->nro = x;
     nuevoNodo->izq = NULL;
     nuevoNodo->der = NULL;

     return nuevoNodo;
}
void insertar(ABB &arbol, int x)
{
     if(arbol==NULL)
     {
           arbol = crearNodo(x);
     }
     else if(x < arbol->nro)
          insertar(arbol->izq, x);
     else if(x > arbol->nro)
          insertar(arbol->der, x);
}

void verArbol(ABB arbol, int n)
{
     if(arbol==NULL)
          return;
     verArbol(arbol->der, n+1);

     for(int i=0; i<n; i++)
         cout<<"   ";

     cout<< arbol->nro <<endl;

     verArbol(arbol->izq, n+1);
}

int main()
{
    ABB arbol = NULL;   // creado Arbol

    int n;  // numero de nodos del arbol
    int x; // elemento a insertar en cada nodo

    cout << "\n\t\t  ..[ ARBOL BINARIO DE BUSQUEDA ]..  \n\n";
     cout<<"Mostrando expresion: "<<endl;
    cout<<"[x*y/A)]+(B*C)"<<endl;

    
    arbol=crearNodo('*');
    arbol->izq=crearNodo('x');
    arbol->der=crearNodo('y');
    arbol->der->izq=crearNodo('/');
    arbol->der->izq->izq=crearNodo('A');
    arbol->der->der=crearNodo('+');
    arbol->der->der->der=crearNodo('*');
    arbol->der->der->der->izq=crearNodo('B');
    arbol->der->der->der->der=crearNodo('C');
    cout << endl;
    
    cout << "\n Mostrando ABB \n\n";
    verArbol( arbol, 0);
   



    cout << endl << endl;

    system("pause");
    return 0;
}
