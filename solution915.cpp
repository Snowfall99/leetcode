class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int size = nums.size();
        int left = 0;
        int leftMax = nums[0];
        int currMax = nums[0];

        for (int i = 0; i < size - 1; i++) {
            currMax = max(currMax, nums[i]);
            if (nums[i] < leftMax) {
                leftMax = currMax;
                left = i;
            }
        }
        return left + 1;
    }
};
