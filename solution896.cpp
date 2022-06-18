class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int size = nums.size() - 1;
        bool inc = false;
        bool dec = false;

        for (int i = 0; i < size; i++) {
            if (nums[i] > nums[i+1]) {
                if (inc) {
                    return false;
                } else {
                    dec = true;
                }
            } else if (nums[i] < nums[i+1]) {
                if (dec) {
                    return false;
                } else {
                    inc = true;
                }
            }
        }
        return true;
    }
};
