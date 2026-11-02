class Solution {
    public int pivotIndex(int[] nums) {
        int sum = 0, ls =0,rs=0;
        for(int i = 0; i<nums.length;i++){
            sum += nums[i];
        }
        for(int i = 0; i<nums.length;i++){
            if(ls == sum -ls-nums[i])
            return i;
            ls+=nums[i];
        }
        return -1;
    }
}