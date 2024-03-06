#ifndef FLASHCARD_H
#define FLASHCARD_H
#include <string>

class Flashcard{
public:
    Flashcard();
    Flashcard(std::string front, std::string back);
    std::string get_front();
    std::string get_back();


private:
    std::string front_;
    std::string back_;
    int priority_ = 0;
};

#endif