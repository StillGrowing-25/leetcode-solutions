# Maximum Sum of Distinct Subarrays of Size K

# Problem Description [Maximum Sum of Distinct Subarrays With Length K](https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/)

Given an integer array `nums` and an integer `k`, find the maximum sum of a subarray of length `k` such that all elements in the subarray are distinct.

Return the maximum sum of such a subarray. If no such subarray exists, return `0`.

Example 1:

Input: nums = [1,5,4,2,9,9,9], k = 3  
Output: 15

Explanation: The subarrays of length 3 with distinct elements include `[1,5,4]`, `[5,4,2]`, and `[4,2,9]`. Their sums are 10, 11, and 15, respectively. The maximum sum is 15.

Example 2:

Input: nums = [4,4,4], k = 3  
Output: 0

Explanation: Every subarray of length 3 contains duplicate elements, so no valid subarray exists.

Constraints:
- `1 <= k <= nums.length <= 10^5`
- `1 <= nums[i] <= 10^5`

# Intuition

The problem requires finding the maximum sum among all subarrays of fixed length `k` whose elements are distinct.

A sliding window combined with a `HashSet` allows us to maintain a window of distinct elements and calculate its sum efficiently without repeatedly traversing the entire subarray.

# Approach

1. Initialize two pointers, `start` and `end`, at the beginning of the array.
2. Create a `HashSet` to store the distinct elements in the current window and a variable `sum` to maintain the window's sum.
3. Expand the window by moving `end` through the array.
4. If `nums[end]` already exists in the set:
   - Remove `nums[start]` from the set.
   - Subtract `nums[start]` from `sum`.
   - Increment `start`.
   - Repeat until the duplicate is removed.
5. Add `nums[end]` to the set and add its value to `sum`.
6. When the window size equals `k`:
   - Update `max` with the maximum of `max` and `sum`.
   - Remove the element at `start` from the set and subtract it from `sum`.
   - Increment `start` to slide the window forward.
7. Return `max`.

# Complexity Analysis

# Time Complexity: O(n)

Each element is added to and removed from the `HashSet` at most once. Therefore, the total time complexity is **O(n)** on average.

# Space Complexity: O(k)

The `HashSet` stores at most `k` distinct elements in the active window, resulting in **O(k)** auxiliary space.

# Code

```java
class Solution {
    public long maximumSubarraySum(int[] nums, int k) {
        int n = nums.length;
        long sum = 0, max = 0;
        int end = 0, start = 0;
        Set<Integer> set = new HashSet<>();

        while (end < n) {
            while (set.contains(nums[end])) {
                set.remove(nums[start]);
                sum -= nums[start];
                start++;
            }

            set.add(nums[end]);
            sum += nums[end];

            if (end - start + 1 == k) {
                max = Math.max(max, sum);
                sum -= nums[start];
                set.remove(nums[start]);
                start++;
            }

            end++;
        }

        return max;
    }
}
```
