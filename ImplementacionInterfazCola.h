// Archivo encabezado para la definicion de una clase para un TDA Pila
// Realizacion dinamica mediante una clase y apuntadores

#include "exepcionesclaseCola.h" //Archivo para manejar las excepciones

// INTERFAZ
//observacion: No hacemos la division de archivos usual porque vamos a usar templates

typedef int StackItemType; //Si usamos templates tenemos que colocar implementacion en el mismo archivo

template <class T>
class Cola
{
public:
//Constructores y Destructor:
Cola();//Constructor por default
Cola(const Cola& aStack);//Constructor Copia
~Cola(); //Destructor

// Funciones (operaciones basicas) para la Cola
bool esvacia() const; //Funcion constante no cambia las variables
void encolar(T newItem); // throw(StackException); 
void desencolar();// throw(StackException);
void desencolar(T& stackTop);// throw(StackException);
void obtener(T& stackTop) const;// throw(StackException);
void imprime(); // Funcion para imprimir la Cola actual
int mainCola(); // Function to operations menu

private:
struct NodoCola // Un nodo en la Cola
{
T dat; // Almacenamiento para un tipo de dato
NodoCola *sig; // apuntador hacia otro nodo
}; //Fin de la estructura para el nodo

 NodoCola *iniptr, *finptr; //Apuntador al inicio de la Cola y al fin
}; //Fin de la Clase Cola

// // FIN-INTEFAZ

// INICIO-IMPLEMENTACION 
//observacion: No hacemos la division de archivos usual porque vamos a usar templates

using namespace::std; //para cin/cout

//------Constructor por default
template<typename T>
Cola<T>::Cola() : iniptr(NULL), finptr(NULL) // Con una forma particular de inicializar el apuntador del nodo inicial con NULL
{
}//Fin Constructor por default

// Constructor Copia
template<typename T>
Cola<T>::Cola(const Cola& aCola) //Recibe una copia del objeto - instancia de la clase
{
if(aCola.iniptr == NULL) // Si el objeto tiene un aputador tope vacio dejarlo
	iniptr = NULL; // Creamos el apuntador miembro a NULL
else
{
//Copia el primer Nodo
iniptr = new NodoCola; // Asignamos memoria para una estructura StackNode
assert(iniptr != NULL); // Nos aseguramos que topPtr != NULL sea verdadero, caso contrario termina el programa
iniptr->dat = aCola.iniptr->dat; // Copiamos el dato en aCola.iniptr a iniptr->dat

//Copiamos el resto de la Cola
NodoCola *nuevoptr = iniptr; //Nuevo apuntador de estructura (nodo) y lo apuntamos a iniptr, miembro de la clase

// Iniciamos con origPtr apuntando al siguiente nodo de aStack.topPtr; mientras sea distinto de NULL continuamos
// avanzamos entre los nodos iniciando con origptr = origPtr->next, origptr es el iterador
for(NodoCola *origptr = aCola.iniptr->sig; origptr != NULL; origptr = origptr->sig)
{
  // Bloque para el swap - intercambio
nuevoptr->sig = new NodoCola; // Creamos memoria y la apuntamos a newPtr->next
assert(nuevoptr->sig != NULL); // Nos aseguramos que newPtr->next != NULL 
nuevoptr = nuevoptr->sig; // Nos desplazamos al siguiente nodo en newPtr->next
nuevoptr->dat = origptr->dat; //copiamos el dato en origPtr->item en newPtr->item
}//Fin for
nuevoptr->sig = NULL; // Al ultimo nodo agregamos NULL

} //Fin else
} //Fin Constructor Copia

//------Destructor
template<typename T>
Cola<T>::~Cola(){
//Extraer mientras hay algo que extraer
while(!esvacia())
desencolar();
// Asercion : topPtr == NULL
} // Fin del Destructor

// Funcion para descidir si la Pila esta vacia
template<typename T>
bool Cola<T>::esvacia() const
{
return iniptr == NULL;
}

//Funcion para introducir un nuevo dato a la pila
template<typename T>
void Cola<T>::encolar(T nuevodato)
{
//Creamos un nuevo nodo y asignamos memoria para el
NodoCola *nuevoptr = new NodoCola;
nuevoptr->dat = nuevodato; //alojamos el dato

if(nuevoptr == NULL) //Revisar si hay espacio
throw ColaExcep("StackExeption: La operacion meter no puede alojar memoria");
else
{
// Hay memoria disponible!
  if(esvacia())
    {
  finptr = nuevoptr; // finptr apunta al primer elemento introducido a la Cola
  finptr->sig = NULL; // Su nodo sigiente es Null
   }
  else
    {
//insertamos el nuevo nodo
iniptr->sig = nuevoptr; // iniptr->sig apunta a todo el nodo nuevo, enlazado despues de iniptr
    }
iniptr = nuevoptr; // se inicializa nodo iniptr con nuevo, note que esta instruccion va despues sino se pierte la informacion de iniptra, nuveoptr toma la posicion (direccion) de iniptr.
} //Fin else
} //Fin encolar

// Funcion para extraer el tope de la Cola
template<typename T>
void Cola<T>::desencolar()
{
  // Revisar si hay memoria
if(esvacia())
 throw ColaExcep("Cola Vacia en el tope");
else
{
//La Cola no esta vacia, borramos el tope

NodoCola *tmp = finptr; // Creamos un apuntador de Nodo y lo inicializamos a iniptr

// while(tmp->sig != NULL)
finptr = finptr->sig; // lo que tiene el apuntador iniptr->sig lo apuntamos a iniptr, es decir avanzamos

 if(finptr == NULL) iniptr = NULL; //Si al avanzar encontramos que el sig es NULL entonces solo habia un elemento y hacemos iniptr = NULL

// Hacemos que el tope apunte a NULL, el nodo borrado
cout<<"Nodo eliminado de la cola:\t"<<tmp->dat<<endl;
delete tmp; // Borramos la memoria
} // Fin Else
} // Fin desencolar()


// Funcion para imprimir la Pila actual
template<typename T>
void Cola<T>::imprime()
{
NodoCola *nodotmp;
nodotmp = finptr;

 if(esvacia())
    throw ColaExcep("OOPS! Cola Vacia... Nada que imprimir");
 else
   {
do
{
  cout<<nodotmp->dat<<endl;
  if(nodotmp->sig != NULL)
  nodotmp = nodotmp->sig;
 } while( nodotmp->sig != NULL ); //este ciclo solo imprime hasta el penultimo nodo
//Imprimimos el dato dentro del ultimo nodo
 if(iniptr != NULL)
 cout<<iniptr->dat<<endl;
   } // Fin else
} // Fin de print

template<typename T>
int Cola<T>::mainCola()
{
int r; //Respuesta
T dato; // Declaramos el Dato a almacenar en los nodos
// Cola<int> aCola; // Declaracion del objeto Cola, instancia

do{
cout<<"[Colas enlazadas] Selecciona una opcion"<<endl;
cout<<"[1] Agregar un valor a la Cola"<<endl;
cout<<"[2] Sacar el valor tope de la Cola"<<endl;
cout<<"[3] Imprimir la Cola"<<endl;
cout<<"[0] Salir"<<endl;
cin>>r;

switch(r)
{
case 1: cout<<"Introduce el dato a colocar en la Pila"<<endl;
	cin>>dato;
	encolar(dato);
	break;
case 2: if( !esvacia() ){
	desencolar();
	cout<<"Tope de la Cola Fuera"<<endl;
	break;
	}else
	cout<<"Cola Vacia"<<endl;
	break;
	
case 3: if( !esvacia() ){
        cout<<"Cola Actual:"<<endl; //Vamos a desplazarnos dentro de la pila
	imprime();
	break;
	}else
	  cout<<"Cola Vacia"<<endl;
        break;
 } // Fin Switch
}while(r!=0);

return 0;
}

// FIN IMPLEMENTACION


