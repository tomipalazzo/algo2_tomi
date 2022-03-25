#include <vector>
#include "algobot.h"

using namespace std;

// Ejercicio 1


bool pertenece(int n, vector<int> s){
    int i;
    for (i=0; i<s.size() && s[i]!=n ; i++){
    }
    return i<s.size();

}

bool pertenece_char(char n, vector<char> s){
    int i;
    for (i=0; i<s.size() && s[i]!=n ; i++){
    }
    return i<s.size();

}

vector<int> quitar_repetidos(vector<int> s) {
    vector<int> res;

    for (int i=0; i<s.size(); i++){
        if(! pertenece(s[i], res)){
            res.push_back(s[i]);
        }
    }


    return res;

}

// Ejercicio 2
vector<int> quitar_repetidos_v2(vector<int> s) {
    vector<int> res;
    set<int> conjunto;
    for (int i=0; i<s.size();i++){
        conjunto.insert(s[i]);
    }
    for (int i:conjunto){
        res.push_back(i);
    }
    return res;
}

// Ejercicio 3
bool mismos_elementos(vector<int> a, vector<int> b) {
    set<int> conjunto_a;
    set<int> conjunto_b;
    for (int i=0; i<a.size();i++) {
        conjunto_a.insert(a[i]);
    }

    for (int i=0; i<b.size();i++) {
        conjunto_b.insert(b[i]);
    }



    return conjunto_a == conjunto_b;
}

// Ejercicio 4
bool mismos_elementos_v2(vector<int> a, vector<int> b) {
    set<int> conjunto_a;
    set<int> conjunto_b;
    for (int i=0; i<a.size();i++) {
        conjunto_a.insert(a[i]);
    }

    for (int i=0; i<b.size();i++) {
        conjunto_b.insert(b[i]);
    }



    return conjunto_a == conjunto_b;
}

// Ejercicio 5
map<int, int> contar_apariciones(vector<int> s) {
    map<int, int> res;
    vector<int> val_unicos;
    val_unicos = quitar_repetidos_v2(s);
    for (int i = 0; i < val_unicos.size(); ++i) {
        res[val_unicos[i]] = 0;
    }

    for (int i=0; i<s.size();i++){
         res[s[i]]++;
    }
    return res;
}

// Ejercicio 6
vector<int> filtrar_repetidos(vector<int> s) {
    vector<int> res;
    map<int,int> dic = contar_apariciones(s);
    for (int i = 0; i < s.size(); ++i) {
        if(dic[s[i]] == 1){
            res.push_back(s[i]);
        }
    }
    return res;
}

// Ejercicio 7
set<int> interseccion(set<int> a, set<int> b) {
    set<int> res;
    for (int i:a) {
        if (b.count(i)==1){
            res.insert(i);
        }
    }
    return res;
}

// Ejercicio 8
map<int, set<int>> agrupar_por_unidades(vector<int> s) {
    map<int,set<int>> res;
    set<int> empty;

    for (int i = 0; i < s.size(); ++i) {
        int last_dig = s[i]%10;
        if (res.count(last_dig) ==1){
            res[last_dig].insert(s[i]);
        } else{
            res[last_dig].insert(s[i]);
        }
    }



    return res;
}

// Ejercicio 9
vector<char> traducir(vector<pair<char, char>> tr, vector<char> str) {
    vector<char> res;
    for (int i = 0; i < str.size(); i++) {
        int j;
        for (j=0; j < tr.size() && str[i]!= tr[j].first; j++);
        if (j<tr.size()){
            res.push_back(tr[j].second);
        }else{
            res.push_back(str[i]);
        }
    }
    return res;
}

// Ejercicio 10
/*bool integrantes_repetidos(vector<Mail> s) {
    bool res = false;
    for (int i = 0; i < s.size(); i++)
    {
        for (int j = 0; i < s.size(); j++)
        {
            if (interseccion(s[i].libretas(), s[j].libretas()).size()==1){
                res=true;
            }
        }
        
    }
    


    return res;
}
*/

set<LU> interseccion_LU(set<LU> a, set<LU> b) {
    set<LU> res;
    for (LU i:a) {
        if (b.count(i)==1){
            res.insert(i);
        }
    }
    return res;
}
bool integrantes_repetidos(vector<Mail> s) {
    bool res = false;
    for (Mail mail1:s)
    {
        set<LU> integrantesMail1 = mail1.libretas();

        for(Mail mail2:s){
            set<LU> integrantesMail2 = mail2.libretas();
        if(!mail1.operator==(mail2) && !interseccion_LU(integrantesMail1, integrantesMail2).empty()){
            res=true;
        }

        }
    }
    


    return res;
}

// Ejercicio 11
map<set<LU>, Mail> entregas_finales(vector<Mail> s) {
    map<set<LU>,Mail> res;

    for (Mail mail:s)
    {
        set<LU> libretas = mail.libretas();
        if (res.count(libretas)!=1){
            res[libretas] = mail;
        }
    }
    




  return res;
}
