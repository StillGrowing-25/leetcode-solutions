# Toeplitz Matrix

# Problem Description
[766. Toeplitz Matrix](https://leetcode.com/problems/toeplitz-matrix/)

Given an `m x n` matrix, return `true` if the matrix is **Toeplitz**. Otherwise, return `false`.

A matrix is **Toeplitz** if every diagonal from top-left to bottom-right has the same element.

### Example 1:

Input: `matrix = [[1,2,3,4],[5,1,2,3],[9,5,1,2]]`

Output: `true`

### Example 2:

Input: `matrix = [[1,2],[2,2]]`

Output: `false`

### Constraints:

* `m == matrix.length`
* `n == matrix[i].length`
* `1 <= m, n <= 20`
* `0 <= matrix[i][j] <= 99`

# Intuition

A Toeplitz matrix has the property that every diagonal from the top-left to the bottom-right contains the same value. Therefore, we can traverse each diagonal and compare every element with the next element on the same diagonal.

# Approach

1. Get the number of rows `n` and columns `m`.
2. Traverse all diagonals starting from each row of the first column.
3. Move diagonally down-right and compare adjacent diagonal elements.
4. If any two adjacent diagonal elements are different, return `false`.
5. Traverse the remaining diagonals starting from the first row (excluding the first column).
6. Again, compare adjacent diagonal elements while moving diagonally.
7. If all diagonals satisfy the condition, return `true`.

# Complexity Analysis

## Time Complexity

Let:

* `n = number of rows`
* `m = number of columns`

Each element is visited at most once while traversing the diagonals.

**O(n × m)**

## Space Complexity

Only a few variables are used for traversal.

**O(1)**

# Code

```cpp
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int i, j, x, y;

        for (i = 0; i < n; i++) {
            j = 0;
            x = i;
            y = j;

            while ((x + 1) < n && (y + 1) < m) {
                if (matrix[x][y] != matrix[x + 1][y + 1])
                    return false;

                x++;
                y++;
            }
        }

        for (j = 1; j < m; j++) {
            i = 0;
            x = i;
            y = j;

            while ((x + 1) < n && (y + 1) < m) {
                if (matrix[x][y] != matrix[x + 1][y + 1])
                    return false;

                x++;
                y++;
            }
        }

        return true;
    }
};
```
