//
// Created by clinux01 on 04/05/22.
//

#ifndef SOLUCION_MULTICONJUNTO_HPP
#define SOLUCION_MULTICONJUNTO_HPP
#include "Diccionario.hpp"

template<class T>
class Multiconjunto{
public:
    Multiconjunto();
    void agregar(T x);
    int ocurrencias(T x) const;
    bool operator<=(Multiconjunto<T> otro) const;

private:
    Diccionario<T,int> _multConj;
};
template<class T>
Multiconjunto<T>::Multiconjunto() {
    _multConj;
}

template<class T>
void Multiconjunto<T>::agregar(T x) {
    if (_multConj.def(x)){
        _multConj.definir(x, _multConj.obtener(x) + 1);
    } else{
        _multConj.definir(x, 1);
    }
}

template<class T>
int Multiconjunto<T>::ocurrencias(T x) const {
    int res;
    if(_multConj.def(x)){
        res = _multConj.obtener(x);
    } else{
        res=0;
    }
    return res;
}

template<class T>
bool Multiconjunto<T>::operator<=(Multiconjunto<T> otro) const {
    bool res=true;
    std::vector<T> claves = (this->_multConj).claves();
    for (int i = 0; i < claves.size(); ++i) {
        if (!(this->ocurrencias(claves[i])<=otro.ocurrencias(claves[i]))){
            res= false;
        }
    }
    return res;
}

#endif //SOLUCION_MULTICONJUNTO_HPP
