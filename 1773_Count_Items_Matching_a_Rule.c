#include <stdio.h>
#include <stdlib.h>

int countMatches(char*** items, int itemsSize, int* itemsColSize, char* ruleKey,
                 char* ruleValue) {
    int ans = 0;
    int c = 0;

    switch (ruleKey[0]) {
        case 't':
            c = 0;
            break;
        case 'c':
            c = 1;
            break;
        case 'n':
            c = 2;
            break;
        default:
            return -1;
    }

    for (int i = 0; i < itemsSize; i++) {
        if (compareStr(items[i][c], ruleValue) == 0) ans++;
    }

    return ans;
}

int compareStr(char a[], char b[]) {
    int i = 0;
    int alen;
    int blen;

    for (alen = 0; a[alen] != '\0'; alen++)
        ;
    for (blen = 0; b[blen] != '\0'; blen++)
        ;

    if (alen != blen) return 1;

    while (a[i] != '\0' && b[i] != '\0') {
        if (a[i] != b[i]) {
            return 1;
        }
        i++;
    }

    return 0;
}

int main() {
    char** items[] = {{"phone", "blue", "pixel"},
                      {"computer", "silver", "lenovo"},
                      {"phone", "gold", "iphone"}};
    return 0;
}