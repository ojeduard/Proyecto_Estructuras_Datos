//
// Created by Eduardo Ojeda on 20/10/22.
//

#include "List.h"
#include <sstream>
#include <iostream>

List::List(Node* in,std::string name,char orientation){
    Begin = in;
    NamePerson = name;
    direction = orientation;
}

void List::mostrarNext(){

    Node* p = Begin;
    std::cout<<"Palabra Formada Por "<<NamePerson<<" :";
    while(p){
        if(p)
        std::cout<<p->getLetter().getLetter();
        p = p->getNext();
    }

}
void List::mostrarDown(){

    Node* p = Begin;
    std::cout<<"Palabra Formada Por "<<NamePerson<<" :";
    while(p){
        if(p)
        std::cout<<p->getLetter().getLetter();
        p = p->getNextDown();
    }

};
void List::addRight(Node* neW){
    Node* p = Begin;
    if(!p)
        Begin = neW;
    else{
        while(p->getNext()){
            p = p->getNext();
        }
        p->setNext(neW);
    }


}
void List::addDown(Node* neW){
    Node* p = Begin;
    if(!p)
        Begin = neW;
    else{
        while(p->getNextDown()){
            p = p->getNextDown();
        }
        p->setNextDown(neW);
    }

}

void List::add(char ori, Node * node) {
    if(ori == '1'){
        addDown(node);
    }
    if(ori == '2'){
        addRight(node);
    }
}

Node *List::getBegin() const {
    return Begin;
}

char List::getDirection() const {
    return direction;
}

void List::setDirection(char direction) {
    List::direction = direction;
}




