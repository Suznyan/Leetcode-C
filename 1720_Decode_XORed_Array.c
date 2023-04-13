#include <stdio.h>
#include <stdlib.h>

int* decode(int* encoded, int encodedSize, int first, int* returnSize) {
    int* ans = malloc(sizeof(int) * (encodedSize + 1));
    *returnSize = encodedSize + 1;
    ans[0] = first;

    for (int i = 0; i < encodedSize; i++) {
        ans[i + 1] = first ^ encoded[i];
        first = ans[i + 1];
    }

    return ans;
}

int main() { return 0; }