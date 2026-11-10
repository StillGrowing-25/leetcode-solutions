class Solution {
    public int calculate(String s) {
        int currNum = 0;
        int prevop = '+';
        char ch;
        int res = 0;
        int lastNum = 0;
        for (int i = 0; i < s.length(); i++) {
            ch = s.charAt(i);
            if (Character.isDigit(ch)) {
                currNum = currNum * 10 + (ch - '0');
            }
            if ((!Character.isDigit(ch) && !Character.isWhitespace(ch)) || i == s.length() - 1) {
                if (prevop == '+' || prevop == '-') {
                    res += lastNum;
                    lastNum = (prevop == '-') ? -currNum : currNum;
                } else if (prevop == '*') {
                    lastNum *= currNum;
                } else if (prevop == '/') {
                    lastNum /= currNum;
                }
                prevop = ch;
                currNum = 0;
            }
        }
        res += lastNum;
        return res;
    }
}
