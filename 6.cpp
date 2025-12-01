#include <iostream>
#include <string>
using namespace std;

enum State { S0, S1 };

int main() {
    string input;
    cout << "Enter a binary string: ";
    cin >> input;

    State current = S0;  // Start state: even number of 1s

    for (char c : input) {
        if (c != '0' && c != '1') {
            cout << "Invalid input (only 0 and 1 allowed)\n";
            return 0;
        }

        // Transition
        switch (current) {
            case S0:
                if (c == '0') current = S0;
                else current = S1;
                break;

            case S1:
                if (c == '0') current = S1;
                else current = S0;
                break;
        }
    }

    if (current == S0)
        cout << "Accepted\n";
    else
        cout << "Rejected\n";

    return 0;
}
