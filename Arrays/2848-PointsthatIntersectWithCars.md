# Points That Intersect With Cars

# Problem Description [Points That Intersect With Cars](https://leetcode.com)
-You are given a 0-indexed 2D integer array `nums` representing the coordinates of the cars parking on a number line. For any index `i`, `nums[i] = [start_i, end_i]` where `start_i` is the starting point of the `i`th car and `end_i` is the ending point of the `i`th car.
-Return the number of integer points on the line that are covered with any part of a car.

Example 1:
Input: nums = [[3,6],[1,5],[4,7]]
Output: 7

Example 2:
Input: nums = [[1,3],[5,8]]
Output: 7

Constraints:
-1 <= nums.length <= 100
-nums[i].length == 2
-1 <= start_i <= end_i <= 100

# Code
```java
class Solution {
    public int numberOfPoints(List<List<Integer>> nums) {
        int[] arr = new int[102];
        for (int i = 0; i < nums.size(); i++) {
            int s = (nums.get(i)).get(0);
            int e = (nums.get(i)).get(1);
            arr[s]++;
            arr[e + 1]--;
        }
        int count = 0;
        int sum = 0;
        for (int i = 0; i < 102; i++) {
            sum += arr[i];
            arr[i] = sum;
            if (arr[i] > 0)
                count++;
        }
        return count;
    }
}
```

# Intuition
Instead of marking every single coordinate for every car individually—which would take redundant steps if multiple cars overlap—we can track only where the coverage starts and ends. This is efficiently handled using the **Difference Array / Prefix Sum** technique, where we mark structural boundaries on a coordinate array and accumulate the net overlap values in a single sweep.

# Approach
1. Initialize a fixed-size difference array `arr` of size 102 to cover the maximum constraint range (1 to 100).
2. Iterate through each car's range `[s, e]`:
   * Increment `arr[s]` by 1 to indicate a car starts covering points from here.
   * Decrement `arr[e + 1]` by 1 to indicate that the coverage drops off after point `e`.
3. Track a running prefix sum `sum` across the array to compute the active car coverage at each point `i`.
4. If the active prefix sum at a given coordinate is greater than 0, it means at least one car is parked over it, so increment the unique point tracker `count`.

# Complexity Analysis
# Time Complexity: O(n + K)
The code processes `n` intervals in linear time and performs a single fixed sweep of size `K` (where `K = 102`), giving a linear time complexity of **O(n)**.

# Space Complexity: O(K)
A fixed-size tracking array of length 102 is used regardless of input length, yielding a constant auxiliary space complexity of **O(1)**.
