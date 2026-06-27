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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL) return NULL;
        int cnt = 0;
        ListNode* temp = head;
        ListNode* prev = head;
        while(temp != NULL){
            cnt++;
            prev = temp;
            temp = temp->next;
        }
        ListNode* lastNode = prev;

        k = k % cnt;
        if(k == 0) return head;

        int kFromStart = cnt - k;

        temp = head;
        int tempCnt = 1;
        while(true){
            if(tempCnt == kFromStart){
                break;
            }
            tempCnt++;
            temp = temp->next;
        }

        ListNode* newHead = temp->next;
        temp->next = NULL;
        lastNode->next = head;

        return newHead;
    }
};
