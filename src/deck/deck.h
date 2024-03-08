#ifndef DECK_H
#define DECK_H
#include <queue>
#include "flashcard/flashcard.h"

class Deck{
public:
    Deck();
    void study();
private:

    //need flashcard operator<
    std::priority_queue<Flashcard> deck;
};
#endif