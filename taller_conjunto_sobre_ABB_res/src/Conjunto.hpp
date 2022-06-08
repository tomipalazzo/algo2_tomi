
template <class T>
Conjunto<T>::Conjunto(): _raiz(nullptr), _cardinal(0) {
}


template <class T>
Conjunto<T>::~Conjunto() {
    _raiz->borrarRama();
}

template <class T>
void Conjunto<T>::Nodo::borrarRama(){
    if(this != nullptr){
        if(der != nullptr)
            der->borrarRama();
        if(izq != nullptr)
            izq->borrarRama();
        delete this;
    }
}

template <class T>
bool Conjunto<T>::pertenece(const T& clave) const {
    if (_raiz == nullptr)
        return false;

    Nodo* current = _raiz;
    bool esta = false;
    bool termino = false;
    while (!termino){
        if (clave == current->valor){
            esta = true;
        }
        if (clave < current->valor){
            if (current->izq == nullptr)
                termino = true;
            else
                current = current->izq;
        }else{
            if (current->der == nullptr)
                termino = true;
            else
                current = current->der;
        }

    }
    return esta;
}

template <class T>
void Conjunto<T>::insertar(const T& clave) {
    if(_raiz == nullptr){
        _raiz = new Nodo(clave);
        _cardinal++;
    }else{
        Nodo* current = _raiz;
        while (current->valor != clave){
            if (clave < current->valor){
                if (current->izq == nullptr){
                    current->izq = new Nodo(clave);
                    _cardinal++;
                }
                else
                    current = current->izq;
            }else{
                if (current->der == nullptr){
                    current->der = new Nodo(clave);
                    _cardinal++;
                }
                else
                    current = current->der;
            }
        }
    }
}

// definitivamente esto se tiene que poder escribir de una forma más clean, perdón si lo querías entender jajajajaj
template <class T>
void Conjunto<T>::remover(const T& clave) {
    if (_cardinal != 0) {      // ignoro el vacio
        if (_cardinal == 1) {  // solo la raiz
            if (clave == _raiz->valor) {
                delete _raiz;
                _raiz = nullptr;
                _cardinal--;
            }
        } else { // cardinal > 1
            if (clave == _raiz->valor) {
                if (_raiz->izq == nullptr){           // vacio a izq
                    Nodo* temp = _raiz->der;
                    delete _raiz;
                    _raiz = temp;
                    _cardinal--;
                } else{
                    if (_raiz->der == nullptr){       // solo raiz
                        Nodo* temp = _raiz->izq;
                        delete _raiz;
                        _raiz = temp;
                        _cardinal--;
                    } else{
                        T nuevoValor = _raiz->der->minimoSub(); // ambos hijos
                        this->remover(nuevoValor);
                        _raiz->valor = nuevoValor;
                    }
                }
            } else {
                Nodo *padre = _raiz;
                Nodo *current = nullptr;
                if (clave < _raiz->valor) {
                    current = _raiz->izq;
                }

                else if (clave > _raiz->valor) {
                    current = _raiz->der;
                }

                // Buscar para borrar
                bool seguir = true;
                while (seguir) {
                    if (clave < current->valor) {
                        if (current->izq == nullptr)
                            seguir = false;
                        else {
                            padre = current;
                            current = current->izq;
                        }

                    } else {
                        if (clave > current->valor) {
                            if (current->der == nullptr)
                                seguir = false;
                            else {
                                padre = current;
                                current = current->der;
                            }
                        } else { // clave == current->valor
                            seguir = false;
                        }

                    }
                }

                // Borrar perse
                if(clave == current->valor){
                    if (current->izq == nullptr && current->der == nullptr) {      // es hoja
                        if (padre->izq == current)
                            padre->izq = nullptr;
                        else
                            padre->der = nullptr;
                        delete current;
                        _cardinal--;

                    } else {                                                            // no es hoja
                        if (current->izq == nullptr) {                                      // un solo hijo por der
                            if (padre->izq == current)
                                padre->izq = current->der;
                            else
                                padre->der = current->der;
                            delete current;
                            _cardinal--;
                        } else {
                            if (current->der == nullptr) {                                      // un solo hijo por izq
                                if (padre->izq == current)
                                    padre->izq = current->izq;
                                else
                                    padre->der = current->izq;
                                delete current;
                                _cardinal--;
                            } else {                                                                // dos hijos
                                // buscar minimo a derecha
                                // deletear el que tiene el minimo
                                // asignarle ese valor a current
                                T nuevoValor = current->der->minimoSub();
                                this->remover(nuevoValor);
                                current->valor = nuevoValor;
                            }
                        }
                    }
                }
            }
        }
    }
}



template <class T>
const T& Conjunto<T>::siguiente(const T& clave) {
    // El caso de que clave sea la raiz se trata a parte porque la raiz no tiene padre.

    if(clave == _raiz->valor){
        return _raiz->minimoSub();
    }

    Nodo* current = _raiz;
    Nodo* padre = nullptr; // se define en la primer iteración, sabemos que no va a terminar ahi por el bloque anterior
    bool encontre = false;

    while (!encontre) {
        if (clave == current->valor){
            encontre = true;
        } else {
            if (clave < current->valor){
                padre = current;
                current = current->izq;
            }
            else{
                padre = current;
                current = current->der;
            }
        }

    }
    if (current->der == nullptr){
        return padre->valor;
    }else{
        return current->der->minimoSub();
    }

}

template <class T>
const T& Conjunto<T>::Nodo::minimoSub() {
    Nodo* current = this;
    while(current->izq != nullptr)
        current = current->izq;
    return current->valor;
}

template <class T>
const T& Conjunto<T>::minimo() const {
    return _raiz->minimoSub();
}

template <class T>
const T& Conjunto<T>::Nodo::maximoSub(){
    Nodo* current = this;
    while(current->der != nullptr)
        current = current->der;
    return current->valor;
}

template <class T>
const T& Conjunto<T>::maximo() const {
    return _raiz->maximoSub();
}

template <class T>
unsigned int Conjunto<T>::cardinal() const {
    return _cardinal;
}

template <class T>
void Conjunto<T>::Nodo::mostrarSub() const {
    if(this != nullptr){
        if(izq != nullptr)
            izq->mostrarSub();
        if(der != nullptr)
            der->mostrarSub();
        std::cout << this->valor << ", ";
    }
}

template <class T>
void Conjunto<T>::mostrar() const {
    _raiz->mostrarSub();
}






