# Spiral Matrix

# Problem Description
[54. Spiral Matrix](https://leetcode.com/problems/spiral-matrix/)

Given an `m x n` matrix, return all elements of the matrix in **spiral order**.

### Example 1:

Input: `matrix = [[1,2,3],[4,5,6],[7,8,9]]`

Output: `[1,2,3,6,9,8,7,4,5]`

### Example 2:

Input: `matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]`

Output: `[1,2,3,4,8,12,11,10,9,5,6,7]`

### Constraints:

* `m == matrix.length`
* `n == matrix[i].length`
* `1 <= m, n <= 10`
* `-100 <= matrix[i][j] <= 100`

# Intuition

A matrix can be traversed in spiral order by processing one boundary at a time. We maintain four boundaries—`top`, `bottom`, `left`, and `right`—that represent the current layer of the matrix. After traversing one side of the current layer, we move the corresponding boundary inward and continue until all elements have been visited.

# Approach

1. Initialize four boundaries:
   * `top = 0`
   * `bottom = number of rows - 1`
   * `left = 0`
   * `right = number of columns - 1`
2. While `top <= bottom` and `left <= right`:
   * Traverse from left to right across the top row, then increment `top`.
   * Traverse from top to bottom along the right column, then decrement `right`.
   * If `top <= bottom`, traverse from right to left across the bottom row, then decrement `bottom`.
   * If `left <= right`, traverse from bottom to top along the left column, then increment `left`.
3. Repeat until all layers have been traversed.
4. Return the elements stored in the answer vector.

# Complexity Analysis

## Time Complexity

Let:

* `m = number of rows`
* `n = number of columns`

Each element of the matrix is visited exactly once.

**O(m × n)**

## Space Complexity

Apart from the output vector, only a few variables are used.

**O(1)**

# Code

```cpp
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int top = 0, bottom = matrix.size() - 1;
        int left = 0, right = matrix[0].size() - 1;

        vector<int> ans;

        while (top <= bottom && left <= right) {

            for (int i = left; i <= right; i++)
                ans.push_back(matrix[top][i]);
            top++;

            for (int i = top; i <= bottom; i++)
                ans.push_back(matrix[i][right]);
            right--;

            if (top <= bottom) {
                for (int i = right; i >= left; i--)
                    ans.push_back(matrix[bottom][i]);
                bottom--;
            }

            if (left <= right) {
                for (int i = bottom; i >= top; i--)
                    ans.push_back(matrix[i][left]);
                left++;
            }
        }

        return ans;
    }
};
```
