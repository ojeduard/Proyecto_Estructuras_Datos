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
    Node * nextDown;



public:
    Node(LetterBlock l , Node* = nullptr,Node* = nullptr);

    Node *getNextDown() const;

    void setNextDown(Node *nextDown);

    const LetterBlock &getLetter() const;

    void setLetter(const LetterBlock &letter);

    Node *getNext() const;

    void setNext(Node *next);


    friend std::ostream &operator<<(std::ostream &os, const Node &node);

    virtual ~Node();

};


#endif //PROYECTO_ESTRUCTURAS_DATOS_NODE_H
