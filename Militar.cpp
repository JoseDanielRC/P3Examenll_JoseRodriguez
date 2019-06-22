#include "Militar.h"

Militar::Militar(){
}
Militar::Militar(string nombre ,string codigo ,string edad ,string rango){

this->nombre=nombre;
this->codigo=codigo;
this->edad=edad;
this->rango=rango;
}
string Militar::getnombre(){
return nombre;
}
void Militar::setnombre(string nombre){
this->nombre=nombre;
}

string Militar::getcodigo(){
return codigo;
}
void Militar::setcodigo(string codigo){
this->codigo=codigo;
}

string Militar::getedad(){
return edad;
}
void Militar::setedad(string edad){
this->edad=edad;
}

string Militar::getrango(){
return rango;
}
void Militar::setrango(string rango){
this->rango=rango;
}
string Militar::toString(){
string MilitarStr;
MilitarStr=nombre+"-"+rango;
return MilitarStr;
}
