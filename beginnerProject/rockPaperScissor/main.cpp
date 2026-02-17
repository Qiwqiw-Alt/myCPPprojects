#include <iostream>
#include <random>

using namespace std;

int main() {
    int computer, player;
    bool tie = true;

    cout << "\n=== Rock, Paper, & Scissor!! === \n";
    while (tie) {
        computer = (rand() % 3) + 1;

        cout << "(1) Rock, (2), Paper, (3) Scissor" << endl;
        cout << "Enter your choice (e.g 1 for Rock): ";
        cin >> player;

        if (player == computer) {
            cout << "Tie!!!, You and Computer made the same choice" << endl;
        } else if (player == 1 && computer == 3) {
            cout << "You win, Rock beat Scissor!!!" << endl;
            tie = false;
        } else if (player == 1 && computer == 2) {
            cout << "You lose, Paper beat Rock ;(" << endl;
            tie = false;
        } else if (player == 2 && computer == 3) {
            cout << "You lose, Scissor beat Paper ;(" << endl;
            tie = false;
        } else if (computer == 1 && player == 3) {
            cout << "You lose, Rock beat Scissor!!!" << endl;
            tie = false;
        } else if (computer == 1 && player == 2) {
            cout << "You win, Paper beat Rock ;(" << endl;
            tie = false;
        } else if (computer == 2 && player == 3) {
            cout << "You win, Scissor beat Paper ;(" << endl;
            tie = false;
        }
    }


    return 0;
}