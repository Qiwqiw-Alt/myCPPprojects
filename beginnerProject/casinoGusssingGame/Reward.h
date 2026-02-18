//
// Created by lenovo on 17/02/2026.
//

#ifndef CASSIONOGUSSSINGGAME_REWARD_H
#define CASSIONOGUSSSINGGAME_REWARD_H

using namespace std;

class Reward {
    public:
        long money;
        int difficulityLevel;

        Reward();

        Reward(long money, int difficulityLevel);

        void setMoney(long money);
        long getMoney();

        void setDifficultyLevel(int difficulityLevel);
        int getDifficultyLevel();

};

#endif //CASSIONOGUSSSINGGAME_REWARD_H