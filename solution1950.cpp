class Solution {
public:
    int row, col;
    bool flag[100][100] = {false};
    
    int movingCount(int m, int n, int k) {
        // DFS
        row = m;
        col = n;
        int count = dfs(0, 0, k);
        return count;
    }

    int dfs(int i, int j, int k) {
        if (i >= row || i < 0 || j >= col || j < 0 || flag[i][j] == true) {
            return 0;
        }
        int ii = 0, jj = 0;
        ii = i / 10 + i % 10;
        jj = j / 10 + j % 10;
        if (ii + jj > k) {
            return 0;
        }

        flag[i][j] = true;
        return 1 + dfs(i + 1, j, k) + dfs(i - 1, j, k) + dfs(i, j + 1, k) + dfs(i, j -1, k);
    }
};