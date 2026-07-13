class Solution {
public:

    // int crossSum(vector<int>& nums, int low, int mid, int high) {
    //     int sum = 0;
    //     int left_sum = INT_MIN;

    //     for(int i = mid; i >= low; i--) {
    //         sum += nums[i];
    //         left_sum = max(left_sum, sum);
    //     }

    //     sum = 0;
    //     int right_sum = INT_MIN;

    //     for(int i = mid + 1; i <= high; i++) {
    //         sum += nums[i];
    //         right_sum = max(right_sum, sum);
    //     }

    //     return left_sum + right_sum;
    // }

    // int arraySum(vector<int>& nums, int low, int high) {
    //     if(low == high)
    //         return nums[low];

    //     int mid = (low + high) / 2;

    //     return max({
    //         arraySum(nums, low, mid),
    //         arraySum(nums, mid + 1, high),
    //         crossSum(nums, low, mid, high)
    //     });
    // }

    // int maxSubArray(vector<int>& nums) {
    //     return arraySum(nums, 0, nums.size() - 1);
    // }
    int maxSubArray(vector<int>& nums) {
        int currentSum = nums[0];
        int maxSum = nums[0];

        for(int i = 1; i < nums.size(); i++) {
            currentSum = max(nums[i], currentSum + nums[i]);
            maxSum = max(maxSum, currentSum);
        }

        return maxSum;
    }
};
