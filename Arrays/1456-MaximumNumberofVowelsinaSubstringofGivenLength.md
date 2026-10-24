# Maximum Number of Vowels in a Substring of Given Length

**Problem Link:** [LeetCode 1456 – Maximum Number of Vowels in a Substring of Given Length](https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/)

## Problem Description

Given a string `s` and an integer `k`, return the maximum number of vowel letters in any substring of `s` with length `k`.

Vowels are `'a'`, `'e'`, `'i'`, `'o'`, and `'u'`.

### Examples

**Example 1:**
- Input: `s = "abciiidef", k = 3`
- Output: `3`
- Explanation: The substring `"iii"` contains 3 vowels.

**Example 2:**
- Input: `s = "aeiou", k = 2`
- Output: `2`
- Explanation: Any substring of length 2 contains 2 vowels.

**Example 3:**
- Input: `s = "leetcode", k = 3`
- Output: `2`
- Explanation: The substring `"lee"` contains 2 vowels.

### Constraints
- `1 <= s.length <= 10^5`
- `s` consists of lowercase and uppercase English letters.
- `1 <= k <= s.length`

## Intuition

A brute-force approach would count the vowels in every substring of length `k`, repeatedly checking the same characters. Instead, a **fixed-size sliding window** allows us to maintain the vowel count efficiently as the window moves through the string.

## Approach

1. Initialize two pointers, `start` and `end`, along with `count` and `max`.
2. Expand the window by moving `end`. If the current character is a vowel, increment `count`.
3. When the window size becomes `k`, update `max` with the current vowel count.
4. Before sliding the window forward, remove the contribution of the character at `start` if it is a vowel.
5. Increment `start` and continue until all characters have been processed.
6. Return `max`.

## Complexity Analysis

- **Time Complexity:** `O(n)` — Each character is processed a constant number of times.
- **Space Complexity:** `O(1)` — Only a fixed number of variables are used.

## Code

```java
class Solution {
    boolean isVowel(char ch) {
        return (ch == 'a' || ch == 'e' || ch == 'i'
                || ch == 'o' || ch == 'u'
                || ch == 'A' || ch == 'E' || ch == 'I'
                || ch == 'O' || ch == 'U');
    }

    public int maxVowels(String s, int k) {
        int start = 0, end = 0, n = s.length();
        int count = 0, max = 0;

        while (end < n) {
            if (isVowel(s.charAt(end))) {
                count++;
            }

            if (end - start + 1 == k) {
                max = Math.max(max, count);

                if (isVowel(s.charAt(start))) {
                    count--;
                }
                start++;
            }

            end++;
        }

        return max;
    }
}
```
