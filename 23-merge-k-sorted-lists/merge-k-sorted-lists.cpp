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
        bool operator()(ListNode* a, ListNode* b){
            return a->val>b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*> , cmp> pq;
        for(int i=0;i<lists.size();i++){
            ListNode* start=lists[i];
            if(start!=NULL)
             pq.push(start);
        }
        
        ListNode* neg=new ListNode(-1);
        ListNode* head=neg;

        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            if(it!=NULL and it->next!=NULL)
                pq.push(it->next);
            
            neg->next=it;
            neg=neg->next;

        }
        return head->next;
        
    }
};