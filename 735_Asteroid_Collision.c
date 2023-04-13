#include <stdio.h>
#include <stdlib.h>

int* asteroidCollision(int* asteroids, int asteroidsSize, int* returnSize) {
    int top = -1;
    int* stack = malloc(asteroidsSize * sizeof(int));
    for (int i = 0; i < asteroidsSize; i++) {
        int a = asteroids[i];
        int destroyed = 0;
        while (top != -1 && stack[top] > 0 && a < 0 && !destroyed) {
            if (stack[top] >= -a) destroyed = 1;

            if (stack[top] <= -a) top--;
        }
        if (!destroyed) stack[++top] = a;
    }
    *returnSize = top + 1;
    return stack;
}

int main() {
    int asteroids[] = {10, 2, -5};
    int size = sizeof(asteroids) / sizeof(*asteroids);

    int returnSize;
    int* res = asteroidCollision(asteroids, size, &returnSize);
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", res[i]);
    }
    printf("\n");
    free(res);
    res = NULL;

    return 0;
}