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
       ListNode l1=list1;
        ListNode l2=list2;
        //creating a newList
        ListNode Head=null;
        ListNode curr=null;
       
        while(l1 != null && l2 != null){
            
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
        
        while(l1 != null){
             //creating a temp node
                 ListNode temp=new ListNode(l1.val);
           //if ll is empty
                if(Head==null){
                    curr=l1;
                    Head=l1;
                }
                else{
                    curr.next=l1;
                    curr=curr.next;
                }
                
                //increment l1
                l1=l1.next;
        }
        while(l2  != null){
              //creating a temp node
                 ListNode temp=new ListNode(l2.val);
                //if ll is empty
                if(Head==null){
                    curr=l2;
                    Head=l2;
                }
                else{
                    curr.next=l2;
                    curr=curr.next;
                } 
                
                //increment l2
                l2=l2.next;
        }
        return Head;
    }
}
