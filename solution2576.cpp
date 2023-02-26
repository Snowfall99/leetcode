class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        int right = nums.size() / 2;
        int left = 0;
        
        sort(nums.begin(), nums.end());
        while (right < nums.size() && left < nums.size() / 2) {
            if (2 * nums[left] <= nums[right]) {
                left ++;
            }
            right ++;
        }
        return left * 2;
    }
};
