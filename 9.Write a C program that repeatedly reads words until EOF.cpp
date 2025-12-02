/*Q9.
Write a C program that repeatedly reads words until EOF and classifies each word as:
- a C keyword (from a small fixed list, e.g., int, if, else, for, while, return, char, float, double, void),
- a valid identifier,
- or an invalid token.

Print the classification for each word.
*/
#include <iostream>
#include <string>
#include <cctype>
#include <set>
using namespace std;

set<string> keywords = {
    "int", "if", "else", "for", "while", "return", "char", "float", "double", "void"};

bool isIdentifier(const string &word)
{
    if (word.empty())
        return false;

    if (!isalpha(word[0]) && word[0] != '_')
        return false;

    for (size_t i = 1; i < word.length(); i++)
    {
        if (!isalnum(word[i]) && word[i] != '_')
            return false;
    }
    return true;
}

int main()
{
    string word;

    cout << "Enter words (Ctrl+D to end input on Unix, Ctrl+Z on Windows):\n";

    while (cin >> word)
    {
        if (keywords.count(word))
        {
            cout << word << " : Keyword\n";
        }
        else if (isIdentifier(word))
        {
            cout << word << " : Valid Identifier\n";
        }
        else
        {
            cout << word << " : Invalid Token\n";
        }
    }

    return 0;
}
