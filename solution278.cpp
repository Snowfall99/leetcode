// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int ret = 1;
        int front = 1, back = n;
        int mid = front + (back - front) / 2;

        while (front < back) {
            if (isBadVersion(mid) == true) {
                if (isBadVersion(mid - 1) == false) {
                    ret = mid;
                    break;
                } else {
                    back = mid;
                    mid = front + (back - front) / 2;
                }
            } else {
                if (isBadVersion(mid + 1) == true) {
                    ret = mid + 1;
                    break;
                } else {
                    front = mid;
                    mid = front + (back - front) / 2;
                }
            }
        }
        return ret;
    }
};