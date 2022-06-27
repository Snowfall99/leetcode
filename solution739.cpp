class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        int size = temperatures.size();
        vector<int> ans(size);
        for (int i = 0; i < size; i++) {
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                int prevIndex = st.top();
                ans[prevIndex] = i - prevIndex;
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};
