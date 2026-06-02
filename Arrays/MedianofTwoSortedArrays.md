# Median of Two Sorted Arrays

# Problem Description [Median of Two Sorted Arrays](https://leetcode.com/problems/median-of-two-sorted-arrays/description/)
-Given two sorted arrays `nums1` and `nums2` of size `m` and `n` respectively, return the median of the two sorted arrays.
-The overall run time complexity should be `O(log (m+n))`.

Example 1:
Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000

Example 2:
Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000

Constraints:
-nums1.length == m
-nums2.length == n
-0 <= m <= 1000
-0 <= n <= 1000
-1 <= m + n <= 2000
--10^6 <= nums1[i], nums2[i] <= 10^6

# Intuition
Since both arrays are already sorted, we can merge them into a single sorted array and then directly find the median element.
If the total number of elements is odd, the median is the middle element.
If the total number of elements is even, the median is the average of the two middle elements.

# Approach
1. Find the sizes of both arrays.
2. Create a new array `merged` to store all elements in sorted order.
3. Use two pointers:
   * One pointer for `nums1`
   * One pointer for `nums2`
4. Compare elements from both arrays and insert the smaller one into `merged`.
5. Add remaining elements after one array is exhausted.
6. Find the median:
   * If total size is even, average the two middle elements.
   * If total size is odd, return the middle element.

# Complexity Analysis

# Time Complexity: O(m + n)
Both arrays are traversed once while merging, so the time complexity is **O(m + n)**.

# Space Complexity: O(m + n)
An additional merged array of size `m + n` is used, so the space complexity is **O(m + n)**.

# Code
```java id="h2n4yr"
class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {

        int m = nums1.length;
        int n = nums2.length;

        int[] merged = new int[m + n];

        int i = 0, j = 0, k = 0;

        while(i < m && j < n) {

            if(nums1[i] < nums2[j])
                merged[k++] = nums1[i++];

            else
                merged[k++] = nums2[j++];
        }

        while(i < m)
            merged[k++] = nums1[i++];

        while(j < n)
            merged[k++] = nums2[j++];

        double median;

        int x = (m + n) / 2;

        if((m + n) % 2 == 0) {
            median = (merged[x] + merged[x - 1]) / 2.0;
        }

        else
            median = merged[x];

        return median;
    }
}
```
