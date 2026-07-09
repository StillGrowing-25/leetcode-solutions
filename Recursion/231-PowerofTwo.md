# Power of Two

# Problem Description
[Power of Two](https://leetcode.com/problems/power-of-two/description/)

Given an integer `n`, return `true` if it is a power of two. Otherwise, return `false`.

An integer `n` is a power of two if there exists an integer `x` such that:

`n = 2^x`, where `x >= 0`.

### Example 1:
Input: n = 1  
Output: true

### Example 2:
Input: n = 16  
Output: true

### Example 3:
Input: n = 3  
Output: false

### Constraints:
- `-2^31 <= n <= 2^31 - 1`

# Intuition

A power of two can be represented as `2^x`, where `x` is a non-negative integer. Therefore, taking the base-2 logarithm of the number should result in an integer. If the logarithm value is an integer, the number is considered a power of two.

# Approach

1. If `n` is less than or equal to `0`, return `false` since powers of two are always positive.
2. Compute the base-2 logarithm of `n` using `log2()`.
3. Convert the logarithm value to an integer.
4. Compare the logarithm value with the integer value (or the next integer).
5. If either comparison is true, return `true`; otherwise, return `false`.

# Complexity Analysis

## Time Complexity: O(1)

Computing the logarithm and performing comparisons take constant time.

## Space Complexity: O(1)

No extra space is used apart from a few variables.

# Code

```cpp
class Solution {
public:
    bool isPowerOfTwo(int n) {

        if (n <= 0)
            return false;

        double x = log2(n);
        int y = (int)x;
        int z = y + 1;

        if (x == y || x == z)
            return true;
        else
            return false;
    }
};
```
