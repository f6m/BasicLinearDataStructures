// Archivo encabezado para la definicion de una clase para un TDA Pila
// Realizacion dinamica mediante una clase y apuntadores

#include "exepcionesclase.h"
typedef int StackItemType;

class Stack{
public:
//Constructores y Destructor:
Stack();//Constructor por default
Stack(const Stack& aStack);//Constructor Copia
~Stack(); //Destructor

// Funciones/Operaciones de Pila
bool isEmpty() const;
void push(StackItemType newItem); // throw(StackException); 
void pop();// throw(StackException);
void pop(StackItemType& stackTop);// throw(StackException);
void getTop(StackItemType& stackTop) const;// throw(StackException);
void print();
int  mainPila();

private:
struct StackNode // Un nodo en la pila
{
StackItemType item; // Almacenamiento para una entero
StackNode *next; // apuntador hacia otro nodo
}; //Fin struct

StackNode *topPtr; //Apuntador al inicio de la Pila
}; //Fin de la Clase Stack

//Fin Del archivo de Encabezado


