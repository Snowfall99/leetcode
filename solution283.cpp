class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int head = 0;
        int tail = 0;
        int size = nums.size();

        while (tail < size) {
            if (nums[tail]) {
                swap(nums[head], nums[tail]);
                head ++;
            }
            tail ++;
        }
    }
};
