/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        //Note:- a/c we have to just to return the node where cycle begin
        // not we have to remove the cycle as Yogesh Question
        ListNode* slow = head;
        ListNode* fast = head;
        while( slow && fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) break;
            
        }
        if(!slow || !fast || !fast->next){
            // it means ll doesn't has cycle
            return NULL;
        }
        // else it has definitely cycle

        if(slow == head){
            //both point to same node that is head node and which shows
            // there is cycle to head node
            return head;
        }
        else {  // there is cycle but not at head 
            slow = head;
            while(slow->next != fast->next){
                slow = slow->next;
                fast = fast->next;
            }
            return fast->next;
        }
        return NULL; // this is never gon to execute
    }
    
};
