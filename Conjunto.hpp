
template <class T>
Conjunto<T>::Conjunto() {
    // Completar
}

template <class T>
Conjunto<T>::~Conjunto() { 
    // Completar
}

template <class T>
bool Conjunto<T>::pertenece(const T& clave) const {
    Nodo *actual = this;
    return pertenece_aux(clave, actual);
}

template <class T>
bool Conjunto<T>::pertenece_aux(const T& clave, Nodo* actual){ // Es la funcion pertenece pero con un nodo de parametro (Analiza el arbol de la raiz acutal)
    bool res;

    if (actual->valor == NULL){
        res= false;
    } else {if ((pertenece(clave, actual->izq)) || (pertenece(clave, actual->der))){
        res= true;
    } else{
        res=false;
    }
}
    return res;
}



template <class T>
typename Conjunto<T>::Nodo nodoDer() const{
    return this->_raiz->der;
}

template <class T>
void Conjunto<T>::insertar(const T& clave) {
    Nodo* actual = this;
    if (not pertenece(clave)){
        insertar_aux(clave, actual);
    }
}

template <class T>
void Conjunto<T>::insertar_aux(const T& clave, Nodo* actual){// Realiza la operacion insertar para el sub arbol de nodo Actual
    if (actual->valor=NULL){
        actual->valor=clave;
    }else{
        if(clave > actual->valor){
            insertar_aux(clave, actual->der);
        }else{
            insertar_aux(clave, actual->izq);
        }
    }
}

template <class T>
void Conjunto<T>::remover(const T&) {
    assert(false);
}

template <class T>
const T& Conjunto<T>::siguiente(const T& clave) {
    assert(false);
}

template <class T>
const T& Conjunto<T>::minimo() const {
    Nodo* actual = this;
    while (actual->izq != NULL){
        actual = actual->izq;
    }
    return actual->valor;
}


template <class T>
const T& Conjunto<T>::maximo() const {
    Nodo* actual = this;
    while (actual->der != NULL){
        actual = actual->der;
    }
    return actual->valor;
}

template <class T>
unsigned int Conjunto<T>::cardinal() const {
    assert(false);
    return 0;
}

template <class T>
void Conjunto<T>::mostrar(std::ostream&) const {
    assert(false);
}

