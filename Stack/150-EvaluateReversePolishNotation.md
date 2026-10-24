# Evaluate Reverse Polish Notation

**Problem Link:** [LeetCode 150 – Evaluate Reverse Polish Notation](https://leetcode.com/problems/evaluate-reverse-polish-notation/)

## Problem Description

You are given an array of strings `tokens` that represents an arithmetic expression in Reverse Polish Notation (RPN).

Evaluate the expression and return an integer representing its value.

Valid operators are `+`, `-`, `*`, and `/`. Integer division truncates toward zero.

### Examples

**Example 1:**
- Input: `tokens = ["2","1","+","3","*"]`
- Output: `9`
- Explanation: `((2 + 1) * 3) = 9`

**Example 2:**
- Input: `tokens = ["4","13","5","/","+"]`
- Output: `6`
- Explanation: `(4 + (13 / 5)) = 6`

**Example 3:**
- Input: `tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]`
- Output: `22`

### Constraints
- `1 <= tokens.length <= 10^4`
- `tokens[i]` is an operator or an integer in the range `[-200, 200]`.
- Division between two integers always truncates toward zero.
- The input expression is a valid Reverse Polish Notation expression.

## Intuition

Use a **stack** to evaluate the expression. In Reverse Polish Notation, each operator comes after its operands. A stack stores numbers until an operator appears, at which point the required operands are popped, the operation is performed, and the result is pushed back.

## Approach

1. Create an empty stack of integers.
2. Traverse each token in the array.
3. If the token is a number, convert it to an integer and push it onto the stack.
4. If the token is an operator:
   - Pop the second operand `b`.
   - Pop the first operand `a`.
   - Perform the operation `a operator b`.
   - Push the result onto the stack.
5. After processing all tokens, the stack contains the final result. Pop and return it.

**Important:** Pop `b` before `a` because subtraction and division are order-dependent.

## Complexity Analysis

- **Time Complexity:** `O(n)` — Each token is processed once, with constant-time stack operations.
- **Space Complexity:** `O(n)` — The stack can store up to `n` operands.

## Code

```java
import java.util.Stack;

class Solution {
    public int evalRPN(String[] tokens) {
        Stack<Integer> st = new Stack<>();

        for (String token : tokens) {
            if (token.equals("+") || token.equals("-") ||
                token.equals("*") || token.equals("/")) {

                int b = st.pop();
                int a = st.pop();

                switch (token) {
                    case "+":
                        st.push(a + b);
                        break;
                    case "-":
                        st.push(a - b);
                        break;
                    case "*":
                        st.push(a * b);
                        break;
                    case "/":
                        st.push(a / b);
                        break;
                }
            } else {
                st.push(Integer.parseInt(token));
            }
        }

        return st.pop();
    }
}
```
