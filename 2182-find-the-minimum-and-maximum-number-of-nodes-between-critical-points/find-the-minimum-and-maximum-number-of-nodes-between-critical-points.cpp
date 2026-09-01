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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int maxi=INT_MIN;
        int mini=INT_MAX;
        int l=1;
        ListNode* p=head;
        ListNode* c=head->next;
        int sta=-1;
        int i=1;
        bool st=false;
        while(c->next!=NULL){
            if((p->val<c->val and c->val>c->next->val ) or (p->val>c->val and c->val<c->next->val ))
            {
                if(!st){
                    st=true;
                    sta=i;
                }
                else{
                cout<<l<<" "<<c->val<<endl;
                maxi=max(l,i-sta);
                mini=min(l,mini);
                
                }
                l=0;
            }
          i++;
           l++;
            p=c;
            c=c->next;
        }
        maxi=(maxi!=INT_MIN)?maxi:-1;
        mini=(mini!=INT_MAX)?mini:-1;
              return {mini,maxi};
    }
};