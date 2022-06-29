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
    public ListNode rotateRight(ListNode head, int k) {
                //JUST A LITTLE IMPROVEMET IN 1ST SUBMISSION
                   //1. In stead of storing the last node we cycle the last node to head
                   //2. we remove if(k== 0) checking condition
        
        //if head is null
        if(head==null)
            return head;
        
        //count no of nodes
        ListNode temp=head;
        int count=0;
        while(temp.next != null){
            count++;
            temp=temp.next;
        }
        count++;
        //linking last node to 1st node (i.e making cycle)
        temp.next=head;
        
        // no of rotation required= k % count
        k=k%count;
        
        //now go to (last-k -1) node and break the link
        temp=head;
        for(int i=1; i<count-k ; i++){
           temp=temp.next;
        }
        //here we are at the node whose link we need to break  but before breaking link 1st 
        //store next node in some variable b/c this next node is going to be our new Head
       
        // 1st store the new_head 
        ListNode new_head=temp.next;
        // 2nd break the link
        temp.next=null;
        
        //now return the  new head
        return new_head;
    }
    
}
