impl Solution {
    pub fn max_product(nums: Vec<i32>) -> i32 {
        let mut result = nums[0];
        let mut dp_max = nums[0];
        let mut dp_min = nums[0];
        for i in 1..nums.len() {
            let (max, min) = (dp_max, dp_min);
            dp_max = i32::max(max * nums[i], i32::max(nums[i], min * nums[i]));
            dp_min = i32::min(min * nums[i], i32::min(nums[i], max * nums[i]));
            result = result.max(dp_max);
        }
        result
    }
}
