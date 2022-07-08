class Solution {
public:
    bool backtrace(vector<vector<char>>& board, string word, int row, int col, int index, vector<vector<int>>& visited) {
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size()) {
            return false;
        }
        if (visited[row][col]) {
            return false;
        }
        if (board[row][col] != word[index]) {
            return false;
        }
        visited[row][col] = 1;
        index ++;
        if (index == word.size()) {
            return true;
        }
        bool result = backtrace(board, word, row - 1, col, index, visited) || backtrace(board, word, row + 1, col, index, visited) || backtrace(board, word, row, col - 1, index, visited) || backtrace(board, word, row, col + 1, index, visited);
        visited[row][col] = 0;
        return result;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> visited(m, vector<int>(n));
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (backtrace(board, word, i, j, 0, visited)) {
                    return true;
                }
            }
        }
        return false;
    }
};
