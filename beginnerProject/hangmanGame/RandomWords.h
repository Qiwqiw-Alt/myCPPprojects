#ifndef HANGMANGAME_RANDOMWORDS_H
#define HANGMANGAME_RANDOMWORDS_H
#include <string>
using namespace std;

struct WordData {
    string word;
    string hint;
};

class RandomWords {
private:
    string selectedWord;
    string selectedWordHint;
    int selectedWordLength{};
public:
    RandomWords();

    void chooseRandomWord();

    [[nodiscard]]string getWord() const;
    [[nodiscard]]string getWordHint() const;
    [[nodiscard]]int getWordLength() const;
};


#endif //HANGMANGAME_RANDOMWORDS_H