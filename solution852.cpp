class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int size = arr.size();
        int front = 0, back = size;
        int mid;

        while (front < back) {
            mid = front + (back - front) / 2;
            if (arr[mid] < arr[mid + 1]) {
                front = mid + 1;
            } else {
                back = mid;
            }
        }

        return front;
    }
};