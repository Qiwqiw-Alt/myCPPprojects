#include <iostream>
#include <vector>
#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

vector<vector<char>> boardGame = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}
};

void checkWinner(char *winner);
void locationToIndeks(int location, int *i, int *j);
void printBoard();
void greetings();

int main() {
    #ifdef _WIN32
        HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
        if (hOut == INVALID_HANDLE_VALUE) return 1;

        DWORD dwMode = 0;
        if (GetConsoleMode(hOut, &dwMode)) {
            dwMode |= 0x0004;
            SetConsoleMode(hOut, dwMode);
        }
    #endif

    const char playerX = 'X';
    const char playerO = 'O';
    char currentPlayer = playerX;
    char winner = ' ';
    int location = -1;
    int row = -1, col = -1;

    for (int i = 0; i < 9; i++) {
        // system("cls");
        greetings();
        printBoard();

        do {
            cout << "Current Player: " << currentPlayer << endl;
            cout << "Enter location: "; cin >> location;
            locationToIndeks(location, &row, &col);
            if (location < 1 || location > 9) {
                cout << "Invalid input, please try again!" << endl;
            } else if (boardGame[row][col] == 'X' || boardGame[row][col] == 'O') {
                cout << "Tile is full, please try again!" << endl;
            }
            else {
                break;
            }
            row = -1, col = -1;
            cin.clear();
            cin.ignore(10000, '\n');
        } while (true);

        boardGame[row][col] = currentPlayer;
        currentPlayer = (currentPlayer == playerX) ? playerO : playerX;
        checkWinner(&winner);
        if (winner != ' ') {
            break;
        }
    }

    if (winner != ' ') {
        cout << "The winner is " << winner << endl;
    } else {
        cout << "Tie!" << endl;
    }

    return 0;
}

void checkWinner(char *winner) {
    for (int i = 0; i< 3; i++) {
        if ((boardGame[i][0] == 'X' || boardGame[i][0] == 'O' ) && boardGame[i][0] == boardGame[i][1] && boardGame[i][1] == boardGame[i][2]) {
            *winner = boardGame[i][0];
            return;
        }

        if ((boardGame[0][i] == 'X' || boardGame[0][i] == 'O') && boardGame[0][i] == boardGame[1][i] && boardGame[1][i] == boardGame[2][i]) {
            *winner = boardGame[0][i];
            return;
        }
    }

    if ((boardGame[0][0] == 'X' || boardGame[0][0] == 'O') && boardGame[0][0] == boardGame[1][1] && boardGame[1][1] == boardGame[2][2]) {
        *winner = boardGame[0][0];
        return;
    }

    if ((boardGame[2][0] == 'X' || boardGame[2][0] == 'O') && boardGame[2][0] == boardGame[1][1] && boardGame[1][1] == boardGame[0][2]) {
        *winner = boardGame[2][0];
        return;
    }
}

void locationToIndeks(int location, int *i, int *j) {
    switch (location) {
        case 1: *i = 0, *j = 0; break;
        case 2: *i = 0, *j = 1; break;
        case 3: *i = 0, *j = 2; break;
        case 4: *i = 1, *j = 0; break;
        case 5: *i = 1, *j = 1; break;
        case 6: *i = 1, *j = 2; break;
        case 7: *i = 2, *j = 0; break;
        case 8: *i = 2, *j = 1; break;
        case 9: *i = 2, *j = 2; break;
        default: *i = -1, *j = -1; break;
    }
}

void printBoard() {
    for (int i = 0; i < 3; i++) {
        cout << "     ";
        for (int j = 0; j < 3; j++) {
            cout << " | ";
            if (boardGame[i][j] == 'X') cout << "\033[31mX\033[0m";
            else if (boardGame[i][j] == 'O') cout << "\033[32mO\033[0m";
            else cout << "\033[33m" << boardGame[i][j] << "\033[0m";
        }
        cout << " |" << endl;
        if (i < 2) cout << "      -------------" << endl;
    }
}

void greetings() {
    cout << "==================================================" << endl;
    cout << "=    Welcome to Tic-Tac-Toe Game (Twoplayer)   =" << endl;
    cout << "==================================================" << endl;
}