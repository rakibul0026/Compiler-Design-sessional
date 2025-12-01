/*Design and implement in C a DFA simulator that accepts all binary strings (over 0 and 1) that end with the substring 01.  
The program should read one input string and print “Accepted” if it ends with 01, otherwise “Rejected”.
*/
#include <stdio.h>
#include <string.h>

typedef enum { S0, S1, S2 } State;

int main() {
    char input[100];
    printf("Enter a binary string: ");
    scanf("%s", input);

    State current = S0;

    for (int i = 0; i < strlen(input); i++) {
        char c = input[i];

        if (c != '0' && c != '1') {
            printf("Invalid input (only 0 and 1 allowed)\n");
            return 0;
        }

        switch (current) {
            case S0:
                if (c == '0') current = S1;
                else current = S0;
                break;

            case S1:
                if (c == '0') current = S1;
                else current = S2;
                break;

            case S2:
                if (c == '0') current = S1;
                else current = S0;
                break;
        }
    }

    if (current == S2)
        printf("Accepted\n");
    else
        printf("Rejected\n");

    return 0;
}
