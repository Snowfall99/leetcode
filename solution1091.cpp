class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0] == 1) {
            return -1;
        }
        
        int dirs[8][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
        int res = 1;
        int n = grid.size();
        queue<pair<int, int>> que;
        grid[0][0] = 1;
        que.push({0, 0});

        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; i ++) {
                auto curr = que.front();
                que.pop();
                if (curr.first == n - 1 && curr.second == n - 1) {
                    return res;
                }
                for (auto dir : dirs) {
                    int nx = curr.first + dir[0];
                    int ny = curr.second + dir[1];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] == 0)  {
                        grid[nx][ny] = 1;
                        que.push({nx, ny});
                    } 
                }
            }
            res ++;
        }
        return -1;
    }
};
