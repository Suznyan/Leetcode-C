#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool* kidsWithCandies(int* candies, int candiesSize, int extraCandies,
                      int* returnSize) {
    bool* ans = malloc(sizeof(bool) * candiesSize);
    *returnSize = candiesSize;
    int max = 0;

    for (int i = 0; i < candiesSize; i++) {
        if (candies[i] > max) max = candies[i];
    }

    for (int i = 0; i < candiesSize; i++) {
        if ((candies[i] + extraCandies) >= max) {
            ans[i] = true;
        } else
            ans[i] = false;
    }

    return ans;
}

int main() {
    int input[] = {4,2,1,1,2};
    int extraCan = 1;
    int returnSize;

    bool* ans = kidsWithCandies(input, sizeof(input) / sizeof(*input), extraCan,
                                &returnSize);

    for (int i = 0; i < returnSize; i++) {
        printf("%s ", ans[i] ? "true" : "false");
    }

    free(ans);

    return 0;
}