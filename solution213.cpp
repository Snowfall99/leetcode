class Solution {
public:
    int robRange(vector<int>& nums, int start, int end) {
        int first = nums[start];
        int second = max(nums[start], nums[start + 1]);

        for (int i = start + 2; i <= end; i++) {
            int temp = second;
            second = max(nums[i] + first, second);
            first = temp;
        }

        return second;
    }

    int rob(vector<int>& nums) {
        int size = nums.size();
        
        if (size == 1) {
            return nums[0];
        }
        if (size == 2) {
            return max(nums[0], nums[1]);
        }

        return max(robRange(nums, 0, size - 2), robRange(nums, 1, size - 1));
    }
};
