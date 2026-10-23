class Solution {
    public int numOfSubarrays(int[] arr, int k, int threshold) {
        int count =0;
        int start = 0, end = 0, n = arr.length;
        double sum = 0;
        double max = Integer.MIN_VALUE;
        while (end < n) {
            sum += arr[end];
            if (end - start + 1 == k) {
                if(sum>=threshold*k)
                    count++;
                sum -= arr[start];
                start++;
            }
            end++;
        }
        return count;
    }
}
