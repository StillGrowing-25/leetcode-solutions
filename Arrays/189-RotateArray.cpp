class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();

        //Approach-1 extra array
        //vector<int> ans(nums.size()) ;
        // for(int i =0, j=0; i<nums.size();i++){
        //     if(k > 0){
        //     ans[i] = nums[n-k];
        //     k--;
        //     } else{
        //         ans[i]= nums[j];
        //         j++;
        //     }
        // }
        // nums = ans;

        //Approach-2 one iteration at a time
        // int x,p;
        // while(k!=0){
        //     p = nums[0];
        //     nums[0] = nums[n-1];
        //     for(int i =1; i<n; i++){
        //         x = nums[i];
        //         nums[i] = p;
        //         p = x;
        //     }
        //     k--;
        // }

        if(nums.size() <= 1 | nums.size() == k) return;
        if(nums.size() < k){
            k = k%nums.size();
        }
        reverse(nums.begin(),nums.end()-k);
        reverse(nums.end()-k,nums.end());
        reverse(nums.begin(),nums.end());
    }
};
