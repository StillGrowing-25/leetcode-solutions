# Intersection of Two Arrays II

# Problem Description
[350. Intersection of Two Arrays II](https://leetcode.com/problems/intersection-of-two-arrays-ii/)

Given two integer arrays `nums1` and `nums2`, return an array of their intersection. Each element in the result must appear as many times as it shows in both arrays, and you may return the result in any order.

### Example 1:

Input: `nums1 = [1,2,2,1]`, `nums2 = [2,2]`

Output: `[2,2]`

### Example 2:

Input: `nums1 = [4,9,5]`, `nums2 = [9,4,9,8,4]`

Output: `[4,9]`

Explanation: `[9,4]` is also accepted.

### Constraints:

* `1 <= nums1.length, nums2.length <= 1000`
* `0 <= nums1[i], nums2[i] <= 1000`

# Intuition

To find the intersection while preserving duplicate occurrences, we need to know how many times each element appears in one of the arrays. A hash map can efficiently store these frequencies. As we traverse the second array, we include an element in the result only if it is still available in the hash map, ensuring that each element appears the correct number of times.

# Approach

1. Create an unordered map to store the frequency of each element in `nums1`.
2. Traverse `nums1` and increment the frequency of every element.
3. Traverse `nums2`:
   * If the current element exists in the hash map with a frequency greater than `0`, add it to the answer.
   * Decrement its frequency in the hash map.
4. Return the resulting intersection array.

# Complexity Analysis

## Time Complexity

Let:

* `n = nums1.length`
* `m = nums2.length`

Each array is traversed once, and hash map operations take constant time on average.

**O(n + m)**

## Space Complexity

An unordered map is used to store the frequencies of elements from `nums1`.

**O(n)**

# Code

```cpp
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {

        unordered_map<int, int> freq;
        vector<int> ans;

        for (int num : nums1)
            freq[num]++;

        for (int num : nums2) {
            if (freq[num] > 0) {
                ans.push_back(num);
                freq[num]--;
            }
        }

        return ans;
    }
};
```
