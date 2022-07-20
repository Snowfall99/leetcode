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
  pub fn partition(head: Option<Box<ListNode>>, x: i32) -> Option<Box<ListNode>> {
      let mut head = head;
      let mut list1 = Box::new(ListNode{ val: 0, next: None });
      let mut list1_mut = list1.as_mut();
      let mut list2 = Box::new(ListNode{ val: 0, next: None });
      let mut list2_mut = list2.as_mut();

      while let Some(mut node) = head {
          head = node.next.take();
          if node.val >= x {
              list2_mut.next = Some(node);
              list2_mut = list2_mut.next.as_mut().unwrap();
          } else {
              list1_mut.next = Some(node);
              list1_mut = list1_mut.next.as_mut().unwrap();
          }
      }
      list1_mut.next = list2.next;
      list1.next

  }
}
