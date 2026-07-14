# 1752. Check if Array Is Sorted and Rotated

**Problem Link:** https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/

## Intuition

A sorted and rotated array can have **at most one position** where the order decreases. This position is called a **drop** and occurs when `nums[i] > nums[i + 1]`.

- A completely sorted array has **0 drops**.
- A sorted array rotated some number of times has **exactly 1 drop**.
- If there are **more than one drop**, the array cannot be obtained by rotating a sorted array.

Since the last element should also connect back to the first after rotation, we compare `nums[n-1]` with `nums[0]` using circular indexing.

---

## Approach

### Approach 1: Brute Force (Rotation Simulation)

- First, check whether the given array is already sorted.
- If it is not sorted, generate every possible rotation of the array.
- For each rotation:
  - Reverse the first part.
  - Reverse the second part.
  - Reverse the entire array to simulate rotation.
  - Check whether the rotated array is sorted.
- If any rotation is sorted, return `true`.
- Otherwise, return `false`.

**Time Complexity:** `O(n²)`  
**Space Complexity:** `O(n)`

---

### Approach 2: Optimal (Count the Drops)

- Traverse the array once.
- Compare each element with the next element using circular indexing:
  ```cpp
  nums[(i + 1) % n]
  ```
- Count how many times:
  ```cpp
  nums[i] > nums[(i + 1) % n]
  ```
- If the count exceeds 1, return `false`.
- Otherwise, return `true`.

This works because a sorted rotated array can contain only one breaking point.

---

# Complexity

### Brute Force
- **Time Complexity:** `O(n²)`
- **Space Complexity:** `O(n)`

### Optimal
- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(1)`

---

# Code

### Brute Force

```cpp
class Solution {
public:
    bool rotateCheck(vector<int>& nums){
        vector<int> ans(nums.size());
        bool flag;

        for(int k = 1; k < nums.size(); k++){
            ans = nums;

            reverse(ans.begin(), ans.end() - k);
            reverse(ans.end() - k, ans.end());
            reverse(ans.begin(), ans.end());

            flag = sortCheck(ans);

            if(flag)
                return true;
        }

        return false;
    }

    bool sortCheck(vector<int>& nums){
        if(nums.size() <= 1)
            return true;

        for(int i = 1; i < nums.size(); i++){
            if(nums[i] < nums[i - 1])
                return false;
        }

        return true;
    }

    bool check(vector<int>& nums) {

        if(sortCheck(nums))
            return true;
        else if(rotateCheck(nums))
            return true;
        else
            return false;
    }
};
```

---

### Optimal

```cpp
#include <vector>
using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        int countDrops = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (nums[i] > nums[(i + 1) % n]) {
                countDrops++;
            }

            if (countDrops > 1) {
                return false;
            }
        }

        return true;
    }
};
```
