#include "deck.h"
#include "iostream"

Deck::Deck(){

}

void Deck::add_card(Flashcard card){
    deck.push(card);
}

void Deck::study(){
    if (deck.size() == 0){
        std::cout << "Nothing to study - Deck empty!" << std::endl;
        return;
    }

    Flashcard card = deck.top();
    while (card.get_interval() == 0){
        std::cout << std::endl;

        std::cout << card.get_front() << std::endl;
        std::cout << "[Reveal? [1]]" << std::endl;

        int user_input;
        std::cin >> user_input;

        switch (user_input){
            case 1:
                std::cout << card.get_back() << std::endl;
        }

        int score;
        std::cout << "Fail [0], Pass [1]" << std::endl;
        std::cin >> score;
        std::cout << "score: " << score << std::endl;
        
        deck.pop();
        card.update(score);
        std::cout << "card updated interval: " << card.get_interval() << std::endl;
        deck.push(card);
        card = deck.top();

        std::cout << "new top: " << card.get_front() << std::endl;

    }
}