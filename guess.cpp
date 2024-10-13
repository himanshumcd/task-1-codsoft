#include <iostream>
#include <cstdlib>  
#include <ctime>    

using namespace std;

int main() {
    // Initialize random seed based on current time
    srand(static_cast<unsigned int>(time(0)));

    // Generate a random number between 1 and 100
    int randomNum = rand() % 100 + 1;

    int userGuess = 0;
    int  attempt = 0;

    cout << "Welcome to the Guess the Number game!" << endl;
    cout << "I have generated a random number between 1 and 100." << endl;
    cout << "Try to guess it!" << endl;

    // Keep asking the user for guesses until they guess correctly
    do {
        cout << "Enter your guess: ";
        cin >> userGuess;

        attempt++;  // Increment the number of attempts

        if (userGuess < randomNum) {
            cout << "to small try again." << endl;
        } else if (userGuess > randomNum) {
            cout << "Too large Try again." << endl;
        } else {
            cout << "Congratulations! You guessed the correct number, " << randomNum << ", in " << attempt << " attempts!" << endl;
        }

    } while (userGuess != randomNum);

    return 0;
}
