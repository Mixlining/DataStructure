//
// Created by QwQ on 2023/1/16.
//

#include "Binarysearch.h"

int search(int *nums, int numsSize, const int target) {
    //请实现查找算法,利用了有序的特性

    return search_road(nums, 0, numsSize - 1, target);

}

int search_road(int *nums, int left, int right, const int target) {
    if (left > right) {
        return -1;
    }
    int mid = (left + right) / 2;

    if (nums[mid] == target) {
        return mid;
    } else if (nums[mid] > target) {
        return search_road(nums, left, mid - 1, target);
    } else {
        return search_road(nums, mid + 1, right, target);
    }
}

void search_run() {
    int arr[] = {1, 3, 4, 6, 7, 8, 10, 11, 13, 15};
    const int target = 13;//寻找的数
    printf("%d", search(arr, sizeof(arr) / sizeof(arr[0]), target));
}
