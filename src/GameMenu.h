//
// Created by Eduardo Ojeda on 16/10/22.
//

#ifndef PROYECTO_ESTRUCTURAS_DATOS_GAMEMENU_H
#define PROYECTO_ESTRUCTURAS_DATOS_GAMEMENU_H
#include "Game.h"
#include "vector


class GameMenu {
private:
    Game* game;

public:
    GameMenu();

    void mainMenu();
    void secondMenu();
    void insertPlayer(int);
    void startGame();
    bool firstPlay(Player& player);
    virtual ~GameMenu();

};


#endif //PROYECTO_ESTRUCTURAS_DATOS_GAMEMENU_H

// 1. Play
// 0. Exit

// -------- Opcion 1 ------
// 1. Two pLayers
// 2. Three players
// 3. Four players

// ----- Cualwuier opcion ----
// Solicitar el nombre de cada jugador y enviarlos por parametro a game para que les asignee las letras (add)


