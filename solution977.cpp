class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int size = nums.size();
        vector<int> result(size);

        for (int i = 0, j = size - 1, pos = size - 1; pos >= 0; pos--) {
            int num1 = nums[i] * nums[i];
            int num2 = nums[j] * nums[j];
            if (num1 < num2) {
                result[pos] = num2;
                j --;
            } else {
                result[pos] = num1;
                i ++;
            }
        }
        return result;
    }
};
