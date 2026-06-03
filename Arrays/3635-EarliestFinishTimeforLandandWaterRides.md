# Earliest Finish Time for Land and Water Rides I

## Problem Description
[LeetCode 3633. Earliest Finish Time for Land and Water Rides I](https://leetcode.com/problems/earliest-finish-time-for-land-and-water-rides-i/description/)

You are given two categories of theme park attractions: **land rides** and **water rides**.

### Land rides
- `landStartTime[i]` – the earliest time the `i-th` land ride can be boarded.
- `landDuration[i]` – the duration of the `i-th` land ride.

### Water rides
- `waterStartTime[j]` – the earliest time the `j-th` water ride can be boarded.
- `waterDuration[j]` – the duration of the `j-th` water ride.

A tourist must experience exactly **one land ride** and **one water ride**, in either order.

A ride may be started at its opening time or any later moment.

If a ride is started at time `t`, it finishes at time `t + duration`.

Immediately after finishing one ride, the tourist may board the other ride if it is already open, or wait until it opens.

Return the earliest possible time at which the tourist can finish both rides.

---

## Intuition

The tourist must take exactly one ride from each category. Since the order is not fixed, we need to consider both possibilities:

1. Land Ride → Water Ride
2. Water Ride → Land Ride

For every pair of rides, we calculate when the first ride finishes. If the second ride is already open, we start it immediately; otherwise, we wait until it opens. We keep track of the minimum finishing time among all possible combinations.

---

## Approach

### Land → Water

1. Choose a land ride.
2. Calculate its finishing time:
   ```cpp
   finishLand = landStartTime[i] + landDuration[i];
   ```
3. Check every water ride:
   - If the water ride is already open, board it immediately.
   - Otherwise, wait until it opens.
4. Calculate the final finishing time.
5. Update the minimum answer.

### Water → Land

1. Choose a water ride.
2. Calculate its finishing time.
3. Repeat the same process with every land ride.
4. Update the minimum answer.

Finally, return the smallest finishing time obtained.

---

## Complexity Analysis

### Time Complexity: O(n × m)

- The first nested loop checks all Land-Water combinations.
- The second nested loop checks all Water-Land combinations.

Therefore, the overall time complexity is:

```text
O(n × m)
```

where:
- `n` = number of land rides
- `m` = number of water rides

### Space Complexity: O(1)

Only a few extra variables are used.

```text
O(1)
```

---

## Code

```cpp
class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {

        int minimum = INT_MAX;
        int x = 0;

        // Land -> Water
        for(int i = 0; i < landStartTime.size(); i++) {
            for(int j = 0; j < waterStartTime.size(); j++) {

                x = landStartTime[i] + landDuration[i];

                if(x >= waterStartTime[j])
                    x += waterDuration[j];
                else
                    x = waterStartTime[j] + waterDuration[j];

                minimum = min(minimum, x);
            }
        }

        // Water -> Land
        for(int i = 0; i < waterStartTime.size(); i++) {
            for(int j = 0; j < landStartTime.size(); j++) {

                x = waterStartTime[i] + waterDuration[i];

                if(x >= landStartTime[j])
                    x += landDuration[j];
                else
                    x = landStartTime[j] + landDuration[j];

                minimum = min(minimum, x);
            }
        }

        return minimum;
    }
};
```
