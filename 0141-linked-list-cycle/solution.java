/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public boolean hasCycle(ListNode head) {
     
        int i=0;
        ListNode[]  arr=new ListNode[10000];
        
        //creating a temp node
        ListNode temp1=head;
        if(head==null)
            return false;
       
        while(temp1.next !=null ){  // &&  i<10000){
            arr[i]=temp1;
            for(int j=0;j<i;j++){
                if(arr[j]==temp1.next)
                    return true;
            }
            i++;
            temp1=temp1.next;
        }
        return false;
    }
}
