#include <iostream>
#include <list>

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
// Clase Fecha:

class Fecha {
  public:
    Fecha(int mes, int dia);


    int dia();
    int mes();


    #if EJ >= 9 // Para ejercicio 9
    void incrementar_dia();
    bool operator==(Fecha f);
    #endif

   /* #if EJ >= 14
    int dia() const;
    int mes() const;
    bool operator<(Fecha o) const;
    #endif*/

  private:
    int mes_;
    int dia_;
};
Fecha::Fecha(int mes, int dia): mes_(mes), dia_(dia){}


int Fecha::dia()
{
    return dia_;

}

int Fecha::mes()
{
    return mes_;
}


#if EJ >= 9
void Fecha::incrementar_dia()
{
    if(mes_ == 12 && dias_en_mes(mes_) == dia_ ){
        mes_= 1;
        dia_ = 1;
    } else {
        if(dias_en_mes(mes_) == dia_) {
            mes_++;
            dia_= 1;
        }else {
            dia_++;
        }
    }
}

bool Fecha::operator==(Fecha f)
{
    bool igual_dia = this->dia() == f.dia();
    bool igual_mes = this->mes() == f.mes();
    return (igual_dia && igual_mes);
}
#endif

/*#if EJ >= 14
int Fecha::dia() const {
    return dia_;
}

int Fecha::mes() const {
    return mes_;
}

bool Fecha::operator<(Fecha o) const {
    bool menor_dia = this->dia() < o.dia();
    bool menor_mes = this->mes() < o.mes();
    bool igual_mes = this->mes() == o.mes();
    return (menor_mes || (igual_mes && menor_dia));
}
#endif*/


ostream& operator<<(ostream& os, Fecha f)
{
    os << f.dia() << "/" << f.mes();
    return os;
}



// Ejercicio 11, 12
// Clase Horario:

class Horario {
public:
    Horario(uint hora,uint min);

    uint hora();
    uint min();

    bool operator==(Horario h);
    bool operator<(Horario h);

private:
    int hora_;
    int min_;
};
Horario::Horario(uint hora, uint min) : hora_(hora), min_(min) {}


uint Horario::hora()
{
    return hora_;
}

uint Horario::min() {
    return min_;
}


bool Horario::operator==(Horario h) {
    bool igual_hora = this->hora() == h.hora();
    bool igual_min  = this->min()  == h.min();
    return(igual_hora && igual_min);
}

bool Horario::operator<(Horario h)
{
    bool mayor_hora;
    if(this->hora() == h.hora()){
        mayor_hora = this->min() < h.min();
    } else {
        mayor_hora = this->hora() < h.hora();
    }
    return mayor_hora;
}


ostream& operator<<(ostream& os, Horario h)
{
    os << h.hora() << ":" << h.min();
    return os;
}



// Ejercicio 13
// Clase Recordatorio:

class Recordatorio {
public:
    Recordatorio(Fecha fecha, Horario horario, string mensaje);

    string mensaje();
    Fecha fecha();
    Horario horario();

    bool operator<(Recordatorio rec);

private:
    string mensaje_;
    Fecha fecha_;
    Horario horario_;
};
Recordatorio::Recordatorio(Fecha fecha, Horario horario, string mensaje) :fecha_(fecha), horario_(horario), mensaje_(mensaje) {};


string Recordatorio::mensaje() {
    return mensaje_;
}

Fecha Recordatorio::fecha() {
    return fecha_;
}

Horario Recordatorio::horario() {
    return horario_;
}


bool Recordatorio::operator<(Recordatorio rec)
{
        return (this->horario() < rec.horario());
}


ostream& operator<<(ostream& os, Recordatorio r)
{
    os << r.mensaje() << " @ " << r.fecha().dia() << "/" << r.fecha().mes() << " " << r.horario().hora() << ":" << r.horario().min();
    return os;
}



// Ejercicio 14
// Clase Agenda:

class Agenda {
public:
    Agenda(Fecha fecha_inicial);

    Fecha hoy();
    void agregar_recordatorio(Recordatorio rec);
    void incrementar_dia();
    list<Recordatorio> recordatorios_de_hoy();

private:
    Fecha hoy_;
    list<Recordatorio> agenda_;
};

Agenda::Agenda(Fecha fecha_inicial) : hoy_(fecha_inicial) {};

Fecha Agenda::hoy()
{
    return hoy_;
}

void Agenda::agregar_recordatorio(Recordatorio rec)
{
    agenda_.push_back(rec);
}

void Agenda::incrementar_dia()
{
    Fecha maniana(hoy_.mes(), hoy_.dia());
    maniana.incrementar_dia();
    hoy_ = maniana;
}

list <Recordatorio> Agenda::recordatorios_de_hoy() {
    list<Recordatorio> res = {};
    for(Recordatorio r : agenda_)
    {
        if(hoy_ == r.fecha())
        {
            res.push_back(r);
        }
    }
    return res;
}


ostream& operator<<(ostream& os, Agenda a)
{
    os << a.hoy() <<endl;
    os << "=====" <<endl;
    list<Recordatorio> res = a.recordatorios_de_hoy();
    res.sort();
    for(Recordatorio r : res)
    {
        os << r <<endl;
    }
    return os;
}










