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
    public boolean isPalindrome(ListNode head) {
             // i think @TechDose ka hai 
        //fist find the middle node using solw & fast pointer
        ListNode slow= head;
        ListNode fast = head;
        while(slow != null && fast != null && fast.next != null){
            slow = slow.next;
            fast = fast.next.next;

            if(slow == fast) break;
        }
        // here slow point to middle node of ll
        //ab 2nd half ko reverse kar denge

        ListNode backHead = reverseLL(slow);
        

        // 2 pointer app ke through palindrom check kar lenge
        while(backHead != null){
            if(head.val != backHead.val) return false;

            backHead= backHead.next;
            head = head.next;
        }
        return true;

    }
    public ListNode reverseLL(ListNode head){
        ListNode prev = null;
        ListNode curr = head;
        while(curr != null){
            ListNode nextNode = curr.next;
            curr.next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }
}
