use std::collections::BinaryHeap;
use std::cmp::Reverse;

impl Solution {
    pub fn smallest_k(arr: Vec<i32>, k: i32) -> Vec<i32> {
        let mut result = Vec::with_capacity(k as usize);
        let n = arr.len();
        let mut heap = BinaryHeap::with_capacity(n);
        for num in arr {
            heap.push(Reverse(num));
        }
        for _ in 0..k {
            let num = heap.pop().unwrap().0;
            result.push(num);
        }
        return result;
    }
}