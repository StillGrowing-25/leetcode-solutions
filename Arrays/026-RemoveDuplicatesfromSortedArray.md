# 26. Remove Duplicates from Sorted Array | Two Pointers | C++

**Problem Link:** https://leetcode.com/problems/remove-duplicates-from-sorted-array/

## Intuition

Since the array is already sorted, all duplicate elements appear consecutively. Instead of creating a new array, we can overwrite duplicate elements by placing each unique element at the next available position. This allows us to modify the array in-place while keeping only the unique elements at the beginning.

---

## Approach

Use the **Two Pointers** technique:

- Initialize a pointer `j` to indicate the position where the next unique element should be placed.
- Traverse the array starting from index `1`.
- If the current element differs from the previous one, it is a unique element:
  - Increment the count of unique elements.
  - Copy the current element to `nums[j]`.
  - Move `j` forward.
- After the traversal, the first `k` elements of the array contain all unique elements in sorted order.
- Return `k`.

---

## Complexity

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(1)`

---

## Code

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 1;

        for (int i = 1, j = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1]) {
                k++;
                nums[j++] = nums[i];
            }
        }

        return k;
    }
};
```
