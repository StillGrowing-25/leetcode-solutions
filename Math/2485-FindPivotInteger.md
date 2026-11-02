# Find the Pivot Integer

# Problem Description [Find the Pivot Integer](https://leetcode.com)
-Given a positive integer `n`, find the pivot integer `x` such that:
  * The sum of all elements between `1` and `x` inclusively equals the sum of all elements between `x` and `n` inclusively.
-Return the pivot integer `x`. If no such integer exists, return `-1`. It is guaranteed that there will be at most one pivot index for the given input.

Example 1:
Input: n = 8
Output: 6

Example 2:
Input: n = 1
Output: 1

Example 3:
Input: n = 4
Output: -1

Constraints:
- `1 <= n <= 1000`

# Intuition
The sum of numbers from `1` to `x` is given by the formula $\frac{x(x + 1)}{2}$. The sum of numbers from `x` to `n` can be written as the total sum minus the prefix sum up to $x-1$, which is $\frac{n(n + 1)}{2} - \frac{x(x - 1)}{2}$. 

Setting these two expressions equal yields:
$$\frac{x(x + 1)}{2} = \frac{n(n + 1)}{2} - \frac{x(x - 1)}{2}$$

Expanding both sides gives:
$$\frac{x^2 + x}{2} = \frac{n(n + 1)}{2} - \frac{x^2 - x}{2}$$

$$\frac{x^2 + x + x^2 - x}{2} = \frac{n(n + 1)}{2}$$

$$\frac{2x^2}{2} = \frac{n(n + 1)}{2}$$

$$x^2 = \frac{n(n + 1)}{2}$$

Therefore, $x = \sqrt{\frac{n(n + 1)}{2}}$. If the total sum $\frac{n(n + 1)}{2}$ is a perfect square, its integer square root is our pivot element `x`. Otherwise, no valid pivot integer exists.

# Approach
1. Compute the total sum of integers from `1` to `n` using the formula `totalSum = (n * (n + 1)) / 2`.
2. Find the integer square root of `totalSum` using `Math.sqrt()`.
3. Check if squaring this integer result gives back the exact value of `totalSum`.
4. If it matches, return the calculated square root as the pivot integer.
5. If it does not match, return `-1`.

# Complexity Analysis
# Time Complexity: O(1)
The calculation relies strictly on arithmetic formulas and a single built-in square root operation, yielding a constant time complexity of **O(1)**.

# Space Complexity: O(1)
No additional memory or data structures are allocated, keeping the auxiliary space complexity at **O(1)**.

# Code
```java
class Solution {
    public int pivotInteger(int n) {
        int totalSum = (n * (n + 1)) / 2;
        int x = (int) Math.sqrt(totalSum);

        if (x * x == totalSum) {
            return x;
        }

        return -1;
    }
}
```
