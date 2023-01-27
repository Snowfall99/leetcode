use std::collections::HashMap;

impl Solution {
    pub fn intersection(nums1: Vec<i32>, nums2: Vec<i32>) -> Vec<i32> {
        let mut map: HashMap<i32, bool> = HashMap::new();
        let mut result: Vec<i32> = Vec::new();

        for num in nums1 {
            map.insert(num, true);
        }
        for num in nums2 {
            if let Some(flag) = map.remove(&num) {
                result.push(num);
            }
        }
        return result;
    }
}
