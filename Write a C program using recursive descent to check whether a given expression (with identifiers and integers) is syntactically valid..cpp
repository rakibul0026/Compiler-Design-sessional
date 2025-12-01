#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string input;
int pos = 0;

// Skip spaces
void skip_spaces() {
    while (isspace(input[pos])) pos++;
}

// id → letter/_ (then letter/digit/_)
// OR integer → digit+
bool parse_id() {
    skip_spaces();

    // Case 1: integer
    if (isdigit(input[pos])) {
        while (isdigit(input[pos])) pos++;
        return true;
    }

    // Case 2: identifier
    if (isalpha(input[pos]) || input[pos] == '_') {
        pos++;
        while (isalnum(input[pos]) || input[pos] == '_')
            pos++;
        return true;
    }

    return false;
}

/*
Grammar:
F → ( E ) | id
*/
bool parse_F() {
    skip_spaces();

    if (input[pos] == '(') {
        pos++;
        if (!parse_E()) return false;

        skip_spaces();
        if (input[pos] == ')') {
        pos++;
        return true;
        }
        return false;
    }

    return parse_id();
}

/*
T' → * F T' | / F T' | ε
*/
bool parse_Tdash() {
    skip_spaces();

    while (input[pos] == '*' || input[pos] == '/') {
        char op = input[pos];
        pos++;

        if (!parse_F()) return false;

        skip_spaces();
    }

    return true;  // ε allowed
}

/*
T → F T'
*/
bool parse_T() {
    if (!parse_F()) return false;
    return parse_Tdash();
}

/*
E' → + T E' | - T E' | ε
*/
bool parse_Edash() {
    skip_spaces();

    while (input[pos] == '+' || input[pos] == '-') {
        char op = input[pos];
        pos++;

        if (!parse_T()) return false;

        skip_spaces();
    }

    return true; // ε allowed
}

/*
E → T E'
*/
bool parse_E() {
    if (!parse_T()) return false;
    return parse_Edash();
}

int main() {
    cout << "Enter expression: ";
    getline(cin, input);
    input.push_back('\0');

    if (parse_E() && input[pos] == '\0')
        cout << "Valid expression.\n";
    else
        cout << "Invalid expression.\n";

    return 0;
}
