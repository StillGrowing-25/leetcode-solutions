# Maximum Average Subarray I

# Problem Description [Maximum Average Subarray I](https://leetcode.com/problems/maximum-average-subarray-i/description/)

You are given an integer array `nums` consisting of `n` elements and an integer `k`.

Find a contiguous subarray whose length is equal to `k` that has the maximum average value and return this value.

Any answer with a calculation error less than \(10^{-5}\) will be accepted.

**Example 1:**

Input: `nums = [1,12,-5,-6,50,3], k = 4`

Output: `12.75000`

Explanation: The subarray `[12,-5,-6,50]` has the maximum average value.

\[
\frac{12-5-6+50}{4}=\frac{51}{4}=12.75
\]

**Example 2:**

Input: `nums = [5], k = 1`

Output: `5.00000`

**Constraints:**

- `n == nums.length`
- `1 <= k <= n <= 10^5`
- `-10^4 <= nums[i] <= 10^4`

# Intuition

The problem requires finding the maximum average of a subarray of fixed length `k`.

A **fixed-size sliding window** is optimal because we can calculate the sum of the first `k` elements and then slide the window one position at a time. Instead of recalculating the entire sum, we subtract the element leaving the window and add the new element entering it.

# Approach

1. Initialize `start` and `end` to `0`, and initialize `sum` to `0`.
2. Initialize `max` to `Integer.MIN_VALUE` to handle arrays containing negative numbers.
3. Traverse the array using `end` and add `nums[end]` to `sum`.
4. When the window size equals `k`:
   - Update `max` with the maximum of `max` and `sum`.
   - Subtract `nums[start]` from `sum`.
   - Increment `start` to slide the window forward.
5. Increment `end` to continue traversing the array.
6. Return `max / k` as a `double`.

# Complexity Analysis

**Time Complexity: O(n)**

Each element is visited once as the `end` pointer moves through the array. Therefore, the time complexity is **O(n)**.

**Space Complexity: O(1)**

Only a constant number of variables are used, so the auxiliary space complexity is **O(1)**.

# Code

```java
class Solution {
    public double findMaxAverage(int[] nums, int k) {

        int start = 0, end = 0, n = nums.length;
        double sum = 0;
        double max = Integer.MIN_VALUE;

        while (end < n) {
            sum += nums[end];

            if (end - start + 1 == k) {
                max = Math.max(max, sum);
                sum -= nums[start];
                start++;
            }

            end++;
        }

        return max / k;
    }
}
```
