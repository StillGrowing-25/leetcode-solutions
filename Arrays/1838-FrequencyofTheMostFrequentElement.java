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
