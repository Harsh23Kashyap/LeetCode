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
    ListNode* reverseList(ListNode* head, ListNode* end) 
    {
        if(head==NULL or head->next==NULL)
            return head;
        
        ListNode *temp=head->next;
        ListNode *prev=head;
        ListNode *curr=head->next;
        prev->next=NULL;
        
        while(curr->next!=end->next)
        {
            temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        curr->next=prev;
        return curr;
    }
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        if(k==1)
            return head;
      vector<pair<ListNode*,ListNode*>> ans;
        ListNode* copy=head;
        while(copy)
        {
            ListNode *start=copy;
            for(int i=0;i<k-1;i++)
            {
                if(copy==NULL)
                    break;
                copy=copy->next;
            }
            if(copy!=NULL)
            {
                
                ans.push_back({start,copy});
                copy=copy->next;
            }
            else
                ans.push_back({start,NULL});
            
            
        }
        if(ans[0].second==NULL)
            return head;
        ListNode* prevS=ans[0].first;
        ListNode* prevE=ans[0].second;
        ListNode *rev=reverseList(prevS,prevE);
        ListNode *newhead=prevE;
        prevS=newhead;
        prevE=ans[0].first;
        //cout<<prevE->val;
        for(int i=1;i<ans.size();i++)
        {
            ListNode *start=ans[i].first;
            ListNode *end=ans[i].second;
            if(end!=NULL)
            {
                ListNode *rev=reverseList(start,end);
                prevE->next=rev;
                prevS=rev;
                prevE=start;
                
            }
            else
            {
                prevE->next=start;
            }
        }
        
        // for(int i=0;i<ans.size();i++)
        // {
        //     cout<<ans[i].first->val<<"  - "<<ans[i].second->val<<endl;
        // }
        return newhead;
        
    }
};