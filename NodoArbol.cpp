
#include "NodoArbol.h"

NodoArbol::NodoArbol(){
}
NodoArbol::NodoArbol(Militar* militar){

this->militar=militar;
this->NodosHijos=NodosHijos;
}
Militar* NodoArbol::getmilitar(){
return militar;
}
void NodoArbol::setmilitar(Militar* militar){
this->militar=militar;
}

vector<NodoArbol*> NodoArbol::getNodosHijos(){
return NodosHijos;
}
void NodoArbol::setNodosHijos(vector<NodoArbol*> NodosHijos){
this->NodosHijos=NodosHijos;
}
void NodoArbol::agregarnodo(NodoArbol* nodo){
    NodosHijos.push_back(nodo);
}
string NodoArbol::toString(){;
return militar->toString();
}
