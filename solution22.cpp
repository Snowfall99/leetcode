class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<vector<string>> result(n+1);
        result[0] = {""};
        result[1] = {"()"};
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                for (string p : result[j]) {
                    for (string q : result[i - j - 1]) {
                        result[i].push_back("(" + p + ")" + q);
                    }
                }
            }
        }
        return result[n];
    }
};