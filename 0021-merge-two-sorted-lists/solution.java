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
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
      // HINT: SOLVE BY 2 POINTERS APPROACH
        ListNode l1=list1;
        ListNode l2=list2;
        
        //if l1 or l2 is null or both are null 
        if(l1 == null || l2 == null)
           return l1==null ? l2 : l1;
        
        //creating a newList
        ListNode Head=null;
        ListNode curr=null;
       
        while(l1 != null && l2 != null){
                //if list1 val is smaller  
            if(l1.val<l2.val){
                 //creating a temp node
                 ListNode temp=new ListNode(l1.val);
                //if ll is empty
                if(Head==null){
                    curr=temp;
                    Head=temp;
                }
                else{
                    curr.next=temp;
                    curr=curr.next;
                }
                //increment l1
                l1=l1.next;
            }
                 //  if list2 val is smaller or equal
            else{
                  //creating a temp node
                 ListNode temp=new ListNode(l2.val);
                //if ll is empty
                if(Head==null){
                    curr=temp;     
                    Head=temp;         
                }
                else{
                    curr.next=temp;
                    curr=curr.next;
                } 
                //increment l2
                l2=l2.next;
            }
        } 

        curr.next=l1 == null ? l2 :l1 ;
        return Head;
    }
}
