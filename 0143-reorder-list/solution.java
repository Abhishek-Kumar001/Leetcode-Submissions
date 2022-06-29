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
    public void reorderList(ListNode head) {
                  //SAME CODE ONLY ADDING MORE COMMENTS FOR UNDERSTINDING     
        //counting no of nodes
        ListNode temp=head;
        int count=0;
        while(temp != null){
            count++;
            temp=temp.next;
        }
        //creating a arrayList of given linked list size
        ArrayList<ListNode> al=new ArrayList(count);
       
        //now storing all link address in the ArrayList
        temp=head;
        while(temp != null){
            al.add(temp);
            temp=temp.next;
        }
        //now swap the only nodes not data a/c to given ordar(IN QUESTION)
        temp=head;
        //mannage 1st 2 nodes  b/c they were not comming fit in our formula of for loop
        temp.next=al.get(count-1);
        temp=temp.next;
        //after managing 1st 2 nodes 
        for(int i=1;i<count/2; i++){ 
           temp.next=al.get(i);
            temp.next.next=al.get(count-1-i);
            temp=temp.next.next;  
        }
        //managing last node  
        //if no of nodes is even the add middle node 1st in the ll then point last node to null
        if(count%2 ==1){
            temp.next=al.get(count/2);
            temp.next.next=null;
        }
        else{       //if no of ll is even only set last node to null
            temp.next=null;
        }
    }
}
