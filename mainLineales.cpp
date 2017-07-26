// Menu principal para usar la implementacion de las estructuas lineales: Lista, Pila y  Cola
// compilacion:
// $g++ mainLineales.cpp ImplementacionPila.cpp -g
// ejecucion:
// ./a.out

#include <iostream>
#include "ClasePila.h"
#include "ImplementacionInterfazCola.h"

using namespace::std;

int main()
{
int r; //Respuesta
int dato; // Declaramos el Dato a almacenar en los nodos
Cola<int> aCola; // Declaracion del objeto Cola, instancia
Stack aPila; // Declaracion del objeto Pila, instancia

do{
cout<<"[Estructuras Lineales Basicas] Selecciona una opcion"<<endl;
cout<<"[1] Colas..."<<endl;
cout<<"[2] Pilas..."<<endl;
cout<<"[3] Listas.."<<endl;
cout<<"[0] Salir"<<endl;
cin>>r;

switch(r)
{
case 1: aCola.mainCola(); //Llamamos al menu de las Colas
	break;
case 2: aPila.mainPila();
	break;
case 3: cout<<"En construccion"<<endl;
	break;
 } // Fin Switch
}while(r!=0);

return 0;
}
