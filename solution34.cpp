class Solution {
public:
    int binarySearch(vector<int>& nums, int target, bool upper) {
        int left = 0, right = nums.size() - 1;
        int ans = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                ans = mid;
                if (upper) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int begin = -1;
        int end = -1;

        if (nums.size() == 0) {
            return {begin, end};
        }
        begin = binarySearch(nums, target, false);
        end = binarySearch(nums, target, true);

        return {begin, end};
    }
};
