# Merge Intervals

**Problem Link:** https://leetcode.com/problems/merge-intervals/

---

# Intuition

If the intervals are sorted by their starting points, overlapping intervals will appear next to each other.

We can maintain an `ans` vector containing the merged intervals. For every interval:

- If it does not overlap with the last interval in `ans`, add it directly.
- If it overlaps, merge it by updating the ending point of the last interval.

This allows us to merge all overlapping intervals in a single traversal after sorting.

---

# Approach

1. Sort the intervals based on their starting points.
2. Create an empty `ans` vector.
3. Traverse every interval:
   - If `ans` is empty or the current interval starts after the end of the last merged interval, there is **no overlap**. Add it to `ans`.
   - Otherwise, the intervals overlap. Update the ending point:
     ```cpp
     ans.back()[1] = max(ans.back()[1], interval[1]);
     ```
4. Return the merged intervals.

---

# Complexity

- **Time complexity:** `O(n log n)`
  - Sorting takes `O(n log n)`.
  - Traversing the intervals takes `O(n)`.
  - Overall: `O(n log n)`.

- **Space complexity:** `O(n)`
  - The `ans` vector can contain up to `n` intervals.
  - Sorting may also use additional implementation-dependent stack/temporary space.

---

# Code

```cpp
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;

        for (auto interval : intervals) {
            // No overlap
            if (ans.empty() || ans.back()[1] < interval[0]) {
                ans.push_back(interval);
            }

            // Overlap
            else {
                ans.back()[1] = max(ans.back()[1], interval[1]);
            }
        }

        return ans;
    }
};
```
