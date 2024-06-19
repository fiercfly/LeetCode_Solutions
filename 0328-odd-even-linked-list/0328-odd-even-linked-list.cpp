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
    ListNode* oddEvenList(ListNode* head) {
        if(head==nullptr || head->next== nullptr){
            return head;
        }
        ListNode *prev= head;
        ListNode *temp1;
        ListNode*temp2;
        ListNode *curr= head->next;

        while(curr!= nullptr && curr->next != nullptr){
            temp1= curr->next;
            curr->next= curr->next->next;
            curr= curr->next;
            temp2= prev->next;
            prev->next= temp1;
            prev= prev->next;
            prev->next= temp2;
        }
        return head;
    }
};