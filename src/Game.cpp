//
// Created by andre on 13/10/2022.
//

#include "Game.h"
#include <ctime>
Game::Game() {
    players = new std::vector<Player>;
    board = new Board();
    availableletters[0] ='A'; availableletters[1] = 'E';availableletters[2] = 'I';availableletters[3] = 'O';availableletters[4] = 'U';
    availableletters[5] = 'R';availableletters[6] = 'S';availableletters[7] = 'T';availableletters[8] = 'M';availableletters[9] = 'C';
    WordsForm = new std::vector<List>;
}

Game::~Game() {
    delete board;
    delete players;
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
        players->push_back(Jug);

}
bool Game::isOver(){
    for(Player p: *players){
        if(p.LetterblockIsEmpty())
            return true;
    }
    return false;
}
Player Game::Winner(){
    for(Player p: *players){
        if(p.LetterblockIsEmpty())
            return p;
    }
}

Board *Game::getBoard() const {
    return board;
}

void Game::setBoard(Board *board) {
    Game::board = board;
}

bool Game::isInDAO(std::string word) {
    return DataBase::searchWord(word);
}

std::vector<Player> *Game::getPlayers() const {
    return players;
}
void Game::devuelveLetras(std::string pal,Player& jug){
    for(int i=0;i<pal.size();i++){
        char letra = pal.at(i);
        LetterBlock letr(letra);
        Node* n = new Node(letr);
        jug.addLetter(n);
    }

}

std::vector<List> *Game::getWordsForm() const {
    return WordsForm;
}

void Game::setWordsForm(std::vector<List> *wordsForm) {
    WordsForm = wordsForm;
}



