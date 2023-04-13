#include <stdio.h>
#include <stdlib.h>

int finalValueAfterOperations(char** operations, int operationsSize) {
    int x = 0;
    for (int i = 0; i < operationsSize; i++) {
        operations[i][1] == '+' ? x++ : x--;
    }
    return x;
}

int main() {
    char* input[] = {"++X", "++X", "X++"};
    printf("%d",
           finalValueAfterOperations(input, sizeof(input) / sizeof(input[0])));
    return 0;
}