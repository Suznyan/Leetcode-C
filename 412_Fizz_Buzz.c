#include <stdio.h>
#include <stdlib.h>

void add(char* str, char* word, char** next) {
    while (*word != '\0') *str++ = *word++;
    *next = str;
}

char* FBCompute(int num) {
    char* str = malloc(9 * sizeof(char));
    for (int i = 0; i < 9; i++) str[i] = '\0';
    char* p = str;
    if (num % 3 != 0 && num % 5 != 0) sprintf(p, "%d", num);
    if (num % 3 == 0) add(p, "Fizz", &p);
    if (num % 5 == 0) add(p, "Buzz", &p);
    return str;
}

char** fizzBuzz(int n, int* returnSize) {
    char** res = malloc(n * sizeof *res);
    for (int i = 0; i < n; i++) res[i] = FBCompute(i + 1);
    *returnSize = n;
    return res;
}

int main() {
    int n;
    printf("n = ");
    scanf("%d", &n);
    int returnSize;
    char** str = fizzBuzz(n, &returnSize);
    printf("[");
    for (int i = 0; i < returnSize; i++) {
        printf("\"%s\"", str[i]);
        if (i < returnSize - 1) printf(",");
    }
    printf("]");
    free(str);
    str = NULL;
    return 0;
}