#ifndef  __NODE_H__
#define  __NODE_H__

#include "wchar.h"
#include <iostream>

class Node
{
private:
    
public:
    Node();             //constructor principal
    Node(int _elem);    //constructor pot parametro
    
    int elem;
    Node *next;

    void modific(int _elem);    //funcion para imprimir un nodo

    void print();       //funcion para immprimir un nodo

    friend std::ostream &operator << (std::ostream &,const Node &);

    ~Node();
};

//constructor principal
Node::Node()
{
    elem = NULL;
    next = NULL;
}

//constructor por parametro
Node::Node(int _elem)
{
    elem = _elem;
    next = NULL;
}

//funcionpara modificar un nodo
void Node::modific(int _elem)
{
    elem = _elem;
}

//funcion para imprimir un nodo
void Node::print(){
        //cout << "Nodo-> " << "Elemento: " << elem << " Direcion: " << this << " Siguiente: " << next << endl;
        std::cout << elem << "-> ";;
    }

//Sobrecarga
std::ostream &operator << (std::ostream &out, const Node &C){
    out << "Nodo-> " << "Elemento: " << C.elem << " Siguiente: " << C.next <<"\n";
    return out;
}

//Destructor
Node::~Node()
{
    if (next)
        next->~Node();
    delete this;
}


#endif