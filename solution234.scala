/**
 * Definition for singly-linked list.
 * class ListNode(var _x: Int = 0) {
 *   var next: ListNode = null
 *   var x: Int = _x
 * }
 */
import scala.collection.mutable.ArrayBuffer

object Solution {
    def isPalindrome(head: ListNode): Boolean = {
        var vals = new ArrayBuffer[Int]

        def f(head: ListNode): Unit = {
            head match {
                case null =>
                case _ => vals.append(head.x); f(head.next)
            }
        }

        f(head)
        val a1 = vals.toArray
        val a2 = a1.reverse
        a1.sameElements(a2)
    }
}