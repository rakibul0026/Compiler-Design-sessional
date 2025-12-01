/*Design and implement in C a DFA simulator that accepts all binary strings (over 0 and 1) that end with the substring 01.  
The program should read one input string and print “Accepted” if it ends with 01, otherwise “Rejected”.
*/
#include <bits/stdc++.h>
#include<string>
using namespace std;
typedef enum
{
    s0,
    s1,
    s2

} state;

int main()
{
    string input;
    cout << "Enter a binary string :";
    cin >> input;

    state current = s0;

    for (char c : input)
    {
        if (c != '0' && c != '1')
        {
            cout << "Invalid input (only 0 and 1 allowed )" << endl;
            return 0;
        }
        switch (current)
        {
        case s0:
            if (c == '0')
                current = s1;
            else
                current = s0;
            break;

        case s1:
          if(c=='0')current=s1;
          else  current=s2;
          break;

          case s2:
          if(c=='0')current=s1;
          else current=s0;
          break;
        }
    }
    if(current==s2)
    cout<<"accepted"<<endl;
    else
    cout<<"Rejected"<<endl;
}

