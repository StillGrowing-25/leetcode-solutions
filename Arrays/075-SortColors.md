# Sort Colors (Dutch National Flag Algorithm)

**Problem Link:** https://leetcode.com/problems/sort-colors/

## Intuition

Since the array contains only three distinct values (`0`, `1`, and `2`), we don't need a general sorting algorithm. Instead, we can sort the array in a single traversal by maintaining three pointers that divide the array into different regions.

- `low` points to the position where the next `0` should be placed.
- `mid` is the current element being processed.
- `high` points to the position where the next `2` should be placed.

At any point:
- `0` to `low - 1` contains all `0`s.
- `low` to `mid - 1` contains all `1`s.
- `mid` to `high` contains unsorted elements.
- `high + 1` to `n - 1` contains all `2`s.

This is known as the **Dutch National Flag Algorithm**.

## Approach

1. Initialize three pointers:
   - `low = 0`
   - `mid = 0`
   - `high = n - 1`
2. Traverse the array while `mid <= high`.
3. If `nums[mid] == 0`:
   - Swap `nums[mid]` and `nums[low]`.
   - Increment both `low` and `mid`.
4. If `nums[mid] == 1`:
   - It is already in the correct position.
   - Increment `mid`.
5. If `nums[mid] == 2`:
   - Swap `nums[mid]` and `nums[high]`.
   - Decrement `high`.
   - Do **not** increment `mid` because the swapped element needs to be checked.
6. Continue until `mid > high`.

## Complexity

- **Time Complexity:** `O(n)`
  - Each element is processed at most once.

- **Space Complexity:** `O(1)`
  - No extra space is used apart from three pointers.

## Code

```cpp
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size() - 1;

        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[mid], nums[low]);
                low++;
                mid++;
            }
            else if (nums[mid] == 1) {
                mid++;
            }
            else {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};
```
