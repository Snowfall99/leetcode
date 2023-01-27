use std::cmp::max;

impl Solution {
    pub fn max_sub_array(nums: Vec<i32>) -> i32 {
        let mut current: i32 = 0;
        let mut maxAns: i32 = nums[0];

        for num in nums {
            current = max(current + num, num);
            maxAns = max(maxAns, current);
        }
        return maxAns;
    }
}
