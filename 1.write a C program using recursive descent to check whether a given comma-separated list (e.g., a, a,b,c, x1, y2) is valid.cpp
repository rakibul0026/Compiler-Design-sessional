//Q1.
Using the grammar L → id | id , L, where id is an identifier starting with a letter or _ followed by letters, digits, or _, write a C program using recursive descent to check whether a given comma-separated list (e.g., a, a,b,c, x1, y2) is valid.
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string input;
int pos = 0;

// Parse identifier: id → letter | '_' (then letters/digits/_)
bool parse_id() {
    if (!(isalpha(input[pos]) || input[pos] == '_'))
        return false;

    pos++;

    while (isalnum(input[pos]) || input[pos] == '_')
        pos++;

    return true;
}

// Skip spaces
void skip_spaces() {
    while (input[pos] == ' ')
        pos++;
}

// Grammar: L → id | id , L
bool parse_L() {

    skip_spaces();

    if (!parse_id())
        return false;

    skip_spaces();

    if (input[pos] == ',') {
        pos++;  // consume comma
        skip_spaces();
        return parse_L();  // recursive call
    }

    return true;  // no comma → done
}

int main() {
    cout << "Enter comma-separated list: ";
    getline(cin, input);

    // Add one extra '\0' to simplify boundary checking
    input.push_back('\0');

    if (parse_L() && input[pos] == '\0')
        cout << "Valid list.\n";
    else
        cout << "Invalid list.\n";

    return 0;
}
