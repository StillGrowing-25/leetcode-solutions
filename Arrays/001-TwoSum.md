# Two Sum

# Problem Description [Two Sum](https://leetcode.com/problems/two-sum/description/)
-Given an array of integers `nums` and an integer `target`, return indices of the two numbers such that they add up to `target`.
-You may assume that each input would have exactly one solution, and you may not use the same element twice.
-You can return the answer in any order.

Example 1:
Input: nums = [2,7,11,15], target = 9
Output: [0,1]

Example 2:
Input: nums = [3,2,4], target = 6
Output: [1,2]

Example 3:
Input: nums = [3,3], target = 6
Output: [0,1]

Constraints:
-2 <= nums.length <= 10^4
--10^9 <= nums[i] <= 10^9
--10^9 <= target <= 10^9
-Only one valid answer exists.

# Intuition
The idea is to check every possible pair of numbers in the array and find the pair whose sum equals the target value.
Since each input has exactly one solution, once we find the correct pair, we can immediately return their indices.

# Approach
1. Create an array to store the result indices.
2. Use two nested loops:
   * The outer loop selects one element.
   * The inner loop checks all elements after it.
3. If the sum of two elements equals the target:
   * Return their indices.
4. If no pair is found, return `null`.

# Complexity Analysis
# Time Complexity: O(n²)
Two nested loops are used to check every possible pair in the array, resulting in a time complexity of **O(n²)**.

# Space Complexity: O(1)
Only a few extra variables are used, so the space complexity is **O(1)**.

# Code
```java
class Solution {
    public int[] twoSum(int[] nums, int target) {
        int[] obj = new int[2];

        for(int i = 0; i < nums.length; i++) {
            for(int j = i + 1; j < nums.length; j++) {

                if((nums[i] + nums[j]) == target) {
                    return new int[] {i, j};
                }
            }
        }

        return null;
    }
}
```
