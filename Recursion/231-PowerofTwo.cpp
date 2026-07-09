class Solution {
public:
    bool isPowerOfTwo(int n) {

        if (n <= 0)
            return false;

        double x = log2(n);
        int y = (int)x;
        int z = y+1;
        
        if(x == y || x == z)
        return true;
        else
        return false;
    }
};
