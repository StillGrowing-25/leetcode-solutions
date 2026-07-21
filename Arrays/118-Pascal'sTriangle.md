# LeetCode 118: Pascal's Triangle

## Problem Link
https://leetcode.com/problems/pascals-triangle/

## Intuition
Pascal's Triangle follows a simple pattern:
- The first and last element of every row is always `1`.
- Every middle element is the sum of the two elements directly above it from the previous row.

So, we build the triangle row by row using the values already computed.

## Approach
1. Create a 2D vector where the `i-th` row contains `i + 1` elements.
2. Set the first element of every row to `1`.
3. For each row, compute the middle elements using:
   - `current[j + 1] = previous[j] + previous[j + 1]`
4. Set the last element of every row (except the first) to `1`.
5. Return the completed triangle.

## Complexity
- **Time Complexity:** `O(numRows²)`
- **Space Complexity:** `O(numRows²)`

## Code

```cpp
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        for (int i = 0; i < numRows; i++) {
            ans.push_back(vector<int>(i + 1));
        }

        for (int i = 0; i < numRows; i++) {
            int j = 0;

            ans[i][0] = 1;

            while (j < i - 1) {
                ans[i][j + 1] = ans[i - 1][j] + ans[i - 1][j + 1];
                j++;
            }

            if (i != 0)
                ans[i][i] = 1;
        }

        return ans;
    }
};
```
