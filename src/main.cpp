#include <iostream>
#include "flashcard/flashcard.h"
#include "deck/deck.h"


int main(){

    Deck spanish_deck;

    Flashcard c1("hello", "hola");
    Flashcard c2("my name is", "me llamo es");

    spanish_deck.add_card(c1);
    spanish_deck.add_card(c2);

    spanish_deck.study();

    return 0;
}