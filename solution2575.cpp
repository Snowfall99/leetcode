class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        vector<int> result;
        int len = word.size();
        long int curr = 0;
        
        if (len == 0) {
            return result;
        }
        for (int i = 0; i < len; i++) {
            curr = curr * 10 + (word[i] - '0');
            if (curr % m == 0) {
                result.push_back(1);
            } else {
                result.push_back(0);
            }
            curr = curr % m;
        }
        return result;
    }
};
