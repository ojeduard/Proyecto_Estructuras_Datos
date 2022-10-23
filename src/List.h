//
// Created by Eduardo Ojeda on 20/10/22.
//

#ifndef PROYECTO_ESTRUCTURAS_DATOS_LIST_H
#define PROYECTO_ESTRUCTURAS_DATOS_LIST_H

#include <ostream>
#include "Node.h"

class List {
private:
    Node* Begin;
    std::string NamePerson;
    char direction;
public:
    char getDirection() const;
    void setDirection(char direction);
    List(Node* = nullptr,std::string = " ",char = ' ');
    void addRight(Node*);
    void addDown(Node*);
    void mostrarNext();
    void mostrarDown();
    void add(char,Node*);
    Node *getBegin() const;


};


#endif //PROYECTO_ESTRUCTURAS_DATOS_LIST_H
