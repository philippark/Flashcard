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


void Flashcard::update(){
    
}