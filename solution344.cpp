class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        int p0 = 0, p1 = n-1;
        while(p0 <= p1) {
            swap(s[p0], s[p1]);
            p0 ++;
            p1 --;
        }
    }
};