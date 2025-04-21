#include <iostream>
#include <cstdlib>  // For rand() function
#include <ctime>    // For time() function
using namespace std;

int main() {
    // Seed the random number generator
    srand(time(0));

    // Generate random number between 1 and 100
    int secretNumber = rand() % 100 + 1;
    int guess;
    int attempts = 0;

    cout << "Number Guessing Game" << endl;
    cout << "I'm thinking of a number between 1 and 100." << endl << endl;
    cout << secretNumber;
    do {
        cout << "Enter your guess: ";
        cin >> guess;
        attempts++;
        if(guess < secretNumber){
            cout << "Too low! Try again.\n\n";
        }
        if(guess > secretNumber){
            cout << "Too high! Try again.\n\n";
        }
    } while (guess != secretNumber);

    cout << "Congratulations! You guessed the number "<< secretNumber << " correctly!\n";
    cout << "It took you " << attempts << " guesses.";

    return 0;
}