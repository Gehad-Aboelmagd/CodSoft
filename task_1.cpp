// Number Guessing Game

#include <iostream>

using namespace std;

int main() {
    int generated_number;
    generated_number = rand() % 101;

    int user_guess;
    cout << "Enter a number between 0 and 100: ";
    cin >> user_guess;

    while (user_guess != generated_number) {
        (user_guess > generated_number) ? cout << "Too high! Try again: "
                                        : cout << "Too Low! Try again: ";

        cin >> user_guess;
    }

    cout << "Correct!";

    return 0;
}
