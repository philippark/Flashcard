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

    Flashcard card = deck.top();
    while (card.get_interval() == 0){
        std::cout << std::endl;

        std::cout << card.get_front() << std::endl;

        //record
        if (!sf::SoundBufferRecorder::isAvailable()){
            std::cout << "Error: no sound buffer recording available" << std::endl;
        }

        sf::SoundBufferRecorder recorder;
        sf::SoundBuffer recordingBuffer;

        recorder.start();

        
        sf::RenderWindow window(sf::VideoMode(800, 800), "My window");
        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event)) // This function has been renamed to PollEvent in SFML 2.0
            {
                if (event.type == sf::Event::Closed){
                    recorder.stop();
                    recordingBuffer = recorder.getBuffer();
                    recordingBuffer.saveToFile("recording.ogg");
                    window.close();
                }

            }
        }

        sf::Sound sound;
        sound.setBuffer(recordingBuffer);
        sound.play();

        std::cout << "[Reveal? [1]]" << std::endl;

        int user_input;
        std::cin >> user_input;

        switch (user_input){
            case 1:
                std::cout << card.get_back() << std::endl;
        }

        int score;
        std::cout << "Fail [0], Pass [1]" << std::endl;
        std::cin >> score;
        std::cout << "score: " << score << std::endl;
        
        deck.pop();
        card.update(score);
        std::cout << "card updated interval: " << card.get_interval() << std::endl;
        deck.push(card);
        card = deck.top();

        std::cout << "new top: " << card.get_front() << std::endl;

    }
}