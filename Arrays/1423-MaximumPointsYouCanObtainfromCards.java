class Solution {
    public int maxScore(int[] cardPoints, int k) {
        int start = 0, end = 0, n = cardPoints.length;
        int sum = 0,summ=0;
        int min = Integer.MAX_VALUE;
        for(int i =0; i<n;i++){
            summ+=cardPoints[i];
        }
        if(k ==n)
        return summ;
        while (end < n) {
            sum += cardPoints[end];
            if (end - start + 1 == (n-k)) {
                min = Math.min(min, sum);
                sum -= cardPoints[start];
                start++;
            }
            end++;
        }
        return summ-min;
    }
}
