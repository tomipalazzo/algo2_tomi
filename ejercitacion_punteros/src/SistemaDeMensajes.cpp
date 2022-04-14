#include "SistemaDeMensajes.h"
#include "Proxy2.h"



SistemaDeMensajes::SistemaDeMensajes(): punteros_proxy_(){
    _conns[0] = NULL;
    _conns[1] = NULL;
    _conns[2] = NULL;
    _conns[3] = NULL;
}

void SistemaDeMensajes::registrarJugador(int id, string ip){
    if (_conns[id] != NULL){
        *_conns[id] = ConexionJugador(ip);
    }else {
        ConexionJugador *p;
        p = new ConexionJugador(ip);
        _conns[id] = p;
    }
}

void SistemaDeMensajes::enviarMensaje(int id, string mensaje){
    (_conns[id])->enviarMensaje(mensaje);
}

bool SistemaDeMensajes::registrado( int id) const{
    return _conns[id] != NULL;
}

string SistemaDeMensajes::ipJugador(int id) const{
    return  _conns[id]->ip();
}
SistemaDeMensajes::~SistemaDeMensajes(){
    for (int i = 0; i < 4; ++i) { //Es hasta 4 pq es la long del array
        delete _conns[i];
    }
    for (int i = 0; i < punteros_proxy_.size(); ++i) {
        delete punteros_proxy_[i];
        //te quiero mucho
    }
}


void SistemaDeMensajes::desregistrarJugador(int id){
    delete _conns[id];
    _conns[id] = NULL;
}

Proxy* SistemaDeMensajes::obtenerProxy(int id) {
    Proxy* P;
    P = new Proxy(&_conns[id]);
    punteros_proxy_.push_back(P);
    return P;
}

