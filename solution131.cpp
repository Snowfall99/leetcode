class Solution {
public:
    vector<vector<string>> result;
    vector<string> path;
    
    bool isPalindrome(string s, int start, int end) {
        if (start >= end) {
            return true;
        }
        if (s[start] != s[end]) {
            return false;
        }
        return isPalindrome(s, start + 1, end - 1);
    }

    void backtrack(string s, int index) {
        if (index == s.size()) {
            result.push_back(path);
            return;
        }
        for (int i = index; i < s.size(); i++) {
            if (isPalindrome(s, index, i)) {
                path.push_back(s.substr(index, i - index + 1));
            } else {
                continue;
            }
            backtrack(s, i + 1);
            path.pop_back();
        }
    }

    vector<vector<string>> partition(string s) {
        backtrack(s, 0);
        return result;
    }
};
