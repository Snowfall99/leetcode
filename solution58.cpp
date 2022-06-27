class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int count = 0;
        int index = n - 1;
        while (s[index] == ' ') {
            index --;
        }
        while(index >= 0) {
            if (s[index] == ' ') {
                return count;
            }
            count ++;
            index --;
        }
        return count;
    }
};
