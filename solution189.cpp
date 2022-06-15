class Solution {
public:
    void reverse(vector<int>& nums, int start, int end) {
        while (start < end) {
            swap(nums[start], nums[end]);
            start ++;
            end --;
        }
    }

    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        k %= size;
        int n = size - 1;
        reverse(nums, 0, n);
        reverse(nums, 0, k - 1);
        reverse(nums, k, n);
    }
};
