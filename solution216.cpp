class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;

    void combination(int k, int n, int pathSum, int index) {
        if (pathSum == n && path.size() == k) {
            result.push_back(path);
        } else if (pathSum > n) {
            return;
        }
        for (int i = index; i <= 9; i++) {
            path.push_back(i);
            pathSum += i;
            combination(k, n, pathSum, i + 1);
            pathSum -= i;
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        combination(k, n, 0, 1);
        return result;
    }
};
