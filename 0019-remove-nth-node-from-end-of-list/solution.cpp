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
        // 1st count the no of nodes 
        int cnt = 0;
        ListNode* temp = head;
        while(temp != NULL){
            cnt++;
            temp = temp->next;
        }

        int nFromStart = cnt - n + 1;
        if(nFromStart == 1) return head->next;

        temp = head;
        int tempCnt = 1;
        while( true ){
            if(tempCnt == nFromStart-1) break;
            tempCnt++;
            temp = temp->next;
        }

        temp->next = temp->next->next;
        return head;
    }
};
