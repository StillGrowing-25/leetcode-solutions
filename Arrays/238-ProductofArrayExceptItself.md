# [LeetCode 238] Product of Array Except Self

## 🔗 Quick Links
- **Problem Link:** [LeetCode - Product of Array Except Self](https://leetcode.com/problems/product-of-array-except-self/)
- **Difficulty:** Medium
- **Topics:** Array, Prefix Sum

---

## 📝 Problem Description
Given an integer array `nums`, return an array `answer` such that `answer[i]` is equal to the product of all the elements of `nums` except `nums[i]`.

The product of any prefix or suffix of `nums` is guaranteed to fit in a 32-bit integer.

**Constraints:**
- You must write an algorithm that runs in $O(n)$ time.
- You cannot use the division operation.

---

## 💡 Intuition
Since division is prohibited, calculating the total product of the array and dividing by each element isn't an option. However, the product of all numbers except `nums[i]` is simply the product of all numbers to its left multiplied by all numbers to its right. We can precompute or dynamically compute these prefix and suffix products to construct the final array efficiently.

## 🛠️ Approach (In-Place Two Passes)
1. **Initialize Output:** Create an output array `ans` of size `n` and fill it with `1`.
2. **Prefix Pass:** Loop from left to right. Accumulate the running product of elements seen so far and store it in `ans[i]`. After this pass, `ans[i]` contains the product of all elements strictly to the left of `i`.
3. **Suffix Pass:** Loop from right to left. Maintain a variable `suffixProduct` (initially `1`). In each step, multiply `ans[i]` by `suffixProduct`, then update `suffixProduct` by multiplying it with `nums[i]`.
4. By using the output array to store the prefixes and tracking suffixes dynamically with a single variable, we completely avoid using extra space.

---

## 📊 Complexity Analysis

- **Time Complexity:** $\mathcal{O}(n)$
  - Requires exactly two linear passes through the array of length $n$.
- **Space Complexity:** $\mathcal{O}(1)$
  - Excludes the output array `ans` as requested by the problem statement. The algorithm only uses one auxiliary tracking integer (`suffixProduct`).

---

## 💻 C++ Source Code

```cpp
#include <vector>

class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> ans(n, 1);
        
        // Pass 1: Accumulate prefix products directly into the answer array
        for (int i = 1; i < n; ++i) {
            ans[i] = ans[i - 1] * nums[i - 1];
        }
        
        // Pass 2: Multiply with suffix products on the fly from right to left
        int suffixProduct = 1;
        for (int i = n - 1; i >= 0; --i) {
            ans[i] *= suffixProduct;
            suffixProduct *= nums[i];
        }
        
        return ans;
    }
};
```
