# 136. Single Number | Bit Manipulation (XOR) | C++

**Problem Link:** https://leetcode.com/problems/single-number/

## Intuition

Every element in the array appears exactly twice except for one element. Using the properties of the XOR (`^`) operator, we can eliminate all duplicate elements and obtain the unique element.

The XOR operation has the following properties:

- `a ^ a = 0`
- `a ^ 0 = a`
- XOR is commutative and associative.

When all elements are XORed together, every pair of identical numbers cancels out, leaving only the single number.

---

## Approach

- Initialize a variable `ans` to `0`.
- Traverse the array once.
- XOR each element with `ans`.
- Since duplicate elements cancel each other out, only the unique element remains.
- Return `ans`.

This approach satisfies the problem constraints of **linear time** and **constant extra space**.

---

## Complexity

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(1)`

---

## Code

```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;

        for (int num : nums) {
            ans ^= num;
        }

        return ans;
    }
};
```
