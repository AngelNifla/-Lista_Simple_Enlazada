#include <iostream>
 
#include "LinkedList.h"

using namespace std;
 
int main()
{
    /*
    Node N1(15);

    cout<<N1<<endl;

    LinkedList L0;
    L0.insert_node(8);
    L0.insert_node(12);

    cout<<L0<<endl;
     */ 
    LinkedList L1;

    int elem;
    int size;
    int pos;
    int pos1;

    L1.print();
    cout << "Ingresa la dimension de la lista: " << endl;
    cin >> size;

    L1.insert_node_size(size);

    cout << "Lista Inicial" << endl;
    L1.print();
 
    cout << "Agrega un elemento a la lista: " << endl;
    cin >> elem;
    L1.insert_node(elem);
    L1.print();
    
    cout << "modificar un elemento de la lista: " << endl;
    cout << "posicion del elemento: ";
    cin >> pos;
    cout << "elemento nuevo: ";
    cin>> elem;
    L1.modificar_node_lista(pos,elem);
    L1.print();

    cout << "Elimina un elemento por posicion: " << endl;
    cin >> pos1;
    L1.remove(pos1);
    L1.print();
 
    L1.~LinkedList();
  
    return 0;
}
