class Solution {
    public int[] productExceptSelf(int[] nums) {
        int n = nums.length;
        int[] lp = new int[n];   // Left product array
        int[] ans = new int[n];  // Final answer array
        
        int prod = 1;
        // First pass: Calculate prefix products
        for (int i = 0; i < n; i++) {
            lp[i] = prod;
            prod *= nums[i];
        }
        
        prod = 1;
        // Second pass: Multiply with suffix products from the right
        for (int i = n - 1; i >= 0; i--) {
            ans[i] = lp[i] * prod;
            prod *= nums[i];
        }
        
        return ans;
    }
}
