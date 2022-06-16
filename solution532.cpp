class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_set<int> visited;
        unordered_set<int> result;

        for (int num : nums) {
            if (visited.count(num - k)) {
                result.emplace(num - k);
            }
            if (visited.count(num + k)) {
                result.emplace(num);
            }
            visited.emplace(num);
        }
        return result.size();
    }
};
