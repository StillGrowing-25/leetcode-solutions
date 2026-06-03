# Earliest Finish Time for Land and Water Rides

## Problem Description

[LeetCode 3633. Earliest Finish Time for Land and Water Rides I](https://leetcode.com/problems/earliest-finish-time-for-land-and-water-rides-i/description/)

You are given two categories of theme park attractions: **land rides** and **water rides**.

### Land rides

* `landStartTime[i]` – the earliest time the `i-th` land ride can be boarded.
* `landDuration[i]` – the duration of the `i-th` land ride.

### Water rides

* `waterStartTime[j]` – the earliest time the `j-th` water ride can be boarded.
* `waterDuration[j]` – the duration of the `j-th` water ride.

A tourist must experience exactly one ride from each category, in either order.

A ride may be started at its opening time or any later moment.

If a ride is started at time `t`, it finishes at time `t + duration`.

Immediately after finishing one ride, the tourist may board the other ride if it is already open, or wait until it opens.

Return the earliest possible time at which the tourist can finish both rides.

---

# Brute Force Approach

## Intuition

Since the tourist must take one land ride and one water ride, we can simply try every possible combination.

For each pair:

1. Take the land ride first and then the water ride.
2. Take the water ride first and then the land ride.
3. Compute the finishing time.
4. Keep track of the minimum finishing time.

---

## Approach

### Land → Water

For every land ride:

1. Compute when it finishes.
2. For every water ride:

   * If the water ride is already open, start immediately.
   * Otherwise, wait until it opens.
3. Compute the final completion time.
4. Update the minimum answer.

### Water → Land

Repeat the same process with the order reversed.

---

## Complexity Analysis

### Time Complexity: O(n × m)

Every land ride is paired with every water ride.

### Space Complexity: O(1)

Only a few extra variables are used.

---

## Brute Force Code

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

---

# Optimal Approach

## Intuition

The brute-force solution checks every possible pair of rides, which is expensive for large inputs.

Suppose the first ride finishes at time `t`.

For a second ride:

```cpp
finishTime = max(t, startTime) + duration
```

This creates two cases:

### Case 1: Ride already open

```cpp
startTime <= t
```

Then:

```cpp
finishTime = t + duration
```

To minimize the answer, we only need the minimum duration among all rides already open.

---

### Case 2: Ride not open yet

```cpp
startTime > t
```

Then:

```cpp
finishTime = startTime + duration
```

To minimize the answer, we only need the minimum value of:

```cpp
startTime + duration
```

among rides that are still closed.

Instead of checking every ride repeatedly, we preprocess these values.

---

## Approach

1. Sort rides by opening time.
2. Build a prefix minimum array storing the smallest duration seen so far.
3. Build a suffix minimum array storing the smallest value of:

```cpp
startTime + duration
```

from each position onward.
4. For each first ride:

* Calculate its finishing time.
* Use binary search to separate rides into:

  * Already open
  * Not yet open
* Use the precomputed arrays to get the best possible second ride instantly.

5. Repeat for both ride orders:

   * Land → Water
   * Water → Land

---

## Complexity Analysis

### Time Complexity

Sorting:

```text
O(n log n + m log m)
```

Binary search for every ride:

```text
O(n log m + m log n)
```

Overall:

```text
O((n + m) log(n + m))
```

### Space Complexity

```text
O(n + m)
```

for auxiliary arrays.

---

## Optimal Code

```cpp
class Solution {
public:

    long long solve(vector<int>& startTime,
                    vector<int>& duration,
                    vector<int>& otherStartTime,
                    vector<int>& otherDuration) {

        int m = otherStartTime.size();

        vector<pair<int,int>> rides;

        for(int i = 0; i < m; i++) {
            rides.push_back({otherStartTime[i], otherDuration[i]});
        }

        sort(rides.begin(), rides.end());

        vector<int> starts(m);
        vector<long long> prefMinDuration(m);
        vector<long long> suffMinFinish(m);

        for(int i = 0; i < m; i++) {
            starts[i] = rides[i].first;
        }

        prefMinDuration[0] = rides[0].second;

        for(int i = 1; i < m; i++) {
            prefMinDuration[i] =
                min(prefMinDuration[i-1],
                    (long long)rides[i].second);
        }

        suffMinFinish[m-1] =
            (long long)rides[m-1].first +
            rides[m-1].second;

        for(int i = m-2; i >= 0; i--) {

            suffMinFinish[i] =
                min(suffMinFinish[i+1],
                    (long long)rides[i].first +
                    rides[i].second);
        }

        long long minimum = LLONG_MAX;

        for(int i = 0; i < startTime.size(); i++) {

            long long finishFirst =
                (long long)startTime[i] +
                duration[i];

            int pos =
                upper_bound(starts.begin(),
                            starts.end(),
                            finishFirst)
                - starts.begin();

            long long best = LLONG_MAX;

            if(pos > 0) {
                best =
                    min(best,
                        finishFirst +
                        prefMinDuration[pos-1]);
            }

            if(pos < m) {
                best =
                    min(best,
                        suffMinFinish[pos]);
            }

            minimum = min(minimum, best);
        }

        return minimum;
    }

    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {

        long long landToWater =
            solve(landStartTime,
                  landDuration,
                  waterStartTime,
                  waterDuration);

        long long waterToLand =
            solve(waterStartTime,
                  waterDuration,
                  landStartTime,
                  landDuration);

        return (int)min(landToWater, waterToLand);
    }
};
```
