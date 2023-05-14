class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int len = derived.size();
        int count = 0;
        
        for (int i = 0; i < len; i++) {
            count += derived[i];
        }
        
        return count % 2 == 0;
    }
};
