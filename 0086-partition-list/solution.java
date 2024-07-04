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
 //using external space
class Solution {
    public ListNode partition(ListNode head, int x) {
        ListNode lessThanXHead = new ListNode(-1);  // creating a dummy node
        ListNode temp1 = lessThanXHead;
        ListNode greaterOrEqualXHead = new ListNode(-1);  // creatin a dummy node
        ListNode temp2 = greaterOrEqualXHead;


        ListNode curr= head;

        while(curr != null){
            if(curr.val < x){
                temp1.next = curr;
                temp1 = temp1.next;
            }else{
                temp2.next = curr;
                temp2 = temp2.next;
            }
            curr = curr.next;
        }

        // pointing the next node of temp2 to null b/c this is our new tail node
        temp2.next = null;
        // linking the last node of smaller ll to head of greater ll
        temp1.next = greaterOrEqualXHead.next; //next b/c 1st node was a dummy node

        return lessThanXHead.next;


        
    }
}


