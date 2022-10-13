//
// Created by Eduardo Ojeda on 13/10/22.
//

#ifndef PROYECTO_ESTRUCTURAS_DATOS_NODE_H
#define PROYECTO_ESTRUCTURAS_DATOS_NODE_H

#include <ostream>
#include "LetterBlock.h"


class Node {
private:
    LetterBlock letter;
    Node * next;

public:
    Node(LetterBlock = nullptr, Node* = nullptr);

    const LetterBlock &getLetter() const;

    void setLetter(const LetterBlock &letter);

    Node *getNext() const;

    void setNext(Node *next);

    friend std::ostream &operator<<(std::ostream &os, const Node &node);

    virtual ~Node();

};


#endif //PROYECTO_ESTRUCTURAS_DATOS_NODE_H
