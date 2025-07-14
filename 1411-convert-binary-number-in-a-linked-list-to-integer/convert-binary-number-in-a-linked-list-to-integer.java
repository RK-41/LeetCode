/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    // 14.07.25 potd
    public int getDecimalValue(ListNode head) {
        int result = head.val;
        while (head.next != null) {
            result = (result << 1) | head.next.val;
            head = head.next;
        }
        return result;
    }
}