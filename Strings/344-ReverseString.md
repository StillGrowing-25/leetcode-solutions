````md
# Reverse String

# Problem Description
[344. Reverse String](https://leetcode.com/problems/reverse-string/)

Write a function that reverses a string. The input string is given as an array of characters `s`.

You must modify the input array **in-place** with **O(1)** extra memory.

### Example 1:

Input: `s = ["h","e","l","l","o"]`

Output: `["o","l","l","e","h"]`

### Example 2:

Input: `s = ["H","a","n","n","a","h"]`

Output: `["h","a","n","n","a","H"]`

### Constraints:

* `1 <= s.length <= 10^5`
* `s[i]` is a printable ASCII character.

# Intuition

To reverse the string efficiently, we can swap the characters from both ends while moving toward the center. Since only two pointers are required, the reversal can be performed in-place without using any additional array.

# Approach

1. Initialize two pointers:
   * `i` at the beginning of the string.
   * `j` at the end of the string.
2. While `i` is less than `j`:
   * Swap the characters at indices `i` and `j`.
   * Increment `i` and decrement `j`.
3. Continue until both pointers meet or cross.
4. The input array is now reversed in-place.

# Complexity Analysis

## Time Complexity

Let:

* `n = length of the string`

Each character is swapped at most once.

**O(n)**

## Space Complexity

Only two pointers are used, and the reversal is performed in-place.

**O(1)**

# Code

```cpp
class Solution {
public:
    void reverseString(vector<char>& s) {
        int i = 0, j = s.size() - 1;

        while (i < j) {
            swap(s[i], s[j]);
            i++;
            j--;
        }
    }
};
```
````
