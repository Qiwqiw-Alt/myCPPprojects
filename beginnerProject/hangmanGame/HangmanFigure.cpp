#include "HangmanFigure.h"
#include <iostream>
using namespace std;

HangmanFigure::HangmanFigure() {
    this->wrongGuesses = 0;
    this->guessChance = 6;
}

HangmanFigure::HangmanFigure(int wrongGuesses, int guessChance) {
    this->wrongGuesses = wrongGuesses;
    this->guessChance = guessChance;
}

void HangmanFigure::setWrongGuesses(int wrongGuesses) { this->wrongGuesses = wrongGuesses; }
void HangmanFigure::setGuessChance(int guessChance) { this->guessChance = guessChance; }

int HangmanFigure::getWrongGuesses() const { return this->wrongGuesses; }
int HangmanFigure::getGuessChance() const { return this->guessChance; }

void HangmanFigure::draw() const {
    switch (this->wrongGuesses) {
        case 0:
            cout << "  +---+" << endl;
            cout << "  |   |" << endl;
            cout << "      |" << endl;
            cout << "      |" << endl;
            cout << "      |" << endl;
            cout << "      |" << endl;
            cout << "============" << endl;
            cout << " Ready?...  " << endl;
            cout << "============" << endl;
            break;
        case 1:
            cout << "  +---+" << endl;
            cout << "  |   |" << endl;
            cout << "  O   |" << endl;
            cout << "      |" << endl;
            cout << "      |" << endl;
            cout << "      |" << endl;
            cout << "============" << endl;
            cout << " 1st chance " << endl;
            cout << "============" << endl;
            break;
        case 2:
            cout << "  +---+" << endl;
            cout << "  |   |" << endl;
            cout << "  O   |" << endl;
            cout << "  |   |" << endl;
            cout << "      |" << endl;
            cout << "      |" << endl;
            cout << "============" << endl;
            cout << " 2nd chance " << endl;
            cout << "============" << endl;
            break;
        case 3:
            cout << "  +---+" << endl;
            cout << "  |   |" << endl;
            cout << "  O   |" << endl;
            cout << " /|   |" << endl;
            cout << "      |" << endl;
            cout << "      |" << endl;
            cout << "============" << endl;
            cout << " 3rd chance " << endl;
            cout << "============" << endl;
            break;
        case 4:
            cout << "  +---+" << endl;
            cout << "  |   |" << endl;
            cout << "  O   |" << endl;
            cout << " /|\\  |" << endl;
            cout << "      |" << endl;
            cout << "      |" << endl;
            cout << "============" << endl;
            cout << " 4th chance " << endl;
            cout << "============" << endl;
            break;
        case 5:
            cout << "  +---+" << endl;
            cout << "  |   |" << endl;
            cout << "  O   |" << endl;
            cout << " /|\\  |" << endl;
            cout << " /    |" << endl;
            cout << "      |" << endl;
            cout << "============" << endl;
            cout << " 5th chance " << endl;
            cout << "============" << endl;
            break;
        case 6:
            cout << "  +---+" << endl;
            cout << "  |   |" << endl;
            cout << "  O   |" << endl;
            cout << " /|\\  |" << endl;
            cout << " / \\  |" << endl;
            cout << "      |" << endl;
            cout << "============" << endl;
            cout << " 6th chance " << endl;
            cout << "============" << endl;
            break;
        default: break;
    }
}
bool HangmanFigure::isGameOver() const { return this->guessChance == this->wrongGuesses; }
