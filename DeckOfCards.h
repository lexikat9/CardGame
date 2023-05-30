/* Lexi Katramados                                                                                                                                                                
   CPSC 1070: 005                                                                                                                                                                 
   E2: Runtime Terror                                                                                                                                                             
   4/5/23 */

#ifndef DECKOFCARDS_H // used to prevent a header file from being inlcuded twice                                                                                                  
#define DECKOFCARDS_H
#include <cstdlib> // allows us to use the standard library                                                                                                                       
#include <vector> // allows us to use vectors                                                                                                                                     
#include "Card.h" // allows us to use card class                                                                                                                                  
using namespace std;

class DeckOfCards {
 public:
  // Default constructor                                                                                                                                                          
  DeckOfCards();

  // Declare methods                                                                                                                                                              
  void shuffle();
  bool moreCards();
  Card dealCard();
  int size();
  void addCard(Card);

  // Declare vector
  vector<Card> deck;
  
private:

  // Declare variable                                                                                                                                                             
  int currentCard;

};
#endif
