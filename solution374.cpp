/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int pick = n;
        int front = 1, back = n;
        int mid;

        while (front < back) {
            mid = front + (back - front) / 2;
            if (guess(mid) <= 0) {
                back = mid;
            } else {
                front = mid + 1;
            }
        }

        pick = front;
        return pick;
    }
};