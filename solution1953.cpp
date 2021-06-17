class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        for (int i = 0; i < 32; i ++) {
            int ret = (n >> i) & 0x1;
            count += ret;
        }
        return count;
    }
};