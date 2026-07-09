# Transpose Matrix

# Problem Description
[867. Transpose Matrix](https://leetcode.com/problems/transpose-matrix/)

Given a 2D integer array `matrix`, return **the transpose** of the matrix.

The transpose of a matrix is the matrix flipped over its main diagonal, switching the matrix's row and column indices.

### Example 1:

Input: `matrix = [[1,2,3],[4,5,6],[7,8,9]]`

Output: `[[1,4,7],[2,5,8],[3,6,9]]`

### Example 2:

Input: `matrix = [[1,2,3],[4,5,6]]`

Output: `[[1,4],[2,5],[3,6]]`

### Constraints:

* `m == matrix.length`
* `n == matrix[i].length`
* `1 <= m, n <= 1000`
* `1 <= m * n <= 10^5`
* `-10^9 <= matrix[i][j] <= 10^9`

# Intuition

The transpose of a matrix is obtained by converting its rows into columns and its columns into rows. Therefore, each element at position `(i, j)` in the original matrix should be placed at position `(j, i)` in the transposed matrix.

# Approach

1. Determine the number of rows `m` and columns `n` in the original matrix.
2. Create a new matrix `ans` with `n` rows and `m` columns.
3. Traverse every element of the original matrix.
4. Assign each element `matrix[i][j]` to `ans[j][i]`.
5. Return the transposed matrix.

# Complexity Analysis

## Time Complexity

Let:

* `m = number of rows`
* `n = number of columns`

Each element of the matrix is visited exactly once.

**O(m × n)**

## Space Complexity

An additional matrix of size `n × m` is used to store the transpose.

**O(m × n)**

# Code

```cpp
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {

        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> ans(n, vector<int>(m));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans[j][i] = matrix[i][j];
            }
        }

        return ans;
    }
};
```
