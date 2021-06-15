class Solution {
public:
    int fib(int n) {
        if (n == 0) {
            return 0;
        } else if (n == 1) {
            return 1;
        }

        int f1 = 0, f2 = 1;
        int sum;
        for (int i = 1; i < n; i++) {
            sum = f1 + f2;
            f1 = f2;
            f2 = sum % 1000000007;
        }
        return sum % 1000000007;
    }
};