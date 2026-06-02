# Reverse Integer

# Intuition
To reverse an integer, repeatedly extract its last digit using the modulo (`%`) operator and append it to a new number. After extracting a digit, remove it from the original number by dividing by `10`.
Since the reversed number may exceed the 32-bit signed integer range `[-2^31, 2^31 - 1]`, we check for overflow during the construction of the reversed number and return `0` if it occurs.

# Approach
1. Initialize a variable `y` to store the reversed number.
2. While `x` is not zero:
   * Extract the last digit using `x % 10`.
   * Append the digit to `y` using `y = y * 10 + digit`.
   * Check whether `y` has exceeded the integer range.
   * Remove the last digit from `x` using `x /= 10`.
3. Return the reversed number if no overflow occurs.

# Complexity Analysis

# Time Complexity: O(log n)
The loop runs once for each digit in the integer. Since the number of digits in an integer `n` is proportional to `log₁₀(n)`, the time complexity is **O(log n)**.

# Space Complexity: O(1)
Only a few variables are used regardless of the input size, so the space complexity is **O(1)**.

# Code

```cpp
class Solution {
public:
    int reverse(int x) {
        long int y, d;
        y = 0;

        while (x != 0) {
            d = x % 10;
            y = y * 10 + d;

            if (y > INT_MAX || y < INT_MIN)
                return 0;

            x /= 10;
        }

        return y;
    }
};
```
