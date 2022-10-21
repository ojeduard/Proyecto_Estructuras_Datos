//
// Created by Eduardo Ojeda on 13/10/22.
//

#ifndef PROYECTO_ESTRUCTURAS_DATOS_PLAYER_H
#define PROYECTO_ESTRUCTURAS_DATOS_PLAYER_H
#include "Node.h"
#include "String"
#include "vector"


class Player {
private:
    // Define players
    std::string name;
    std::vector<Node*> letters; // This STL or better linked list


public:
    Player(const std::string &name, const std::vector<Node *> &letters);

    Player(const std::string &name);

    const std::string &getName() const;

    void setName(const std::string &name);

    const std::vector<Node *> &getLetters() const;

    void setLetters(const std::vector<Node *> &letters);

    void addLetter(Node* node);

    std::string getLettersasString();
    
    bool canBuildWord(std::string);

    bool LetterblockIsEmpty();

    Node* getAt(char);

    virtual ~Player();

    std::string toString();

    bool isLetter(char letter);



};


#endif //PROYECTO_ESTRUCTURAS_DATOS_PLAYER_H
