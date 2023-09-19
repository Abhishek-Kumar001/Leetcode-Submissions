/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        

        // first count the no of nodes
        ListNode* temp = head;
        int cnt =0;
        while( temp ){
            cnt++;
            temp = temp->next;
        }

        // now nth node from last means (cnt-n+1)th node from beginning 
        int nFromBeginning = cnt-n+1;
        if(nFromBeginning == 1){  // means we have to delete head node 
           return head->next;
        }
        // else we have to delete nFromBeginning node it means we have to go
        // to nFromBeginning-1 node and delete nFromBeginning node

        temp = head;
        cnt =1; 
        while( cnt < nFromBeginning-1){
            cnt++;
            temp = temp->next;
        }
        // now delete the node
        temp->next = temp->next->next;
        return head;
    }
};
