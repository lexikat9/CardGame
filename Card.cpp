/* Lexi Katramados
   CPSC 1071: 005
   E2: Runtime Terror
   4/5/23 */

// File headers
#include <iostream> // allows us to do input and output (cin and cout)
#include <string> // allows us to use strings
#include <cstdlib> // includes use of standard library
#include "DeckOfCards.h" // allows us to implement the DeckOfCards class     
#include "Card.h" // allows us to implement the Card class
using namespace std;

// Fill our arrays with the values of faces and suits (need a blank filler space in the beginning because arrays start at 0 and face and suit start at 1)
const string Card::faces[14] = {"Null", "Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
const string Card::suits[5] = {"Null", "Hearts", "Diamonds", "Clubs", "Spades"};

// Constructor (need to convert ints to type Faces and Suits in order to be stored in face and suit)
Card::Card(int userFace, int userSuit) {
  face = static_cast<Faces>(userFace);
  suit = static_cast<Suits>(userSuit);
}

// Method to turn the randomly picked card into an int to see who won round
int Card::realValue(){

  // If else statement to convert enum card value to int of corresponding value (need to change because of index)
  if (face == 1) {
    return 2;
  }
  else if (face == 2) {
    return 3;
  }
  else if (face == 3) {
    return 4;
  }
  else if (face == 4) {
    return 5;
  }
  else if (face == 5) {
    return 6;
  }
  else if (face == 6) {
    return 7;
  }
  else if (face == 7) {
    return 8;
  }
  else if (face == 8) {
    return 9;
  }
  else if (face == 9) {
    return 10;
  }
  else if (face == 10) {
    return 11;
  }
  else if (face == 11) {
    return 12;
  }
  else if (face == 12) {
    return 13;
  }
  else {
    return 14; // otherwise, it's a 0 which is an ace and aces are the highest (14)
  }

}

// Method that takes the face and suit and returns the value and suit of the card as one string
string Card::toString() {

  // Convert face given as int to a string
  string realFace = faces[face];

  // Convert suit given as int to a string
  string realSuit = suits[suit];

  // Put it all together and return
  string finalValue = realFace + " of " + realSuit;
  return finalValue;
}
