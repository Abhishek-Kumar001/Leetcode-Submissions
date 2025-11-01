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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        map<int, int> mpp;
        for(int x : nums) mpp[x]++;

        ListNode* temp = new ListNode(-1);
        temp->next = head;
 
        ListNode* prev = temp;
        ListNode* tracker = temp;
        ListNode* curr = temp->next;
        while(curr){
            if(mpp[curr->val]) prev->next = curr->next;
            else prev = curr;
            
            curr = curr->next;
        }

        return tracker->next;
    }
};
