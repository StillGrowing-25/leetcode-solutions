// class Solution {
// public:
//     bool rotateCheck(vector<int>& nums){
//         vector<int>ans(nums.size());
//         bool flag;
//         for(int k =1; k<nums.size();k++){
//                 ans = nums;
//                 reverse(ans.begin(),ans.end()-k);
//                 reverse(ans.end()-k,ans.end());
//                 reverse(ans.begin(),ans.end());
//                 flag = sortCheck(ans);
//                 if(flag == true)
//                 return flag;
//             }
//             return flag;
//     }
//     bool sortCheck(vector<int>& nums){
//         if(nums.size()<=1)
//         return true;
//         for(int i =1; i<nums.size();i++){
//             if(nums[i]>=nums[i-1]){}
//             else
//             return false;
//         }
//         return true;
//     }
//     bool check(vector<int>& nums) {

//         if(sortCheck(nums))
//         return true;
//         else if(rotateCheck(nums))
//         return true;
//         else
//         return false;
        
//     }
// };
#include <vector>
using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        int countDrops = 0;
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            if (nums[i] > nums[(i + 1) % n]) {
                countDrops++;
            }
            
            if (countDrops > 1) {
                return false;
            }
        }
        
        return true;
    }
};
