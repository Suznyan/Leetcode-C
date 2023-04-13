#include <stdio.h>
#include <stdlib.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmp(const void* a, const void* b) { return (*(int*)b - *(int*)a); }
char** sortPeople(char** names, int namesSize, int* heights, int heightsSize,
                  int* returnSize) {
    char** ans = (char**)calloc(namesSize, sizeof(char*));
    for (int i = 0; i < heightsSize; i++) heights[i] = (heights[i] << 10) + i;
    qsort(heights, heightsSize, sizeof(int), cmp);
    for (int i = 0; i < heightsSize; i++) ans[i] = names[heights[i] & 0x3FF];
    *returnSize = heightsSize;
    return ans;
}

int main() {
    int namesSize = 3;
    char** names = malloc(namesSize * sizeof(*names));
    for (int i = 0; i < namesSize; i++) {
        names[i] = malloc(20 * sizeof **names);
    }

    for (int i = 0; i < namesSize; i++) {
        scanf("%[^\n]%*c", &names[i]);
    }

    printf("%s\n", names[0]);

    free(names);
    names = NULL;

    return 0;
}