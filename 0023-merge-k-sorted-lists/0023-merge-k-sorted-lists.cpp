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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* hd= new ListNode(0);
        ListNode* ans= hd;
        auto cmp = [](ListNode* a, ListNode* b) { return a->val > b->val; };
        
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);
        for(ListNode* l: lists){
            if(l != nullptr) pq.push(l);
        }

        while(!pq.empty()){
            ListNode* temp= pq.top();
            pq.pop();
            if(temp->next!= nullptr){
                pq.push(temp->next);
            }
            ans->next= new ListNode(temp->val);
            ans= ans->next;
        }

        return hd->next;

    }
};