#ifndef ALGO2_LABO_CLASE5_ALGORITMOS_H
#define ALGO2_LABO_CLASE5_ALGORITMOS_H

#include <utility>
#include <iterator>
#include <vector>



// Ejercicio 1
template<class Contenedor>
typename Contenedor::value_type minimo(const Contenedor& c){
    typename Contenedor::const_iterator it = c.begin();
    auto min = it;
    while(it != c.end()){
        if(*it < *min){
            min = it;
        }
        ++it;
    }
    return *min;
}

// Ejercicio 2
template<class Contenedor>
typename Contenedor::value_type promedio(const Contenedor& c) {
    int n = 0;
    typename Contenedor::value_type suma = 0;
    typename Contenedor::const_iterator it = c.begin();

    while (it != c.end()) {
        n++;
        suma = suma + *it;
        ++it;
    }
    return suma / n;
}

// Ejercicio 3 a
template<class Iterator>
typename Iterator::value_type minimoIter(const Iterator& desde, const Iterator& hasta){
    auto min = desde;
    for(auto it=desde; it!=hasta;++it){
        if(*it < *min){
            min = it;
        }
    }
    return *min;
}
   // typename Contenedor::iterator it = c.begin();

// Ejercicio 3 b

template<class Iterator>
typename Iterator::value_type promedioIter(const Iterator& desde, const Iterator& hasta){
    typename Iterator::value_type suma = 0;
    int n = 0;
    for (auto it=desde; it!=hasta; ++it){
        n++;
        suma = suma + *it;
    }
    return  suma/n;
}

// Ejercicio 4

template<class Contenedor>
void filtrar(Contenedor &c, const typename Contenedor::value_type& elem){
    typename Contenedor::iterator it = c.begin();
    while (it!=c.end()){
        if(*it == elem){
            it = c.erase(it);
        }else{
            ++it;
        }
    }
}


// Ejercicio 5

template<class Contenedor>
bool ordenado(Contenedor &c){
    typename Contenedor::const_iterator it = c.begin();
    bool res = true;
    while (it!=c.end()){
        auto val_actual = it;
        if(++it != c.end()){ //Actualizo el iterador
            if (*val_actual >= *(it)){
                res = false;
            }
        }

    }
    return res;
}




template<class Contenedor>
std::pair<Contenedor, Contenedor>
split(const Contenedor & c,
      const typename Contenedor::value_type& elem){
    Contenedor mayores;
    Contenedor menores;

    typename Contenedor::const_iterator it = c.begin();
    typename Contenedor::const_iterator itMen = menores.end();
    typename Contenedor::const_iterator itMay = mayores.end();

    while (it!=c.end()){
        if (*it < elem) {
           itMen = menores.insert(itMen, *it);
           itMen= menores.end();
        }else{
            itMay = mayores.insert(itMay, *it);
            itMay= mayores.end();
        }
        ++it;
    }
    std::pair<Contenedor, Contenedor> res;
    res.first = menores;
    res.second = mayores;
    return res;
}

// Ejercicio 7




#endif //ALGO2_LABO_CLASE5_ALGORITMOS_H
