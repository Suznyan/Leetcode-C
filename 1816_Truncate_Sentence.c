#include <stdio.h>
#include <stdlib.h>

char* truncateSentence(char* s, int k) {
    char* ans = s;
    do {
        ans++;
        if (*ans == ' ')
            k--;
        else if (*ans == '\0')
            break;
    } while (k);

    *ans = '\0';

    return s;
}

int main() {
    char input[] = {"What is the solution to this problem"};
    printf("%s", truncateSentence(input, 4));
    return 0;
}