all: compile link

compile:
	g++ -c src/main.cpp -IC:\sfml\src\include -I:
	g++ -c src/flashcard/flashcard.cpp -IC:\sfml\src\include -I:
	g++ -c src/deck/deck.cpp -IC:\sfml\src\include -I:
	g++ -c src/audio.cpp -IC:\sfml\src\include -I:

link:
	g++ main.o flashcard.o deck.o -o main -LC:\sfml\src\lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio 
	g++ audio.o -o audio -LC:\sfml\src\lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio 

clean:
	rm -f main *.o