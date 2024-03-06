all: compile link

compile:
	g++ -c main.cpp -IC:\sfml\src\include -I:
	g++ -c flashcard.cpp -IC:\sfml\src\include -I:

link:
	g++ main.o flashcard.o -o main -LC:\sfml\src\lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio 


clean:
	rm -f main *.o