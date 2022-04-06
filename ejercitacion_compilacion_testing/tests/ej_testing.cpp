#include "gtest-1.8.1/gtest.h"
#include "../src/Libreta.h"
#include "../src/Truco.h"
#include <map>
#include <cmath>

using namespace std;

// Ejercicio 4
TEST(Aritmetica, suma) {
    EXPECT_EQ(15+7,22);
}

// Ejercicio 5
TEST(Aritmetica, potencia) {
    float res= pow(10,2);
    EXPECT_EQ(res, 100);
}

// Ejercicio 6

TEST(Aritmetica, potencia_general){
    for (int i = -5; i <= 5; ++i) {
        EXPECT_EQ(pow(i,2), i*i);
    }

}

// Ejercicio 7
TEST(Diccionario, obtener){
    map<int,int> dic;
    dic[0] = 10;
    EXPECT_EQ(dic[0], 10);
}

// Ejercicio 8

TEST(Truco, inicio){
    Truco iniciar;
    iniciar = Truco();
    EXPECT_EQ(iniciar.puntaje_j1(),0);
    EXPECT_EQ(iniciar.puntaje_j2(),0);
}

// Ejercicio 9

TEST(Truco, buenas){
    Truco t;
    t = Truco();

    EXPECT_FALSE(t.buenas(1));
    for (int i = 0; i < 15; ++i) {
        t.sumar_punto(1);
    }
    EXPECT_FALSE(t.buenas(1));

    t.sumar_punto(1);
    EXPECT_TRUE(t.buenas(1));

    for (int i = 0; i < 2; ++i) {
        t.sumar_punto(1);
    }
    EXPECT_TRUE(t.buenas(1));
}



