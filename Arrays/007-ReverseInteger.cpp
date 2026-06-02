class Solution {
public:
    int reverse(int x) {
        long int y, d;
        y = 0;

        while (x != 0) {

            d = x % 10;
            y = y * 10 + d;

            if (y > INT_MAX || y < INT_MIN)
                return 0;
            x /= 10;
        }
        return y;
    }
};
