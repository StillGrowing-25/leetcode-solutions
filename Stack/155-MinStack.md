# Min Stack

**Problem Link:** https://leetcode.com/problems/min-stack/

---

# Intuition

The challenge is to implement a stack that supports `push`, `pop`, `top`, and `getMin` operations in **O(1)** time.

To achieve this, each element in the stack stores two values:
- The actual value.
- The minimum value among all elements currently in the stack up to that point.

Therefore, the minimum element can always be accessed directly from the top of the stack without traversing the entire stack.

---

# Approach

1. Use a stack of pairs:
   - `first` → stores the actual value.
   - `second` → stores the minimum value up to the current node.
2. During `push`:
   - If the stack is empty, both values are `val`.
   - Otherwise, store `min(val, st.top().second)` as the current minimum.
3. During `pop`, simply remove the top pair.
4. During `top`, return `st.top().first`.
5. During `getMin`, return `st.top().second`.

Since the minimum is maintained at every level, `getMin()` takes constant time.

---

# Complexity

- **Time complexity:** `O(1)` for `push`, `pop`, `top`, and `getMin`.
- **Space complexity:** `O(n)` where `n` is the number of elements stored in the stack.

---

# Code

```cpp
class MinStack {
public:
    stack<pair<int, int>> st;

    MinStack() {
    }

    void push(int val) {
        if (st.empty())
            st.push({val, val});
        else
            st.push({val, min(val, st.top().second)});
    }

    void pop() {
        st.pop();
    }

    int top() {
        return st.top().first;
    }

    int getMin() {
        return st.top().second;
    }
};
```
