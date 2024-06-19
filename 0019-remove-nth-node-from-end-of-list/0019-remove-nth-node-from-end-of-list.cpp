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
        if(head == NULL){
            return NULL;
        }
        ListNode* temp= head;
        ListNode* temp2= head;
        int siz=0;
        while(temp!= nullptr ){
            
            siz++;
            temp= temp->next;
        }
        if(siz == n){
            ListNode* newHead= head->next;
            delete(head);
            return newHead;
        }
        int nodRem= siz-n-1;
        while(nodRem>0){
            nodRem--;
            temp2= temp2->next;
        }
        ListNode* delNode= temp2->next;
        temp2->next= temp2->next->next;
        delete(delNode);
        return head;
    }

};