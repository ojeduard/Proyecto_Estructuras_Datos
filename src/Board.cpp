//
// Created by andre on 13/10/2022.
//

#include "Board.h"
#include "List.h"
Board::Board(){
    for(int i=0;i<10;i++) {
        for (int j = 0; j < 10; j++) { //Ingreso de la primera fila y primera columna por default
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
    for(int i=0;i<10;i++) {
        for (int j = 0; j < 10; j++) {
            s << board[i][j]->getLetter().getLetter() << "  ";
        }
        s<<std::endl;
    }
    return s.str();

}

void Board::addNode(Node * ingreso, int fila, int columnna) {
        if(fila < 10 && columnna < 10)
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
   if(isEmpty(5,5)->getLetter().getLetter() == '-')
       return false;
   return true;
}
void Board::addHor(List list, int column, int row){
    Node * aux = list.getBegin();
    while(aux){
        board[row][column++] = aux;
        aux = aux->getNext();
    }
}

void Board::addToBoard(char type, List list, int column, int row) {
    if (type == '1'){
        Board::addVer(list, column, row);
    }else if (type == '2'){
        Board::addHor(list, column, row);
    } else{
        throw std::invalid_argument ("Not selected (Vertical or Horizontal)");
    }

}

void Board::addVer(List list, int column, int row){
    Node * aux = list.getBegin();
    while(aux){
        board[row++][column] = aux;
        aux = aux->getNextDown();

    }

}
void Board::reset(){
    for(int i=0;i<10;i++) {
        for (int j = 0; j < 10; j++) { //Ingreso de la primera fila y primera columna por default
            if(board[i][j]->getLetter().getLetter() == '*')
                board[i][j]->setLetter(LetterBlock('-'));
        }
    }
}
bool Board::PrePlay(int f,int c,int tam,char ori){
    if(ori == '1'){
        for(int i=0;i<tam;i++)
            if(f < 10)
                board[f++][c]->setLetter(LetterBlock('*'));
            else return false;

    }
    if(ori == '2'){
        for(int i=0;i<tam;i++)
            if(c < 10)
                board[f][c++]->setLetter(LetterBlock('*'));
            else return false;
    }
    return true;
}




//