//
// Created by clinux01 on 04/05/22.
//
#ifndef SOLUCION_DICCIONARIO_HPP
#define SOLUCION_DICCIONARIO_HPP
#include "Templates.hpp"


template<class Clave, class Valor>
class Diccionario {
public:
    Diccionario();
    void definir(Clave k, Valor v);
    bool def(Clave k) const;
    Valor obtener(Clave k) const;
    std::vector<Clave> claves() const;
private:

    struct Asociacion {
        Asociacion(Clave k, Valor v);
        Clave clave;
        Valor valor;
    };
    std::vector<Asociacion> _asociaciones;
};

template<class Clave, class Valor>
Diccionario<Clave, Valor>::Diccionario() {
}
template<class Clave, class Valor>
Diccionario<Clave, Valor>::Asociacion::Asociacion(Clave k, Valor v) : clave(k), valor(v) {
}

template<class Clave, class Valor>
void Diccionario<Clave, Valor>::definir(Clave k, Valor v) {
    for (unsigned int i = 0; i < _asociaciones.size(); i++) {
        if (_asociaciones[i].clave == k) {
            _asociaciones[i].valor = v;
            return;
        }
    }
    _asociaciones.push_back(Asociacion(k, v));
}

template<class Clave, class Valor>
bool Diccionario<Clave, Valor>::def(Clave k) const {
    for (unsigned int i = 0; i < _asociaciones.size(); i++) {
        if (_asociaciones[i].clave == k) {
            return true;
        }
    }
    return false;
}

template<class Clave, class Valor>
Valor Diccionario<Clave, Valor>::obtener(Clave k) const {
    for (unsigned int i = 0; i < _asociaciones.size(); i++) {
        if (_asociaciones[i].clave == k) {
            return _asociaciones[i].valor;
        }
    }
    assert(false);
}
template<class Clave, class Valor>
std::vector<Clave> Diccionario<Clave, Valor>::claves() const {
    std::vector<Clave> v1;
    std::vector<Clave> v2;

    for (int i = 0; i < _asociaciones.size(); ++i) { //Guardo claves
        v1.push_back(_asociaciones[i].clave);
    }

    int min_i = 0;
    int max_i = 0;
    for (int j = 0; j < v1.size(); ++j) {
        for (int k = 0; k < v1.size(); ++k) {
            if (v1[k]<=v1[min_i]){
                min_i = k;
            }
            if (!(v1[k]<=v1[max_i])){
                max_i = k;
            }
        }
        v2.push_back(v1[min_i]);
        v1[min_i]=v1[max_i];
    }
    return v2;
}

#endif //SOLUCION_DICCIONARIO_HPP
