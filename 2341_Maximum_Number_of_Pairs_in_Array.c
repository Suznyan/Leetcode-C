#include <uthash.h>
typedef struct {
    int key;
    int val;
    UT_hash_handle hh;
} hash_table;
hash_table *hash = NULL, *elem, *temp;

int* numberOfPairs(int* nums, int numsSize, int* returnSize) {
    int* res = malloc(2 * sizeof(int));
    res[0] = 0;
    res[1] = 0;

    for (int i = 0; i < numsSize; i++) {
        HASH_FIND_INT(hash, &nums[i], elem);
        if (elem) {
            res[0]++;
            nums[i] = -1;
            nums[elem->val] = -1;
            HASH_DEL(hash, elem);
        } else {
            elem = malloc(sizeof(hash_table));
            elem->key = nums[i];
            elem->val = i;
            HASH_ADD_INT(hash, key, elem);
        }
    }

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == -1) continue;
        res[1]++;
    }

    // free up hash table
    HASH_ITER(hh, hash, elem, temp) {
        HASH_DEL(hash, elem);
        free(elem);
    }

    *returnSize = 2;
    return res;
}