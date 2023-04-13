#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <uthash.h>

typedef struct {
    int key;
    int val;
    UT_hash_handle hh;
} hash_table;
hash_table *hash = NULL, *elem, *tmp;

bool containsNearbyDuplicate(int *nums, int numsSize, int k) {
    int flag = 0;
    for (int i = 0; i < numsSize; i++) {
        HASH_FIND_INT(hash, &nums[i], elem);
        if (elem) {
            if (abs((elem->val) - i) <= k) {
                flag = 1;
                break;
            } else
                elem->val = i;
        } else {
            elem = malloc(sizeof(hash_table));
            elem->key = nums[i];
            elem->val = i;
            HASH_ADD_INT(hash, key, elem);
        }
    }

    // free up hash table
    HASH_ITER(hh, hash, elem, tmp) {
        HASH_DEL(hash, elem);
        free(elem);
    }

    return flag ? true : false;
}

int main() {
    int nums[] = {1, 0, 1, 1};
    int k = 1;
    int size = sizeof(nums) / sizeof(*nums);

    printf(containsNearbyDuplicate(nums, size, k) ? "true" : "false");

    return 0;
}