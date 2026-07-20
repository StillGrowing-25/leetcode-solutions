# 560. Subarray Sum Equals K

**Problem Link:** https://leetcode.com/problems/subarray-sum-equals-k/

# Intuition

A brute force approach checks every possible subarray and calculates its sum, resulting in **O(n²)** time complexity. To optimize this, we use the concept of **prefix sums**. If the difference between the current prefix sum and a previously seen prefix sum is equal to `k`, then the elements between those two indices form a subarray with sum `k`.

# Approach

1. Create a prefix sum array `ps`, where `ps[i]` stores the sum of elements from index `0` to `i`.
2. Use an `unordered_map` to store the frequency of prefix sums encountered so far.
3. Initialize the map with `{0 : 1}` to handle subarrays that start from index `0`.
4. Traverse the prefix sum array:
   - Check if `(ps[i] - k)` exists in the map.
   - If it exists, add its frequency to the answer since each occurrence represents a valid subarray.
   - Store the current prefix sum in the map by incrementing its frequency.
5. Return the total count of valid subarrays.

# Complexity

- **Time complexity:**  
  **O(n)**

- **Space complexity:**  
  **O(n)**

# Code

```cpp
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        vector<int> ps(nums.size());
        ps[0] = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            ps[i] = ps[i - 1] + nums[i];
        }

        unordered_map<int, int> map;
        map[0] = 1;

        for (int i = 0; i < nums.size(); i++) {
            if (map.find(ps[i] - k) != map.end()) {
                count += map[ps[i] - k];
            }
            map[ps[i]]++;
        }

        return count;
    }
};
```
