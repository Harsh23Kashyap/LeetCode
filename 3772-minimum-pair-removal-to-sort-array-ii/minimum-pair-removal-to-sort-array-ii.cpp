class Solution {
public:
    class Node{
        public:
        long long data;
        Node* prev;
        Node* next;
        Node(int d){
            data=d;
            prev=NULL;
            next=NULL;
        }
    };

    Node* build(vector<int>& a)
    {
        
        Node* head=NULL;
        Node* prev=NULL;

        for(int i:a){
            Node* curr=new Node(i);
            curr->prev=prev;
            if(prev!=NULL)
                prev->next=curr;
            if(prev==NULL)
                head=curr;
            prev=curr;
        }
        return head;
    }
    int minimumPairRemoval(vector<int>& nums) {

typedef pair<long long, pair<Node*,Node*>> pp;
        int count=0;

        priority_queue<pp,vector<pp>, greater<pp>> pq;


        Node* head=build(nums);
        Node* copy=head;
        while(copy!=NULL)
        {
            // cout<<copy->data<<" ";
            if(copy->next!=NULL)
            pq.push({copy->data+copy->next->data,{copy,copy->next}});
            copy=copy->next;
        }
        int breakup=0;
        for(int i=0;i<nums.size();i++){
            if(i>0 and nums[i-1]>nums[i])
            breakup++;
        }

        unordered_set<Node*> dead;
        while(breakup>0){
            auto it=pq.top();
            pq.pop();
            // cout<<"Lowest-> "<<it.first<<endl;
            auto [l,r]=it.second;


            //dead kill
            if(dead.find(l)!=dead.end() or dead.find(r)!=dead.end())
                continue;
            if(l->data+r->data!=it.first)
                continue;

            //subtracting count
            if(l->data>r->data)
                breakup--;
            if(l->prev!=NULL and l->prev->data>l->data)
                breakup--;
            if(r->next!=NULL and r->data>r->next->data)
                breakup--;
                
            //Adding in l
            l->data+=r->data;
            l->next=r->next;
            
            if(r->next!=NULL){
                r->next->prev=l;
            }

            dead.insert(r);

            //adding count
            if(l->prev!=NULL and l->prev->data>l->data)
                breakup++;
            if(l->next!=NULL and l->data>l->next->data)
                breakup++;

            if(l->prev!=NULL)
            pq.push({1ll*l->data+l->prev->data,{l->prev,l}});

            if(l->next!=NULL)
            pq.push({1ll*l->data+l->next->data,{l,l->next}});
            count++;


        }

        return count;

        
        // return 0;
    }
};