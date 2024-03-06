#include <iostream>
#include "flashcard.h"
#include <queue>

bool operator<(Flashcard a, Flashcard b){
    return a.get_priority() < b.get_priority();
}

int main(){
    std::priority_queue<Flashcard> q1;

    Flashcard f1("1", "2");
    Flashcard f2("3", "4");

    q1.push(f1);
    q1.push(f2);

    while (q1.size() != 0){
        Flashcard temp = q1.top();
        q1.pop();
        std::cout << temp.get_front() << std::endl;
    }
}