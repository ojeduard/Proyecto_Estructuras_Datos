//
// Created by andre on 13/10/2022.
//

#include "Board.h"
Board::Board(){
    for(int i=0;i<11;i++) {
        for (int j = 0; j < 11; j++) { //Ingreso de la primera fila y primera columna por default
            if (i == 0 && j == 0)
                board[i][j] = new Node(LetterBlock(' '));
            else if (i == 0) {
                char word = 'a' + (j - 1);
                board[i][j] = new Node(LetterBlock(word));
            } else if (j == 0) {
                board[i][j] = new Node(LetterBlock('0' + i-1));
            }
            else
                board[i][j] = new Node(LetterBlock('-'));
        }
    }
}

std::string Board::toString() {
    std::stringstream s;
    for(int i=0;i<11;i++) {
        for (int j = 0; j < 11; j++) {
            s << board[i][j]->getLetter().getLetter() << "  ";
        }
        s<<std::endl;
    }
    return s.str();

}

void Board::addNode(Node * ingreso, int fila, int columnna) {
        if(fila < 11 && columnna < 11)
            board [fila][columnna] = ingreso;
        else
            std::cout<<"Ficha no Ingresada"<<std::endl;
}

Board::~Board() {

}
Node* Board::isEmpty(int x,int y){
    return board[x][y];
}
bool Board::centerEmpty(){
   if(isEmpty(4,5)||isEmpty(4,4)||isEmpty(5,4)||isEmpty(5,5))
   return false;
   return true;
}

