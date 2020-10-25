/**
 * Definition for a binary tree node.
 * class TreeNode(_value: Int = 0, _left: TreeNode = null, _right: TreeNode = null) {
 *   var value: Int = _value
 *   var left: TreeNode = _left
 *   var right: TreeNode = _right
 * }
 */
object Solution {
    def inorderTraversal(root: TreeNode): List[Int] = {
        def inorderTraversal(root: TreeNode, returnList: List[Int]): List[Int] = {
            if (root == null) returnList
            else inorderTraversal(root.right, inorderTraversal(root.left, returnList) :+ root.value)
        }

        inorderTraversal(root, List.empty)
    }
}