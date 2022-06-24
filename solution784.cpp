class Solution {
public:
    void dfs(vector<string>& ans,string s,string temp,int curr){
        if (curr == s.size()) {
            ans.push_back(temp);
            return;
        }
        if (isdigit(s[curr])) {
            temp += s[curr];
            dfs(ans, s, temp, curr + 1);
            temp.erase(temp.begin() + curr);
        } else {
            temp += toupper(s[curr]);
            dfs(ans, s, temp, curr + 1);
            temp.erase(temp.begin() + curr);
            temp += tolower(s[curr]);
            dfs(ans, s, temp, curr + 1);
            temp.erase(temp.begin() + curr);
        }
    }
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        string temp;
        dfs(ans, s, temp, 0);
        return ans;
    }
};
