# 227. Basic Calculator II

## Problem Link
- [LeetCode 227 - Basic Calculator II](https://leetcode.com/problems/basic-calculator-ii/)

## Intuition
The problem requires us to evaluate a mathematical expression string containing non-negative integers, `+`, `-`, `*`, `/`, and spaces. 

Since multiplication (`*`) and division (`/`) have higher precedence than addition (`+`) and subtraction (`-`), we cannot simply evaluate the expression from left to right. 

We can solve this efficiently in $O(n)$ time using a single pass with the help of a `lastNum` variable (instead of a full stack):
1. **Iterate through the string** character by character.
2. If the character is a digit, build the current number (`currNum`).
3. If the character is an operator (`+`, `-`, `*`, `/`) or we have reached the **end of the string**:
   - If the previous operator was `+` or `-`, we add `lastNum` to our final result (`res`) and update `lastNum` to either `currNum` or `-currNum` (accounting for the sign).
   - If the previous operator was `*` or `/`, we perform the operation immediately on `lastNum` and `currNum` to respect operator precedence.
4. After the loop finishes, add any remaining `lastNum` to `res`.

## Complexity Analysis

- **Time Complexity:** $O(n)$, where $n$ is the length of the string `s`. We traverse the input string in a single pass.
- **Space Complexity:** $O(1)$, as we only use a few constant extra variables (`currNum`, `lastNum`, `res`, `prevop`) regardless of the input size, avoiding the use of an explicit stack.

## Code

```java
class Solution {
    public int calculate(String s) {
        int currNum = 0;
        int prevop = '+';
        char ch;
        int res = 0;
        int lastNum = 0;
        for (int i = 0; i < s.length(); i++) {
            ch = s.charAt(i);
            if (Character.isDigit(ch)) {
                currNum = currNum * 10 + (ch - '0');
            }
            if ((!Character.isDigit(ch) && !Character.isWhitespace(ch)) || i == s.length() - 1) {
                if (prevop == '+' || prevop == '-') {
                    res += lastNum;
                    lastNum = (prevop == '-') ? -currNum : currNum;
                } else if (prevop == '*') {
                    lastNum *= currNum;
                } else if (prevop == '/') {
                    lastNum /= currNum;
                }
                prevop = ch;
                currNum = 0;
            }
        }
        res += lastNum;
        return res;
    }
}
