#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool arrayStringsAreEqual(char **word1, int word1Size, char **word2,
                          int word2Size) {
    const char *ptr1;
    const char *ptr2;

    if (word1Size && word2Size) {
        ptr1 = *word1;
        ptr2 = *word2;
    }

    do {
        if (*ptr1 == '\0' && --word1Size) ptr1 = *(++word1);
        if (*ptr2 == '\0' && --word2Size) ptr2 = *(++word2);
        if (*(ptr1++) != *(ptr2++)) return false;
    } while (word1Size && word2Size);

    return true;
}

int main() {
    char *word1[] = {"abc", "d"};
    char *word2[] = {"abcd"};

    printf(arrayStringsAreEqual(word1, 2, word2, 1) ? "true" : "false");

    return 0;
}