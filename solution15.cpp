class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        for (int i = 0; i < n; i ++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int curr = nums[i];
            int first = i + 1;
            int second = n - 1;
            while (first < second) {
                if (first > i + 1 && nums[first] == nums[first - 1]) {
                    first ++;
                    continue;
                }
                if (curr + nums[first] + nums[second] == 0) {
                    ans.push_back({curr, nums[first], nums[second]});
                    first ++;
                    second --;
                } else if (curr + nums[first] + nums[second] > 0) {
                    second --;
                } else {
                    first ++;
                }
            }
        }
        return ans;
    }
};
