class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minLen = INT_MAX;
        int n = nums.size();
        int sum = 0;
        int start = 0, end = 0;

        while (end < n) {
            sum += nums[end];
            while (sum >= target) {
                minLen = min(minLen, end - start + 1);
                sum -= nums[start];
                start ++;
            }
            end ++;
        }
        
        return minLen == INT_MAX ? 0 : minLen;
    }
};
