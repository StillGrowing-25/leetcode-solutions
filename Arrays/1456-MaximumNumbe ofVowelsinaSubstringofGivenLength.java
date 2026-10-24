class Solution {
    boolean isVowel(char ch) {
        return (ch == 'a' || ch == 'e' || ch == 'o' || ch == 'i' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I'
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
                }start++;
            }
            end++;
        }
        return max;
    }
}
