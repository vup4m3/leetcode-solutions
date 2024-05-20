# include <stdlib.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int* result = (int *) malloc(sizeof(int) * 2);
    int diff;
    *returnSize = 2;
    for (int i = 0; i < numsSize; i++) {
        diff = target - nums[i];
        for (int j = i+1; j < numsSize; j++) {
            if (diff == nums[j]) {
                result[0] = i;
                result[1] = j;
                return result;
            }
        }
    }

    return result;
}
