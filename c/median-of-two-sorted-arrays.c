#include <stdio.h>
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int is_odd = 0;
    int num1_index = 0, num2_index = 0;
    int median_index = 0;
    double result;
    int i = 0;

    median_index  = (nums1Size + nums2Size) / 2 ;
    is_odd = (nums1Size + nums2Size) % 2;

    while (1) {
        if (!nums1Size && !nums2Size) {
            result = (double) 0;
            break;
        }

        if (num2_index >= nums2Size ||
            num1_index < nums1Size && nums1[num1_index] < nums2[num2_index]) {
            if (i == median_index) {
                if (is_odd) {
                    result = (double) nums1[num1_index];
                    break;
                } else {
                    result = (double) (nums1[num1_index] + result) / 2;
                    break;
                }

            } else {
                result = (double) nums1[num1_index];
                num1_index++;
            }
        } else {
            if (i == median_index) {
                if (is_odd) {
                    result = (double) nums2[num2_index];
                    break;
                } else {
                    result = (double) (nums2[num2_index] + result) / 2;
                    break;
                }

            } else {
                result = (double) nums2[num2_index];
                num2_index++;
            }
        }

        i++;
    }

    return result;
}

int main() {
    int nums1[2] = {1, 3};
    int nums2[1] = {2};

    printf("%f\n", findMedianSortedArrays(nums1, 2, nums2, 1));

    int nums3[2] = {1, 2};
    int nums4[2] = {3, 4};
    printf("%f\n", findMedianSortedArrays(nums3, 2, nums4, 2));
}
