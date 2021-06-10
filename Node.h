#ifndef  __NODE_H__
#define  __NODE_H__

#include "wchar.h"
#include <iostream>

class Node
{
private:
    int elem;
    Node *next;
public:
    Node();             //constructor principal
    Node(int _elem);    //constructor pot parametro
    
    

    void modific(int _elem);    //funcion para imprimir un nodo

    void print();       //funcion para immprimir un nodo
    int get_elem(){
        return elem;
    };
    void set_elem(int _elem){
        elem = _elem;
    }
    void set_next(Node*_next){
        next = _next;
    }
    Node* get_next(){
        return next;
    };


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