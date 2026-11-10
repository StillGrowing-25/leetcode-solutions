# 1838. Frequency of the Most Frequent Element

## Problem Link
- [LeetCode 1838 - Frequency of the Most Frequent Element](https://leetcode.com/problems/frequency-of-the-most-frequent-element/)

## Intuition
The problem asks us to find the maximum possible frequency of any element in an array after performing at most $k$ increment operations. 

1. **Sorting:** First, we sort the array in ascending order. Sorting allows us to group elements close in value together, making it easier to try and make smaller elements equal to a larger target element efficiently using a sliding window.
2. **Sliding Window:** We maintain a window from `left` to `right`. For any chosen `right` element as our target value, all elements inside the current window from `left` to `right` can theoretically be incremented to match `nums[right]`.
3. **Operations Check:** The total operations required to make all elements in the window equal to `nums[right]` is:
   $$\text{Operations} = (\text{nums[right]} \times \text{Window Size}) - \text{Current Window Sum}$$
   If this value exceeds $k$, the window is invalid, so we shrink it from the left (`left++`) until the condition holds true again.
4. **Max Frequency:** We update our answer with the maximum window size (`right - left + 1`) encountered during the iteration.

## Code

```java
import java.util.Arrays;

class Solution {
    public int maxFrequency(int[] nums, int k) {
        // Step 1: Sort the array to process elements greedily
        Arrays.sort(nums);
        
        int left = 0;
        int maxFreq = 0;
        long currentWindowSum = 0;
        
        // Step 2: Expand the window using the right pointer
        for (int right = 0; right < nums.length; right++) {
            currentWindowSum += nums[right];
            
            // Calculate operations needed: (Target * Window Size) - Actual Sum
            // If operations needed > k, shrink the window from the left
            while ((long) nums[right] * (right - left + 1) - currentWindowSum > k) {
                currentWindowSum -= nums[left];
                left++;
            }
            
            // Step 3: Update maximum frequency found so far
            maxFreq = Math.max(maxFreq, right - left + 1);
        }
        
        return maxFreq;
    }
}

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(n \log n)$, where $n$ is the number of elements in the array `nums`. The sorting step takes $\mathcal{O}(n \log n)$ time, and the sliding window traversal runs in $\mathcal{O}(n)$ time as both pointers traverse the array at most once.
- **Space Complexity:** $\mathcal{O}(\log n)$ or $\mathcal{O}(n)$ depending on the internal sorting algorithm used by `Arrays.sort()`.
