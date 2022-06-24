class Solution {
public:
    vector<int> temp;
    vector<vector<int>> ans;

    void dfs(int n, int curr, int k) {
        if (temp.size() + (n - curr + 1) < k) {
            return;
        }
        if (temp.size() == k) {
            ans.push_back(temp);
            return;
        }
        temp.push_back(curr);
        dfs(n, curr + 1, k);
        temp.pop_back();

        dfs(n, curr + 1, k);
    }

    vector<vector<int>> combine(int n, int k) {
        dfs(n, 1, k);
        return ans;
    }
};
