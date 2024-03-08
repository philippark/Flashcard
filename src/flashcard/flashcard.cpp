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

void Flashcard::update(){

}

bool operator<(Flashcard a, Flashcard b){
    return a.get_interval() < b.get_interval();
}