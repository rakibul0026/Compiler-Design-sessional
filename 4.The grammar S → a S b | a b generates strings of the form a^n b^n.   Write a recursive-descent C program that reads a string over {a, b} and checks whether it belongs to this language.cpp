/*Q4.
The grammar S → a S b | a b generates strings of the form a^n b^n.  
Write a recursive-descent C program that reads a string over {a, b} and checks whether it belongs to this language.
*/

#include <bits/stdc++.h>
using namespace std;
char input[100];
int pos = 0;
int parse_s()
{
    if (input[pos] != 'a')
        return 0;

    pos++;

    if (input[pos] == 'a')
    {
        if (!parse_s())
            return 0;

        if (input[pos] == 'b')
        {
            pos++;
            return 1;
        }
        return 0;
    }
    if (input[pos] == 'b')
    {
        pos++;
        return 1;
    }
    return 0;
}
int main()
{
    cout << "Enter string over {a,b} :";
    cin >> input;
    if (parse_s() && input[pos] == '\0')
    {
        cout << "Valid:Belong to a^n b^n language ." << endl;
    }
    else
        cout << "Invalid string" << endl;
}
