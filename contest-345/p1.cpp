class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        unordered_map<int, bool> map;
        int curr = 0;
        int i = 1;
        vector<int> result;
        
        for (int j = 0; j < n; j++) {
            map[j] = false;
        }
        
        while (!map[curr]) {
            map[curr] = true;
            curr = (curr + i * k) % n;
            i ++;
        }
        
        for (auto &[key, val] : map) {
            if (!map[key]) {
                result.push_back(key + 1);
            }
        }
        sort(result.begin(), result.end());
        return result;
    }
};
