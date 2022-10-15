//
// Created by andre on 13/10/2022.
//

#include "Game.h"
#include <ctime>
Game::Game() {
    Players = new std::vector<Player>;
    board = new Board();
    availableletters[0] ='A'; availableletters[1] = 'E';availableletters[2] = 'I';availableletters[3] = 'O';availableletters[4] = 'U';
    availableletters[5] = 'R';availableletters[6] = 'S';availableletters[7] = 'T';availableletters[8] = 'M';availableletters[9] = 'C';
}

Game::~Game() {
    delete board;
    delete Players;
}

void Game::addPlayer(Player& Jug) {
    int cont = 0;
    srand(time(nullptr));
    while(cont < 6){ //se le dan las letras de manera aleatoria al jugador
        int valRandom = rand()%10;
        char letra = availableletters[valRandom];
        LetterBlock ficha(letra);
        Jug.addLetter(new Node(ficha));
        cont++;
    }
    Players->push_back(Jug);
}


