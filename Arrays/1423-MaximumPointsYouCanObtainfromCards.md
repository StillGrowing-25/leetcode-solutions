# Maximum Points You Can Obtain from Cards

# Problem Description [Maximum Points You Can Obtain from Cards](https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/)

There are several cards arranged in a row, and each card has an associated point value given in the integer array `cardPoints`.

In one step, you can take one card from either the beginning or the end of the row. You must take exactly `k` cards.

Return the maximum score you can obtain.

**Example 1:**

Input: `cardPoints = [1,2,3,4,5,6,1], k = 3`

Output: `12`

Explanation: Taking the last three cards gives a score of `5 + 6 + 1 = 12`.

**Example 2:**

Input: `cardPoints = [2,2,2], k = 2`

Output: `4`

**Example 3:**

Input: `cardPoints = [9,7,7,9,7,7,9], k = 7`

Output: `55`

# Intuition

We need to select exactly `k` cards from either end to maximize the score.

Instead of checking every possible combination of cards taken from the two ends, we can use the total sum of the array.

If we take `k` cards, then `n - k` cards remain unselected. These unselected cards must form a contiguous subarray.

Therefore,

`Maximum Score = Total Sum - Minimum Sum of a Subarray of Size (n - k)`

We can find the minimum sum using a sliding window.

# Approach

1. Calculate the sum of all elements in `cardPoints`.
2. If `k == n`, return the total sum because all cards must be selected.
3. Initialize a sliding window of size `n - k` and track its sum.
4. Whenever the window reaches size `n - k`, update the minimum window sum.
5. Remove the element at `start` and move the window forward.
6. Return `totalSum - min`, which gives the maximum obtainable score.

# Complexity Analysis

**Time Complexity:** `O(n)` — Calculating the total sum and finding the minimum window sum each take linear time.

**Space Complexity:** `O(1)` — Only a constant number of variables are used.

# Code

```java
class Solution {
    public int maxScore(int[] cardPoints, int k) {
        int start = 0, end = 0, n = cardPoints.length;
        int sum = 0, summ = 0;
        int min = Integer.MAX_VALUE;

        for (int i = 0; i < n; i++) {
            summ += cardPoints[i];
        }

        if (k == n)
            return summ;

        while (end < n) {
            sum += cardPoints[end];

            if (end - start + 1 == (n - k)) {
                min = Math.min(min, sum);
                sum -= cardPoints[start];
                start++;
            }

            end++;
        }

        return summ - min;
    }
}
```
