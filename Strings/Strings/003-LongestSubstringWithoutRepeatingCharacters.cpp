class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0)
        return 0;
        int len = 1;
        int maximum = 1; int n;
        for(int i = 0; i< s.size(); i++){
            len=1;
            n=1;
            for(int j = i+1; j<s.size();j++){
                bool flag = true;
                for(int k = 0; k<n;k++){
                    if(s[i+k]==s[j]){
                    flag = false;
                    break;
                    }
                }
                if(!flag)
                break;

                n++;
                ++len;
                maximum = max(len,maximum);
            }
        }
        return maximum;
    }
};
