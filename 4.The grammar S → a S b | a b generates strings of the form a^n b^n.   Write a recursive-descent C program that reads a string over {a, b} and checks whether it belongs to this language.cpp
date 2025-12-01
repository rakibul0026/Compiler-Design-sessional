#include <stdio.h>
#include <string.h>

char input[100];
int pos = 0;

// S → a S b | a b
int parse_S() {
    if (input[pos] != 'a') 
        return 0;          // Must start with 'a'

    pos++;                // consume 'a'

    // Check if next is 'a' → then must be a S b
    if (input[pos] == 'a') {
        if (!parse_S()) 
            return 0;

        // After recursive S, next must be 'b'
        if (input[pos] == 'b') {
            pos++;        // consume 'b'
            return 1;
        }
        return 0;
    }

    // Otherwise case: S → a b
    if (input[pos] == 'b') {
        pos++;            // consume 'b'
        return 1;
    }

    return 0;
}

int main() {
    printf("Enter string over {a, b}: ");
    scanf("%s", input);

    if (parse_S() && input[pos] == '\0')
        printf("Valid: belongs to a^n b^n language.\n");
    else
        printf("Invalid string.\n");

    return 0;
}
