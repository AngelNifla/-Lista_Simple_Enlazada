#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

#include "Node.h"
#include <string>
#include <iostream>
#include <stdlib.h>


class LinkedList
{
private:
    int size;
    Node *head;
public:
    LinkedList();
    LinkedList(int _size);
    void insert_node(int _size);
    void insert_node_size(int _size);
    void modificar_node_lista(int _pos,int _elem);
    void remove(int _pos);
    void print();

    
    
    int getsize() const{
        return size;
    }
    Node* gethead() const{
        return head;
    }
    ~LinkedList();
};

//constructor principal
LinkedList::LinkedList()
{
    size = NULL;
    head = NULL;
}

//funcion para insertar un nodo a la lista
void LinkedList::insert_node(int _dato)
{
    Node *new_Node = new Node(_dato);
    Node *aux = head;

    if (!head) {
        head = new_Node;
    } else {
        if (head->get_elem() > _dato) {
            new_Node->set_next(head);
            head = new_Node;
        } else {
            while ((aux->get_next() != NULL) && (aux->get_next()->get_elem() < _dato)) {
                aux = aux->get_next();
            }
            new_Node->set_next(aux->get_next());
            aux->set_next(new_Node);
        }
    }
    size++;
}

//funcion para insertar nodos a la lista
void LinkedList::insert_node_size(int _size)
{
    for (int i = 0; i < _size; i++) {
        insert_node(NULL);
    }
}


// MOdificar un nodo de la lista
void LinkedList::modificar_node_lista(int _pos,int _elem)
{
    Node *aux = head;

    if (_pos < 1 || _pos > size) {
        std::cout << "Fuera de rango \n";
    } else {
        for (int i = 1; i <= _pos; i++) {
            if (i == _pos) {
                aux->modific(_elem);
            }
            aux = aux->get_next();
            
        }
    }
}

// Eliminar un nodo por posicion
void LinkedList::remove(int _pos)
{
    Node *aux = head;
    Node *aux1 = aux->get_next();
 
    if (_pos < 1 || _pos > size) {
        std::cout << "Fuera de rango \n";
    } else if (_pos == 1) {
        head = aux->get_next();
    } else {
        for (int i = 2; i <= _pos; i++) {
            if (i == _pos) {
                Node *aux_node = aux1;
                aux->set_next(aux1->get_next());
                delete aux_node;
                size--;
            }
            aux = aux->get_next();
            aux1 = aux1->get_next();
        }
    }
}

//imprimir lista de nodos
void LinkedList::print()
{
    Node *aux = head;
    if (!head) {
        std::cout << "La Lista está vacía \n";
    } else {
        while (aux) {
            aux->print();
            if (!aux->get_next()) std::cout << "vacio";
                aux = aux->get_next();
        }
  }
  std::cout <<"\n\n";
}

std::ostream& operator << (std::ostream &o, const LinkedList &_DA){
    Node *aux= _DA.gethead();

    for(int i=1; i<=_DA.getsize(); i++){
		o << "Nodo-> " << "Elemento: " <<aux->get_elem()<<" Siguiente: " << aux->get_next() <<"\n";
        aux = aux->get_next();
	}
    
    return o;
}

//Destructor
LinkedList::~LinkedList()
{
    head->~Node();
    head = 0;
}


#endif