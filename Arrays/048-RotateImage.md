# Rotate Image (LeetCode 48)

A simple C++ solution to rotate an `n × n` matrix by **90 degrees clockwise** using an auxiliary matrix.

## 📝 Problem Statement

Given an `n × n` 2D matrix representing an image, rotate the image by **90 degrees (clockwise)**.

> **Note:** The rotation should ideally be performed **in-place**, but this solution uses an additional matrix for simplicity.

## 💡 Approach

- Create a new `n × n` matrix.
- Traverse each element of the original matrix.
- Place every element in its rotated position using:

```cpp
rotated[j][n - 1 - i] = matrix[i][j];
```

- Copy the rotated matrix back to the original matrix.

## 🚀 Algorithm

1. Initialize an auxiliary matrix of size `n × n`.
2. Traverse the original matrix.
3. Store each element in its new rotated position.
4. Replace the original matrix with the rotated matrix.

## 📊 Complexity Analysis

| Complexity | Value |
|------------|-------|
| Time | **O(n²)** |
| Space | **O(n²)** |

## 💻 C++ Solution

```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> a(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                a[j][n - 1 - i] = matrix[i][j];
            }
        }

        matrix = a;
    }
};
```

## 📌 Example

### Input

```text
1 2 3
4 5 6
7 8 9
```

### Output

```text
7 4 1
8 5 2
9 6 3
```

## 📚 Concepts Used

- 2D Arrays
- Matrix Manipulation
- Index Mapping
- Simulation

## 🔗 LeetCode

**Problem:** Rotate Image (LeetCode 48)
