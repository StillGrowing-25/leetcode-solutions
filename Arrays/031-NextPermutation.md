# 31. Next Permutation

**Problem Link:** https://leetcode.com/problems/next-permutation/

## Intuition
To find the next lexicographically greater permutation, we need to make the smallest possible change to the current arrangement. We first locate the point where the sequence stops increasing from right to left. Then, we swap that element with the smallest greater element on its right and reverse the remaining suffix to obtain the next permutation.

## Approach
- Traverse the array from right to left to find the first index `idx` such that `nums[idx] < nums[idx + 1]`.
- If no such index exists, the array is in descending order, so reverse the entire array to obtain the smallest permutation.
- Otherwise:
  - Traverse from the end of the array to find the first element greater than `nums[idx]`.
  - Swap that element with `nums[idx]`.
  - Reverse the subarray after `idx` to get the smallest possible suffix.
- The resulting array is the next lexicographical permutation.

## Complexity
- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(1)`

## Code

```cpp
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int idx = -1;

        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                idx = i;
                break;
            }
        }

        if (idx == -1) {
            reverse(nums.begin(), nums.end());
        } else {
            for (int i = n - 1; i > idx; i--) {
                if (nums[i] > nums[idx]) {
                    swap(nums[i], nums[idx]);
                    break;
                }
            }
            reverse(nums.begin() + idx + 1, nums.end());
        }
    }
};
```
