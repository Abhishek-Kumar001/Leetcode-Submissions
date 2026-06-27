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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // if we have only one node 
        ListNode* prevNode = NULL;
        ListNode* curr = head;
        int cnt = 1;
        while(curr != NULL && cnt != left){
            cnt++;
            prevNode = curr;
            curr = curr->next;
        }

        ListNode* leftNode = curr;  // we are storing the lefNode
        ListNode* prev = NULL;
        ListNode* nextNode = NULL;
        cnt = left;
        while(curr != NULL and cnt != right){
            cnt++;
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        if(curr != NULL){
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        // now we have reverse the asked part now we have to like it with original
        // node

        if( prevNode != NULL ) prevNode->next = prev;
        if(leftNode != NULL) leftNode->next = nextNode ? nextNode : NULL;

        if(1 == left) return prev;

        return head;   
    }
};
