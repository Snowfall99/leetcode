class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        queue<pair<int, int>> que;
        int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        for (int i = 0; i < m; i ++) {
            if (board[i][0] == 'O') {
                que.push({i, 0});
                board[i][0] = 'A';
            }
            if (board[i][n - 1] == 'O') {
                que.push({i, n - 1});
                board[i][n - 1] = 'A';
            }
        }

        for (int i = 0; i < n; i ++) {
            if (board[0][i] == 'O') {
                que.push({0, i});
                board[0][i] = 'A';
            }
            if (board[m - 1][i] == 'O') {
                que.push({m - 1, i});
                board[m - 1][i] = 'A';
            }
        }

        while (!que.empty()) {
            auto curr = que.front();
            que.pop();
            for (auto dir : dirs) {
                int nx = curr.first + dir[0];
                int ny = curr.second + dir[1];
                if (nx >= 0 && ny >= 0 && nx < m && ny < n && board[nx][ny] == 'O') {
                    board[nx][ny] = 'A';
                    que.push({nx, ny});
                }
            }
        }

        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'A') {
                    board[i][j] = 'O';
                } else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
