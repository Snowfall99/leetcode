class Solution {
public:
    int minLength(string s) {
        string ab = "AB";
        string cd = "CD";
        
        int pos1 = s.find(ab);
        int pos2 = s.find(cd);
        while (pos1 != std::string::npos || pos2 != std::string::npos) {
            if (pos1 != std::string::npos) {
                s.erase(pos1, 2);
            } else if (pos2 != std::string::npos) {
                s.erase(pos2, 2);
            }
            pos1 = s.find(ab);
            pos2 = s.find(cd);
        }
        
        return s.size();
    }
};
