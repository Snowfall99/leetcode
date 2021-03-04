class Solution {
public:
    int max(int a, int b) {return (a >= b)? a : b;}
    int min(int a, int b) {return (a < b)? a : b;}
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0, right = arr.size() - 1;
        int index = -1;
        int mid = left + (right - left) / 2;

        if (arr[0] >= x) {
            return vector<int>(arr.begin(), arr.begin() + k);
        } else if (arr[right] <= x) {
            return vector<int>(arr.end() - k, arr.end());
        } else {
            while (left < right) {
                if (arr[mid] == x) {
                    break;
                } else if (arr[mid] > x) {
                    if (arr[mid - 1] < x) break;
                    right = mid;
                    mid = left + (right - left) / 2;
                } else {
                    if (arr[mid + 1] > x) break;
                    left = mid;
                    mid = left + (right - left) / 2;
                }
            }
            index = mid;
            int low = max(index - k, 0), high = min(index + k, arr.size() - 1);
            while ((high - low) + 1 > k) {
                if ((arr[high] - x) >= (x - arr[low])) {
                    high -= 1;
                } else {
                    low += 1;
                }
            }
            // cout<<"low: "<<low<<" high: "<<high<<endl;
            return vector<int>(arr.begin() + low, arr.begin() + low + k);
        }
    }
};