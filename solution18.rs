fn main() {
    Solution::four_sum(vec![-1,-5,-5,-3,2,5,0,4], -7);
}

struct Solution;

impl Solution {
    pub fn four_sum(nums: Vec<i32>, target: i32) -> Vec<Vec<i32>> {
        if nums.len() < 4 {return vec![];}
        let mut nums = nums;
        nums.sort();
        println!("{:?}", nums);
        let mut result = vec![];
        let length = nums.len();
        for i in 0..length-3 {
            if i > 0 && nums[i]==nums[i-1] {
                continue;
            }
            if nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > target {
                break;
            } 
            if nums[i] + nums[length-3] + nums[length-2] + nums[length-1] < target {
                continue;
            }
            for j in i+1..length-2 {
                if j>i+1 && nums[j] == nums[j-1] {
                    continue;
                }
                if nums[i] + nums[j] + nums[j+1] + nums[j+2] > target {
                    break;
                }
                if nums[i] + nums[j] + nums[length-2] + nums[length-1] < target {
                    continue;
                }
                let mut left = j+1;
                let mut right = length - 1;

                while left < right {
                    let sum: i32 = nums[i] + nums[j] + nums[left] + nums[right];
                    if sum == target {
                        result.push(vec![nums[i], nums[j], nums[left], nums[right]]);
                        while left < right && nums[left] == nums[left+1] {
                            left += 1;
                        }
                        left += 1;
                        while left < right && nums[right] == nums [right-1] {
                            right -= 1;
                        }
                        right -= 1;
                    } else if sum < target {
                        left += 1;
                    } else {
                        right -= 1;
                    }
                }   
            }
        }
        return result;
    }
}

#[cfg(test)]
mod test {
    use crate::*;

    #[test]
    fn basic() {
        assert_eq!(
            Solution::four_sum(vec![1, 0, -1, 0, -2, 2], 0),
            vec![
                vec![-2, -1, 1, 2],
                vec![-2,  0, 0, 2],
                vec![-1,  0, 0, 1],
            ]
        )
    }

    #[test]
    fn duplicated() {
        assert_eq!(
            Solution::four_sum(vec![-1,-5,-5,-3,2,5,0,4], -7),
            vec![
                vec![-5,-5,-1,4],
                vec![-5,-3,-1,2], 
            ]
        )
    }
}