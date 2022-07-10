class Solution {
public:
    int jump(vector<int>& nums) {
        int step = 0;
        int rightmost = 0;
        int end = 0;
        int size = nums.size();

        for (int i = 0; i < size - 1; i ++) {
            if (i <= rightmost) {
                rightmost = max(rightmost, i + nums[i]);
                if (i == end) {
                    end = rightmost;
                    step ++;
                }
            }
        }
        return step;
    }
};
