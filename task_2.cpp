// Simple Calculator

#include <iostream>

using namespace std;

int main () {
    int num1, num2;
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;
    
    char operation;
    cout << "Enter operation (+, -, *, /): ";
    cin >> operation;

    switch (operation) {
        case '+':
            cout << num1 << " + " << num2 << " = " << num1 + num2;
            break;

        case '-':
            cout << num1 << " - " << num2 << " = " << num1 - num2;
            break;

        case '*':
            cout << num1 << " * " << num2 << " = " << num1 * num2;
            break;

        case '/':
            if (num2 == 0) {
                cout << "Division by zero is unallowed!";
            }
            else{
                cout << num1 << " / " << num2 << " = " << num1 / num2;
            }
            break;

        default:
            cout << "invalid operation";
            break;
    }

    return 0;
}