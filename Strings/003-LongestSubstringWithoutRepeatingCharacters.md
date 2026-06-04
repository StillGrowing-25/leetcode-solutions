# Longest Substring Without Repeating Characters

# Problem Description [3. Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/)

Given a string `s`, find the length of the longest substring without repeating characters.

A substring is a contiguous sequence of characters within a string.

### Example 1:

Input: `s = "abcabcbb"`

Output: `3`

Explanation: The answer is `"abc"`, with length 3.

### Example 2:

Input: `s = "bbbbb"`

Output: `1`

Explanation: The answer is `"b"`, with length 1.

### Example 3:

Input: `s = "pwwkew"`

Output: `3`

Explanation: The answer is `"wke"`, with length 3.

### Constraints:

* `0 <= s.length <= 5 * 10^4`
* `s` consists of English letters, digits, symbols and spaces.

# Intuition

For every character in the string, we can consider it as the starting point of a substring. We then try to extend the substring one character at a time while ensuring that no character repeats.

To determine whether the next character can be included, we check if it already exists in the current substring. If a duplicate is found, the current substring can no longer be extended, so we stop and move to the next starting position.

By keeping track of the maximum valid substring length found during this process, we obtain the answer.

# Approach

1. Handle the edge case where the string is empty by returning `0`.
2. Iterate through every index `i` and treat it as the starting position of a substring.
3. Initialize:

   * `len` as the current substring length.
   * `n` as the number of characters currently present in the substring.
4. For every next character `s[j]`:

   * Check whether it already exists in the current substring using a loop.
   * If a duplicate is found, stop extending the substring.
5. Otherwise:

   * Increase the current length.
   * Update the maximum length found so far.
6. After checking all possible starting positions, return the maximum length.

# Complexity Analysis

## Time Complexity

Let:

* `n = length of the string`

The algorithm uses three nested loops:

* Outer loop chooses the starting index.
* Middle loop extends the substring.
* Inner loop checks for duplicates.

**O(n³)**

## Space Complexity

Only a few integer and boolean variables are used.

**O(1)**

# Code

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0)
            return 0;

        int len = 1;
        int maximum = 1;
        int n;

        for(int i = 0; i < s.size(); i++) {
            len = 1;
            n = 1;

            for(int j = i + 1; j < s.size(); j++) {
                bool flag = true;

                for(int k = 0; k < n; k++) {
                    if(s[i + k] == s[j]) {
                        flag = false;
                        break;
                    }
                }

                if(!flag)
                    break;

                n++;
                ++len;
                maximum = max(len, maximum);
            }
        }

        return maximum;
    }
};
```
