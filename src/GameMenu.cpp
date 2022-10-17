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
        std::cout << game->getBoard()->toString();

        for (Player p : *game->getPlayers()){
            // Not first play
            if (play != 0 ){


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
    std::vector<Node> aux;

    do {

        std::cout << "\tSelect your move " << std:: endl << std:: endl;
        std::cout << "1. Vertical " << std:: endl;
        std::cout << "2. Horizontal " << std:: endl;
        std::cin >> select;

    }while(select != '1' && select != '2' );

    while (!playOver){
        std::cout << "Available letters" << std::endl;
        player.getLetters();

        std::cout << "Enter your letter: "; std::cin>>letter;
        LetterBlock letterBlock(letter);

    }
}



