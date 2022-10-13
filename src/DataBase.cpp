//
// Created by Eduardo Ojeda on 13/10/22.
//

#include "DataBase.h"


bool DataBase::searchWord(std::string fileName, std::string word) {
    // create a file
    std::ifstream file(fileName);
    std::string line;
    int offset;

    // Check if it is open
    if (!file.is_open()){
        throw std::invalid_argument("File " + fileName  + "is not available.");
    }

    // Check line by line
    while (!file.eof()){
        getline(file, line);

        // Could be this way
//        if (offset = line.find(word, 0) != std::string::npos){
//            file.close();
//            return true;
//        }

        // Could be this way 2
        if (line == word){
            file.close();
            return true;
        }
    }

    // Always close the file
    file.close();
    return false;

}
