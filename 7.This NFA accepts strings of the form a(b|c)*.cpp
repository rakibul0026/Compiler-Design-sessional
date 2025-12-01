/*Q7.
An NFA has two states: q0 (start) and q1 (accept).  
Transitions:
- From q0 on input a → q1
- From q1 on input b or c → q1

This NFA accepts strings of the form a(b|c)*.  
Write a C program that simulates this NFA (by tracking the set of current states) and prints whether a given input string is accepted.
*/


#include <iostream>
#include <set>
#include <string>
using namespace std;

int main()
{
    string input;
    cout << "Enter input string:";
    cin >> input;

    set<string> current_states;
    current_states.insert("q0");

    for (char c : input)
    {
        set<string> next_states;

        for (const string &state : current_states)
        {
            if (state == "q0")
            {
                if (c == 'a')
                    next_states.insert("q1");
            }
            else if (state == "q1")
            {
                if (c == 'b' || c == 'c')
                    next_states.insert("q1");
            }
        }
        current_states = next_states;
        if (current_states.empty())
            break;
    }

    if (current_states.count("q1"))
        cout << "Accepted " << endl;
    else
        cout << "Rejected" << endl;

    return 0;
}
