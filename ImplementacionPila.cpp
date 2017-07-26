#include "ClasePila.h"
#include <cstddef> //Para el NULL
#include <cassert> //Para assert
#include <iostream> //Para cout in print
using namespace::std;

//------Constructor por default
Stack::Stack() : topPtr(NULL) // estamos usando una forma particular de inicializar el apuntador del nodo inicial con NULL
{
}//Fin Constructor por default

//------Constructor Copia
Stack::Stack(const Stack& aStack) //Recibe una copia del objeto - instancia de la clase
{
if(aStack.topPtr == NULL) // Si el objeto tiene un aputador tope vacio dejarlo
	topPtr = NULL; // Creamos el apuntador miembro a NULL
else
{
//Copia el primer Nodo
topPtr = new StackNode; // Asignamos memoria para una estructura StackNode
assert(topPtr != NULL); // Nos aseguramos que topPtr != NULL sea verdadero, caso contrario termina el programa
topPtr->item = aStack.topPtr->item; // Copiamos el dato en aStack.topPtr a topPtr->item

//Copia el resto de la lista
StackNode *newPtr = topPtr; //Nuevo apuntador de estructura (nodo) y lo apuntamos a topPtr, miembro de la clase

// Iniciamos con origPtr apuntando al siguiente nodo de aStack.topPtr; mientras sea distinto de NULL continuamos
// avanzamos entre los nodos con origPtr = origPtr->next
for(StackNode *origPtr = aStack.topPtr->next; origPtr != NULL; origPtr = origPtr->next)
{
newPtr->next = new StackNode; // Creamos memoria y la apuntamos a newPtr->next
assert(newPtr->next != NULL); // Nos aseguramos que newPtr->next != NULL 
newPtr = newPtr->next; // Nos desplazamos al siguiente nodo en newPtr->next
newPtr->item = origPtr->item; //copiamos el dato en origPtr->item en newPtr->item
}//Fin for
newPtr->next = NULL; // Al ultimo nodo agregamos NULL

} //Fin else
} //Fin Constructor Copia

//------Destructor
Stack::~Stack(){
//Extraer mientras hay algo que extraer
while(!isEmpty())
pop();
// Asercion : topPtr == NULL
} // Fin del Destructor

// Funcion para descidir si la Pila esta vacia
bool Stack::isEmpty() const
{
return topPtr == NULL;
}

//Funcion para introducir un nuevo elemento a la pila
void Stack::push(StackItemType newItem)
{
//Creamos un nuevo nodo
StackNode *newPtr = new StackNode;

if(newPtr == NULL) //Revisar si hay espacio
throw StackException("StackExeption: La operacion meter no puede alojar memoria");
else
{
// Hay memoria disponible
newPtr->item = newItem;
//insertamos el nuevo nodo
newPtr->next = topPtr;
topPtr = newPtr;
} //Fin else
} //Fin Push

// Funcion para extraer el tope de la pila
void Stack::pop()
{
if(isEmpty())
 throw StackException("Pila Vacia en el tope");
else
{
//La pila no esta vacia, borramos el tope
StackNode *temp = topPtr; // Creamos un apuntador de tipo estructura Nodo temp inicializandolo a topPtr
topPtr = topPtr->next; // lo que tiene el apuntador topPtr->next lo apuntamos a topPtr, es decir avanzamos
// Hacemos que el tope apunte a NULL, el nodo borrado
temp->next = NULL;
delete temp; // Borramos la memoria
} // Fin Else
} // Fin pop()

// Funcion para extraer el tope de la pila y recuperarlo en stackTop
void Stack::pop(StackItemType& stackTop)
{
if(isEmpty())
 throw StackException("Pila Vacia en el tope");
else
{
//La pila no esta vacia, recupera y borramos el tope
stackTop = topPtr->item; // Recuperamos el dato en stackTop
StackNode *temp = topPtr; // Creamos un nuevo nodo apuntando a topPtr
topPtr = topPtr->next; // Avanzamos el tope
// Regresamos el nodo borrado
temp->next = NULL;
delete temp; // Borramos la memoria
} // Fin Else
} // Fin pop(StackItemType&)

//-------Funcion para obterner el tope sin Borrar en stackTop.
void Stack::getTop(StackItemType& stackTop) const
{
if(isEmpty())
 throw StackException("Pila Vacia para extraer el tope");
else
// La pila no esta vacia para extraer el tope, recuperamos el tope
stackTop = topPtr->item;
 // Fin else
} // Fin getTop

// Funcion para imprimir la Pila actual
void Stack::print()
{
StackNode *nodotmp;
nodotmp = topPtr;
do
{
  cout<<nodotmp->item<<endl;
  nodotmp = nodotmp->next;
}while( nodotmp->next != NULL );
cout<<nodotmp->item<<endl;
} // Fin de print

// Funcion para el menu principal

int Stack::mainPila()
{
int r; //Respuesta
StackItemType dato; // Declaramos el Dato a almacenar en los nodos
//Stack aStack; // Declaracion del objeto pila

do{
cout<<"Selecciona una opcion"<<endl;
cout<<"[1] Agregar un valor a la Pila"<<endl;
cout<<"[2] Sacar el valor tope de la Pila"<<endl;
cout<<"[3] Imprimir la Pila"<<endl;
cout<<"[0] Salir"<<endl;
cin>>r;

switch(r)
{
case 1: cout<<"Introduce el dato a colocar en la Pila"<<endl;
	cin>>dato;
	push(dato); //usamos el apuntador this
	break;
case 2: if( !isEmpty() ){
	pop();
	cout<<"Tope de la Pila Borrado"<<endl;
	break;
	}else
	cout<<"Pila Vacia"<<endl;
	break;
	
case 3: cout<<"Pila:"<<endl; //Vamos a desplazarnos dentro de la pila
	print();
	break;

}
}while(r!=0);

return 0;
}

//-------Fin del archivo de implementacion


