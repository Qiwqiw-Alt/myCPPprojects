#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    double num1, num2;
    char operation, anotherOperation = 'y';

    while (anotherOperation == 'y' || anotherOperation == 'Y') {
        cout << "\n=== Simple Calculator ===" << endl;
        cout << "Please enter two numbers" << endl;
        cout << "Number 1: ";
        cin >> num1;
        cout << "Operations (+, -, x, / , %, ^): ";
        cin >> operation;
        cout << "Number 2: ";
        cin >> num2;

        switch (operation) {
            case '+':
                cout << "Result: " << num1 + num2 << endl;
                break;
            case '-':
                cout << "Result: " << num1 - num2 << endl;
                break;
            case 'x':
                cout << "Result: " << num1 * num2 << endl;
                break;
            case '/':
                if (num2 != 0) {
                    cout << "Result: " << num1 / num2 << endl;
                } else {
                    cout << "Error! Divison by zero!" << endl;
                }
                break;
            case '%':
                if ((int)num2 != 0) {
                    cout << "Result: " << (int)num1 % (int)num2 << endl;
                } else {
                    cout << "Error! Modulo by zero!" << endl;
                }
                break;
            case '^':
                cout << "Result: " << fixed << setprecision(0) << pow(num1, num2) << endl;
                break;
            default:
                cout << "Error! operator is not correct" << endl;
                break;
        }

        cout << "Want to use again? (y/n) :";
        cin >> anotherOperation;
    }

    return 0;
}