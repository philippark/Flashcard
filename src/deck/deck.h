#ifndef DECK_H
#define DECK_H
#include <queue>
#include "../flashcard/flashcard.h"


class Deck{
public:
    Deck();
    void add_card(Flashcard card);
    void study();
private:
    std::priority_queue<Flashcard> deck;
};
#endif