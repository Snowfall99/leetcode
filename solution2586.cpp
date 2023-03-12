class Solution {
public:
    int vowelStrings(vector<string>& words, int left, int right) {
        int count = 0;
        for (int i = left; i <= right; i++) {
            string word = words[i];
            int last = word.size() - 1;
            if (word[0] == 'a' || word[0] == 'e' || word[0] == 'i' || word[0] == 'o' || word[0] == 'u') {
                if (word[last] == 'a' || word[last] == 'e' || word[last] == 'i' || word[last] == 'o' || word[last] == 'u') {
                    count ++;
                }
            }
        }
        return count;
    }
};
