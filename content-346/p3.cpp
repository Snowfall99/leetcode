class Solution {
public:
    int punishmentNumber(int n) {
        int res = 0;
        for (int i = 1; i <= n; i++) {
            if (isPunishmentNumber(to_string(i * i), i)) {
                res += i * i;
            }
        }
        return res;
    }
    
    bool isPunishmentNumber(string s, int target) {
        if (s == "" && target == 0) {
            return true;
        }
        if (target < 0) {
            return false;
        }
        for (int i = 0; i < s.size(); i++) {
            string left = s.substr(0, i + 1);
            string right = s.substr(i + 1);
            int leftNum = stoi(left);

            if (isPunishmentNumber(right, target - leftNum)) {
                return true;
            }
        }
        return false;
    }
};
