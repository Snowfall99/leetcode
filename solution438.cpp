class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int left = 0, right = 0;
        int m = s.size();
        int n = p.size();
        vector<int> ans;
        vector<int> sCount(26);
        vector<int> pCount(26);

        if (m < n) {
            return ans;
        }

        for (int i = 0; i < n; i++) {
            sCount[s[i] - 'a'] ++;
            pCount[p[i] - 'a'] ++;
        }

        if (sCount == pCount) {
            ans.emplace_back(0);
        }

        for (int i = 0; i < m - n; i++) {
            sCount[s[i] - 'a'] --;
            sCount[s[i + n] - 'a'] ++;
            if (sCount == pCount) {
                ans.emplace_back(i + 1);
            }
        }

        return ans;
    }
};
