# Plates Between Candles

# Problem Description [Plates Between Candles](https://leetcode.com)
- You are given a **0-indexed** string `s` consisting of characters `'*'` and `'|'`, where `'*'` represents a plate and `'|'` represents a candle.
- You are also given a **0-indexed** 2D integer array `queries` where `queries[i] = [left_i, right_i]` denotes the substring `s[left_i...right_i]` (inclusive).
- For each query, find the number of plates that are **between candles** that are also contained within the substring. A plate is considered between candles if there is at least one candle to its left and at least one candle to its right **within the substring**.
- Return an integer array `ans` where `ans[i]` is the answer to the `i^th` query.

Example 1:
Input: s = "**|**|***|", queries = [[2,5],[5,9]]
Output: [2,3]

Example 2:
Input: s = "***|**|*****|**||**|*", queries = [[1,17],[4,5],[14,17],[5,11],[15,16]]
Output: [9,0,0,0,0]

Constraints:
- `3 <= s.length <= 10^5`
- `s` consists of `'*'` and `'|'` characters.
- `1 <= queries.length <= 10^5`
- `queries[i].length == 2`
- `0 <= left_i <= right_i < s.length`

# Intuition
For any given query range `[leftQueryBound, rightQueryBound]`, any plates outside the outermost candles inside that range cannot be bounded. Therefore, the problem simplifies to:
1. Finding the first candle position at or after `leftQueryBound`.
2. Finding the last candle position at or before `rightQueryBound`.

Once these inner boundary candles (`startCandle` and `endCandle`) are found, the plates between them can be calculated in $O(1)$ time using a **Prefix Sum array** that tracks the total number of plates seen up to each index. To find the inner candles efficiently without scanning the string for every single query, we can precalculate two arrays tracking the nearest left and right candle indices for every position.

# Approach
1. **Prefix Sum for Plates (`prefixPlates`)**: Iterate through the string from left to right, maintaining a running total of plate characters (`'*'`).
2. **Nearest Left Candle (`leftCandle`)**: Process the string from left to right. Keep track of the index of the most recently seen candle (`'|'`). For each position, store this index.
3. **Nearest Right Candle (`rightCandle`)**: Process the string from right to left. Keep track of the index of the most recently seen candle from the right side.
4. **Query Processing**: For each query `[leftQueryBound, rightQueryBound]`:
   * Determine the actual active window of valid candles: `startCandle = rightCandle[leftQueryBound]` and `endCandle = leftCandle[rightQueryBound]`.
   * Check if a valid range exists (`startCandle != -1 && endCandle != -1 && startCandle < endCandle`).
   * If valid, the number of plates between them is `prefixPlates[endCandle] - prefixPlates[startCandle]`. Otherwise, return `0`.

# Complexity Analysis
# Time Complexity: O(n + q)
Precalculating the three auxiliary arrays takes three linear passes over the string of length `n`, costing $O(n)$. Processing each of the `q` queries takes a constant $O(1)$ lookup time, resulting in an overall time complexity of **O(n + q)**.

# Space Complexity: O(n)
Three integer arrays (`prefixPlates`, `leftCandle`, and `rightCandle`) of size `n` are constructed to support fast lookups, giving a total auxiliary space complexity of **O(n)**.

# Code
```java
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
```
