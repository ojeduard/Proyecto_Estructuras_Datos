//
// Created by andre on 13/10/2022.
//

#ifndef PROYECTO_ESTRUCTURAS_DATOS_GAME_H
#define PROYECTO_ESTRUCTURAS_DATOS_GAME_H
#include "Player.h"
#include "Board.h"

class Game {
private:
    std::vector<Player>* Players;
    char availableletters[10];
    Board* board;
public:
    Game();
    virtual ~Game();
    void addPlayer(Player &Jug);
    bool validacionPalabrasegunFichas(std::string,Player);



};


#endif //PROYECTO_ESTRUCTURAS_DATOS_GAME_H
