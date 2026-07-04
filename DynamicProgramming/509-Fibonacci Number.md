# 509. Fibonacci Number | Recursion & Dynamic Programming | C++

## 📝 Problem
Given an integer `n`, return the `n`th Fibonacci number.

The Fibonacci sequence is defined as:

- `F(0) = 0`
- `F(1) = 1`
- `F(n) = F(n - 1) + F(n - 2)`, for `n > 1`

**LeetCode:** https://leetcode.com/problems/fibonacci-number/

---

# Solution 1: Recursive Approach

## 💡 Intuition
The Fibonacci sequence follows a simple recursive pattern where each number is the sum of the previous two numbers.

- If `n = 0`, return `0`.
- If `n = 1`, return `1`.
- Otherwise, recursively calculate the previous two Fibonacci numbers and return their sum.

### 🚀 Approach
1. Handle the base cases (`n == 0` and `n == 1`).
2. Recursively call:
   - `fib(n - 1)`
   - `fib(n - 2)`
3. Return their sum.

### ⏱️ Complexity
- **Time Complexity:** `O(2^n)`
- **Space Complexity:** `O(n)`

### 💻 Code

```cpp
class Solution {
public:
    int fib(int n) {
        if (n == 0 || n == 1)
            return n;

        return fib(n - 1) + fib(n - 2);
    }
};
```

---

# Solution 2: Dynamic Programming (Bottom-Up)

## 💡 Intuition
The recursive solution recalculates the same Fibonacci values many times. Dynamic Programming stores previously computed values, eliminating redundant calculations and making the solution much more efficient.

### 🚀 Approach
1. Create a DP array of size `n + 1`.
2. Initialize:
   - `dp[0] = 0`
   - `dp[1] = 1`
3. Iterate from `2` to `n`:
   - `dp[i] = dp[i - 1] + dp[i - 2]`
4. Return `dp[n]`.

### ⏱️ Complexity
- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(n)`

### 💻 Code

```cpp
class Solution {
public:
    int fib(int n) {
        if (n <= 1)
            return n;

        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = 1;

        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
};
```

---

## 📊 Comparison

| Approach | Time Complexity | Space Complexity |
|----------|-----------------|------------------|
| Recursion | `O(2^n)` | `O(n)` |
| Dynamic Programming | `O(n)` | `O(n)` |

