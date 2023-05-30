/* Lexi Katramados                                                                                                                                                                
   CPSC 1070: 005                                                                                                                                                                 
   E2: Runtime Terror                                                                                                                                                             
   4/5/23 */

#include <string> // allows us to use strings                                                                                                                                     
#include <cstdlib> // allows us to use the standard library                                                                                                                       
#ifndef CARD_H // used to prevent a header file from being inlcuded twice                                                                                                         
#define CARD_H
using namespace std;

class Card {
 public:
  // Declare default constructor                                                                                                                                                  
  Card (int, int);

  // Declare 2 static arrays representing faces and suits                                                                                                                         
  static const string faces[14];
  static const string suits[5];

  // Declare methods                                                                                                                                                             
  string toString();
  int realValue();
  
 private:
  // Declare 2 enums: one for faces, one for suits                                                                                                                                
  enum Faces {Ace, Deuce, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King};
  enum Suits {Hearts, Diamonds, Clubs, Spades};

  // Declare variables of type enum                                                                                                                                               
  Faces face;
  Suits suit;

};
#endif
