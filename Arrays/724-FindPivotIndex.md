# 724. Find Pivot Index

## Problem Link
[LeetCode - 724. Find Pivot Index](https://leetcode.com)

## Problem Description
Given an array of integers `nums`, calculate the **pivot index** of this array.

The **pivot index** is the index where the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the right of the index.

If the index is on the left edge of the array, then the left sum is `0` because there are no elements to the left. This also applies to the right edge of the array.

Return the *leftmost pivot index*. If no such index exists, return `-1`.

---

## Approach & Intuition
To find the pivot index efficiently, we can use a **Prefix Sum / Running Sum** technique instead of calculating the left and right sums from scratch at every single position.

1. **Total Sum Tracking**: We first compute the total sum of all elements in the array (`sum`). 
2. **Dynamic Comparison**: As we iterate through the array, we maintain a running sum of all elements encountered so far to represent the left sum (`ls`).
3. **Right Sum Derivation**: Instead of iterating to the right to compute the right sum, we can calculate it instantly using algebra:
   $$\text{Right Sum} = \text{Total Sum} - \text{Left Sum} - \text{Current Element}$$
4. **Pivot Check**: At each index `i`, we check if $\text{Left Sum} == \text{Right Sum}$ (or `ls == sum - ls - nums[i]`). The first index where this condition holds true is our leftmost pivot index.

This avoids an $O(n^2)$ nested loop approach and brings the time complexity down to a single linear scan after initialization.

---

## Test Cases

### Example 1
* **Input:** `nums = [1, 7, 3, 6, 5, 6]`
* **Output:** `3`
* **Explanation:**
  The pivot index is 3.
  * Left sum = `nums[0] + nums[1] + nums[2]` = `1 + 7 + 3 = 11`
  * Right sum = `nums[4] + nums[5]` = `5 + 6 = 11`

### Example 2
* **Input:** `nums = [1, 2, 3]`
* **Output:** `-1`
* **Explanation:**
  There is no index that satisfies the conditions in the array.

### Example 3
* **Input:** `nums = [2, 1, -1]`
* **Output:** `0`
* **Explanation:**
  The pivot index is 0.
  * Left sum = `0` (no elements to the left of index 0)
  * Right sum = `nums[1] + nums[2]` = `1 + (-1) = 0`

---

## Solution (Java)

```java
class Solution {
    public int pivotIndex(int[] nums) {
        int sum = 0, ls = 0;
        
        // Calculate the total sum of the array
        for (int i = 0; i < nums.length; i++) {
            sum += nums[i];
        }
        
        // Find the pivot index where left sum equals right sum
        for (int i = 0; i < nums.length; i++) {
            // sum - ls - nums[i] represents the right sum at index i
            if (ls == sum - ls - nums[i]) {
                return i;
            }
            ls += nums[i];
        }
        
        return -1;
    }
}
```

---

## Complexity Analysis

| Complexity | Notation | Description |
| :--- | :--- | :--- |
| **Time Complexity** | $O(n)$ | We iterate through the array twice: once to calculate the total sum ($O(n)$) and once to find the pivot index ($O(n)$). Total time scales linearly with array size $n$. |
| **Space Complexity** | $O(1)$ | No extra data structures or memory arrays are allocated; we only maintain a few integer variables (`sum`, `ls`) which use constant space. |
