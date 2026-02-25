#include <iostream>
#include <vector>
#include "GuessingProgress.h"
#include "HangmanFigure.h"
#include "RandomWords.h"
using namespace std;

const int guessChance = 6;

int main() {
    srand(static_cast<unsigned int>(time(0)));
    RandomWords randomWordSelected = RandomWords();
    randomWordSelected.chooseRandomWord();
    GuessingProgress guessingProgress = GuessingProgress(randomWordSelected.getWord(), randomWordSelected.getWordLength());
    HangmanFigure hangman = HangmanFigure(0, guessChance);

    char userInput;
    int chanceUsed = 0;
    vector<char> history;

    do {
        cout << "=========================================" << endl;
        cout << "====  Hangman Game:  Guess The Word!  ===" << endl;
        cout << "========  Topic: tech & academic ========" << endl;
        cout << "=========================================" << endl;

        hangman.draw();

        cout << "\nWord: " << guessingProgress.convertCharToWord() << endl;
        cout << "Hint: " << randomWordSelected.getWordHint() << endl;
        cout << "-----------------------------------------" << endl;
        cout << "Chances Left : " << (guessChance - chanceUsed) << endl;

        cout << "Guessed      : "; for(char c : history) cout << c << " ";
        cout << "\n-----------------------------------------" << endl;

        cout << "Input your guess : "; cin >> userInput;
        history.push_back(userInput);

        if (guessingProgress.isGuessCorrect(userInput)) {
            cout << "\nCorrect!, Good job fella " << endl;
        } else {
            cout << "Wrong!, The hangman is closser... " << endl;
            ++chanceUsed;
            hangman.setWrongGuesses(chanceUsed);
        }


        if (guessingProgress.convertCharToWord() == randomWordSelected.getWord()) {
            cout << "=========================================" << endl;
            cout << "      CONGRATULATIONS! YOU WIN!          " << endl;
            cout << "=========================================" << endl;
            cout << "The word was: " << randomWordSelected.getWord() << endl;
            break;
        }

        if (chanceUsed > guessChance) {
            hangman.draw();
            cout << "=========================================" << endl;
            cout << "       GAME OVER - YOU LOSE!             " << endl;
            cout << "=========================================" << endl;
            cout << "The word was: " << randomWordSelected.getWord() << endl;
            break;
        }

        cout << "\nPress Enter to continue...";
        cin.ignore();
        cin.get();
    } while (!hangman.isGameOver());

    return 0;
}