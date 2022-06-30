class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxSize = 0;
        int currSize = 0;
        int left = 0, right = height.size() - 1;

        while (left < right) {
            currSize = min(height[left], height[right]) * (right - left);
            if (currSize > maxSize) {
                maxSize = currSize;
            }
            if (height[left] < height[right]) {
                left ++;
            } else {
                right --;
            }
        }
        return maxSize;
    }
};
