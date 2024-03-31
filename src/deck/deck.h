#ifndef DECK_H
#define DECK_H
#include <queue>
#include "../flashcard/flashcard.h"
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Deck{
public:
    Deck();
    Deck(std::string name_);
    void create_card(std::string front, std::string back);
    void study();
    std::string get_name();
private:
    std::priority_queue<Flashcard> deck;
    std::string name = "Unnamed";
};
#endif