# Maximum Subarray | Divide and Conquer + Kadane's Algorithm

## Problem Link
[LeetCode 53 - Maximum Subarray](https://leetcode.com/problems/maximum-subarray/)
# Intuition

The problem is to find the contiguous subarray with the maximum sum.

There are two ways to solve this problem:

### 1. Divide and Conquer Approach

The maximum subarray can only be present in one of three places:
- Completely in the left half.
- Completely in the right half.
- Crossing the middle element.

So, we recursively divide the array into two halves and calculate the maximum sum for the left part, right part, and the crossing part. The answer is the maximum among these three values.

For the crossing subarray, we find:
- Maximum sum starting from the middle and going towards the left.
- Maximum sum starting from the middle+1 and going towards the right.
- Add both sums to get the crossing sum.

---

### 2. Kadane's Algorithm

Kadane's algorithm solves the same problem using a greedy approach.

While traversing the array, we maintain:
- `currentSum`: Maximum sum of a subarray ending at the current index.
- `maxSum`: Maximum sum found so far.

At every element, we decide whether:
- To start a new subarray from the current element.
- To extend the previous subarray by adding the current element.

The better choice is stored in `currentSum`, and `maxSum` keeps track of the best answer.

---

# Approach

### Divide and Conquer

1. Divide the array into two halves.
2. Recursively calculate the maximum subarray sum in the left and right halves.
3. Calculate the maximum crossing sum:
   - Find the best sum on the left side of the middle.
   - Find the best sum on the right side of the middle.
   - Add both sums.
4. Return the maximum of:
   - Left half result.
   - Right half result.
   - Crossing sum.

Formula:


Maximum Subarray Sum =
max(leftSum, rightSum, crossSum)


---

### Kadane's Algorithm

1. Initialize `currentSum` and `maxSum` with the first element.
2. Traverse the array from the second element.
3. For every element:


currentSum = max(nums[i], currentSum + nums[i])


This checks whether starting a new subarray is better than continuing the previous one.

4. Update the maximum result:


maxSum = max(maxSum, currentSum)


5. Return `maxSum`.

---

# Complexity

### Divide and Conquer

- Time complexity:

$$O(n \log n)$$

- Space complexity:

$$O(\log n)$$

---

### Kadane's Algorithm

- Time complexity:

$$O(n)$$

- Space complexity:

$$O(1)$$

---

# Code

```cpp []
class Solution {
public:

    // Divide and Conquer Approach

    // int crossSum(vector<int>& nums, int low, int mid, int high) {
    //     int sum = 0;
    //     int left_sum = INT_MIN;

    //     for(int i = mid; i >= low; i--) {
    //         sum += nums[i];
    //         left_sum = max(left_sum, sum);
    //     }

    //     sum = 0;
    //     int right_sum = INT_MIN;

    //     for(int i = mid + 1; i <= high; i++) {
    //         sum += nums[i];
    //         right_sum = max(right_sum, sum);
    //     }

    //     return left_sum + right_sum;
    // }

    // int arraySum(vector<int>& nums, int low, int high) {
    //     if(low == high)
    //         return nums[low];

    //     int mid = (low + high) / 2;

    //     return max({
    //         arraySum(nums, low, mid),
    //         arraySum(nums, mid + 1, high),
    //         crossSum(nums, low, mid, high)
    //     });
    // }

    // int maxSubArray(vector<int>& nums) {
    //     return arraySum(nums, 0, nums.size() - 1);
    // }


    // Kadane's Algorithm

    int maxSubArray(vector<int>& nums) {
        int currentSum = nums[0];
        int maxSum = nums[0];

        for(int i = 1; i < nums.size(); i++) {
            currentSum = max(nums[i], currentSum + nums[i]);
            maxSum = max(maxSum, currentSum);
        }

        return maxSum;
    }
};
