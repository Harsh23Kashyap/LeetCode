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
        priority_queue<ListNode*,vector<ListNode*>,cmp> pq;
        for(auto it:lists)
        {
            if(it)
                pq.push(it);
        }
        ListNode* prev=new ListNode(0);
        ListNode* start=prev;
        while(!pq.empty())
        {
            ListNode* remove=pq.top();
            pq.pop();
            if(remove->next!=NULL)
                pq.push(remove->next);
            prev->next=remove;
            prev=remove;
            
        }
        return start->next;
        
    }
};