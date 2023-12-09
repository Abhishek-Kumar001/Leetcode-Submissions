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
    ListNode* reverseList(ListNode* head){
        if(head == NULL || head->next == NULL)
           return head;

        ListNode* curr=head;
        ListNode* prev=NULL;

        while(curr != NULL){
            ListNode* forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        return prev;
    }
    void insertAtTail(ListNode** head, ListNode** tail, int d){
        ListNode* newNode= new ListNode(d);
        if(*head == NULL){
            *head=newNode;
            *tail=newNode;
            return;
        }
        else{
            (*tail)->next=newNode;
            *tail=newNode;
        }
    }
    ListNode* add(ListNode* first, ListNode* second){
        ListNode* ansHead=NULL;
        ListNode* ansTail=NULL;
        int carry=0;
        while(first != NULL && second != NULL){
            int sum = carry + first -> val + second -> val;
            int digit = sum%10;
            insertAtTail(&ansHead, &ansTail,digit);
            carry = sum/10;
            first=first->next;
            second=second->next;
        }
        while(first != NULL){
            int sum=carry + first->val;
            int digit = sum % 10;
            insertAtTail(&ansHead, &ansTail,digit); 
            carry= sum/10;
            first=first->next;
        }
        while(second != NULL){
            int sum=carry + second->val;
            int digit = sum % 10;
            insertAtTail(&ansHead, &ansTail,digit); 
            carry= sum/10;
            second=second->next;
        }
        while(carry != 0){
            int sum=carry ;
            int digit = sum % 10;
            insertAtTail(&ansHead, &ansTail,digit); 
            carry= sum/10;
        }
        return ansHead;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //ListNode* first=reverseList(l1);
        //ListNode* second=reverseList(l2);

        //ListNode* sum = add(first,second);
        

        //ListNode* ans = reverseList(sum);

        //return ans;

        ListNode * ans = add( l1, l2);
        return ans;
    }
};

