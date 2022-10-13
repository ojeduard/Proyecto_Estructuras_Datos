//
// Created by Eduardo Ojeda on 13/10/22.
//

#ifndef PROYECTO_ESTRUCTURAS_DATOS_LETTERBLOCK_H
#define PROYECTO_ESTRUCTURAS_DATOS_LETTERBLOCK_H


#include <ostream>

class LetterBlock {
private:
    // All chars needed to create words one by one
    char letter;
public:
    LetterBlock(char letter);

    LetterBlock();

    char getLetter() const;

    void setLetter(char letter);

    friend std::ostream &operator<<(std::ostream &os, const LetterBlock &block);

    virtual ~LetterBlock();


};


#endif //PROYECTO_ESTRUCTURAS_DATOS_LETTERBLOCK_H
