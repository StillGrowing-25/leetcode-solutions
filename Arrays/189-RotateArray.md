# Rotate Array

**LeetCode Problem:** https://leetcode.com/problems/rotate-array/

## Intuition

The last `k` elements of the array need to be moved to the beginning while maintaining their relative order. Instead of shifting elements one by one, which is inefficient, we can use the reverse operation to rotate the array in-place.

The idea is:
- Reverse the first `n-k` elements.
- Reverse the last `k` elements.
- Reverse the entire array.

This results in the array being rotated to the right by `k` positions.

---

## Approach

1. Compute `k %= n` to handle cases where `k` is greater than the size of the array.
2. If `k == 0`, no rotation is needed.
3. Reverse the first `n-k` elements.
4. Reverse the last `k` elements.
5. Reverse the entire array.

This approach performs the rotation in-place without using any extra array.

---

## Complexity

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(1)`

---

## Code

```cpp
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();

        if (n <= 1) return;

        k %= n;
        if (k == 0) return;

        reverse(nums.begin(), nums.end() - k);
        reverse(nums.end() - k, nums.end());
        reverse(nums.begin(), nums.end());
    }
};
```
