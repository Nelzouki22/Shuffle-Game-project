#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

// Function to shuffle the deck
void shuffleDeck(vector<int>& deck) {
    srand(time(NULL)); // Seed the random number generator
    random_shuffle(deck.begin(), deck.end());
}

// Function to play the game
void playGame(const vector<int>& deck) {
    int targetCard;
    cout << "Enter the position of the target card (1-" << deck.size() << "): ";
    cin >> targetCard;

    if (targetCard < 1 || targetCard > deck.size()) {
        cout << "Invalid position. Please enter a number between 1 and " << deck.size() << ".\n";
        return;
    }

    int targetValue = deck[targetCard - 1]; // Adjusting for 0-based indexing

    cout << "Now, let's shuffle the deck...\n";
    vector<int> shuffledDeck = deck;
    shuffleDeck(shuffledDeck);

    // Find the position of the target card in the shuffled deck
    auto it = find(shuffledDeck.begin(), shuffledDeck.end(), targetValue);
    int position = distance(shuffledDeck.begin(), it) + 1; // Adjusting for 1-based indexing

    cout << "The target card was found at position: " << position << endl;

    if (position == targetCard) {
        cout << "Congratulations! You guessed correctly!\n";
    }
    else {
        cout << "Sorry, you guessed incorrectly. Better luck next time!\n";
    }
}

int main() {
    // Creating a deck of cards (here represented by integers 1 to 52)
    vector<int> deck(52);
    for (int i = 0; i < 52; ++i) {
        deck[i] = i + 1;
    }

    char playAgain = 'y';
    while (playAgain == 'y' || playAgain == 'Y') {
        playGame(deck);
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    }

    cout << "Thanks for playing!\n";
    return 0;
}
