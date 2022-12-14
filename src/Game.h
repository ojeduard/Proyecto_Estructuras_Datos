//
// Created by andre on 13/10/2022.
//

#ifndef PROYECTO_ESTRUCTURAS_DATOS_GAME_H
#define PROYECTO_ESTRUCTURAS_DATOS_GAME_H
#include "Player.h"
#include "Board.h"
#include "DataBase.h"
#include "List.h"

class Game {
private:
    std::vector<Player>* players;
    char availableletters [10];
    Board* board;
    std::vector<List>* WordsForm;
public:
    std::vector<List> *getWordsForm() const;

    void setWordsForm(std::vector<List> *wordsForm);
    Game();
    virtual ~Game();
    void addPlayer(Player &Jug);
    bool isOver();
    Player Winner();

    void setBoard(Board *board);
    bool isInDAO(std::string word);


    Board *getBoard() const;

    std::vector<Player> *getPlayers() const;

    void devuelveLetras(std::string,Player&);
};


#endif //PROYECTO_ESTRUCTURAS_DATOS_GAME_H
