class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // vector<int> ans;
        // int x = (int)floor(nums.size()/3);
        // unordered_map<int, int> hash;
        // for(int i =0; i<nums.size(); i++){
        //     hash[nums[i]]++;
        // }
        // for(auto it: hash){
        //     if(it.second > x){
        //         ans.push_back(it.first);
        //     }
        // }
        // return ans;
        vector<int> ans;
        int x = (int)floor(nums.size() / 3);
        int a = INT_MIN, b = INT_MIN, ca = 0, cb = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (ca == 0 && nums[i] != b) {
                ca = 1;
                a = nums[i];
            } else if (cb == 0 && nums[i] != a) {
                cb = 1;
                b = nums[i];
            } else if (nums[i] == a) {
                ca++;
            } else if (nums[i] == b) {
                cb++;
            } else {
                ca--;
                cb--;
            }
        }
        ca = 0; cb = 0;
        for(int i =0; i<nums.size();i++){
            //Manual Check
            if(nums[i] == a)ca++;
            else if(nums[i] == b) cb++;
        }
        if (ca > x)
            ans.push_back(a);
        if (cb > x)
            ans.push_back(b);
        return ans;
    }
};
