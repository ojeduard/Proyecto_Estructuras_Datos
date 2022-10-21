//
// Created by Eduardo Ojeda on 16/10/22.
//

#include "GameMenu.h"
GameMenu::GameMenu() {
    game = new Game();
    mainMenu();
}

void GameMenu::insertPlayer(int select) {
    std::string name;
    for(int i=0;i<select;i++){
        std::cout<<"\tPlayer #"<<i+1<<std::endl;
        std::cout<<"Enter the name of the player: ";
        std::cin>>name;
        Player pl(name);
        game->addPlayer(pl);
        system("clear");
    }
    startGame();

}

void GameMenu::mainMenu() {
    char select = '0';

    do {
        std::cout << "\tWELCOME TO THE UNA-SCRABBLE" << std::endl << std::endl;
        std::cout << "\tSelect an option" << std::endl;
        std::cout << "1. Play " << std::endl;
        std::cout << "0. Exit " << std::endl;

        std::cin >> select;



        if ( select == '1'){
            system("clear");
            secondMenu();
        }


    }while(select != '0');
    system("clear");



}

GameMenu::~GameMenu() {
}

void GameMenu::secondMenu() {
    char select = '0';

    do {
        std::cout << "\tPLAY MODE" << std::endl << std::endl;
        std::cout << "\tSelect an option" << std::endl << std::endl;
        std::cout << "1. Two Players " << std::endl;
        std::cout << "2. Three Players " << std::endl;
        std::cout << "3. Four Players " << std::endl;
        std::cout << "0. Exit " << std::endl;

        std::cin >> select;

        switch (select) {
            case  '1' :
                system("clear");
                insertPlayer(2); break;
            case '2':
                system("clear");
                insertPlayer(3); break;
            case '3':
                system("clear");
                insertPlayer(4);
            default: std::cout<<"Opcion Invalida"<<std::endl;
        }
        select = '0';

    } while (select != '0');
    system("clear");

}

void GameMenu::startGame() {
    int play = 0; //if play is 0, it means it is the first play
    while (!game->isOver()){
        for (Player p : *game->getPlayers()){

            // Not first play
            if (play != 0 ){
                afterFirstPlay(p);
            }else{
                // First play
                if (firstPlay(p)){
                    play++;
                }
            }
            // Validate if there are LetterBlocks
            if (game->isOver())
                break;
        }
        system("clear");

    }
    std::cout<<"El ganador es: "<<game->Winner().getName()<<std::endl;
    std::cout<<"El ganador es: "<<"FELICIDADES!"<<std::endl;


}

bool GameMenu::firstPlay(Player &player) {
    char select = '0';
    bool playOver = false;
    char letter;
    char column;
    int row;
    int column2;
    int cont = 0;
    int continu = 1;
    std::string word = "";
    List aux;
    std::cout << game->getBoard()->toString();

    do {

        std::cout << "\tSelect your move " << std:: endl << std:: endl;
        std::cout << "1. Vertical " << std:: endl;
        std::cout << "2. Horizontal " << std:: endl;
        std::cin >> select;

    }while(select != '1' && select != '2' );

    while (!playOver){
        system("clear");


        while(cont == 0){
            std::cout << "Enter the column of the letter(a-i)";
            std::cin >> column;
            column = toupper(column);
            column2 = column - 64;
            std::cout << "Enter the line of the letter(0-8)";
            std::cin >> row;
            if(column2 < 10 && row < 9 )

                cont++;
            else
                std::cout<<"Posicion Incorrecta, Ingrese de Nuevo"<<std::endl;
        }
        if(word.size() > 0)
            std::cout<<"Palabra formandose: "<<word <<std::endl;

        std::cout << player.toString()<<std::endl;
        std::cout << "Enter your letter: "; std::cin>>letter;

        if (player.isLetter(letter)){
            aux.add(select,player.getAt(letter));
            word += letter;
            std::cout << "Do you want to add another letter? (PRESS 0) ";
            std::cin >> playOver;
            std::cout<<word<<std::endl;
        }else {
            std::cout << "The letter does not exist!";
            system("pause");

        }

    }

    game->getBoard()->PrePlay(row+1, column2, word.size(), select);
    std::cout<<game->getBoard()->toString()<<std::endl;
    if (game->getBoard()->centerEmpty() && DataBase::searchWord(word)){
        std::cout<<"Jugada Valida "<<std::endl;
        game->getBoard()->addToBoard(select, aux, column2, row+1);
        std::cout << game->getBoard()->toString()<<std::endl;
        return true;
    }else{
        std::cout<<"Jugada Invalida, turno del siguiente jugador "<<std::endl;
        game->devuelveLetras(word,player);
        game->getBoard()->reset();
        std::cout<<player.toString()<<std::endl;
        return false;
    }
}

bool GameMenu::afterFirstPlay(Player &player) {
    std::cout << game->getBoard()->toString();

    return false;
}




