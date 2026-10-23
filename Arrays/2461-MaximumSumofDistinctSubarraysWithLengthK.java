class Solution {
    public long maximumSubarraySum(int[] nums, int k) {
        int n = nums.length;
		long sum = 0, max = 0;
        int end =0, start = 0;
        Set<Integer> set = new HashSet<>();
		while (end < n) {
            while(set.contains(nums[end])){
               set.remove(nums[start]);
                sum -= nums[start];
                start++;
            }
            set.add(nums[end]);
			sum += nums[end];
			if (end - start + 1 == k) {
				max = Math.max(max, sum);
				sum -= nums[start];
                set.remove(nums[start]);
				start++;
			}
			end++;
		}
		return max;
    }
}
