class Solution {
public:
    string reverseWords(string s) {
        int left = 0;
        int right = 0;
        int size = s.size();

        while (left < size) {
            while (right < size && s[right] != ' ') {
                right ++;
            }
            int tmp_right = right - 1;
            while (left < tmp_right) {
                swap(s[left], s[tmp_right]);
                left ++;
                tmp_right --;
            }
            right ++;
            left = right;
        }
        return s;
    }
};
