# Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold

# Problem Description [Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold](https://leetcode.com/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold/)

Given an array of integers `arr` and two integers `k` and `threshold`, return the number of sub-arrays of size `k` whose average is greater than or equal to `threshold`.

**Example 1:**

Input: `arr = [2,2,2,2,5,5,5,8], k = 3, threshold = 4`

Output: `3`

Explanation: Sub-arrays `[2,5,5]`, `[5,5,5]`, and `[5,5,8]` have averages greater than or equal to `4`.

**Example 2:**

Input: `arr = [11,13,17,23,29,31,7,5,2,3], k = 3, threshold = 5`

Output: `6`

# Intuition

We need to count all sub-arrays of size `k` whose average is at least `threshold`.

Instead of calculating the average for every sub-array, we can compare its sum with `threshold * k`. Since every sub-array contains exactly `k` elements:

`average >= threshold` is equivalent to `sum >= threshold * k`.

A sliding window allows us to calculate each window's sum efficiently.

# Approach

1. Initialize `count` to `0` and `sum` to `0`.
2. Use two pointers, `start` and `end`, to maintain a window of size `k`.
3. Add `arr[end]` to the running sum.
4. When the window size becomes `k`:
   - If `sum >= threshold * k`, increment `count`.
   - Remove `arr[start]` from the sum.
   - Move `start` forward to slide the window.
5. Move `end` forward and repeat until the array is traversed.
6. Return `count`.

# Complexity Analysis

**Time Complexity:** `O(n)` — Each element is added to and removed from the sliding window at most once.

**Space Complexity:** `O(1)` — Only a constant number of variables are used.

# Code

```java
class Solution {
    public int numOfSubarrays(int[] arr, int k, int threshold) {
        int count = 0;
        int start = 0, end = 0, n = arr.length;
        double sum = 0;
        double max = Integer.MIN_VALUE;

        while (end < n) {
            sum += arr[end];

            if (end - start + 1 == k) {
                if (sum >= threshold * k)
                    count++;

                sum -= arr[start];
                start++;
            }

            end++;
        }

        return count;
    }
}
```
