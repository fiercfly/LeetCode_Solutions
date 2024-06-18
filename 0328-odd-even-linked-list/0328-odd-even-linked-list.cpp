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
        if(head== NULL || head->next == NULL){
            return head;
        }
        ListNode* otemp= head;
        ListNode* etemp= head->next;
        ListNode* mrg= etemp;
        while((otemp!= nullptr && otemp->next!= nullptr) && (etemp!= nullptr && etemp->next!= nullptr)){
            ListNode* onext= otemp->next->next;
            ListNode* enext= etemp->next->next;
            otemp->next= onext;
            otemp= otemp->next;
            etemp->next= enext;
            etemp= etemp->next;
        }
        otemp->next= mrg;
        return head;
    }
};