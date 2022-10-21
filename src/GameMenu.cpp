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

                std::cout << "FUNCIONA" << std:: endl;
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
    std::vector<Node*> aux;
    std::cout << game->getBoard()->toString();

    do {

        std::cout << "\tSelect your move " << std:: endl << std:: endl;
        std::cout << "1. Vertical " << std:: endl;
        std::cout << "2. Horizontal " << std:: endl;
        std::cin >> select;

    }while(select != '1' && select != '2' );

    while (!playOver){
        system("clear");
        if(word.size() > 0)
            std::cout<<"Palabra formandose: "<<word <<std::endl;

        std::cout << player.toString();
        std::cout << "Available letters" << std::endl;
        std::cout << player.toString();


        if (select == '1') {
            if (cont == 0) {
                std::cout << "Enter the column of the letter(a-j)";
                std::cin >> column;
                column = toupper(column);
                column2 = column - 64;
                std::cout << "Enter the line of the letter(0-9)";
                std::cin >> row;
                cont++;
            }
            std::cout << "Enter your letter: "; std::cin>>letter;


            if (player.getAt(letter)){
                aux.push_back(player.getAt(letter));
                word += letter;


                std::cout << "Do you want to add another letter? (PRESS 0) ";
                std::cin >> playOver;




            }else {
                std::cout << "The letter does not exist!";
                system("pause");

            }

        }

    }

    if (game->getBoard()->centerEmpty() && DataBase::searchWord(word)){
        return true;
    }
    return false;


}

bool GameMenu::afterFirstPlay(Player &player) {
    std::cout << game->getBoard()->toString();

    return false;
}




