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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
        ListNode* start1=list1;
        ListNode* start2=list2;
        if(start1==nullptr and start2==nullptr)
            return nullptr;
        else if(start1==nullptr)
            return start2;
        else if(start2==nullptr)
            return start1;
        else
        {
            ListNode* ans;
            ListNode* head;
            if(start1->val < start2->val)
            {
                ans=new ListNode(start1->val);
                    head=ans;
                start1=start1->next;
            }
            else
            {
                ans=new ListNode(start2->val);
                head=ans;
                start2=start2->next;
            }
            while(start1!=NULL and start2!=NULL)
            {
                if(start1->val < start2->val)
                {
                    //cout<<start1->val<<" of 1, ";
                    ListNode* temp= new ListNode(start1->val);
                    ans->next=temp;
                    ans=temp;
                    start1=start1->next;;
                    
                }
                else
                {
                    //cout<<start2->val<<" of 2, ";
                    ListNode* temp= new ListNode(start2->val);
                    ans->next=temp;
                    ans=temp;
                    start2=start2->next;
                    
                }
            }
            while(start1!=NULL)
            {
                ListNode* temp= new ListNode(start1->val);
                ans->next=temp;
                    ans=temp;
                start1=start1->next;
            }
            while(start2!=NULL)
            {
                ListNode* temp= new ListNode(start2->val);
                    ans->next=temp;
                    ans=temp;
                    start2=start2->next;
            }
            
        return head;
        }
        return nullptr;
    }
};