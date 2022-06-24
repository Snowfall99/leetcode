class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int row = mat.size();
        int col = mat[0].size();
        vector<vector<int>> res(row, vector(col, 0));
        vector<vector<bool>> seen(row, vector(col, false));
        queue<pair<int, int>> que;
        
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (mat[i][j] == 0) {
                    que.emplace(i, j);
                    seen[i][j] = true;
                }
            }
        }
        
        while (!que.empty()) {
            auto curr = que.front();
            que.pop();
            for (int i = 0; i < 4; i++) {
                int ni = curr.first + dirs[i][0];
                int nj = curr.second + dirs[i][1];
                if (ni >= 0 && nj >= 0 && ni < row && nj < col && !seen[ni][nj]) {
                    res[ni][nj] = res[curr.first][curr.second] + 1;
                    que.emplace(ni, nj);
                    seen[ni][nj] = true;
                }
            }
        }
        return res;
    }
};
