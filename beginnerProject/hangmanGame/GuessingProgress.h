#ifndef HANGMANGAME_GUESSINGPROGRESS_H
#define HANGMANGAME_GUESSINGPROGRESS_H
#include <string>
#include <vector>
using namespace std;

class GuessingProgress {
private:
    vector<char> listChar;
    vector<char> guessedChar;
    int wordLength;
public:
    GuessingProgress();
    GuessingProgress(string word, int wordLength);

    void setListChar(const string& word);
    void setWordLength(int wordLength);


    [[nodiscard]] vector<char> getListChar() const;
    [[nodiscard]] vector<char> getGuessedChar() const;
    [[nodiscard]] int getWordLength() const;
    [[nodiscard]] bool isGuessCorrect(char inputChar);
    [[nodiscard]] string convertCharToWord();
};


#endif //HANGMANGAME_GUESSINGPROGRESS_H