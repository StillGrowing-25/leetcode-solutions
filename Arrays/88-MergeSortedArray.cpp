class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> a(n+m);
        int i=0,j=0,k=0;
        while(i<m && j<n){
            if(nums1[i]<nums2[j])
            a[k++]=nums1[i++];
            else 
            a[k++]=nums2[j++];
        }
        while(i<m){
            a[k++]=nums1[i++];
        }
        while(j<n){
            a[k++]=nums2[j++];
        }
        for (int i = 0; i < m + n; i++) {
            nums1[i] = a[i];
        }
    }
};
