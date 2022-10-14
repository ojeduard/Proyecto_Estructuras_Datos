#include <iostream>
#include "DataBase.h"

int main() {
//    std::cout << "Hello, World!" << std::endl;
//
//    if (DataBase::searchWord("../data.txt", "MIAR")){
//        std::cout<< "True";
//    } else{
//        std::cout << "False";
//    }
    int cont = 0;
    srand(time(nullptr));
    while(cont < 6){

        int valRandom = rand()%10;
        std::cout<<valRandom<<std::endl;
        cont++;
    }


    return 0;
}
