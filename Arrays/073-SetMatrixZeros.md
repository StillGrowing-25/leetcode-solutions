# Set Matrix Zeroes (LeetCode 73)

**Problem Link:** https://leetcode.com/problems/set-matrix-zeroes/

## Approach 1: Store Zero Positions

### Intuition

Store the coordinates of every original zero before modifying the
matrix. Then, for each stored coordinate, set its entire row and column
to zero.

### Approach

1.  Traverse the matrix and store all `(row, col)` positions containing
    `0`.
2.  Iterate through the stored positions.
3.  For each position, set its entire row and column to `0`.

### Complexity

-   **Time:** `O(m × n + k × (m + n))`
-   **Space:** `O(k)`

``` cpp
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<vector<int>> pos;

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == 0)
                    pos.push_back({i, j});
            }
        }

        for (const auto& cell : pos) {
            for (int i = 0; i < matrix.size(); i++)
                matrix[i][cell[1]] = 0;

            for (int j = 0; j < matrix[0].size(); j++)
                matrix[cell[0]][j] = 0;
        }
    }
};
```

------------------------------------------------------------------------

## Approach 2: Optimal (First Row & First Column as Markers)

### Intuition

Use the first row and first column as marker arrays instead of
allocating extra memory. Store whether the first row and first column
originally contained a zero using two boolean variables.

### Approach

1.  Check if the first row contains a zero.
2.  Check if the first column contains a zero.
3.  Traverse the remaining matrix and mark rows and columns in the first
    column and first row.
4.  Zero rows using row markers.
5.  Zero columns using column markers.
6.  Finally, zero the first row and first column if required.

### Complexity

-   **Time:** `O(m × n)`
-   **Space:** `O(1)`

``` cpp
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool firstRowZero = false;
        bool firstColZero = false;

        for (int j = 0; j < matrix[0].size(); j++)
            if (matrix[0][j] == 0) {
                firstRowZero = true;
                break;
            }

        for (int i = 0; i < matrix.size(); i++)
            if (matrix[i][0] == 0) {
                firstColZero = true;
                break;
            }

        for (int i = 1; i < matrix.size(); i++) {
            for (int j = 1; j < matrix[0].size(); j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for (int i = 1; i < matrix.size(); i++)
            if (matrix[i][0] == 0)
                for (int j = 0; j < matrix[0].size(); j++)
                    matrix[i][j] = 0;

        for (int j = 1; j < matrix[0].size(); j++)
            if (matrix[0][j] == 0)
                for (int i = 0; i < matrix.size(); i++)
                    matrix[i][j] = 0;

        if (firstRowZero)
            for (int j = 0; j < matrix[0].size(); j++)
                matrix[0][j] = 0;

        if (firstColZero)
            for (int i = 0; i < matrix.size(); i++)
                matrix[i][0] = 0;
    }
};
```
