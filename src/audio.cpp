#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

int main(){

    if (!sf::SoundBufferRecorder::isAvailable()){
        std::cout << "Error: no sound buffer recording avaialble" << std::endl;
    }

    sf::SoundBufferRecorder recorder;


    recorder.start();
    sf::SoundBuffer recordingBuffer;

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



    

}