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
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        if(lists.size()==0)
        {
            return nullptr;
        }
        vector<int> v;
        //cout<<"runs";
        for(int i=0;i<lists.size();i++)
        {
            ListNode* temp=lists[i];
            if(temp==nullptr)
                continue;
            while(temp!=NULL)
            {
                v.push_back(temp->val);
                temp=temp->next;
            }
        }
        //cout<<"\nruns 2";
        sort(v.begin(),v.end());
        // for(int i=0;i<v.size();i++)
        // {
        //     cout<<v[i]<<", ";
        // }
        //cout<<v.size();
        ListNode* newList;
        if(v.size()!=0)
            newList= new ListNode(v[0]);
        else 
            return nullptr;
        ListNode* start=newList;
        for(int i=1;i<v.size();i++)
        {
            ListNode* temp=new ListNode(v[i]);
            newList->next=temp;
            newList=temp;
        }
        return start;
    }
};