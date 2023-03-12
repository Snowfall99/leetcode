class Solution {
public:
    int maxScore(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        int score = 0;
        long curr = 0;
        int size = nums.size();

        for (int i = 0; i < size; i++) {
            curr += nums[i];
            if (curr > 0) {
                score ++;
            } else {
                break;
            }
        }
        return score;
    }
};
