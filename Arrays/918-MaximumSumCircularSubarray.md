# Maximum Sum Circular Subarray
 [918. Maximum Sum Circular Subarray](https://leetcode.com)

## Intuition
The problem extends the classic Maximum Subarray Sum to a circular array. The optimal subarray can either sit normally in the middle of the array, or split across the boundary, wrapping around from the end back to the beginning. The core realization is that a wrapped maximum subarray leaves behind a contiguous minimum subarray in the middle.

## Approach
1. **Dual Kadane's Execution:** Maintain two running states simultaneously in a single pass—one for the maximum subarray sum using standard Kadane's algorithm, and another for the minimum subarray sum using an inverted variation.
2. **Total Aggregation:** Accumulate the `total` sum of all array elements during the same pass.
3. **Complement Calculation:** Compute the circular maximum by subtracting the global minimum subarray sum from the total sum (`total - globMin`).
4. **Edge Case Validation:** If every element in the array is negative, `globMax` will correctly identify the single largest negative number, whereas `total - globMin` will evaluate to `0` (representing an empty subarray, which is disallowed). We bypass the circular calculation if `globMax < 0`.
5. **Selection:** Return the maximum value between the non-wrapped subsegment (`globMax`) and the wrapped subsegment.

## Complexity
- **Time Complexity:** $$O(n)$$ — The algorithm processes the array elements linearly in a single loop.
- **Space Complexity:** $$O(1)$$ — The state tracking utilizes fixed space independent of the input size.

## Code
```cpp
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total = 0;
        int curMax = 0, globMax = nums[0];
        int curMin = 0, globMin = nums[0];
        
        for (int num : nums) {
            total += num;
            curMax = max(curMax + num, num);
            globMax = max(globMax, curMax);
            curMin = min(curMin + num, num);
            globMin = min(globMin, curMin);
        }
        
        if (globMax < 0) return globMax;
        return max(globMax, total - globMin);
    }
};
```
