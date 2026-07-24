# Majority Element II

**Problem Link:** https://leetcode.com/problems/majority-element-ii/

---

# Intuition

Since an element must appear more than ⌊n/3⌋ times, there can be **at most two such elements** in the array. Instead of storing the frequency of every element using a hash map, we can maintain two potential candidates and their counts.

Using the **Boyer-Moore Voting Algorithm**, we eliminate different elements by decreasing both counters whenever a new distinct element is encountered. After the first pass, the remaining candidates are the only possible majority elements. A second pass is required to verify whether they actually occur more than ⌊n/3⌋ times.

---

# Approach

1. Initialize two candidates (`a`, `b`) and their counts (`ca`, `cb`).
2. Traverse the array:
   - If a counter becomes zero, assign the current element as the new candidate.
   - If the current element matches a candidate, increment its count.
   - Otherwise, decrement both counts.
3. Reset the counters and traverse the array again to count the actual occurrences of the two candidates.
4. Add the candidates to the answer if their frequency is greater than ⌊n/3⌋.
5. Return the answer.

---

# Complexity

- **Time complexity:** `O(n)`
- **Space complexity:** `O(1)`

---

# Code

```cpp
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int x = nums.size() / 3;

        int a = INT_MIN, b = INT_MIN;
        int ca = 0, cb = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (ca == 0 && nums[i] != b) {
                ca = 1;
                a = nums[i];
            } else if (cb == 0 && nums[i] != a) {
                cb = 1;
                b = nums[i];
            } else if (nums[i] == a) {
                ca++;
            } else if (nums[i] == b) {
                cb++;
            } else {
                ca--;
                cb--;
            }
        }

        ca = 0;
        cb = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == a)
                ca++;
            else if (nums[i] == b)
                cb++;
        }

        if (ca > x) ans.push_back(a);
        if (cb > x) ans.push_back(b);

        return ans;
    }
};
```

---

# Hash Map Solution

**Problem Link:** https://leetcode.com/problems/majority-element-ii/

---

# Intuition

Store the frequency of every element in a hash map. Since we only need elements occurring more than ⌊n/3⌋ times, we can simply count each element and collect those whose frequency exceeds the threshold.

---

# Approach

1. Compute the threshold `⌊n/3⌋`.
2. Store the frequency of each element using an `unordered_map`.
3. Traverse the map and add every element whose frequency is greater than the threshold.
4. Return the answer.

---

# Complexity

- **Time complexity:** `O(n)` (Average)
- **Space complexity:** `O(n)`

---

# Code

```cpp
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int x = nums.size() / 3;

        unordered_map<int, int> hash;

        for (int i = 0; i < nums.size(); i++) {
            hash[nums[i]]++;
        }

        for (auto it : hash) {
            if (it.second > x) {
                ans.push_back(it.first);
            }
        }

        return ans;
    }
};
```
