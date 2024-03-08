all: compile link

compile:
	g++ -c main.cpp -IC:\sfml\src\include -I:
	g++ -c flashcard/flashcard.cpp -IC:\sfml\src\include -I:
	g++ -c deck/deck.cpp -IC:\sfml\src\include -I:

link:
	g++ main.o flashcard.o deck.o -o main -LC:\sfml\src\lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio 


clean:
	rm -f main *.o