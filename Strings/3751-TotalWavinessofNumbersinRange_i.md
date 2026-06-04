# Total Waviness of Numbers in Range I

# Problem Description [3751. Total Waviness of Numbers in Range I](https://leetcode.com/problems/total-waviness-of-numbers-in-range-i/)

Given two integers `num1` and `num2` representing an inclusive range `[num1, num2]`.

The waviness of a number is defined as the total count of its peaks and valleys:

- A digit is a peak if it is strictly greater than both of its immediate neighbors.
- A digit is a valley if it is strictly less than both of its immediate neighbors.
- The first and last digits of a number cannot be peaks or valleys.
- Any number with fewer than 3 digits has a waviness of 0.

Return the total sum of waviness for all numbers in the range `[num1, num2]`.

Example 1:
Input: num1 = 120, num2 = 130
Output: 3

Example 2:
Input: num1 = 198, num2 = 202
Output: 3

Example 3:
Input: num1 = 4848, num2 = 4848
Output: 2

Constraints:
- 1 <= num1 <= num2 <= 10^5

# Intuition
For each number in the given range, we need to determine how many digits are peaks or valleys.

A digit can only be a peak or valley if it has both a left and right neighbor, so numbers with fewer than three digits automatically have a waviness of 0.

The simplest approach is to iterate through every number in the range, convert it into a string, and check each middle digit. If the digit is strictly greater than both neighbors, it is a peak. If it is strictly smaller than both neighbors, it is a valley. We count all such occurrences and add them to the final answer.

# Approach
1. Initialize a variable `ans` to store the total waviness.
2. Iterate through every number from `num1` to `num2`.
3. Convert the current number into a string.
4. If the number has fewer than 3 digits, its waviness is 0.
5. Traverse all middle digits:
   - Count a peak if the digit is greater than both neighbors.
   - Count a valley if the digit is smaller than both neighbors.
6. Add the waviness of the current number to the answer.
7. Return the final answer.

# Complexity Analysis

## Time Complexity
Let:
- `R = num2 - num1 + 1`
- `D = number of digits`

For each number, we scan all its digits once.

**O(R × D)**

## Space Complexity

We store the string representation of a number.

**O(D)**

# Code

```java
class Solution {

    private int waviness(long num) {
        String s = String.valueOf(num);

        if (s.length() < 3) {
            return 0;
        }

        int count = 0;

        for (int i = 1; i < s.length() - 1; i++) {
            if ((s.charAt(i) > s.charAt(i - 1) &&
                 s.charAt(i) > s.charAt(i + 1)) ||
                (s.charAt(i) < s.charAt(i - 1) &&
                 s.charAt(i) < s.charAt(i + 1))) {
                count++;
            }
        }

        return count;
    }

    public int totalWaviness(int num1, int num2) {
        int ans = 0;

        for (int num = num1; num <= num2; num++) {
            ans += waviness(num);
        }

        return ans;
    }
}
