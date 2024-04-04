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

        /*
        int record = 0;
        std::cout << "Record: [1]" << std::endl;
        std::cin >> record;

        if (record == 1){
            record = 0;

            std::cout << "recording" << std::endl;
            recorder.start();

            std::cout << "Exit: [1]" << std::endl;
            std::cin >> record;

            if (record == 1){
                std::cout << "recording ended" << std::endl;
                recorder.stop();
                recordingBuffer = recorder.getBuffer();
                recordingBuffer.saveToFile("recording.ogg");

                
                sound.setBuffer(recordingBuffer);
                sound.play();
            }
        }
        */

        int user_input = 0;
        while (user_input != 1){
            std::cout << "Reveal [1] Record [2]" << std::endl;
            std::cin >> user_input;

            if (user_input == 2){
                int record;

                std::cout << "recording" << std::endl;
                recorder.start();

                std::cout << "Stop Recording: [1]" << std::endl;
                std::cin >> record;

                if (record == 1){
                    std::cout << "recording ended" << std::endl;
                    recorder.stop();
                    recordingBuffer = recorder.getBuffer();
                    recordingBuffer.saveToFile("recording.ogg");
                }
            }
        }
    

        switch (user_input){
            case 1:
                std::cout << card.get_back() << std::endl;

                std::cout << "playing sound" << std::endl;
                sound.setBuffer(recordingBuffer);
                sound.play();
                
            
            case 2:
                int record;

                std::cout << "recording" << std::endl;
                recorder.start();

                std::cout << "Stop Recording: [1]" << std::endl;
                std::cin >> record;

                if (record == 1){
                    std::cout << "recording ended" << std::endl;
                    recorder.stop();
                    recordingBuffer = recorder.getBuffer();
                    recordingBuffer.saveToFile("recording.ogg");

                    
                    //sound.setBuffer(recordingBuffer);
                    //sound.play();
                }
        }

        int score;
        std::cout << "Fail [0] Pass [1]" << std::endl;
        std::cin >> score;

        deck.pop();
        card.update(score);
        deck.push(card);
        card = deck.top();

    
    }
}