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
    public ListNode reverseList(ListNode head) {
        
        //if no node is there 
        if(head== null)
            return head;
        
        //if only one node is there
        if(head.next == null)
            return head;
        
        // if only 2 node are there  THEN SWAP
        if(head.next.next == null){
             int temp=head.val;
             head.val=head.next.val;
             head.next.val=temp;
             return  head;
        }
        
      //if more than 2 nodes are there 
        
        
        ListNode pre=head;
        ListNode curr=head.next;
        
        while(curr.next != null){
            ListNode Next=curr.next;
            
            curr.next=pre;
            pre=curr;
            
            curr=Next;
        }
        curr.next=pre;
        head.next=null;
        
        return curr;
    }
}
