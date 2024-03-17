#include <iostream>
#include "flashcard/flashcard.h"
#include "deck/deck.h"
#include <fstream>

void read_file(std::vector<Deck> &decks){
    std::ifstream data;
    data.open("src/decks_data.txt");

    std::string mystring;

    while(std::getline(data, mystring)){
        std::cout << mystring << std::endl;
    }
}

void store_file(){

}

//this is where all the user interface should occur
void user_interface(std::vector<Deck> &decks){
    std::cout << "Welcome to VocalCards" << std::endl;
    std::cout << "[1] Study a deck: " << std::endl;

    for (int i = 0; i < decks.size(); i++){
        std::cout << i << " " << decks[i].get_name() << std::endl;
    }
    std::cout << "[2] Create a deck" << std::endl;
    std::cout << std::endl;

    int user = 0;
    std::cin >> user;

    switch(user){
        case 1:
            int deck_number = 0;

            std::cout << "Which deck?" << std::endl;
            std::cin >> deck_number;
            decks[deck_number].study();
        
    }
}

int main(){

    std::vector<Deck> decks;
    read_file(decks);

    /*
    Deck spanish_deck("Spanish");
    spanish_deck.create_card("Hello", "Hola");
    spanish_deck.create_card("My name is", "Me llamo es");

    decks.push_back(spanish_deck);
    */
   
    user_interface(decks);
    return 0;
}