/*Using the grammar S → ( S ) S | ε, write a recursive-descent C program that reads a string of parentheses (only ( and )) and prints whether it is a valid balanced string according to this grammar.*/
#include <iostream>
#include <string>
using namespace std;

string input;
int pos = 0;

// S → ( S ) S | ε
bool parse_S() {
    // Case 1: ε (empty) — only if next char not '('
    if (input[pos] != '(') {
        return true;   // S → ε
    }

    // Otherwise must match: ( S ) S
    if (input[pos] == '(') {
        pos++;  // consume '('

        if (!parse_S()) return false;

        if (input[pos] == ')') {
            pos++;  // consume ')'
        } else {
            return false;  // missing ')'
        }

        // After ( S ) must parse another S
        return parse_S();
    }

    return false;
}

int main() {
    cout << "Enter parentheses string: ";
    cin >> input;
    input.push_back('\0');

    if (parse_S() && input[pos] == '\0')
        cout << "Valid balanced string.\n";
    else
        cout << "Invalid string.\n";

    return 0;
}
