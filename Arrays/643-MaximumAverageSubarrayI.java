class Solution {
    public double findMaxAverage(int[] nums, int k) {

        int start = 0, end = 0, n = nums.length;
        double sum = 0;
        double max = Integer.MIN_VALUE;
        while (end < n) {
            sum += nums[end];
            if (end - start + 1 == k) {
                max = Math.max(max, sum);
                sum -= nums[start];
                start++;
            }
            end++;
        }
        return max/k;
    }
}
