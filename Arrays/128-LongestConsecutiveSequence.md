# LeetCode 128. Longest Consecutive Sequence

**Problem Link:** https://leetcode.com/problems/longest-consecutive-sequence/

## Solution

### Intuition
Since the array is unsorted, sorting it would take **O(n log n)** time, which does not satisfy the required time complexity. Instead, we use a hash set to store all elements for constant-time lookups. We only begin counting a sequence from numbers that do not have a predecessor, ensuring each sequence is processed exactly once.

### Approach
1. Insert all elements into an `unordered_set`.
2. Iterate through each unique element in the set.
3. Check whether the current element is the start of a sequence by verifying that `it - 1` is not present.
4. If it is the start, keep checking for consecutive numbers (`it + 1`, `it + 2`, ...) while they exist in the set.
5. Count the sequence length and update the maximum length found.
6. Return the maximum consecutive sequence length.

### Complexity Analysis
- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(n)`

### C++ Code

```cpp
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        int longest = 1;
        unordered_set<int> set;

        for (int i = 0; i < n; i++) {
            set.insert(nums[i]);
        }

        for (auto it : set) {
            if (set.find(it - 1) == set.end()) {
                int cnt = 1;
                int x = it;

                while (set.find(x + 1) != set.end()) {
                    cnt++;
                    x++;
                }

                longest = max(longest, cnt);
            }
        }

        return longest;
    }
};
```
