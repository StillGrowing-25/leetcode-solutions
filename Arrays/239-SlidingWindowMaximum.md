# Sliding Window Maximum

# Problem Description [Sliding Window Maximum](https://leetcode.com/problems/sliding-window-maximum/description/)
- You are given an array of integers `nums`, there is a sliding window of size `k` which is moving from the very left of the array to the very right. You can only see the `k` numbers in the window. Each time the sliding window moves right by one position.
- Return the max sliding window.

Example 1:
Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------                ---
[1  3  -1] -3  5  3  6  7       **3**
 1 [3  -1  -3] 5  3  6  7       **3**
 1  3 [-1  -3  5] 3  6  7       **5**
 1  3  -1 [-3  5  3] 6  7       **5**
 1  3  -1  -3 [5  3  6] 7       **6**
 1  3  -1  -3  5 [3  6  7]      **7**

Example 2:
Input: nums = [1], k = 1
Output: [1]

Constraints:
- $1 \le nums.length \le 10^5$
- $-10^4 \le nums[i] \le 10^4$
- $1 \le k \le nums.length$

# Intuition
The idea is to maintain a sliding window of size `k` while efficiently keeping track of the maximum element within the current window. Using a Deque (Double-Ended Queue) allows us to store elements in decreasing order of their values and remove elements that fall out of the window or are smaller than the incoming element, ensuring that the maximum element is always at the front of the queue.

# Approach
1. Initialize a `Deque` to store indices (or values) of elements in decreasing order, a `start` pointer at 0, an `end` pointer to traverse the array, and an answer array to store the maximums.
2. Iterate through the array using the `end` pointer:
   * Remove elements from the back of the deque that are smaller than the current element `nums[end]`, as they cannot be the maximum.
   * Add the current element to the back of the deque.
3. Once the window size reaches `k` (`end - start + 1 == k`):
   * Record the maximum element from the front of the deque into the answer array.
   * Slide the window forward by checking if the element at the front of the deque corresponds to the element going out of bounds (`nums[start]`), and remove it if so.
   * Increment the `start` pointer.
4. Return the populated answer array.

# Complexity Analysis
# Time Complexity: O(n)
Each element is added to and removed from the deque at most once during the traversal, resulting in a linear time complexity of **O(n)**.

# Space Complexity: O(k)
In the worst-case scenario (e.g., a strictly increasing array), the deque will store up to `k` elements, giving a space complexity of **O(k)**.

# Code
```java
class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        int start = 0, end = 0, n = nums.length;
        Deque<Integer> dq = new ArrayDeque<>();
        int[] ans = new int[n - k + 1];
        int index = 0;
        
        while (end < n) {
            while (!dq.isEmpty() && nums[end] > dq.peekLast())
                dq.pollLast();
            dq.addLast(nums[end]);
            
            if (end - start + 1 == k) {
                ans[index] = dq.peekFirst();
                index++;
                if (dq.peekFirst() == nums[start])
                    dq.pollFirst();
                start++;
            }
            end++;
        }
        
        return ans;
    }
}
