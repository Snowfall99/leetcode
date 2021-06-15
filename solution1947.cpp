class Solution {
public:
    int minArray(vector<int>& numbers) {
        int size = numbers.size();
        int front = 0;
        int back = size - 1;
        int mid;

        while (front < back) {
            mid = front + (back - front) / 2;
            if (numbers[mid] < numbers[back]) {
                back = mid;
            } else if (numbers[mid] > numbers[back]) {
                front = mid + 1;
            } else {
                back -= 1;
            }
        }
        return numbers[front];
    }
};