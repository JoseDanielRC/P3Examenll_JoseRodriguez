#include"NodoArbol.h"
#include"Militar.h"
#include <ncurses.h>
#include<fstream>
using std::ofstream;
#include<iostream>
using std::cin;
using std::cout;
using std::endl;
#include<string>
using std::string;
#include <vector>
using std::vector;
void EscribirArchivo(string filename,string salida){
    ofstream file;
    file.open("Listados/"+filename,std::ios::app);
    file<<salida<<endl;
    file.close();
}
void PreOrden(NodoArbol* nodo,vector<NodoArbol*> &tipoactual,string &salida){
    if(nodo->getmilitar()->getrango()=="Coronel"){
        printw(" ");
        salida+=" ";
    }else if(nodo->getmilitar()->getrango()=="Mayor"){
        printw("  ");
        salida+="  ";
    }else if(nodo->getmilitar()->getrango()=="Capitan"){
        printw("   ");
        salida+="   ";
    }else if(nodo->getmilitar()->getrango()=="Teniente"){
        printw("    ");
        salida+="    ";
    }else if(nodo->getmilitar()->getrango()=="Sargento"){
        printw("     ");
        salida+="     ";
    }else if(nodo->getmilitar()->getrango()=="Cabo"){
        printw("      ");
        salida+="      ";
    }else if(nodo->getmilitar()->getrango()=="Soldado"){
        printw("       ");
        salida+="       ";
    }
    printw("%s\n",nodo->toString().c_str());
    salida+=nodo->toString()+"\n";
    for (int i = 0; i < nodo->getNodosHijos().size(); i++)
    {
        PreOrden(nodo->getNodosHijos()[i],tipoactual,salida);
    }
    
    
}
void Busqueda(NodoArbol* nodo,vector<NodoArbol*> &tipoactual, string actual){
    if(nodo->getmilitar()->getrango()==actual){
        tipoactual.push_back(nodo);
    }
    for (int i = 0; i < nodo->getNodosHijos().size(); i++)
    {
        Busqueda(nodo->getNodosHijos()[i],tipoactual,actual);
    }
    
    
}
int main(){
    NodoArbol* raiz=new NodoArbol();
    vector <NodoArbol*> militartipoactual;
    raiz->setmilitar(new Militar("DanielR","118113","18","General"));
    int opcion=0,selecciontipo=0;
    char resp='s';
    string salida;
    while(resp=='s'){
        cout<<"1.Crear Militar"<<endl
            <<"2.Visualizar Ejercito(Arbol)"<<endl
            <<"3.Guardar archivo"<<endl;
            cin>>opcion;
            switch (opcion)
            {
            case 1:{
                 Militar* militar;
                string nombre,codigo,edad,rango;
                cout<<"Ingrese nombre del militar: "<<endl;
                cin>>nombre;
                cout<<"Ingrese codigo del militar: "<<endl;
                cin>>codigo;
                cout<<"Ingrese edad: "<<endl;
                cin>>edad;
                cout<<"Ingrese rango: "<<endl;
                int opcionrango=0;
                cout<<"1.Coronel"<<endl
                    <<"2.Mayor"<<endl
                    <<"3.Capitan"<<endl
                    <<"4.Teniente"<<endl
                    <<"5.Sargento"<<endl
                    <<"6.Cabo"<<endl;
                      cin>>opcionrango;
                    switch (opcionrango)
                    {
                    case 1:{
                        rango="Coronel";
                       militar=new Militar(nombre,codigo,edad,rango);
                        raiz->agregarnodo(new NodoArbol(militar));
                        militartipoactual.clear();
                        
                    }                    
                        break;
                    
                    case 2:{
                        rango="Mayor";
                        Busqueda(raiz,militartipoactual,"Coronel");
                        if(militartipoactual.size()>0){
                            militar=new Militar(nombre,codigo,edad,rango);
                            for(int i=0;i<militartipoactual.size();i++){
                                cout<<"     "<<i<<"-"<<militartipoactual[i]->getmilitar()->getnombre()<<endl;
                            }
                            cout<<"     opcion:"<<endl;
                            cin>>opcion;
                            militartipoactual[opcion]->agregarnodo(new NodoArbol(militar));
                            militartipoactual.clear();
                        }
                    }
                        break;
                    case 3:{
                        rango="Capitan";
                        Busqueda(raiz,militartipoactual,"Mayor");
                        if(militartipoactual.size()>0){
                            militar=new Militar(nombre,codigo,edad,rango);
                            for(int i=0;i<militartipoactual.size();i++){
                                cout<<"     "<<i<<"-"<<militartipoactual[i]->getmilitar()->getnombre()<<endl;
                            }
                            cout<<"     opcion:"<<endl;
                            cin>>opcion;
                            militartipoactual[opcion]->agregarnodo(new NodoArbol(militar));
                            militartipoactual.clear();
                        }
                    }
                        break;
                    case 4:{
                        rango="Teniente";
                        Busqueda(raiz,militartipoactual,"Capitan");
                        if(militartipoactual.size()>0){
                            militar=new Militar(nombre,codigo,edad,rango);
                            for(int i=0;i<militartipoactual.size();i++){
                                cout<<"     "<<i<<"-"<<militartipoactual[i]->getmilitar()->getnombre()<<endl;
                            }
                            cout<<"     opcion:"<<endl;
                            cin>>opcion;
                            militartipoactual[opcion]->agregarnodo(new NodoArbol(militar));
                            militartipoactual.clear();
                        }
                    }
                        break;
                    case 5:{
                        rango="Sargento";
                        Busqueda(raiz,militartipoactual,"Teniente");
                        if(militartipoactual.size()>0){
                            militar=new Militar(nombre,codigo,edad,rango);
                            for(int i=0;i<militartipoactual.size();i++){
                                cout<<"     "<<i<<"-"<<militartipoactual[i]->getmilitar()->getnombre()<<endl;
                            }
                            cout<<"     opcion:"<<endl;
                            cin>>opcion;
                            militartipoactual[opcion]->agregarnodo(new NodoArbol(militar));
                            militartipoactual.clear();
                        }
                    }
                        break;
                    case 6:{
                        rango="Cabo";
                        Busqueda(raiz,militartipoactual,"Sargento");
                        if(militartipoactual.size()>0){
                            militar=new Militar(nombre,codigo,edad,rango);
                            for(int i=0;i<militartipoactual.size();i++){
                                cout<<"     "<<i<<"-"<<militartipoactual[i]->getmilitar()->getnombre()<<endl;
                            }
                            cout<<"     opcion:"<<endl;
                            cin>>opcion;
                            militartipoactual[opcion]->agregarnodo(new NodoArbol(militar));
                            militartipoactual.clear();
                        }
                    }
                        break;
                    case 7:{
                        rango="Soldado";
                        Busqueda(raiz,militartipoactual,"Cabo");
                        if(militartipoactual.size()>0){
                            militar=new Militar(nombre,codigo,edad,rango);
                            for(int i=0;i<militartipoactual.size();i++){
                                cout<<"     "<<i<<"-"<<militartipoactual[i]->getmilitar()->getnombre()<<endl;
                            }
                            cout<<"     opcion:"<<endl;
                            cin>>opcion;
                            militartipoactual[opcion]->agregarnodo(new NodoArbol(militar));
                            militartipoactual.clear();
                        }
                    }
                    break;
                    }
            }break;
            
            case 2:{
                
                Busqueda(raiz,militartipoactual,"Coronel");
                Busqueda(raiz,militartipoactual,"Mayor");
                Busqueda(raiz,militartipoactual,"Capitan");
                Busqueda(raiz,militartipoactual,"Teniente");
                Busqueda(raiz,militartipoactual,"Sargento");
                Busqueda(raiz,militartipoactual,"Cabo");
                initscr();
                noecho();
                start_color();
                init_pair(1,COLOR_GREEN,COLOR_BLACK);
                wbkgd(stdscr,COLOR_PAIR(1));
                refresh();
                PreOrden(raiz,militartipoactual,salida);
                char teclado=getch();
                while(teclado!= 'x'){
                    if(teclado=='n'){
                        start_color();
                        init_pair(1,COLOR_GREEN,COLOR_BLACK);
                        wbkgd(stdscr,COLOR_PAIR(1));
                    }else if(teclado=='i'){
                        start_color();
                        init_pair(2,COLOR_BLACK,COLOR_WHITE);
                        wbkgd(stdscr,COLOR_PAIR(2));
                    }else if(teclado=='c'){
                        start_color();
                        init_pair(3,COLOR_BLUE,COLOR_RED);
                        wbkgd(stdscr,COLOR_PAIR(3));
                    }else if(teclado=='l'){
                        start_color();
                        init_pair(4,COLOR_BLUE,COLOR_WHITE);
                        wbkgd(stdscr,COLOR_PAIR(4));
                    }
                teclado=getch();
                refresh();
                }
                endwin();

            }
                break;
            case 3:{
                string filename;
                cout<<"Ingrese nombre del archivo nuevo"<<endl;
                cin>>filename;
                EscribirArchivo(filename+".txt",salida);

            }
                break;
                }
            }

    return 0;
}