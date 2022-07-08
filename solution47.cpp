class Solution {
    vector<int> visited;
public:
    void backtrace(int curr, vector<int>& nums, vector<vector<int>>& ans, vector<int>& perm) {
        if (curr == nums.size()) {
            ans.push_back(perm);
            return;
        }

        for (int i = 0; i < nums.size(); i ++) {
            if (visited[i] || (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1])) {
                continue;
            }
            perm.push_back(nums[i]);
            visited[i] = 1;
            backtrace(curr + 1, nums, ans, perm);
            visited[i] = 0;
            perm.pop_back();
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> perm;
        visited.resize(nums.size());
        backtrace(0, nums, ans, perm);
        return ans;    
    }
};
