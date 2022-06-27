class Solution {
public:
    bool isPowerOfTwo(int n) {
        int count = 0;
        while (n != 0) {
            if (n & 1) {
                count ++;
                if (count > 1) {
                    return false;
                }
            }
            n >>= 1;
        }
        return count == 1;
    }
};
