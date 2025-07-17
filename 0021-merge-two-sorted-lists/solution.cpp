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
        // create a ans link list with a dummy node
        ListNode* ansHead = new ListNode(-1);
        ListNode* ansTemp = ansHead;

        while(list1 != NULL  && list2 != NULL){
            if(list1->val < list2->val){
                ansTemp->next = list1;
                list1 = list1->next;
            }else{
                ansTemp->next = list2;
                list2 = list2->next;
            }
            ansTemp = ansTemp->next;
        }
        while(list1 != NULL){
            ansTemp->next = list1;
            ansTemp = ansTemp->next;
            list1 = list1->next;
        }
        while(list2 != NULL){
            ansTemp->next = list2;
            ansTemp = ansTemp->next;
            list2 = list2->next;
        }

        return ansHead->next;
    }
};
