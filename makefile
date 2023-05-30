compile:
	g++ Driver.cpp Game.cpp Game.h Card.cpp Card.h DeckOfCards.cpp DeckOfCards.h -Wall -o War.out
run:
	./War.out
clean:
	rm *.out
