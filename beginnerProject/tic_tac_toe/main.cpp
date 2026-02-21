#include <iostream>
#include <vector>
using namespace std;

vector<vector<char>> boardGame = {
    {' ', ' ', ' '},
    {' ', ' ', ' '},
    {' ', ' ', ' '}
};

int main() {
    const char playerX = 'X';
    const char playerO = 'O';
    char currentPlayer = playerX;
    int row, col = -1;
    char winner = ' ';

    for (int i = 0; i < 9; i++) {
        // Display the board
        for (int j = 0; j < 3; j++) {
            cout << "| "<< boardGame[j][0] << " | " << boardGame[j][1] << " | " << boardGame[j][2] << " |" << endl;
            if (j != 2) {
                cout << "-------------" << endl;
            }
        }
        if (winner != ' ') {
            break;
        }
        do {
            cout << "Current Player: " << currentPlayer << endl;
            cout << "Enter row and columnn index from 0-2 for row and column: "; cin >> row >> col;
            if (row < 0 || row > 2 || col < 0 || col > 2) {
                cout << "Invalid input, please try again!" << endl;
            } else if (boardGame[row][col] != ' ') {
                cout << "Tile is full, please try again!" << endl;
            }
            else {
                break;
            }
            row, col = -1;
            cin.clear();
            cin.ignore(10000, '\n');
        } while (true);

        boardGame[row][col] = currentPlayer;
        currentPlayer = (currentPlayer == playerX) ? playerO : playerX;

        // check winners
        // rows - horizontal
        for (int r = 0; r < 3; r++) {
            if (boardGame[r][0] != ' ' && boardGame[r][0] == boardGame[r][1] && boardGame[r][1] == boardGame[r][2]) {
                winner = boardGame[r][0];
                break;
            }
        }

        // columns - vertical
        for (int c = 0; c < 3; c++) {
            if (boardGame[c][0] != ' ' && boardGame[c][0] == boardGame[c][1] && boardGame[c][1] == boardGame[c][2]) {
                winner = boardGame[c][0];
                break;
            }
        }

        // diagonal
        if (boardGame[0][0] != ' ' && boardGame[0][0] == boardGame[1][1] && boardGame[1][1] == boardGame[2][2]) {
            winner = boardGame[0][0];
        } else if (boardGame[2][0] != ' ' && boardGame[2][0] ==boardGame[1][1] && boardGame[1][1] == boardGame[0][2]) {
            winner = boardGame[2][0];
        }

        if (winner != ' ') {
            cout << "The winner is " << winner << endl;
        } else {
            cout << "Tie!" << endl;
        }
    }


    return 0;
}