#include "flashcard.h"

Flashcard::Flashcard(){
}

Flashcard::Flashcard(std::string front, std::string back){
    front_ = front;
    back_ = back;
}

std::string Flashcard::get_front(){
    return front_;
}

std::string Flashcard::get_back(){
    return back_;
}

int Flashcard::get_priority(){
    return priority_;
}

int Flashcard::get_interval(){
    return interval;
}

void Flashcard::update(int score){
    switch (score){
        //failed
        case 0:
            interval = 0;
            break;
        //passed
        case 1:
            interval++;
            break;
    }
}

bool operator<(Flashcard a, Flashcard b){
    return a.get_interval() > b.get_interval();
}