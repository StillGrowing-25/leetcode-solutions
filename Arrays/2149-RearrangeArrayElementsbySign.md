# 2149. Rearrange Array Elements by Sign

**Problem Link:** https://leetcode.com/problems/rearrange-array-elements-by-sign/

## Intuition
Since the array contains an equal number of positive and negative integers and the result must start with a positive number, we can directly place positive numbers at even indices and negative numbers at odd indices while traversing the array only once.

## Approach
- Create a new array `ans` of the same size as `nums`.
- Maintain two indices:
  - `k = 0` for placing positive numbers at even indices.
  - `j = 1` for placing negative numbers at odd indices.
- Traverse the input array:
  - If the current element is positive, place it at index `k` and increment `k` by `2`.
  - Otherwise, place it at index `j` and increment `j` by `2`.
- Return the rearranged array.

## Complexity
- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(n)`

## Code

```cpp
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans(nums.size());
        int j = 1, k = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                ans[k] = nums[i];
                k += 2;
            } else {
                ans[j] = nums[i];
                j += 2;
            }
        }

        return ans;
    }
};
```
