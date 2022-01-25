impl Solution {
    pub fn robRange(nums: &Vec<i32>, start: usize, end: usize) -> i32 {
        let mut first: i32 = nums[start];
        let mut second: i32 = nums[start].max(nums[start+1]);

        for i in start+2..end {
            let mut temp = second;
            second = (nums[i] + first).max(second);
            first = temp;
        }
        return second;
    }

    pub fn rob(nums: Vec<i32>) -> i32 {
       let mut res1: i32 = 0;
       let mut res2: i32 = 0;
       
       if nums.len() == 1 {
           return nums[0];
       } else if nums.len() == 2 {
           return nums[0].max(nums[1]);
       }
       res1 = Solution::robRange(&nums, 0 as usize, nums.len()-1 as usize);
       res2 = Solution::robRange(&nums, 1 as usize, nums.len() as usize);

       return res1.max(res2);
    }
}
