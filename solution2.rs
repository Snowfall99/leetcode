// Definition for singly-linked list.
// #[derive(PartialEq, Eq, Clone, Debug)]
// pub struct ListNode {
//   pub val: i32,
//   pub next: Option<Box<ListNode>>
// }
//
// impl ListNode {
//   #[inline]
//   fn new(val: i32) -> Self {
//     ListNode {
//       next: None,
//       val
//     }
//   }
// }
impl Solution {
    pub fn add_two_numbers(l1: Option<Box<ListNode>>, l2: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let mut sum = 0;
        let (mut l1, mut l2) = (l1, l2);
        let mut l = None;
        let mut p = &mut l;

        loop {
            match (l1, l2) {
                (Some(n1), Some(n2)) => {
                    sum += n1.val + n2.val;
                    l1 = n1.next;
                    l2 = n2.next;
                },
                (Some(n1), None) => {
                    sum += n1.val;
                    l1 = n1.next;
                    l2 = None;
                },
                (None, Some(n2)) => {
                    sum += n2.val;
                    l2 = n2.next;
                    l1 = None;
                },
                (None, None) => {
                    break;
                },
            }
            *p = Some(Box::new(ListNode::new(sum % 10)));
            sum /= 10;
            if let Some(p_box_node) = p {
                p = &mut p_box_node.next;
            }
        }

        if sum != 0 {
            *p = Some(Box::new(ListNode::new(sum)));
        }

        l
    }
}