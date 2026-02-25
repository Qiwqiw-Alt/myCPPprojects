#include "GuessingProgress.h"
#include <vector>
using namespace std;

GuessingProgress::GuessingProgress() {
    this->listChar = vector<char>();
    this->guessedChar = vector<char>();
    this->wordLength= 0;
}

GuessingProgress::GuessingProgress(string word , int wordLength) {
    for (int i = 0; i < wordLength; i++) {
        this->listChar.push_back(word[i]);
    }
    for (int i = 0; i < word.size(); i++) {
        if (i == 0 || i == wordLength - 1) {
            this->guessedChar.push_back(word[i]);
        }
        else {
            this->guessedChar.push_back('_');
        }
    }

    this->wordLength = wordLength;
}

void GuessingProgress::setListChar(const string& word) {
    for (int i = 0; i < word.length(); i++) {
        this->listChar.push_back(word[i]);
    }
}

void GuessingProgress::setWordLength(const int wordLength) { this->wordLength = wordLength; }
vector<char> GuessingProgress::getListChar() const { return this->listChar; }
vector<char> GuessingProgress::getGuessedChar() const { return  this->guessedChar; }
int GuessingProgress::getWordLength() const { return this->wordLength; }

bool GuessingProgress::isGuessCorrect(const char inputChar) {
    bool found = false;
    for (int i = 0; i < this->wordLength; i++) {
        if (inputChar == this->listChar[i]) {
            this->guessedChar[i] = inputChar;
            found = true;
        }
    }
    return found;
}

string GuessingProgress::convertCharToWord() {
    string word;
    for (int i = 0; i < this->wordLength ; i++) {
        word += this->guessedChar[i];
    }
    return word;
}
