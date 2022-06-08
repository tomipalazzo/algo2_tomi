#ifndef CONJUNTO_H_
#define CONJUNTO_H_

#include <assert.h>
#include <string>
#include <iostream>

using namespace std;

template <class T>
class Conjunto
{
    public:

        // Constructor. Genera un conjunto vacío.
        Conjunto();

        // Destructor. Debe dejar limpia la memoria.
        ~Conjunto();

        // Inserta un elemento en el conjunto. Si este ya existe,
        // el conjunto no se modifica.
        void insertar(const T&);

        // Decide si un elemento pertenece al conjunto o no.
        bool pertenece(const T&) const;

        // Borra un elemento del conjunto. Si este no existe,
        // el conjunto no se modifica.
        void remover(const T&);

        // Siguiente elemento al recibido por párametro, en orden.
        // Se asume que el elemento recibido se encuentra en el conjunto y existe un elemento siguiente.
        const T& siguiente(const T& elem);

        // Devuelve el mínimo elemento del conjunto según <.
        // Asume no vacio.
        const T& minimo() const;

        // Devuelve el máximo elemento del conjunto según <.
        // Asume no vacio.
        const T& maximo() const;

        // Devuelve la cantidad de elementos que tiene el conjunto.
        unsigned int cardinal() const;

        // Muestra el conjunto.
        void mostrar() const;

    private:

        /**
         * Completar con lo que sea necesario...
         **/

        struct Nodo
        {
            // El constructor, toma el elemento al que representa el nodo.
            Nodo(const T& v): valor(v), izq(nullptr), der(nullptr){
            };
            // El elemento al que representa el nodo.
            T valor;
            // Puntero a la raíz del subárbol izquierdo.
            Nodo* izq;
            // Puntero a la raíz del subárbol derecho.
            Nodo* der;
            // Aux para el destructor
            void borrarRama();
            // Min y max desde un nodo, deberian ser metodos const pero por algun motivo compila
            const T& minimoSub();
            const T& maximoSub();
            void mostrarSub() const;



        };

        // Puntero a la raíz de nuestro árbol.
        Nodo* _raiz;
        // Cantidad de nodos (se podria calcular en O(n) si quisieramos)
        unsigned int _cardinal;

};

template<class T>
std::ostream& operator<<(std::ostream& os, const Conjunto<T>& c) {
	 c.mostrar();
	 return os;
}

#include "Conjunto.hpp"

#endif // CONJUNTO_H_