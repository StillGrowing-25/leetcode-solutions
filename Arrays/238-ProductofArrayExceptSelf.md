# Product of Array Except Self

# Problem Description [Product of Array Except Self](https://leetcode.com)
-Given an integer array `nums`, return an array `answer` such that `answer[i]` is equal to the product of all the elements of `nums` except `nums[i]`.
-The product of any prefix or suffix of `nums` is guaranteed to fit in a 32-bit integer.
-You must write an algorithm that runs in `O(n)` time and without using the division operation.

Example 1:
Input: nums = [1,2,3,4]
Output: [24,12,8,6]

Example 2:
Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]

Constraints:
-2 <= nums.length <= 10^5
--30 <= nums[i] <= 30
-The product of any prefix or suffix of `nums` is guaranteed to fit in a 32-bit integer.

# Code
```java
class Solution {
    public int[] productExceptSelf(int[] nums) {
        int n = nums.length;
        int[] lp = new int[n];   // Left product array
        int[] ans = new int[n];  // Final answer array
        
        int prod = 1;
        // First pass: Calculate prefix products
        for (int i = 0; i < n; i++) {
            lp[i] = prod;
            prod *= nums[i];
        }
        
        prod = 1;
        // Second pass: Multiply with suffix products from the right
        for (int i = n - 1; i >= 0; i--) {
            ans[i] = lp[i] * prod;
            prod *= nums[i];
        }
        
        return ans;
    }
}
```

# Intuition
The final result for any element at index `i` is the product of all elements to its left multiplied by the product of all elements to its right. Instead of computing these from scratch for every element, we can build the running prefix products first, and then update them by iterating backward to factor in the suffix products.

# Approach
1. Initialize an array `lp` to store the prefix products (products of all elements to the left of index `i`).
2. Traverse the array from left to right, maintaining a running product `prod` that multiplies elements sequentially. Store the current `prod` at each index in `lp` before updating it with the current element.
3. Initialize the running product `prod` back to 1 to track suffix products (products of all elements to the right of index `i`).
4. Traverse the array from right to left. Multiply the prefix product stored in `lp[i]` by the running suffix product `prod`, and store the result in the final answer array `ans`.
5. Update the running suffix product `prod` with the current element at each step.

# Complexity Analysis
# Time Complexity: O(n)
The algorithm uses two separate sequential passes over the array of size `n`, resulting in a linear time complexity of **O(n)**.

# Space Complexity: O(n)
An extra array `lp` of size `n` is used to store the intermediate prefix products, leading to a space complexity of **O(n)**.
