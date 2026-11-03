# Car Pooling

# Problem Description [Car Pooling](https://leetcode.com)
- There is a car with `capacity` empty seats. The car only drives **east** (i.e., it cannot turn around and drive west).
- You are given a 2D integer array `trips` where `trips[i] = [numPassengers_i, from_i, to_i]` indicates that the `i^th` trip has `numPassengers_i` passengers and the locations to pick them up and drop them off are `from_i` and `to_i` respectively. The locations are given as the number of kilometers due east from the car's initial location.
- Return `true` if it is possible to pick up and drop off all passengers for all the given trips, or `false` otherwise.

Example 1:
Input: trips = \[[2,1,5],[3,3,7]\], capacity = 4
Output: false

Example 2:
Input: trips = \[[2,1,5],[3,3,7]\], capacity = 5
Output: true

Constraints:
- `1 <= trips.length <= 1000`
- `trips[i].length == 3`
- `1 <= numPassengers_i <= 100`
- `0 <= from_i < to_i <= 1000`
- `1 <= capacity <= 10^5`

# Intuition
This problem can be effectively modeled using the **Line Sweep (Difference Array)** technique. Instead of simulating every kilometer traveled and tracking the exact passenger status, we can focus solely on the locations where passenger counts change:
- When a trip starts at `from_i`, the passenger count in the car increases by `numPassengers_i`.
- When a trip ends at `to_i`, the passenger count in the car decreases by `numPassengers_i`.

Since the constraint guarantees that the maximum location value will not exceed `1000`, we can construct a fixed-size track array of `1001` elements to record these events. Accumulating these changes as we traverse sequentially from kilometer `0` to `1000` gives us the exact, active passenger volume at each timeline coordinate.

# Approach
1. Initialize an array `track` of size `1001` to record real-time net boarding changes at every kilometer marker.
2. Iterate through each trip array element `[numPassengers, from, to]`:
   * Add `numPassengers` to `track[from]` to signify a passenger pickup event.
   * Subtract `numPassengers` from `track[to]` to signify a passenger drop-off event.
3. Traverse sequentially through the `track` array from index `0` to `1000`, running a cumulative prefix sum to reconstruct active capacity.
4. During prefix collection:
   * Keep track of the active timeline balance by adding the previous state into the current value.
   * Check if the updated passenger volume at any moment exceeds `capacity`. If it does, instantly break execution and return `false`.
5. If the loop completes seamlessly without ever breaching bounds, return `true`.

# Complexity Analysis
# Time Complexity: O(n)
Populating individual entry points directly requires one pass across the `trips` list of size `n`. Computing the running prefixes relies on a constant, fixed iteration constraint of `1001` steps. This provides a total linear execution timeframe of **O(n)**.

# Space Complexity: O(1)
The tracking infrastructure allocates a static buffer capacity bounded at exactly `1001` elements, ignoring any size growth factors from the original input layout. Thus, the auxiliary space scale maintains a strict constant boundary of **O(1)**.

# Code
```java
class Solution {
    public boolean carPooling(int[][] trips, int capacity) {
        int[] track = new int[1001];
        
        // Step 1: Record delta changes for pickup and drop-off events
        for (int i = 0; i < trips.length; i++) {
            track[trips[i][1]] = track[trips[i][1]] + trips[i][0];
            track[trips[i][2]] = track[trips[i][2]] - trips[i][0];
        }
        
        int a = 0;
        // Step 2: Compute running total passenger loads using prefix sums
        for (int i = 0; i < 1001; i++) {
            if (i != 0) {
                a = track[i - 1];
            }
            track[i] += a;
            
            // If the passenger count exceeds car capacity at any point
            if (track[i] > capacity) {
                return false;
            }
        }
        
        return true;
    }
}
```
