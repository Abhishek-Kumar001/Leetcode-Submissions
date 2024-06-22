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
    public ListNode swapPairs(ListNode head) {
            // my code learn from swap in k group question
        if(head == null) return null;

        int cnt= 0;
        ListNode curr= head, prev = null;
        while(curr != null && cnt<2){
            cnt++;
            ListNode nextNode = curr.next;
            curr.next = prev;
            prev = curr;
            curr = nextNode;
        }
        head.next = swapPairs(curr);
        return prev;
    }
}
