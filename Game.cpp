/* Lexi Katramados
   CPSC 1071: 005
   E2: Runtime Terror
   4/5/23 */

// File headers
#include <iostream> // allows us to do input and output (cin and cout)
#include <string> // allows us to use strings
#include <cstdlib> // includes standard library
#include <unistd.h> // allows us to use usleep
#include "DeckOfCards.h" // allows us to implement the DeckOfCards class
#include "Card.h" // allows us to implement the Card class
#include "Game.h" // allows us to implement the Game class
using namespace std;

// Default Constructor
Game::Game() {
  
  // Shuffle dem decks boi
  deck1.shuffle();
  deck2.shuffle();
}

// Main method that runs game
void Game::runGame() {

  // Call runMenu
  runMenu();

}

// Method to print menu
void Game::runMenu() {

  // Declare char to hold choice
  string userChoice;

  // Print out welcome statement and menu
  cout << "Welcome to the game of RAW!" << endl << "1. Play the game turn by turn" << endl << "2. Simulate the game" << endl << "3. Quit" << endl << "Enter your choice: ";

  // Read in and validate user input, proceed from there
  cin >> userChoice;
  while (userChoice != "1" && userChoice != "2" && userChoice != "3") {
    cout << "Invalid choice. Try again" << endl;
    cout << "Welcome to the game of RAW!" << endl << "1. Play the game turn by turn" << endl << "2. Simulate the game" << endl << "3. Quit" << endl << "Enter your choice: ";
    cin >> userChoice;
  }

  // Call corresponding functions depending on user input                                                              
  if (userChoice == "1") {
    runTurnByTurn();
  }
  else if (userChoice == "2") {
    runSimulation();
  }
  else {
    cout << "Goodbye" << endl;
    exit(0);
  }
  
}

// Method to run the game prompting user to play a card
void Game::runTurnByTurn() {

  // Make a boolean to use to run the while loop while the game is still going
  bool stillPlaying = true;

  // Sees when user hits enter
  cin.get();

  // While loop to run through each round until the game is over (as long as the user hits enter)
  while (stillPlaying) {
    // Prompt user to play card and check for their play
    cout << "Press enter key to play a turn" << endl;
    cin.get();

    // Output which card each player played and number remaining
    cout << "Player: " << deck1.deck[0].toString() << " | Number of cards in Deck: " << deck1.size() << endl;
    cout << "Computer: " << deck2.deck[0].toString() << " | Number of cards in Deck: " << deck2.size() << endl << endl;

    // Use 2 objects to hold the card object each player just played (card in first index)
    Card deck1played = deck1.dealCard();
    Card deck2played = deck2.dealCard();

    // Get values of cards just played using objects above to call realValue
    int deck1Value = deck1played.realValue();
    int deck2Value = deck2played.realValue();

    // Compare the cards, output winner, and add both cards played to bottom of losers deck
    // If they tie, add both cards played into vector holding cards played in a round and call tie function
    if (deck1Value > deck2Value) {
      cout << "Player wins the turn" << endl;
      deck2.addCard(deck1played);
      deck2.addCard(deck2played);
    }
    else if (deck1Value < deck2Value) {
      cout << "Computer wins the turn" << endl;
      deck1.addCard(deck1played);
      deck1.addCard(deck2played);
    }
    else {
      cout << "Tie! Three cards are put down" << endl;
      cardsPlayed.push_back(deck1played);
      cardsPlayed.push_back(deck2played);
      tie();
    }

    // Check to see if either player has <27 cards left and break the game
    if (deck1.size() < 27) {
      cout << "Player wins the game!" << endl;
      stillPlaying = false;
    }
    if (deck2.size() < 27) {
      cout << "Computer wins the game!" << endl;
      stillPlaying = false;
    }
    
  } // end of while loop
    
}

// Method to run the game automatically
void Game::runSimulation(){

  // Make boolean to run as long as game is still going
  bool stillPlaying = true;

  // While loop to run through turns until the game is over (legit same as manual but without the prompted enter)
  while (stillPlaying) {

    // Use so user can track the process for the automatic program
    usleep(1000000);

    // Output which card each player played and number remaining
    cout << "Player: " << deck1.deck[0].toString() << " | Number of cards in Deck: " << deck1.size() << endl;
    cout << "Computer: " << deck2.deck[0].toString() << " | Number of cards in Deck: " << deck2.size() << endl << endl;

    // Use 2 objects to hold the card object each player just played (card in first index)
    Card deck1played = deck1.dealCard();
    Card deck2played = deck2.dealCard();

    // Get values of cards just played using objects above to call realValue
    int deck1Value = deck1played.realValue();
    int deck2Value = deck2played.realValue();

    // Compare the cards, output winner, and add both cards played to bottom of losers deck
    // If they tie, add both cards played into vector holding cards played in a round and call tie function
    if (deck1Value > deck2Value) {
      cout << "Player wins the turn" << endl;
      deck2.addCard(deck1played);
      deck2.addCard(deck2played);
    }
    else if (deck1Value < deck2Value) {
      cout << "Computer wins the turn" << endl;
      deck1.addCard(deck1played);
      deck1.addCard(deck2played);
    }
    else {
      cout << "Tie! Three cards are put down" << endl;
      cardsPlayed.push_back(deck1played);
      cardsPlayed.push_back(deck2played);
      tie();
    }

    // Check to see if either player has <27 cards left and break the game
    if (deck1.size() < 27) {
      cout << "Player wins the game!" << endl;
      stillPlaying = false;
    }
    if (deck2.size() < 27) {
      cout << "Computer wins the game!" << endl;
      stillPlaying = false;
    }
    
  } // end of while loop
    
}

// Method to run in the case of a tie
void Game::tie() {

  // "Play" 3 cards from each players deck and add to vector holding cards for that turn
  for (int i = 0; i < 3; i++) {
    cardsPlayed.push_back(deck1.dealCard());
    cardsPlayed.push_back(deck2.dealCard());
  }

  // Make 2 objects to hold the 4th card drawn for comparison and add to the vector for the turn as well
  Card player1tie = deck1.dealCard();
  Card player2tie = deck2.dealCard();
  cardsPlayed.push_back(player1tie);
  cardsPlayed.push_back(player2tie);

  // Get the true number value of each players card to compare
  int player1Val = player1tie.realValue();
  int player2Val = player2tie.realValue();

  // Get # of cards played so far
  int numCards = cardsPlayed.size();

  // Check which player won, output, and add all the cards to the losers stack using a loop to run through the vector
  if (player1Val > player2Val) {
    cout << "Computer loses the turn, collecting all the cards!" << endl;
    for (int i = 0; i < numCards; i++) { // adds all played cards to deck 2                                                                                                                                 
      deck2.addCard(cardsPlayed[i]);
    }
  }
  else if (player1Val < player2Val) {
    cout << "Player loses the turn, collecting all the cards!" << endl;
    for (int i = 0; i < numCards; i++) { // adds all played cards to deck 1                                                                                                                                 
      deck1.addCard(cardsPlayed[i]);
    }
  }
  else {
    cout << "Tie! Three cards are put down" << endl;
    tie();
  }

  // Empty cards from cardsPlayer vector after turn is over
  cardsPlayed.clear();

}
