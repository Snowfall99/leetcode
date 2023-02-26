class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>> result;
        while (nums1.size() != 0 && nums2.size() != 0) {
            int front1 = nums1[0][0];
            int front2 = nums2[0][0];
            if (front1 < front2) {
                vector<int> r = nums1.front();
                result.push_back(r);
                nums1.erase(nums1.begin());
            } else if (front1 > front2) {
                vector<int> r = nums2.front();
                result.push_back(r);
                nums2.erase(nums2.begin());
            } else {
                int v1 = nums1[0][1];
                int v2 = nums2[0][1];
                result.push_back(vector<int>{front1, v1+v2});
                nums1.erase(nums1.begin());
                nums2.erase(nums2.begin());
            }
        }
        while (nums1.size() != 0) {
            vector<int> r = nums1.front();
            result.push_back(r);
            nums1.erase(nums1.begin());
        }
        while (nums2.size() != 0) {
            vector<int> r = nums2.front();
            result.push_back(r);
            nums2.erase(nums2.begin());
        }
        return result;
    }
};
