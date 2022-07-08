class Solution {
public:
    vector<vector<int>> ans;
    vector<int> curr;

    void backtrace(vector<int>& candidates, int target, int index) {
        if (index == candidates.size()) {
            return;
        }

        if (target == 0) {
            ans.push_back(curr);
            return;
        }

        backtrace(candidates, target, index + 1);
        if (candidates[index] <= target) {
            curr.push_back(candidates[index]);
            backtrace(candidates, target - candidates[index], index);
            curr.pop_back();
        }        
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtrace(candidates, target, 0);
        return ans;
    }
};
