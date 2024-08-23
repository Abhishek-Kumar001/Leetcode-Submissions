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
//         while(cnt <= right ){   //  && curr != null  // unnecessary tha
//             nextNode = curr.next;
//             curr.next = prev;
//             prev = curr;
//             curr = nextNode;
//             cnt++;
//         }

//         // if( nextNode != null)               // unnecessary
//            head.next = nextNode;

//         return prev;
//     }
// }





class Solution {
    public ListNode reverseBetween(ListNode head, int left, int right) {
        // base case
        if(head.next == null) return head;

        ListNode temp = head;
        int cnt = 1;
        ListNode prevHead = head;
        while(temp != null && cnt < left){
           cnt++;
           prevHead = temp;
           temp = temp.next;
        }

        ListNode newHead = reverse(temp, right-left+1);
        if(left == 1) return newHead;
        
        prevHead.next = newHead;
        return head;
    }
    public ListNode  reverse(ListNode root, int right){
        if(right == 1) return root;

        ListNode temp = root;
        ListNode prev = null;
        int cnt = 0;
        while(temp != null && cnt<right){
            cnt++;
            ListNode nextNode = temp.next;
            temp.next = prev;
            prev = temp;
            temp = nextNode;
        }

        root.next = temp;
        return prev;
    }
}
