class Solution {
public:
    vector<int> leftRigthDifference(vector<int>& nums) {
        vector<int> lefts;
        vector<int> rights;
        vector<int> result;
        int total = 0;
        
        if (nums.size() == 0) {
            return result;
        }
        lefts.push_back(0);
        for (int i = 1; i < nums.size(); i++) {
            lefts.push_back(nums[i - 1] + lefts[i - 1]);
            total += nums[i - 1];
        }
        total += nums[nums.size() - 1];
        for (int i = 0; i < nums.size(); i++) {
            rights.push_back(total - nums[i] - lefts[i]);
        }
        for (int i = 0; i < nums.size(); i++) {
            if (rights[i] > lefts[i]) {
                result.push_back(rights[i] - lefts[i]);
            } else {
                result.push_back(lefts[i] - rights[i]);
            }
        }
        return result;
    }
};
