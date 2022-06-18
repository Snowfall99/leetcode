class Solution {
public:
    int strStr(string haystack, string needle) {
        int hay_size = haystack.size();
        int needle_size = needle.size();

        if (needle_size == 0) {
            return 0;
        }
        for (int i = 0; i < hay_size; i++) {
            if (haystack[i] == needle[0]) {
                bool flag = true;
                for (int j = 1; j < needle_size; j++) {
                    if (haystack[i+j] != needle[j]) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    return i;
                }
            }
        }
        return -1;
    }
};
