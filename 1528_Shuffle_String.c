#include <stdio.h>
#include <stdlib.h>

char* restoreString(char* s, int* indices, int indicesSize) {
    char* ans = malloc(sizeof(char) * indicesSize);
    int i;
    for (i = 0; i < indicesSize; i++) {
        ans[indices[i]] = s[i];
    }

    for (i = 0; i < indicesSize; i++) s[i] = ans[i];

    return s;
}

int main() {
    char s[] = "codeleet";
    int indices[] = {4, 5, 6, 7, 0, 2, 1, 3};   

    printf("%s", restoreString(s, indices, sizeof(indices) / sizeof(*indices)));

    return 0;
}