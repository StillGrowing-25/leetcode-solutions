class Solution {
    void merge(int[] nums, int l, int mid, int h){
        int n1 = mid - l+1;
        int n2 = h-mid;
        int[] a = new int[n1];
        int[] b = new int[n2];
        for(int x = 0; x<n1;x++){
            a[x]=nums[l+x];
        }
        for(int x = 0; x<n2;x++){
            b[x]=nums[mid+x+1];
        }
        int i =0; int j =0;
        int k=l;
        while(i<n1 && j<n2){
            if(a[i]<=b[j])
            nums[k++] = a[i++];
            else
            nums[k++] = b[j++];
        }
        while(i<n1){
            nums[k++]=a[i++];
        }
        while(j<n2){
            nums[k++]=b[j++];
        }
    }

    void mergeSort(int[] nums,int left, int right){
        if (left >= right) {
            return;
        }
        int mid = left + (right - left) / 2;
        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);
        merge(nums, left, mid, right);
    }
    public int[] sortArray(int[] nums) {
        if(nums == null || nums.length<=1)
            return nums;
        mergeSort(nums,0,nums.length-1);
        return nums;
    }
}
