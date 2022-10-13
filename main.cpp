#include <iostream>
#include "DataBase.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    if (DataBase::searchWord("../data.txt", "MIAR")){
        std::cout<< "True";
    } else{
        std::cout << "False";
    }



    return 0;
}
