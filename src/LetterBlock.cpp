//
// Created by Eduardo Ojeda on 13/10/22.
//

#include "LetterBlock.h"

LetterBlock::LetterBlock(char letter) : letter(letter) {}

LetterBlock::LetterBlock() {}

char LetterBlock::getLetter() const {
    return letter;
}

void LetterBlock::setLetter(char letter) {
    LetterBlock::letter = letter;
}

std::ostream &operator<<(std::ostream &os, const LetterBlock &block) {
    os << "letter: " << block.letter;
    return os;
}

LetterBlock::~LetterBlock() {

}
