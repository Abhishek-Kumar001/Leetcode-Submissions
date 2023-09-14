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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ansList = new ListNode(10);
        ListNode* ansHead = ansList;
        ListNode* curr1 = list1;
        ListNode* curr2 = list2;
        
        while(curr1 != NULL  && curr2 != NULL){
            if(curr1->val <= curr2->val){
                ansList->next = curr1;
                ansList = ansList->next;
                curr1 = curr1->next;
            }else{
                ansList->next = curr2;
                ansList = ansList->next;
                curr2 = curr2->next;
            }
        }
        ansList->next = curr1 == NULL ? curr2 : curr1;
        
        return ansHead->next;
    }
};
