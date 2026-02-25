#ifndef HANGMANGAME_HANGMANFIGURE_H
#define HANGMANGAME_HANGMANFIGURE_H

class HangmanFigure {
private:
    int wrongGuesses;
    int guessChance;
public:
    HangmanFigure();
    HangmanFigure(int wrongGuesses, int guessChance);

    void setWrongGuesses(int wrongGuesses);
    void setGuessChance(int guessChance);
    int getWrongGuesses() const;
    int getGuessChance() const;

    void draw() const;
    bool isGameOver() const;
};


#endif //HANGMANGAME_HANGMANFIGURE_H