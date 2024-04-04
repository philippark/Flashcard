#include "deck.h"
#include "iostream"

Deck::Deck(){

}

Deck::Deck(std::string name_){
    name = name_;
}

std::string Deck::get_name(){
    return name;
}

void Deck::create_card(std::string front, std::string back){
    Flashcard card(front, back);
    deck.push(card);
}

void Deck::study(){
    if (deck.size() == 0){
        std::cout << "Nothing to study - Deck empty!" << std::endl;
        return;
    }

    std::cout << "STUDYING " << name << std::endl;

    sf::SoundBufferRecorder recorder;
    sf::SoundBuffer recordingBuffer;
    sf::Sound sound;

    if (!sf::SoundBufferRecorder::isAvailable()){
        std::cout << "Error: no sound buffer recording available" << std::endl;
    }

    Flashcard card = deck.top();
    while (card.get_interval() == 0){
        std::cout << std::endl;

        std::cout << card.get_front() << std::endl;

        int user_input = 0;
        while (user_input != 1){
            std::cout << "Reveal [1] Record [2]" << std::endl;
            std::cin >> user_input;

            if (user_input == 2){
                int record;

                recorder.start();

                std::cout << "Stop Recording: [1]" << std::endl;
                std::cin >> record;

                if (record == 1){
                    recorder.stop();
                    recordingBuffer = recorder.getBuffer();
                    recordingBuffer.saveToFile("recording.ogg");
                }
            }
        }

        
        sound.setBuffer(recordingBuffer);

        std::cout << card.get_back() << std::endl;

        int score = 0;
        while (score != 1 && score != 2){
            std::cout << "Fail [1] Pass [2] Play [3]" << std::endl;
            std::cin >> score;

            if (score == 3){
                sound.play();
            }
        }

        deck.pop();
        card.update(score);
        deck.push(card);
        card = deck.top();

    
    }
}