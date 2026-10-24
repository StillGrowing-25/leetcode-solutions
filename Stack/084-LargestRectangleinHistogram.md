# Largest Rectangle in Histogram

**Problem Link:** [LeetCode 84 – Largest Rectangle in Histogram](https://leetcode.com/problems/largest-rectangle-in-histogram/)

## Problem Description

Given an array of integers `heights` representing the heights of histogram bars, where each bar has a width of `1`, return the area of the largest rectangle that can be formed within the histogram.

### Examples

**Example 1:**
- Input: `heights = [2,1,5,6,2,3]`
- Output: `10`
- Explanation: The largest rectangle has height `5` and width `2`, giving an area of `10`.

**Example 2:**
- Input: `heights = [2,4]`
- Output: `4`

### Constraints
- `1 <= heights.length <= 10^5`
- `0 <= heights[i] <= 10^4`

## Intuition

For each bar, find the nearest smaller bar on its left and right. These smaller bars determine the maximum width over which the current bar can extend while maintaining its height.

A **monotonic increasing stack** efficiently finds these boundaries in linear time.

## Approach

1. Create an array `ans` to store the right boundary index for each bar.
2. Traverse from right to left using a stack to find the **Next Smaller Element to the Right (NSR)**. If no smaller element exists, use `n`.
3. Clear the stack and traverse from left to right to find the **Previous Smaller Element to the Left (NSL)**.
4. Calculate the width as `rightBoundary - leftBoundary - 1`.
5. Calculate the area for each bar using `heights[i] * width` and update `max`.
6. Return the maximum area.

## Complexity Analysis

- **Time Complexity:** `O(n)` — Each index is pushed and popped from the stack at most once per traversal.
- **Space Complexity:** `O(n)` — The auxiliary array and stack require linear space.

## Code

```java
import java.util.Stack;

class Solution {
    public int largestRectangleArea(int[] heights) {
        int[] ans = new int[heights.length];
        Stack<Integer> st = new Stack<>();
        int n = heights.length;
        int max = 0;

        // Find Next Smaller Element to the Right
        for (int i = n - 1; i >= 0; i--) {
            while (!st.isEmpty() &&
                   heights[st.peek()] >= heights[i]) {
                st.pop();
            }

            if (!st.isEmpty()) {
                ans[i] = st.peek();
            } else {
                ans[i] = n;
            }

            st.push(i);
        }

        st.clear();

        // Find Previous Smaller Element to the Left
        for (int i = 0; i < n; i++) {
            while (!st.isEmpty() &&
                   heights[st.peek()] >= heights[i]) {
                st.pop();
            }

            if (!st.isEmpty()) {
                ans[i] = ans[i] - st.peek() - 1;
            }

            max = Math.max(max, ans[i] * heights[i]);
            st.push(i);
        }

        return max;
    }
}
```

**Key pattern:** Monotonic Stack + Next Smaller Element + Previous Smaller Element.
