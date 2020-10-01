// Hash map, O(m+n)
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int jewelCount = 0;
        int JewelLength = J.length(), StoneLength = S.length();
        unordered_set<char> jewelSet;
        for (int i=0; i<JewelLength; i++) {
            char jewel = J[i];
            jewelSet.insert(jewel);
        }
        for (int i=0; i<StoneLength; i++) {
            char stone = S[i];
            if (jewelSet.count(stone)) {
                jewelCount++;
            }
        }
        return jewelCount;
    }
};