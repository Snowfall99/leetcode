class Solution {
public:
    int nextGreaterElement(int n) {
        auto nums = to_string(n);
        int i = (int) nums.length() - 2;
        int j = (int) nums.length() - 1;

        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i --;
        }
        if (i < 0) {
            return -1;
        }
        while (j >= 0 && nums[i] >= nums[j]) {
            j --;
        }
        swap(nums[i], nums[j]);
        reverse(nums.begin() + i + 1, nums.end());
        long res = stol(nums);
        return res > INT_MAX ? -1 : res;
    }
};
