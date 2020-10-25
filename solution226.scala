/**
 * Definition for a binary tree node.
 * class TreeNode(var _value: Int) {
 *   var value: Int = _value
 *   var left: TreeNode = null
 *   var right: TreeNode = null
 * }
 */
object Solution {
    def invertTree(root: TreeNode): TreeNode = {
        def invert(root: TreeNode): Unit = {
            if (root != null) {
                val left = root.left
                val right = root.right
                root.left = right
                root.right = left
                invert(root.left)
                invert(root.right)
            }
        }
        invert(root)
        root
    }
}