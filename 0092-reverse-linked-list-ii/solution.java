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


// class Solution {
//     public ListNode reverseBetween(ListNode head, int left, int right) {
//         // base case
//         if(head.next == null) return head;
        
//         int cnt =1;
//         ListNode prev = head;      
//         ListNode curr = head;
//         while(cnt < left){
//             prev = curr;
//             curr= curr.next;
//             cnt++;
//         }

//         // reverse the n(right) nodes from here(this curr node)
//         ListNode reversedHead = reverse(curr,left, right);
//         if(left == 1) return reversedHead;
   
//         prev.next = reversedHead;
//         return head;

//     }
//     public ListNode  reverse(ListNode head,int left, int right){
//         int cnt =left;
//         ListNode curr = head;
//         ListNode prev = null;
//         ListNode nextNode = null;
//         while(cnt <= right && curr != null){
//             nextNode = curr.next;
//             curr.next = prev;
//             prev = curr;
//             curr = nextNode;
//             cnt++;
//         }

//         if( nextNode != null)
//            head.next = nextNode;

//         return prev;
//     }
// }

                   // same code with romoving unnecessary  checks -
class Solution {
    public ListNode reverseBetween(ListNode head, int left, int right) {
        // base case
        if(head.next == null) return head;
        
        int cnt =1;
        ListNode prev = head;      
        ListNode curr = head;
        while(cnt < left){
            prev = curr;
            curr= curr.next;
            cnt++;
        }

        // reverse the n(right) nodes from here(this curr node)
        ListNode reversedHead = reverse(curr,left, right);
        if(left == 1) return reversedHead;
   
        prev.next = reversedHead;
        return head;

    }
    public ListNode  reverse(ListNode head,int left, int right){
        int cnt =left;
        ListNode curr = head;
        ListNode prev = null;
        ListNode nextNode = null;
        while(cnt <= right ){   //  && curr != null  // unnecessary tha
            nextNode = curr.next;
            curr.next = prev;
            prev = curr;
            curr = nextNode;
            cnt++;
        }

        // if( nextNode != null)               // unnecessary
           head.next = nextNode;

        return prev;
    }
}
