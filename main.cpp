#include "Evaluador.h"
#include <iostream>       // std::cin, std::cout
#include <vector>          // std::list
#include <set>          // std::list
#include <map>          // std::list
#include <string>
using namespace std;


//Agrega valor (dado) a mi_mapa (dado), en la llave dada
//Nota: mi_mapa es un apuntador, para usarlo se sugiere desrreferenciarlo con el operador *
void asignarValor(map<string, int> *mi_mapa, string llave,int valor)
{
    (*mi_mapa)[llave] = valor;
}

//Devuelve el valor asociado a la llave (dada) en mi_mapa (dado)
char obtenerValor(map<int,char> mi_mapa,int llave)
{
    return mi_mapa.find(llave)->second;
}

//Devolver el un mapa con los siguientes valores dados en la tabla
//  LLave     |   Valor
//----------------------------
//  1         |   "lunes"
//  2         |   "martes"
//  3         |   "miercoles"
//  4         |   "jueves"
//  5         |   "viernes"
//  6         |   "sabado"
//  7         |   "domingo"
map<string,int> obtenerSemana()
{
    map<string,int> semana;
    semana["lunes"] = 1;
    semana["martes"] = 2;
    semana["miercoles"] = 3;
    semana["jueves"] = 4;
    semana["viernes"] = 5;
    semana["sabado"] = 6;
    semana["domingo"] = 7;
    return semana;
}

//devuelve la interseccion de mi_set1 (dado) y mi_set2 (dado)
//(devuelve un set que contenga unicamente los valores que mi_set1 y mi_set2 tengan en comun)
set<int> getInserseccion(set<int> mi_set1, set<int> mi_set2)
{
    set<int> mi_set3;
    set<int>::iterator i = mi_set1.begin();
    set<int>::iterator m = mi_set2.begin();
    while(i!= mi_set1.end())
    {
        while(m!=mi_set2.end())
        {
            if(*i == *m){
                mi_set3.insert(*i);
            }
            m++;
        }
        m = mi_set2.begin();
        i++;
    }
    
    
    return mi_set3;
}

//devuelve la union de mi_set1 (dado) y mi_set2 (dado)
//(devuelve un set que contenga todos los valores de mi_set1 y mi_set2)
set<int> getUnion(set<int> mi_set1, set<int> mi_set2)
{
    set<int> mi_set3;
    set<int>::iterator i = mi_set1.begin();
    set<int>::iterator m = mi_set2.begin();
    while(i!= mi_set1.end())
    {
        while(m!=mi_set2.end())
        {
            mi_set3.insert(*m);
            m++;
        }
        mi_set3.insert(*i);
        i++;
    }
    return mi_set3;
}

//devuelve true si mi_sub_set (dado) es un subconjunto de mi_set (dado)
//(mi_set contiene todos los valores de mi_sub_set)
bool esSubConjunto(set<int> mi_set, set<int> mi_sub_set)
{
    set<int>::iterator i = mi_set.begin();
    int cont = 0;
    set<int>::iterator m = mi_sub_set.begin();
    while(i!= mi_set.end())
    {
        int n = 0;
        while(m!=mi_sub_set.end())
        {
            if(*i == *m){
                n++;
                break;
            }
            m++;
        }
        if(n == 0){
            return true;
        }
        n = 0;
        m = mi_sub_set.begin();
        i++;
    }
    return false;
}

int main ()
{

    //Funcion evaluadora
    evaluar();
    return 1;
}