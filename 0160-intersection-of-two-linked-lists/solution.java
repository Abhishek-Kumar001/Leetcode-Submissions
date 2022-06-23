/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        
        ListNode l1=headA;
        ListNode l2=headB;
        
        HashSet<ListNode> s1=new HashSet();
        while(l1 != null){
            s1.add(l1);
            l1=l1.next;
        }
        
        while(l2 != null){
            if(s1.contains(l2)){
                return l2;
            }
            l2=l2.next;
        }
        return null;
    }
}
