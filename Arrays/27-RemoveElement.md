# Remove Element

# Problem Description
[Remove Element](https://leetcode.com/problems/remove-element/description/)

Given an integer array `nums` and an integer `val`, remove all occurrences of `val` in-place. The order of the remaining elements may be changed. Return the number of elements that are not equal to `val`.

The first `k` elements of `nums` should contain all elements that are not equal to `val`, where `k` is the number of remaining elements.

---

## Intuition

Since the order of the remaining elements does not matter, we can efficiently remove elements by swapping every occurrence of `val` with the last unprocessed element in the array.

We maintain two pointers:
- `i` starts from the beginning.
- `j` starts from the end.

Whenever `nums[i]` equals `val`, we swap it with `nums[j]` and decrement `j`. We do not increment `i` immediately because the new element brought from the end has not been checked yet. If `nums[i]` is not equal to `val`, we simply move `i` forward.

When the pointers cross, all valid elements are placed before index `i`, making `i` the required answer.

---

## Approach

1. Initialize two pointers:
   - `i = 0` (left pointer)
   - `j = nums.size() - 1` (right pointer)
2. Traverse the array while `i <= j`.
3. If `nums[i] == val`:
   - Swap `nums[i]` and `nums[j]`.
   - Decrement `j`.
   - Keep `i` at the same position to check the swapped element.
4. Otherwise, increment `i`.
5. Return `i`, which represents the number of elements not equal to `val`.

---

## Complexity

- **Time Complexity:** `O(n)`
  - Each element is processed at most once.

- **Space Complexity:** `O(1)`
  - Only two pointers are used; no extra space is required.

---

## Code

```cpp
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0, j = nums.size() - 1;

        while (i <= j) {
            if (nums[i] == val) {
                swap(nums[i], nums[j]);
                j--;
            } else {
                i++;
            }
        }

        return i;
    }
};
```
