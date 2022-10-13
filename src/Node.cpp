//
// Created by Eduardo Ojeda on 13/10/22.
//

#include "Node.h"

const LetterBlock &Node::getLetter() const {
    return letter;
}

void Node::setLetter(const LetterBlock &letter) {
    Node::letter = letter;
}

Node *Node::getNext() const {
    return next;
}

void Node::setNext(Node *next) {
    Node::next = next;
}

std::ostream &operator<<(std::ostream &os, const Node &node) {
    os << "letter: " << node.letter << " next: " << node.next;
    return os;
}

Node::~Node() {

}
