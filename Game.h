/* Lexi Katramados                                                                                                        
   CPSC 1070: 005
   E2: Runtime Terror
   4/5/23 */

#ifndef GAME_H // used to prevent a header file from being inlcuded twice
#define GAME_H
#include "DeckOfCards.h" // allows us to implement DeckOfCards class
#include "Card.h" // allows us to implement Card class
using namespace std;

class Game {
  public:

    // Declare methods
    Game(); // default constructor
    void runGame();
    void runMenu();
    void runTurnByTurn();
    void runSimulation();
    void tie(); // added: function called if theres a tie

    // Declare objects to hold the decks the players are playing with
    DeckOfCards deck1;
    DeckOfCards deck2;

    // Declare vetor to hold cards played
    vector<Card> cardsPlayed;

};
#endif
