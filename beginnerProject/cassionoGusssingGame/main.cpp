#include <iostream>
#include <random>
#include <string>
#include <format>
#include <vector>
#include <ctime>
#include "Reward.h"

using namespace std;

int guessedNumber(int difficulityLevel);
string message(int difficulityLevel);
void rewardInit();
Reward reward(int difficulityLevel, int totalGuess);

vector<Reward> rewardsEasyLevel(10);
vector<Reward> rewardsMediumLevel(10);
vector<Reward> rewardsHardLevel(10);

int main() {
    srand(static_cast<unsigned int>(time(0)));

    int difficultyLevel;
    int userGuessedNumber = -1;
    int totalGuess = 0;

    rewardInit();

    cout << "\n=== Casino's Game: Guessing The Number!!! ===\n";
    cout << "Pick Difficulty: (1) Easy, (2) Medium, (3) Hard : ";
    cin >> difficultyLevel;

    int number = guessedNumber(difficultyLevel);

    while (difficultyLevel > 0 && number != userGuessedNumber) {
        cout << message(difficultyLevel);
        cin >> userGuessedNumber;
        totalGuess++;

        if (userGuessedNumber == number) {
            Reward playerReward = reward(difficultyLevel, totalGuess);
            cout << format("You guessed the right number!!!, the correct answer was {} \n", number);
            cout << "Your Prize is " << playerReward.getMoney() << "K Dollar " << endl;
            break;
        } else if (userGuessedNumber > number) {
            cout << "Your guess too is high" << endl;
        } else if (userGuessedNumber < number) {
            cout << "Your guess too is low" << endl;
        }
    }

    return 0;
}

int guessedNumber(int difficulityLevel) {
    int number;
    if (difficulityLevel == 1) {
        number = (rand() % 25) + 1;
    } else if (difficulityLevel == 2) {
        number = (rand() % 50) + 1;
    } else if (difficulityLevel == 3) {
        number = (rand() % 100) + 1;
    } else {
        number = -1;
    }

    return number;
}

string message(int difficulityLevel) {
    string message;
    if (difficulityLevel == 1) {
        message = format("Level {} (Easy): Guess the number between 1 - 25: ", difficulityLevel);
    } else if (difficulityLevel == 2) {
        message = format("Level {} (Medium): Guess the number between 1 - 50: ", difficulityLevel);
    } else if (difficulityLevel == 3) {
        message = format("Level {} (hard): Guess the number between 1 - 100: ", difficulityLevel);
    } else {
        message = format("You enter the incorrect level!!!, please select the available level.");
    }

    return message;
}

void rewardInit() {
    // Easy Level Reward
    rewardsEasyLevel[0] = Reward(10, 1);
    rewardsEasyLevel[1] = Reward(15, 1);
    rewardsEasyLevel[2] = Reward(20, 1);
    rewardsEasyLevel[3] = Reward(25, 1);
    rewardsEasyLevel[4] = Reward(30, 1);
    rewardsEasyLevel[5] = Reward(35, 1);
    rewardsEasyLevel[6] = Reward(40, 1);
    rewardsEasyLevel[7] = Reward(45, 1);
    rewardsEasyLevel[8] = Reward(50, 1);
    rewardsEasyLevel[9] = Reward(55, 1);

    // Medium Level Reward
    rewardsMediumLevel[0] = Reward(60, 2);
    rewardsMediumLevel[1] = Reward(65, 2);
    rewardsMediumLevel[2] = Reward(70, 2);
    rewardsMediumLevel[3] = Reward(80, 2);
    rewardsMediumLevel[4] = Reward(85, 2);
    rewardsMediumLevel[5] = Reward(90, 2);
    rewardsMediumLevel[6] = Reward(95, 2);
    rewardsMediumLevel[7] = Reward(100, 2);
    rewardsMediumLevel[8] = Reward(120, 2);
    rewardsMediumLevel[9] = Reward(150, 2);

    // Hard Level Reward
    rewardsHardLevel[0] = Reward(175, 3);
    rewardsHardLevel[1] = Reward(200, 3);
    rewardsHardLevel[2] = Reward(250, 3);
    rewardsHardLevel[3] = Reward(300, 3);
    rewardsHardLevel[4] = Reward(400, 3);
    rewardsHardLevel[5] = Reward(500, 3);
    rewardsHardLevel[6] = Reward(600, 3);
    rewardsHardLevel[7] = Reward(750, 3);
    rewardsHardLevel[8] = Reward(850, 3);
    rewardsHardLevel[9] = Reward(1000, 3);
}

Reward reward(int difficultyLevel, int totalGuess) {
    Reward reward;
    int prizeNumber;
    if (totalGuess >= 10) {
        prizeNumber = 0;
    } else {
        prizeNumber = 10 - totalGuess;
    }


    if (difficultyLevel == 1) {
        reward = rewardsEasyLevel[prizeNumber];
    } else if (difficultyLevel == 2) {
        reward = rewardsMediumLevel[prizeNumber];
    } else if (difficultyLevel == 3) {
        reward = rewardsHardLevel[prizeNumber];
    }

    return reward;
}