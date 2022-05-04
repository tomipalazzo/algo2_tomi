//
// Created by clinux01 on 04/05/22.
//


template <class T=float >
T cuadrado(T x) {
    return x * x;
}

template<class Contenedor, class Elem>
bool contiene(Contenedor s, Elem c) {
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == c) {
            return true;
        }
    }
    return false;
}

template<class Contenedor>
bool esPrefijo(Contenedor a, Contenedor b){
    bool res = true;typedef int Clave;
typedef int Valor;

    if (a.size()>b.size()){
        res= false;
    }
    int i =0;
    while(i<a.size() && res== true){
        if (a[i] != b[i]){
            res= false;
        }
        i++;
    }
    return res;
}

template<class Contenedor, class Elem>
Elem maximo(Contenedor c){
    Elem res=c[0];

    for (int i = 1; i < c.size(); ++i) {
        if (res < c[i]){
            res=c[i];
        }
    }
    return res;
}


