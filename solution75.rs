impl Solution {
    pub fn sort_colors(nums: &mut Vec<i32>) {
        let n = nums.len();
        let (mut p0, mut p1) = (0, 0);
        for i in 0..n {
            if nums[i] == 1 {
                let tmp = nums[i];
                nums[i] = nums[p1];
                nums[p1] = tmp;
                p1 += 1;
            } else if nums[0] == 0 {
                let tmp = nums[i];
                nums[i] = nums[p0];
                nums[p0] = tmp;
                if p0 < p1 {
                    let temp = nums[i];
                    nums[i] = nums[p1];
                    nums[p1] = temp;
                }
                p0 += 1;
                p1 += 1;
            }
        } 
    }
}