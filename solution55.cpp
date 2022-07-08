class Solution {
public:
    bool canJump(vector<int>& nums) {
        int size = nums.size();
        int rightmost = 0;

        if (size == 1) {
            return true;
        }
        for (int i = 0; i < size; i ++) {
            if (i <= rightmost) {
                rightmost = max(rightmost, i + nums[i]);
                if (rightmost >= size - 1) {
                    return true;
                }
            }
        }

        return false;
    }
};
