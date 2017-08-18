#include <iostream>
#include <cmath>
#include <string>
#define MIN 1
#define MAX 100

using namespace std;

bool isNumber(char input[]);

int main(int argc, char *argv[]) {
    cout << "Number Guessing Game!! " << endl;
    int min;
    int max;

    // Parse arguments
    if (argc >= 1) {
        min = MIN;
        max = MAX;
    }
    if (argc >= 2) {
        if (!isNumber(argv[1])) {
            cout << "Argument " << argv[1] << " Error: Invalid Format!" << endl;
            return 2;
        }
        min = atoi(argv[1]);
    }
    if (argc >= 3) {
        if (!isNumber(argv[2])) {
            cout << "Argument " << argv[2] << " Error: Invalid Format!" << endl;
            return 2;
        }
        max = atoi(argv[2]);
    }
    if (max < min) {
        cout << "Range Error: Max < Min" << endl;
        return 2;
    }


    // Generate random seed based on time
    srand(time(0));

    // Initialize variables
    int target = rand() % (max - min + 1) + min;
    int expected = int(ceil(log2(max - min + 1))); //Expected steps
    int count = 1;
    bool cheated = false;

    char user_guess[32];

    while (true) {
        // Print prompt
        cout << "Guess #" << count << " ";
        cout << "(" << min << "-" << max << ")" << " ==> ";

        // Take input
        cin >> user_guess;
        bool cheat = false;
        int guess;

        // Abort the program if error to prevent infinit loop
        if(cin.eof() || cin.fail()) {
            cout << "Abort. " << endl;
            return 3;
        }

        // Cheat code: auto
        if (strcmp(user_guess, "auto") == 0) {
            cheated = cheat = true;
            int suggested = (min + max) / 2;
            guess = suggested;
        // Cheat code: supercheat
        } else if (strcmp(user_guess, "super") == 0) {
            cheated = true;
            cout << "Answer is " << target << endl;
            continue;
        // Cheat code: reset (count)
        } else if (strcmp(user_guess, "reset") == 0) {
            cheated = true;
            cout << "Resetted" << endl;
            count = 1;
            continue;
        }

        // No cheat, Check for number format
        if (!cheat) {
            if (!isNumber(user_guess)) {
                cout << "Number format error! " << endl;
                continue;
            }
            guess = atoi(user_guess);
        }

        // User's guess not in correct range
        if (guess > max || guess < min) {
            cout << "Not in range! " << endl;
            continue;
        }

        // Process User's Guess
        if (guess > target) { // Guess larger than target
            max = guess - 1;
        } else if (guess < target) { // Guess smaller than target
            min = guess + 1;
        } else { // Only possible left is guess equal to target
            if (cheated) {
                cout << "Cheater! You win! ";
            } else {
                cout << "You are right! ";
            }

            cout << "The answer is " << target << ". " << endl;
            cout << "It took you ";
            if (count <= expected) {
                cout << "only " << count << " guesses!!! Not Bad!!";
            } else {
                cout << count << " guesses. Be more smart next time!";
            }
            cout << endl;
            break; // Exit the loop
        }
        count++;
    }

}


bool isNumber(char input[]) {
    for (int i = 0; i < strlen(input); i++) {
        if (!isdigit(input[i])) {
            return false;
        }
    }
    return true;
}
