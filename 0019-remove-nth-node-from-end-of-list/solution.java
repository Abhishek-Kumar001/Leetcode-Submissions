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
    public ListNode removeNthFromEnd(ListNode head, int n) {
        //coutn no. of nodes
        ListNode temp=head;
        int count=0;
        while(temp != null){
            count++;
            temp=temp.next;
        }
        
        //if we have to delete 1st node i.e  count==n 
        if( count == n){
            head=head.next;
            return head;
        }
       // else 1st  reach at the 1 node before of target node 
       temp=head;
        int diff=count-n;
        for(int i=1; i<diff; i++){
            temp=temp.next;
        }
        //here we are at 1 node before of target(delete node) so 
        temp.next=temp.next.next;
        
        return head;
    }
}
