// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
//
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }
use std::rc::Rc;
use std::cell::RefCell;
impl Solution {
    pub fn is_balanced(root: Option<Rc<RefCell<TreeNode>>>) -> bool {
        Solution::height(root) > -1
    }

    pub fn height(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        match root {
            Some(node) => {
                let left = Solution::height(node.borrow().left.clone());
                let right = Solution::height(node.borrow().right.clone());
                if (left - right).abs() > 1 || left == -1 || right == -1 {
                    -1
                } else {
                    1 + left.max(right)
                }
            }
            None => 0
        }
    }
}