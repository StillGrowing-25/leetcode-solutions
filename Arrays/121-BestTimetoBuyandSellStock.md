# Best Time to Buy and Sell Stock

# Problem Description 
https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

Given an integer array `prices` where `prices[i]` is the price of a given stock on the `iᵗʰ` day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return `0`.

### Example 1:
Input:
```text
prices = [7,1,5,3,6,4]
```

Output:
```text
5
```

Explanation:
Buy on day 2 at price `1` and sell on day 5 at price `6`.
Profit = `6 - 1 = 5`.

### Example 2:
Input:
```text
prices = [7,6,4,3,1]
```

Output:
```text
0
```

Explanation:
Since the prices continuously decrease, no profit can be made.

### Constraints:
- `1 <= prices.length <= 10⁵`
- `0 <= prices[i] <= 10⁴`

# Intuition

To maximize profit, we should always buy the stock at the lowest price seen so far. As we traverse the array, we keep updating the minimum price. For every day's price, we calculate the profit if we sold on that day and update the maximum profit whenever we find a better one.

# Approach

1. If the array contains fewer than two elements, return `0` since no transaction is possible.
2. Initialize:
   - `a` to store the minimum price seen so far.
   - `maxP` to store the maximum profit.
3. Traverse the array from the second element:
   - Update the minimum price using `min(a, prices[i])`.
   - Calculate the profit by selling on the current day.
   - Update `maxP` if the current profit is greater.
4. Return `maxP` after traversing the entire array.

# Complexity Analysis

## Time Complexity: O(n)

The array is traversed only once, and each operation inside the loop takes constant time.

## Space Complexity: O(1)

Only two extra variables are used, so the space complexity is constant.

# Code

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2)
            return 0;

        int maxP = 0;

        for (int i = 1, a = prices[0]; i < prices.size(); i++) {
            a = min(prices[i], a);
            maxP = max(maxP, prices[i] - a);
        }

        return maxP;
    }
};
```
