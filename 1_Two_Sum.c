#include <stdio.h>
#include <stdlib.h>
#include <uthash.h>

typedef struct {
    int key;
    int val;
    UT_hash_handle hh;
} hash_table;
hash_table *hash = NULL, *elem, *tmp;

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int* res = malloc(2 * sizeof(int));
    *returnSize = 2;
    for (size_t i = 0; i < count; i++) {
    }
    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];
        HASH_FIND_INT(hash, &complement, elem);
        if (elem) {
            res[0] = elem->val;
            res[1] = i;
            break;
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

    return res;
}
