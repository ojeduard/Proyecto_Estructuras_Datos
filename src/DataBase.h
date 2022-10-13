//
// Created by Eduardo Ojeda on 13/10/22.
//

#ifndef PROYECTO_ESTRUCTURAS_DATOS_DATABASE_H
#define PROYECTO_ESTRUCTURAS_DATOS_DATABASE_H
#include <String>
#include <fstream>


class DataBase {
public:
    // Searching a word in the txt file
    bool static searchWord(std::string fileName, std::string word);

};


#endif //PROYECTO_ESTRUCTURAS_DATOS_DATABASE_H
