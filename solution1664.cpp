class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int result = 0;
        int odd = 0, even = 0;
        int len = nums.size();
        int total = 0;
        int odd2 = 0, even2 = 0;
        vector<int> odd_list;
        vector<int> even_list;

        if (len == 0) {
            return result;
        }
        for (int i = 0; i < len; i++) {
            even_list.push_back(even);
            odd_list.push_back(odd);
            if (i % 2 == 0) {
                even += nums[i];
            } else {
                odd += nums[i];
            }
        }
        total = odd + even;
        for (int i = 0; i < len; i++) {
            if (i % 2 == 0) {
                odd2 = odd_list[i] + (even - even_list[i] - nums[i]);
                even2 = even_list[i] + (odd - odd_list[i]);
            } else {
                odd2 = odd_list[i] + (even - even_list[i]);
                even2 = even_list[i] + (odd - odd_list[i] - nums[i]);
            }
            if (odd2 == even2) {
                result ++;
            }
        }
        return result;
    }
};
