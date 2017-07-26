#include <exception> // Libreria estandar para agregar excepciones
#include <string> // Libreria estandar para el manejo de cadenas
#include <stdexcept>

using namespace std; // Usamos el espacio de nombres estandar

class ColaExcep: public std::runtime_error
{
public:
//Constructor que inicializa el objeto exception con message.c_str(), con la cadena pasada en message.
ColaExcep(const std::string & message="") : std::runtime_error(message)
{}
}; // Fin de la Clase ColaExcep
