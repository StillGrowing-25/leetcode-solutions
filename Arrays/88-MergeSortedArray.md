# Merge Sorted Array

# Problem Description
[Merge Sorted Array](https://leetcode.com/problems/merge-sorted-array/description/)

You are given two integer arrays `nums1` and `nums2`, sorted in non-decreasing order, and two integers `m` and `n` representing the number of valid elements in `nums1` and `nums2`, respectively.

Merge `nums2` into `nums1` as one sorted array. The final sorted array should be stored inside `nums1`.

---

# Intuition

Since both arrays are already sorted, we can merge them into a temporary array by repeatedly comparing the current elements of both arrays and placing the smaller one into the merged array. After one array is exhausted, append the remaining elements from the other array. Finally, copy the merged array back into `nums1`.

---

# Approach

1. Create a temporary vector `a` of size `m + n`.
2. Initialize three pointers:
   - `i` for `nums1`
   - `j` for `nums2`
   - `k` for the temporary array
3. Compare the current elements of both arrays and insert the smaller one into `a`.
4. Copy the remaining elements from the array that is not yet exhausted.
5. Copy all elements from `a` back into `nums1`.

---

# Complexity

- **Time Complexity:** `O(m + n)`
  - Each element from both arrays is processed exactly once.

- **Space Complexity:** `O(m + n)`
  - An additional vector of size `m + n` is used to store the merged array.

---

# Code

```cpp
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> a(m + n);

        int i = 0, j = 0, k = 0;

        while (i < m && j < n) {
            if (nums1[i] < nums2[j])
                a[k++] = nums1[i++];
            else
                a[k++] = nums2[j++];
        }

        while (i < m) {
            a[k++] = nums1[i++];
        }

        while (j < n) {
            a[k++] = nums2[j++];
        }

        for (int i = 0; i < m + n; i++) {
            nums1[i] = a[i];
        }
    }
};
```
