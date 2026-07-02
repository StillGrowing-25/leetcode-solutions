# Move Zeroes

# Problem Description
[Move Zeroes](https://leetcode.com/problems/move-zeroes/description/)

Given an integer array `nums`, move all `0`s to the end while maintaining the relative order of the non-zero elements. The operation must be performed **in-place** without using an extra array.

---

# Intuition

The idea is to keep track of the position where the next non-zero element should be placed. As we traverse the array, every non-zero element is swapped with the element at the current write position. This ensures that all non-zero elements remain in their original order, while the zeroes naturally get shifted towards the end of the array.

---

# Approach

1. Initialize a pointer `j = 0` to indicate the position where the next non-zero element should be placed.
2. Traverse the array using another pointer `i`.
3. If `nums[i]` is non-zero:
   - Swap `nums[i]` with `nums[j]`.
   - Increment `j`.
4. Continue until all elements are processed.

After the traversal, all non-zero elements are at the beginning in their original order, and all zeroes are moved to the end.

---

# Complexity

- **Time Complexity:** `O(n)`
  - The array is traversed only once.

- **Space Complexity:** `O(1)`
  - The rearrangement is done in-place using only two pointers.

---

# Code

```cpp
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                swap(nums[i], nums[j]);
                j++;
            }
        }
    }
};
```
