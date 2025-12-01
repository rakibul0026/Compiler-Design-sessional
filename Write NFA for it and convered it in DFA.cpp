/*  Lab Task : (a|b)*a
  Write NFA for it and convered it in DFA */

#include <iostream>
#include <string>
using namespace std;

// DFA for (a|b)*a

// DFA states:
enum State {
    D0, // start
    D1  // final
};

bool isAccepted(const string& s) {
    State current = D0;

    for (char c : s) {
        if (c != 'a' && c != 'b')
            return false; // invalid symbol

        switch (current) {
            case D0:
                if (c == 'a') current = D1;
                else current = D0; // b
                break;

            case D1:
                if (c == 'a') current = D1;
                else current = D0; // b
                break;
        }
    }

    // Accept only if final state D1
    return (current == D1);
}

int main() {
    string s;
    cout << "Enter string of a and b: ";
    cin >> s;

    if (isAccepted(s))
        cout << "Accepted (matches (a|b)*a)\n";
    else
        cout << "Rejected\n";

    return 0;
}

