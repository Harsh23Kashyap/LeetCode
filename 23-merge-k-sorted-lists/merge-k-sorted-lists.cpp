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
struct cmp{
    static bool operator()(ListNode* a, ListNode* b){
        return a->val>b->val;
    }
};
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*> , cmp> pq;

        for(auto it:lists){
            if(it!=NULL)
                pq.push(it);
        }

        ListNode* neg=new ListNode(-11);
        ListNode* head=neg;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();

            if(it->next!=NULL)
                pq.push(it->next);

            head->next=it;
            head=head->next;

        }
        return neg->next;
    }
};