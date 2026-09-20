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
    public ListNode removeElements(ListNode head, int val) {
        ListNode dummy = new ListNode(-1, head);
		ListNode current = head;
		ListNode lastValid = dummy;
		
        while( current != null) {
            if (current.val == val){
                lastValid.next = current.next;
                current = lastValid.next;
            } else {
                lastValid = current;
                current = current.next;
            }
        }
		
		return dummy.next;
    }
}