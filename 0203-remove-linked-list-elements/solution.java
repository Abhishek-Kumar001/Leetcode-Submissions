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
                // m-1
class Solution {
    public ListNode removeElements(ListNode head, int target) {
        ListNode temp = head;
        if(temp == null) return null;

        ListNode prevNode = new ListNode(-1);
        ListNode prevNodeHead = prevNode;
        
        
        while(temp != null){
            if(temp.val == target);
            else{
                prevNode.next = temp;   
                prevNode = temp;            
            }
            temp = temp.next;
        }
        prevNode.next = null;
        return prevNodeHead.next;
    }
}
               // m-2

// class Solution {
//     public ListNode removeElements(ListNode head, int target) {
//         ListNode temp = head;
//         if(temp == null) return null;
//         if(temp.val == target){
//             while(temp!= null && temp.val ==  target){
//                temp=temp.next;
//                head = temp;
//             }
//         }
        
//         while(temp != null && temp.next != null){
//             if(temp.next.val == target) temp.next = temp.next.next;
//             else temp = temp.next;
//         }
//         return head;
//     }
// }
