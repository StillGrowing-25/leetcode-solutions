# Valid Parentheses

**Problem Link:** https://leetcode.com/problems/valid-parentheses/

---

# Intuition

A valid parentheses string follows a **Last In, First Out (LIFO)** pattern. Whenever an opening bracket appears, we store it in a stack. When a closing bracket appears, it must match the **most recently opened bracket**.

If the brackets do not match, or a closing bracket appears when the stack is empty, the string is invalid.

At the end, the stack must be empty for the parentheses to be valid.

---

# Approach

1. Create a stack to store opening brackets.
2. Traverse the string character by character.
3. If the character is an opening bracket `(`, `{`, or `[`, push it onto the stack.
4. If it is a closing bracket:
   - Check whether the stack is empty.
   - Compare it with the top opening bracket.
   - If they match, pop the opening bracket.
   - Otherwise, return `false`.
5. After processing the entire string:
   - If the stack is empty, return `true`.
   - Otherwise, return `false`.

---

# Complexity

- **Time complexity:** `O(n)`
  - Each character is processed once.

- **Space complexity:** `O(n)`
  - In the worst case, all characters can be opening brackets and stored in the stack.

---

# Code

```cpp
class Solution {
public:
    bool isValid(string s) {
        stack<int> st;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
                st.push(s[i]);

            else if (!st.empty()) {
                if (s[i] == ')' && st.top() == '(')
                    st.pop();

                else if (s[i] == '}' && st.top() == '{')
                    st.pop();

                else if (s[i] == ']' && st.top() == '[')
                    st.pop();

                else
                    return false;
            }

            else
                return false;
        }

        return st.empty();
    }
};
```
