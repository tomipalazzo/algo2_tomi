#ifndef PROXY_H
#define PROXY_H

#include "ConexionJugador.h"
#include <string>

using namespace std;

class Proxy {
public:
    Proxy(ConexionJugador* conn);
    void enviarMensaje(string msg);

// No puedo copiarlo
Proxy(const Proxy&);

private:
    ConexionJugador* _conn;

};

#endif
