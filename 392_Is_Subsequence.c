#include <stdbool.h>
#include <stdio.h>

bool isSubsequence(char* s, char* t) {
    for (;;) {
        if (*s == '\0' || *t == '\0') break;
        if (*s == *t) s++;
        t++;
    }
    return !*s;
}

int main() {
    char* a = "ac";
    char* b = "bcadc";
    bool check = isSubsequence(a, b);
    printf(check ? "true" : "false");
    printf("\n");
    return 0;
}