#include <iostream>
#include "flashcard/flashcard.h"
#include "deck/deck.h"

//this is where all the user interface should occur
void interface(){

}

int main(){

    std::vector<Deck> decks;

    Deck spanish_deck("Spanish");
    spanish_deck.create_card("Hello", "Hola");
    spanish_deck.create_card("My name is", "Me llamo es");

    decks.push_back(spanish_deck);

    
    int user = 0;

    std::cout << "Welcome to VocalCards" << std::endl;
    std::cout << "[1] Study a deck: " << std::endl;
    for (int i = 0; i < decks.size(); i++){
        std::cout << i << " " << decks[i].get_name() << std::endl;
    }
    std::cout << "[2] Create a deck" << std::endl;
    std::cout << std::endl;

    std::cin >> user;

    switch(user){
        case 1:
            int deck_number = 0;

            std::cout << "Which deck?" << std::endl;
            std::cin >> deck_number;
            decks[deck_number].study();
        
    }
    return 0;
}