#ifndef MILITAR_H
#define MILITAR_H
#include<iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;
class Militar{
private:
string nombre;
string codigo;
string edad;
string rango;

public:
Militar();
Militar(string, string, string, string);

string getnombre();
void setnombre(string);

string getcodigo();
void setcodigo(string);

string getedad();
void setedad(string);

string getrango();
void setrango(string);

string toString();
};
#endif
