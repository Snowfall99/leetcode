#include<vector>
using namespace std;

class Solution {
public:
    int specialArray(vector<int>& nums) {
        int len = nums.size();
        for (int i=1; i<=len; i++) {
            vector<int> tmp;
            for (int j=0; j<len; j++) {
                if (nums[j] >= i) tmp.push_back(nums[j]);
            }
            if (tmp.size() == i) return i;
        }
        return -1;
    }
};