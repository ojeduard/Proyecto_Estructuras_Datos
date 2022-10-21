//
// Created by Eduardo Ojeda on 20/10/22.
//

#include "List.h"
#include <sstream>
List::List(Node* in){
    Begin = in;
}

std::string List::toString(){
    std::stringstream s;
    Node* p = Begin;
    s<<"Palabra: ";
    while(p){
        s<<p->getLetter().getLetter();
        p = p->getNext();
    }
    return s.str();
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


