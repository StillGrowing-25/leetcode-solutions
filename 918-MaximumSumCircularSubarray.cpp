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
