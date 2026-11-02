class Solution {
    public int numberOfPoints(List<List<Integer>> nums) {
        int []arr = new int[102];
        for(int i = 0;i< nums.size();i++){
            int s = (nums.get(i)).get(0);
            int e = (nums.get(i)).get(1);
            arr[s]++;
            arr[e+1]--;
        }
        int count = 0;
        int sum = 0;
        for(int i =0; i<102;i++){
            sum += arr[i];
            arr[i]=sum;
            if(arr[i]>0)
            count ++;
        }
        return count;
    }
}