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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummyNode = new ListNode(-1);
        dummyNode->next = head;
        ListNode* prev = dummyNode;
        ListNode* curr = head;

        while(curr != NULL && curr->next != NULL){
            ListNode* fNode = curr;
            ListNode* sNode = curr->next;

            prev->next = sNode;
            curr->next = sNode->next;
            sNode->next = fNode;

            prev = fNode;
            curr = fNode->next;
        }
        return dummyNode->next;
    }
};
