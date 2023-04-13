#include <stdio.h>
#include <stdlib.h>

int mostWordsFound(char** sentences, int sentencesSize) {
    int max = 0;

    for (int i = 0; i < sentencesSize; i++) {
        int cnt = 0;
        for (int j = 0; sentences[i][j] != '\0'; j++) {
            if (sentences[i][j] == ' ') cnt++;
        }
        if (cnt > max) max = cnt;
    }

    return max + 1;
}

int main() { return 0; }