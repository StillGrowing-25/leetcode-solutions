# 485. Max Consecutive Ones | Linear Scan | C++

**Problem Link:** https://leetcode.com/problems/max-consecutive-ones/

## Intuition

We need to find the longest continuous sequence of `1`s in the binary array. As we traverse the array:

- If the current element is `1`, increase the current consecutive count.
- If it is `0`, reset the count because the sequence of consecutive `1`s is broken.
- Keep updating the maximum count encountered during the traversal.

Since only one pass through the array is required, this approach is efficient.

---

## Approach

- Initialize two variables:
  - `count` to store the current streak of consecutive `1`s.
  - `max_1` to store the maximum streak found so far.
- Traverse the array from left to right.
- If the current element is `1`, increment `count`.
- Otherwise, reset `count` to `0`.
- After processing each element, update `max_1` with the maximum of `count` and `max_1`.
- Return `max_1` after the traversal.

---

## Complexity

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(1)`

---

## Code

```cpp
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0, max_1 = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1)
                count++;
            else
                count = 0;

            max_1 = max(count, max_1);
        }

        return max_1;
    }
};
```
