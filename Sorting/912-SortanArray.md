# Sort an Array

# Problem Description [Sort an Array](https://leetcode.com/problems/sort-an-array/description/)

Given an array of integers `nums`, sort the array in ascending order and return it.

You must solve the problem without using built-in functions to sort the array.

**Example 1:**

Input: `nums = [5,2,3,1]`

Output: `[1,2,3,5]`

**Example 2:**

Input: `nums = [5,1,1,2,0,0]`

Output: `[0,0,1,1,2,5]`

**Constraints:**
- `1 <= nums.length <= 5 * 10^4`
- `-5 * 10^4 <= nums[i] <= 5 * 10^4`

# Intuition

Merge Sort uses the divide-and-conquer technique. We divide the array into smaller halves, sort them recursively, and merge the sorted halves to obtain the final sorted array.

# Approach

1. Find the middle index and divide the array into two halves.
2. Recursively sort both halves until each contains a single element.
3. Merge the two sorted halves by comparing their elements and placing the smaller element first.
4. Copy any remaining elements into the original array.
5. Return the sorted array.

# Complexity Analysis

**Time Complexity: O(n log n)**

The array is divided into halves at each level, and merging takes O(n) time per level.

**Space Complexity: O(n)**

Temporary arrays are used during merging.

# Code

```java
class Solution {
    void merge(int[] nums, int l, int mid, int h) {
        int n1 = mid - l + 1;
        int n2 = h - mid;

        int[] a = new int[n1];
        int[] b = new int[n2];

        for (int x = 0; x < n1; x++) {
            a[x] = nums[l + x];
        }

        for (int x = 0; x < n2; x++) {
            b[x] = nums[mid + x + 1];
        }

        int i = 0, j = 0, k = l;

        while (i < n1 && j < n2) {
            if (a[i] <= b[j])
                nums[k++] = a[i++];
            else
                nums[k++] = b[j++];
        }

        while (i < n1) {
            nums[k++] = a[i++];
        }

        while (j < n2) {
            nums[k++] = b[j++];
        }
    }

    void mergeSort(int[] nums, int left, int right) {
        if (left >= right)
            return;

        int mid = left + (right - left) / 2;

        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);
        merge(nums, left, mid, right);
    }

    public int[] sortArray(int[] nums) {
        if (nums == null || nums.length <= 1)
            return nums;

        mergeSort(nums, 0, nums.length - 1);
        return nums;
    }
}
```
