//
// Created by Eduardo Ojeda on 13/10/22.
//

#include "Player.h"


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

std::string Player::getLettersasString() {
    std::string word = "";
    for(Node *letter : letters)
        word += letter->getLetter().getLetter();

    return word;
}
