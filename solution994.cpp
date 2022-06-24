class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        queue<pair<int, int>> que;
        int minutes = 0;
        int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 2) {
                    que.emplace(i, j);
                }
            }
        }
        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; i++) {
                auto curr = que.front();
                que.pop();
                for (int j = 0; j < 4; j++) {
                    int ni = curr.first + dirs[j][0];
                    int nj = curr.second + dirs[j][1];
                    if (ni >= 0 && nj >= 0 && ni < row && nj < col && grid[ni][nj] == 1) {
                        grid[ni][nj] = 2;
                        que.emplace(ni, nj);
                    }
                }
            }
            minutes ++;
        }
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        return minutes == 0 ? 0 : minutes - 1;
    }
};
