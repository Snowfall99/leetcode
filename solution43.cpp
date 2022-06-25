class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }
        int m = num1.size();
        int n = num2.size();
        vector<int> ansArr(m + n);
        for (int i = m - 1; i >= 0; i--) {
            int x = num1.at(i) - '0';
            for (int j = n - 1; j >= 0; j--) {
                int y = num2.at(j) - '0';
                ansArr[i + j + 1] += x * y;
            }
        }
        for (int i = m + n - 1; i >= 1; i--) {
            ansArr[i - 1] += ansArr[i] / 10;
            ansArr[i] %= 10;
        }
        string ans;
        int index = ansArr[0] == 0 ? 1 : 0;
        while (index < m + n) {
            ans.push_back(ansArr[index]);
            index ++;
        }
        for (auto &c: ans) {
            c += '0';
        }
        return ans;
    }
};
