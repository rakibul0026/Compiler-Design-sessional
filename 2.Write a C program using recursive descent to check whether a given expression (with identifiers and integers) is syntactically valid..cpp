/*Q2.
Consider the expression grammar:

- E → T E'
- E' → + T E' | - T E' | ε
- T → F T'
- T' → * F T' | / F T' | ε
- F → ( E ) | id

Write a C program using recursive descent to check whether a given expression (with identifiers and integers) is syntactically valid.*/

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string s;
int i = 0;

bool id() {
    if (!(isalpha(s[i]) || s[i] == '_'))
        return false;

    i++;
    while (isalnum(s[i]) || s[i] == '_')
        i++;

    return true;
}

bool number() {
    if (!isdigit(s[i]))
        return false;

    while (isdigit(s[i]))
        i++;

    return true;
}

bool E(), Ep(), T(), Tp(), F();

bool F() {
    if (s[i] == '(') {
        i++;  // consume '('
        if (!E()) return false;
        if (s[i] != ')') return false;
        i++;  // consume ')'
        return true;
    }

    if (id() || number())
        return true;

    return false;
}

bool Tp() {
    if (s[i] == '*' || s[i] == '/') {
        i++;           // consume operator
        if (!F()) return false;
        return Tp();   // recursive
    }
    return true;       // ε
}

bool T() {
    return F() && Tp();
}

bool Ep() {
    if (s[i] == '+' || s[i] == '-') {
        i++;         // operator
        if (!T()) return false;
        return Ep(); // recursive
    }
    return true;     // ε
}

bool E() {
    return T() && Ep();
}

int main() {
    cout << "Enter expression: ";
    getline(cin, s);
    s.push_back('\0'); // end marker

    if (E() && s[i] == '\0')
        cout << "Valid expression\n";
    else
        cout << "Invalid expression\n";

    return 0;
}
