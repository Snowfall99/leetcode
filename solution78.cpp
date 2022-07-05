class Solution {
public:
    vector<vector<int>> ans;
    vector<int> t;

    void dfs(int curr, vector<int>& nums) {
        if (curr == nums.size()) {
            ans.push_back(t);
            return;
        }

        t.push_back(nums[curr]);
        dfs(curr + 1, nums);
        t.pop_back();
        dfs(curr + 1, nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(0, nums);
        return ans;
    }
};
