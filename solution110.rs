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
        if root == None { 
            return true; 
        }
        let rb = root.as_ref().unwrap().borrow_mut();
        let left = Solution::height(rb.left.clone());
        let right = Solution::height(rb.right.clone());
        (left - right).abs() <= 1 && 
            Solution::is_balanced(rb.left.clone()) && 
            Solution::is_balanced(rb.right.clone())
    }

    pub fn height(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        if root == None {
            return 0;
        }
        let rb = root.as_ref().unwrap().borrow_mut();
        match (rb.left.as_ref(), rb.right.as_ref()) {
            (Some(m), None) => { 1 + Solution::height(Some(m.clone())) },
            (None, Some(m)) => { 1 + Solution::height(Some(m.clone())) },
            ((Some(m), Some(n))) => { (1 + Solution::height(Some(m.clone()))).max(1 + Solution::height(Some(n.clone()))) },
            _ => 1,
        }
    }
}
