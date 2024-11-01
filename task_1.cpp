// Number Guessing Game

#include <iostream>

using namespace std;

int main() {
    int generated_number;
    generated_number = rand() % 101;
    cout << generated_number << endl;

    int user_guess;
    cout << "Enter a number between 0 and 100: ";
    cin >> user_guess;

    while (user_guess != generated_number) {
        (user_guess > generated_number) ? cout << "Higher! Try again: "
                                        : cout << "Lower! Try again: ";

        cin >> user_guess;
    }

    cout << "Correct!";

    return 0;
}