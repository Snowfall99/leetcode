#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int findShortestSubArray(vector<int>& nums) {
    int length = nums.size();
    int i;
    unordered_map<int, vector<int>> map;

    for(i = 0; i < length; i++) {
        if (map.count(nums[i])) {
            map[nums[i]][0] ++;
            map[nums[i]][2] = i;
        } else {
            map[nums[i]] = {1, i, i};
        }
    }

    int maxNum = 0, minLen = 0;
    for (auto& [_, vec] : map) {
        if (maxNum < vec[0]) {
            maxNum = vec[0];
            minLen = vec[2] - vec[1] + 1;
        } else if (maxNum == vec[0]) {
            if (minLen > vec[2] - vec[1] + 1) {
                minLen = vec[2] - vec[1] + 1;
            }
        }
    }
    return minLen;
}

int main() {
    vector<int> nums;
    for (int i = 0; i < 10; i++) {
        nums.push_back(i);
    }
    int minlen = findShortestSubArray(nums);
    printf("%d\n", minlen);
    return 0;
}