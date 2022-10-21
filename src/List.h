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
public:
    List(Node* = nullptr);
    void addRight(Node*);
    void addDown(Node*);
    std::string toString();
};


#endif //PROYECTO_ESTRUCTURAS_DATOS_LIST_H
