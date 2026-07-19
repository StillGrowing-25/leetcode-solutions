# 169. Majority Element

**Problem Link:** https://leetcode.com/problems/majority-element/

## Intuition
Since the majority element appears more than `n / 2` times, it cannot be completely canceled out by all the other elements. The Boyer-Moore Voting Algorithm uses this idea by maintaining a candidate and a counter. Whenever the counter becomes zero, we choose a new candidate. In the end, the remaining candidate is the majority element.

## Approach
- Initialize:
  - `ans` to store the current candidate.
  - `freq` as a counter.
- Traverse the array:
  - If `freq` becomes `0`, set the current element as the new candidate.
  - If the current element matches the candidate, increment `freq`.
  - Otherwise, decrement `freq`.
- After the traversal, `ans` will contain the majority element since it appears more than `n / 2` times.

## Complexity
- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(1)`

## Code

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int freq = 0;
        int ans = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (freq == 0) {
                ans = nums[i];
            }

            if (ans == nums[i]) {
                freq++;
            } else {
                freq--;
            }
        }

        return ans;
    }
};
```
