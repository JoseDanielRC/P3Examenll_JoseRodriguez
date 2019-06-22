#ifndef NODOARBOL_H
#define NODOARBOL_H
#include "Militar.h"
#include <vector>
#include<iostream>
#include <string>
using std::vector;
using std::string;
using std::cout;
using std::endl;
class NodoArbol{
protected:
Militar* militar;
vector<NodoArbol*> NodosHijos;

public:
NodoArbol();
NodoArbol(Militar*);

Militar* getmilitar();
void setmilitar(Militar*);

vector<NodoArbol*> getNodosHijos();
void setNodosHijos(vector<NodoArbol*>);

void agregarnodo(NodoArbol*);
string toString();
};
#endif

