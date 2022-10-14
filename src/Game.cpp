//
// Created by andre on 13/10/2022.
//

#include "Game.h"
#include <ctime>
Game::Game() {
    Players = new std::vector<Player>;
    board = new Board();
    availableletters[0] ='a'; availableletters[1] = 'e';availableletters[2] = 'i';availableletters[3] = 'o';availableletters[4] = 'u';
    availableletters[5] = 'r';availableletters[6] = 's';availableletters[7] = 't';availableletters[8] = 'm';availableletters[9] = 'c';
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

bool Game::validacionPalabrasegunFichas(std::string pal, Player pl) {

    return false;
}
