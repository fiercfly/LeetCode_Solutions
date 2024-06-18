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
    ListNode* revrseList(ListNode* head){
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* newHead= revrseList(head->next);
        // ListNode* front= head->next;
        // front->next= head;
        // head->next= NULL;
        head->next->next= head;
        head->next= NULL;

        return newHead;

    }
    bool isPalindrome(ListNode* head) {
        if(head== NULL || head->next == NULL){
            return true;
        }
        ListNode* slow= head;
        ListNode* fast= head;
        while(fast != nullptr && fast->next!= nullptr){
            slow= slow->next;
            fast= fast->next->next;
        }
        ListNode* secHead= revrseList(slow);
        ListNode* first= head;
        ListNode* second= secHead;
        while(second != NULL && first != NULL){
            if(first->val != second->val){
                revrseList(secHead);
                return false;
            }
            second = second->next;
            first = first->next;
        }
        revrseList(secHead);
        return true;

    }
};