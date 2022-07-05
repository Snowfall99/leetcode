class Solution {
public:
    vector<vector<int>> ans;
    vector<int> t;

    void dfs(bool choosePre, int curr, vector<int>& nums) {
        if (curr == nums.size()) {
            ans.push_back(t);
            return;
        }
        dfs(false, curr + 1, nums);
        if (!choosePre && curr > 0 && nums[curr] == nums[curr -1]) {
            return;
        }
        t.push_back(nums[curr]);
        dfs(true, curr + 1, nums);
        t.pop_back();
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        dfs(false, 0, nums);
        return ans;
    }
};
