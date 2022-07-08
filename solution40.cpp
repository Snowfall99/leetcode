class Solution {
public:
    vector<vector<int>> ans;
    vector<int> curr;
    vector<int> visited;

    void backtrace(vector<int>& candidates, int target, int index) {
        if (target == 0) {
            ans.push_back(curr);
            return;
        }

        if (index == candidates.size()) {
            return;
        }

        backtrace(candidates, target, index + 1);
        if (index > 0 && candidates[index] == candidates[index - 1] && !visited[index - 1]) {
            return;
        }
        if (candidates[index] <= target) {
            curr.push_back(candidates[index]);
            visited[index] = 1;
            backtrace(candidates, target - candidates[index], index + 1);
            visited[index] = 0;
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        visited.resize(candidates.size());
        sort(candidates.begin(), candidates.end());
        backtrace(candidates, target, 0);
        return ans;   
    }
};
