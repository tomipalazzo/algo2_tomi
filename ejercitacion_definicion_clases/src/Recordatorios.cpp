#include <iostream>

using namespace std;

using uint = unsigned int;

// Pre: 0 <= mes < 12
uint dias_en_mes(uint mes) {
    uint dias[] = {
        // ene, feb, mar, abr, may, jun
        31, 28, 31, 30, 31, 30,
        // jul, ago, sep, oct, nov, dic
        31, 31, 30, 31, 30, 31
    };
    return dias[mes - 1];
}

// Ejercicio 7, 8, 9 y 10

// Clase Fecha
class Fecha {
    public:
        // Completar declaraciones funciones
        #if EJ >= 9 // Para ejercicio 9
        bool operator==(Fecha o);
        #endif

        Fecha(int mes, int dia);
        int mes();
        int dia();
        void incrementar_dia();


    private:
        int dia_;
        int mes_;
};

Fecha::Fecha(int mes, int dia): mes_(mes), dia_(dia){}

int Fecha::mes() {
    return mes_;
}
int Fecha::dia() {
    return dia_;
}

// Ejercicio 8

ostream& operator<<(ostream& os, Fecha f){
    os << f.dia() <<"/"<<f.mes();
    return os;
}


// Ejercicio 9

#if EJ >= 9
bool Fecha::operator==(Fecha o) {
    bool igual_dia = this->dia() == o.dia();
    bool igual_mes = this->mes() == o.mes();
    return igual_dia && igual_mes;
}
#endif

// Ejercicio 10, 11, 12
void Fecha::incrementar_dia() {
    if (dia_ < dias_en_mes(mes_)){
        dia_++;
    }else{
        dia_=1;
        mes_++;
    }
}
// Clase Horario

class Horario{
public:
    Horario(uint hora, uint min);
    uint hora();
    uint min();
    bool operator<(Horario h);

private:
    uint hora_;
    uint min_;
};

Horario::Horario(uint hora, uint min): hora_(hora), min_(min) {}
uint Horario::hora(){
    return hora_;
}
uint Horario::min() {
    return min_;
}

ostream& operator<<(ostream& os, Horario h){
    os<< h.hora() << ":" << h.min();
}

bool Horario::operator<(Horario h) {
    bool res;
    if(this->hora() == h.hora()){
        res = this->min() < h.min();
    }else{
        res = this->hora() < h.hora();
    }
    return res;
}


// Ejercicio 13

// Clase Recordatorio

class Recordatorio{
public:
    Recordatorio(Fecha fecha, Horario horario, string mensaje);
    string mensaje();
    Fecha fecha();
    Horario horario();

private:
string mensaje_;
Fecha fecha_;
Horario horario_;
};

Recordatorio::Recordatorio(Fecha fecha, Horario horario, string mensaje): mensaje_(mensaje), fecha_(fecha), horario_(horario) {}

string Recordatorio::mensaje() {
    return mensaje_;
}
Fecha Recordatorio::fecha() {
    return fecha_;
}
Horario Recordatorio::horario() {
    return horario_;
}

ostream& operator<<(ostream& os, Recordatorio r){
    os << r.mensaje() << " @ " << r.fecha() << " " <<r.horario();
}

// Ejercicio 14

// Clase Agenda

