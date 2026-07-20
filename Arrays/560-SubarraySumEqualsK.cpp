class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        vector<int> ps(nums.size());
        ps[0] = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            ps[i] = ps[i - 1] + nums[i];
        }

        unordered_map<int, int> map;
        map[0] = 1;

        for (int i = 0; i < nums.size(); i++) {
            if (map.find(ps[i] - k) != map.end()) {
                count += map[ps[i] - k];
            }
            map[ps[i]]++;
        }

        return count;
    }
};
