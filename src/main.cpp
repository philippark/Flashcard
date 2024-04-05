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
    bool quit = false;

    while (!quit){
        std::cout << "Welcome to VocalCards" << std::endl;

        /*
        std::cout << "Decks: " << std::endl;
        for (int i = 0; i < decks.size(); i++){
            std::cout << i << "-" << decks[i].get_name() << std::endl;
        }
        std::cout << std::endl;
        */

        std::cout << "[1] Study a deck" << std::endl;
        std::cout << "[2] Create a deck" << std::endl;
        std::cout << "[3] Quit" << std::endl;
        std::cout << std::endl;

        int user = 0;
        std::cout << "Choice: " << std::endl;
        std::cin >> user;

        switch(user){
            //study
            case 1: {
                int deck_number;

                std::cout << "Select Deck Number: ";
                std::cin >> deck_number;

                decks[deck_number].study();
            } break;

            //create
            case 2: {
                std::string name;

                std::cout << "Deck Name: " << std::endl;
                std::cin >> name;

                Deck new_deck = Deck(name);
                decks.push_back(new_deck);
            } break;

            //quit
            case 3: {
                quit = true;
            } break;
        }
    }
    std::cout << "[1] Study a deck" << std::endl;
    std::cout << "[2] Create a deck" << std::endl;
    std::cout << std::endl;

    int user = 0;
    std::cout << "Choice: " << std::endl;
    std::cin >> user;

    /*
    switch(user){
        //study
        case 1:
            std::cout << "Decks: " << std::endl;
            for (int i = 0; i < decks.size(); i++){
                std::cout << i << "-" << decks[i].get_name() << std::endl;
            }
            std::cout << std::endl;

            int deck_number;

            std::cout << "Select Deck Number: ";
            std::cin >> deck_number;

            decks[deck_number].study();
    
        //create
        case 2:
        std::string name;

        std::cout << "Deck Name: " << std::endl;
        std::cin >> name;

        Deck new_deck = Deck(name);
        decks.push_back(new_deck);

    }
    */
        
}

int main(){

    std::vector<Deck> decks;
    //read_file(decks);

    Deck spanish("Spanish");
    spanish.create_card("Hello", "Hola");

    decks.push_back(spanish);

   
    user_interface(decks);
    return 0;
}