//
// Created by andre on 13/10/2022.
//

#ifndef PROYECTO_ESTRUCTURAS_DATOS_BOARD_H
#define PROYECTO_ESTRUCTURAS_DATOS_BOARD_H
#include "Node.h"
#include "List.h"
#include <sstream>
#include <iostream>
class Board {
private:
    Node *board [11][11];
public:
    Board();
    virtual~Board();
    std::string toString();
    void addNode(Node*, int, int);
    Node* isEmpty(int,int);
    bool centerEmpty();
    void addToBoard(char type, List, int, int);
    void addVer(List, int, int);
    void addHor(List, int, int);
    void reset();
    bool PrePlay(int,int,int,char);
    bool validWord(int,int,char);


};


#endif //PROYECTO_ESTRUCTURAS_DATOS_BOARD_H
