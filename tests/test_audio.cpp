#include <iostream>
#include "flashcard/flashcard.h"
#include "deck/deck.h"
#include <fstream>

void read_deck(std::string deck_name){
    std::cout << deck_name << std::endl;
    std::ifstream file("data/" + deck_name);
    std::string data;

    while (std::getline(file, data)){
        std::cout << data << std::endl;
    }
}

void read_file(std::vector<Deck> &decks){
    std::ifstream file;
    file.open("data/decks_data.txt");

    std::string deck_name;

    while(std::getline(file, deck_name)){
        std::cout << deck_name << std::endl;
        Deck deck(deck_name);

        //open, and read the data file. in sep method
        read_deck(deck_name + ".txt");


        decks.push_back(deck);
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
   
    user_interface(decks);
    return 0;
}