//
// Created by Eduardo Ojeda on 13/10/22.
//

#include "Player.h"
#include <sstream>

Player::Player(const std::string &name, const std::vector<Node *> &letters) : name(name), letters(letters) {}

Player::Player(const std::string &name) : name(name) {;}

const std::string &Player::getName() const {
    return name;
}

void Player::setName(const std::string &name) {
    Player::name = name;
}

const std::vector<Node *> &Player::getLetters() const {
    return letters;
}

void Player::setLetters(const std::vector<Node *> &letters) {
    Player::letters = letters;
}

void Player::addLetter(Node* node) {
    letters.push_back(node);
}

Player::~Player() {

}

bool Player::LetterblockIsEmpty(){return letters.empty();}

std::string Player::getLettersasString() {
    std::string word = "";
    for(Node *letter : letters)
        word += letter->getLetter().getLetter();
        word += " ";

    return word;
}
bool Player::canBuildWord(std::string pal) {

    for (int i = 0; i < letters.size(); i++) {
        bool bandera = false;
        for (int j = 0; j < pal.length(); i++) {
            if (letters.at(i)->getLetter().getLetter() == pal.at(j))
                bandera = true;
        }
        if (!bandera)
            return false;
    }
    return true;
}

std::string Player::toString(){
    std::stringstream s;
    s<<"Player: "<<name<<" Available letters: ";
    for(Node* no: letters){
        s<<no->getLetter()<<" ";
    }
    return s.str();

}
Node* Player::getAt(char letter){


    for (int i = 0; i < letters.size(); i++) {
        if(letters.at(i)->getLetter().getLetter() == letter){
            Node* n = letters.at(i);
            letters.erase(letters.begin()+i);
            return n;
        }

    }

    return nullptr;
}

bool Player::isLetter(char letter){
    for (auto l : letters){
        if (l->getLetter().getLetter() == letter){
            return true;
        }
    }
    return false;
}

