/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    c
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        //base case
        if( head == NULL) return NULL;

        Node* curr = head;
        // linking dummy nodes just ahead of every original nodes
        while( curr != NULL){
            Node* nextNode = curr->next;
            curr->next = new Node(curr->val);
            curr->next->next = nextNode;
            curr = nextNode;
        }

        //linking random pointer
        curr = head;
        while( curr != NULL){
            if(curr->random != NULL){
                curr->next->random = curr->random->next;
            } // else curr->next->random v point kar hi rha hai already 
            
            curr = curr->next->next;
        }

        // seperating original list and dummy ll
        curr = head;
        Node* dummyHead =  curr->next;
        Node* dummyCurr = curr->next;

        while( curr != NULL){
            curr->next = curr->next->next;
            curr = curr->next;
            if(dummyCurr->next != NULL){  //this check is imp for last node
                dummyCurr->next = dummyCurr->next->next;
            }
            dummyCurr =  dummyCurr->next;
        }
        return dummyHead;
    }
};
