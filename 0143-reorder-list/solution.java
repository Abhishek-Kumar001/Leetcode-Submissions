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
    public ListNode reverse( ListNode head){
        ListNode prev = null;
        ListNode nextNode = null;
        while( head != null){
            nextNode = head.next;
            head.next = prev;
            prev = head;
            head = nextNode;
        }
        return prev;
    }
    public void reorderList(ListNode head) {
        //      #####@@@@ same prev submited code with more added comments

        // soluiton:- the app is hm 2nd half ko reverse kardenge and 2 pointer chala ke nodes ke link ko change
        //            kar denge

        // first count the no of nodes
        ListNode temp = head;
        int size =0;
        while(temp != null){
            size++;
            temp = temp.next;
        }

        // find the mid and reverse the second half
        ListNode fast = head;
        ListNode slow = head;
        while( fast != null  && fast.next != null){
            slow = slow.next;
            fast = fast.next.next;
        }
        // here solw containt the mid node
        ListNode end = reverse( slow );
        ListNode start = head;

        // apply 2 pointer and link nodes a/c to question
        ListNode ansNode =  new ListNode(-1);// creating a dummy node
        ListNode ansHead = ansNode;

        int cnt =0;
        while( cnt < size/2){ // go till size/2 and link nodes a/c to question
            //  hme line no-57 i.e start = stert.next line no 59 ke pahle likhna hi hoga
            // qunki line no 59 i.e( ansNode.next.next) start ke next pointer ke chage kar rha
            ansNode.next = start;
            start = start.next;

            ansNode.next.next= end;
            end = end.next;

            ansNode = ansNode.next.next;
  
            cnt++;
        }
        // if we have even no of nodes given in qs then explicitely link the middle node
        if( size % 2 == 1){
            ansNode.next = start;
            ansNode = ansNode.next;
        }
        // now poin the last node to null other wise we fill fall in cycle

        //if( ansNode != null)  // check karne ki koi jarurat nahi hai
          ansNode.next = null;

        // now updat the head b/c hame given ll ko ki modify kar ke return karna tha
        head = ansHead.next;  // ansHead.next b/c ansHead dummy node (i.e -1 ) hold kiye hue hai 
    }
}
