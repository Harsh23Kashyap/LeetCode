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
    stack<ListNode*> build(ListNode* l)
    {
        stack<ListNode*> s;
        while(l!=NULL)
        {
            s.push(l);
            l=l->next;
        }
        return s;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<ListNode*> s1=build(l1);
        stack<ListNode*> s2=build(l2);
        
        int c=0,sum=0;
        // ListNode* head=new ListNode(-1);
        ListNode* temp=NULL;
        while(!s1.empty() or !s2.empty() or c>0)
        {
            
            sum=c;
            if(!s1.empty())
            {
                auto it=s1.top();
                s1.pop();
                sum+=it->val;
            }
            if(!s2.empty())
            {
                auto it=s2.top();
                s2.pop();
                sum+=it->val;
            }
            // cout<<sum<<endl;
            ListNode* newh= new ListNode(sum%10);
            if(temp!=NULL)
                newh->next=temp;
            temp=newh;
            
            c=sum/10;
        }
        return temp;
        
    }
};