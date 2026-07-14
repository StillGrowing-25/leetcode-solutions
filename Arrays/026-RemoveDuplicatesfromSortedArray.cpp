class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k =1;
        for(int i =1, j =1; i<nums.size(); i++){
            if(nums[i] != nums[i-1]){
            k++;
            nums[j++]=nums[i];
            }
        }
        return k;
    }
};
