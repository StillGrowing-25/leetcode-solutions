#include <vector>

class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);
        
        for (int i = 1; i < n; ++i) {
            ans[i] = ans[i - 1] * nums[i - 1];
        }
        
        int suffixProduct = 1;
        for (int i = n - 1; i >= 0; --i) {
            ans[i] *= suffixProduct;
            suffixProduct *= nums[i];
        }
        
        return ans;
    }
};
