//
// Created by lenovo on 17/02/2026.
//

#include "Reward.h"

Reward::Reward() {
    this->money = 0;
    this->difficulityLevel = 0;
}

Reward::Reward(long money, int difficulityLevel) {
    this->money = money;
    this->difficulityLevel = difficulityLevel;
}

void Reward::setMoney(long money) {
    this->money = money;
}

long Reward::getMoney() {
    return this->money;
}

void Reward::setDifficultyLevel(int difficulityLevel) {
    this->difficulityLevel = difficulityLevel;
}

int Reward::getDifficultyLevel() {
    return this->difficulityLevel;
}
