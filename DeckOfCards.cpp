/* Lexi Katramados                                                                                                                                                                
   CPSC 1071: 005                                                                                                                                                                 
   E2: Runtime Terror                                                                                                                                                             
   4/5/23 */

// File headers                                                                                                                                                                   
#include <iostream> // allows us to do input and output (cin and cout)                                                                                                            
#include <string> // allows us to use strings                                                                                                                                     
#include <vector> // allows us to use vectors                                                                                                                                     
#include <ctime> // allows us to do random number generation                                                                                                                      
#include <cstdlib> // allows us to use standard library functions                                                                                                                 
#include "DeckOfCards.h" // allows us to implement the DeckOfCards class                                                                                                          
#include "Card.h" // allows us to implement the Card class                                                                                                                        
using namespace std;

// Default constructor to initialize all cards in the deck                                                                                                                        
DeckOfCards::DeckOfCards () {

  // Initialize
  currentCard = 0;

  // So we can use random number generator
  srand(time(0));

  // Make deck!
  for (int i = 1; i <= 13; ++i) {
    for (int j = 1; j <= 4; ++j) {
      Card card(i,j);
      deck.push_back(card);
    }
  }

}

// Method to shuffle the cards in the deck                                                                                                                                        
void DeckOfCards::shuffle () {

  // Declare necessary variables to perform random number generation                                                                                                              
  int rand1 = 0;
  int rand2 = 0;
  Card temp(1,1);

  // Use a for loop to iterate through vector 52 times and swap 2 cards at random spots with each other
  for (int i = 0; i < 52; i++) {
    rand1 = rand() % 52;
    rand2 = rand() % 52;
    temp = deck[rand1];
    deck[rand1] = deck[rand2];
    deck[rand2] = temp;
  }

}

// Method to return the next card
Card DeckOfCards::dealCard() {

  // Get the next card and store in object (0 because it will always be the first card of the deck as we draw)
  Card nextCard = deck[0];

  // Make another vector identical to the deck vector we have now
  // So when size changes of the og deck, we have this one
  vector<Card> copy = deck;

  // Clear og deck vector so we can refill it with all the cards minus the one just played
  deck.clear();

  // Use a for loop to remove the card just played from the deck (start at 1 to ignore top card just played)
  int copySize = copy.size();
  for (int i = 1; i < copySize; i++) {
    deck.push_back(copy.at(i));
  }

  // Increment currentCard so next time we use the next card (and to keep track of how many we've dealt)
  currentCard++;

  // Return the next card to be dealt
  return nextCard;
}

// Method to see if there are more cards in the deck
bool DeckOfCards::moreCards() {

  // Check if cards dealt is over 52 and return false if we're out, else, return true
  if (currentCard > 51) {
    return false;
  }
  else {
    return true;
  }

}

// Method to add cards from the round into the losers deck
void DeckOfCards::addCard(Card addBack) {
  deck.push_back(addBack);
}


// Method to return # of cards in a deck
int DeckOfCards::size() {
  return deck.size();
}
