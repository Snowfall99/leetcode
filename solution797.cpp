class Solution {
public:
    vector<vector<int>> ans;
    vector<int> st;
    
    void dfs(vector<vector<int>>& graph, int x, int n) {
        if (x == n) {
            ans.push_back(st);
            return;
        }

        for (auto y : graph[x]) {
            st.push_back(y);
            dfs(graph, y, n);
            st.pop_back();
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size() - 1;
        st.push_back(0);
        dfs(graph, 0, n);
        return ans;
    }
};
