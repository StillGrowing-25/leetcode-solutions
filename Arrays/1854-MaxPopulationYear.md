# Maximum Population Year

# Problem Description [Maximum Population Year](https://leetcode.com)
- You are given a 2D integer array `logs` where each `logs[i] = [birth_i, death_i]` indicates the birth and death years of the `i^th` person.
- The population of some year `x` is the number of people alive during that year. The `i^th` person is counted in year `x`'s population if `x` is in the **inclusive** range `[birth_i, death_i - 1]`. Note that the person is **not** counted in the year that they die.
- Return the **earliest** year with the **maximum population**.

Example 1:
Input: logs = [[1993,1999],[2000,2010]]
Output: 1993

Example 2:
Input: logs = [[1950,1961],[1960,1971],[1970,1981]]
Output: 1960

Constraints:
- `1 <= logs.length <= 100`
- `1950 <= birth_i < death_i <= 2050`

# Intuition
Instead of iterating through every year for every person, we can track only the *changes* in population. This is a classic application of the **Line Sweep (Difference Array)** algorithm. 
- A birth increases the population starting from `birth_year`.
- A death decreases the population starting exactly from `death_year`.

Since the years are strictly bounded between `1950` and `2050`, we can map these years to an array of size `101` (from index `0` to `100`) by offsetting each year by `-1950`. Running a cumulative sum (prefix sum) over this change array gives us the exact population for each year.

# Approach
1. Create a `populationChanges` array of size `101` initialized to `0` to record shifts in population.
2. Iterate through each log `[birth, death]`:
   * Increment the value at index `birth - 1950` by `1`.
   * Decrement the value at index `death - 1950` by `1`.
3. Track `maxPopulation`, `maxYear`, and a running `currentPopulation`.
4. Traverse the `populationChanges` array from index `0` to `100`:
   * Accumulate the current index value into `currentPopulation`.
   * If `currentPopulation` is strictly greater than `maxPopulation`, update `maxPopulation` and set `maxYear = 1950 + i`. (Using `>` instead of `>=` guarantees we naturally select the *earliest* year in case of ties).
5. Return `maxYear`.

# Complexity Analysis
# Time Complexity: O(n)
We iterate through the list of logs of size `n` once to populate the difference array, followed by a fixed loop of `101` steps. This results in a linear time complexity of **O(n)**.

# Space Complexity: O(1)
The helper array size is fixed at `101` elements regardless of the number of logs, keeping the auxiliary space complexity at **O(1)**.

# Code
```java
class Solution {
    public int maximumPopulation(int[][] logs) {
        int[] populationChanges = new int[101];

        // Step 1: Mark the events of birth and death
        for (int[] log : logs) {
            populationChanges[log[0] - 1950]++;
            populationChanges[log[1] - 1950]--;
        }

        int maxPopulation = 0;
        int maxYear = 1950;
        int currentPopulation = 0;

        // Step 2: Compute prefix sum to find the maximum population year
        for (int i = 0; i < 101; i++) {
            currentPopulation += populationChanges[i];
            
            if (currentPopulation > maxPopulation) {
                maxPopulation = currentPopulation;
                maxYear = 1950 + i;
            }
        }

        return maxYear;
    }
}
```
