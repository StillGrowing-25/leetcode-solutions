# Corporate Flight Bookings

# Problem Description [Corporate Flight Bookings](https://leetcode.com)
- There are `n` flights labeled from `1` to `n`.
- You are given a 2D integer array `bookings` where `bookings[i] = [first_i, last_i, seats_i]` represents a booking for flights `first_i` through `last_i` (inclusive) with `seats_i` seats reserved for each flight in the range.
- Return an array `answer` of length `n`, where `answer[i]` is the total number of seats reserved for flight `i`.

Example 1:
Input: bookings = [[1,2,10],[2,3,20],[25,25,25]], n = 5
Output: [10,55,45,25,25]

Example 2:
Input: bookings = [[1,2,10],[2,2,15]], n = 2
Output: [10,25]

Constraints:
- `1 <= n <= 2 * 10^4`
- `1 <= bookings.length <= 2 * 10^4`
- `bookings[i].length == 3`
- `1 <= first_i <= last_i <= n`
- `1 <= seats_i <= 10^4`

# Intuition
Updating a range of values repeatedly can become inefficient ($O(n \cdot m)$ time complexity) if we update each index one by one. To handle this efficiently, we can use a **Difference Array (Line Sweep)** approach. 

Instead of updating every element within the interval `[first_i, last_i]`, we only mark the boundaries of the change:
- Add the number of seats (`seats_i`) at the start index `first_i`.
- Subtract the number of seats (`seats_i`) just after the end index at `last_i + 1`.

Because flights are 1-indexed, creating an array of size `n + 2` allows us to comfortably accommodate the `last_i + 1` updates without risking out-of-bounds exceptions. Computing a running prefix sum across the difference array transforms the boundary markers back into the true cumulative counts for each flight label.

# Approach
1. Allocate a difference tracking array `a` of size `n + 2` filled with zeros.
2. Loop through each item `[first, last, seats]` within the `bookings` matrix:
   * Increment `a[first]` by `seats` to indicate where seat accumulation begins.
   * Decrement `a[last + 1]` by `seats` to declare where the accumulation sequence finishes.
3. Construct the output result array `ans` of length `n`.
4. Run a sequential prefix loop from index `1` to `n`:
   * Combine the previous index value into the current cell: `a[i] += a[i - 1]`.
   * Assign the computed value to the correct 0-indexed destination index: `ans[i - 1] = a[i]`.
5. Return the finalized `ans` structure.

# Complexity Analysis
# Time Complexity: O(n + b)
Marking interval bounds scales directly with the length of the bookings matrix `b`. Rebuilding values via prefix additions involves scanning across a timeline bounded by size `n`. Combining these steps outputs a highly efficient linear complexity of **O(n + b)**.

# Space Complexity: O(n)
The helper tracking container maps up to a size of `n + 2` to safely map flight boundaries, resulting in an auxiliary space footprint of **O(n)** (ignoring the memory space designated for the final return array).

# Code
```java
class Solution {
    public int[] corpFlightBookings(int[][] bookings, int n) {
        // Create difference array of size n + 2 to avoid out-of-bounds errors
        int[] a = new int[n + 2];
        
        // Apply range updates to the difference array
        for (int i = 0; i < bookings.length; i++) {
            a[bookings[i][0]] += bookings[i][2];
            a[bookings[i][1] + 1] -= bookings[i][2];
        }
        
        // Reconstruct the actual values using running prefix sums
        int[] ans = new int[n];
        for (int i = 1; i <= n; i++) {
            a[i] += a[i - 1];
            ans[i - 1] = a[i];
        }
        
        return ans;
    }
}
```
