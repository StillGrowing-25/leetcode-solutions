class Solution {
    public int[] platesBetweenCandles(String s, int[][] queries) {
        int n = s.length();
        
        // prefixPlates[i] stores the total number of plates ('*') from index 0 to i
        int[] prefixPlates = new int[n];
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (s.charAt(i) == '*') {
                count++;
            }
            prefixPlates[i] = count;
        }
        
        // leftCandle[i] stores the index of the closest candle ('|') to the left of or at index i
        int[] leftCandle = new int[n];
        int lastCandleLeft = -1;
        for (int i = 0; i < n; i++) {
            if (s.charAt(i) == '|') {
                lastCandleLeft = i;
            }
            leftCandle[i] = lastCandleLeft;
        }
        
        // rightCandle[i] stores the index of the closest candle ('|') to the right of or at index i
        int[] rightCandle = new int[n];
        int lastCandleRight = -1;
        for (int i = n - 1; i >= 0; i--) {
            if (s.charAt(i) == '|') {
                lastCandleRight = i;
            }
            rightCandle[i] = lastCandleRight;
        }
        
        // Process each query
        int[] ans = new int[queries.length];
        for (int i = 0; i < queries.length; i++) {
            int leftQueryBound = queries[i][0];
            int rightQueryBound = queries[i][1];
            
            // Find the inside-bound candles for the query range
            int startCandle = rightCandle[leftQueryBound];
            int endCandle = leftCandle[rightQueryBound];
            
            // If valid candles exist within the boundaries and form a proper range
            if (startCandle != -1 && endCandle != -1 && startCandle < endCandle) {
                ans[i] = prefixPlates[endCandle] - prefixPlates[startCandle];
            } else {
                ans[i] = 0;
            }
        }
        
        return ans;
    }
}
