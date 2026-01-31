class RandomizedSet {
public:

// class Node{
//     Node* next;
//     Node* prev;
//     int val;
//     Node(int v){
//         val=v;
//         next=NULL;
//         prev=NULL;
//     }
// };

// Node* head=new Node(-1);
unordered_map<int,int> u;
vector<int> v;
    RandomizedSet() {
    }
    
    bool insert(int val) {
        if(u.find(val)!=u.end())
            return false;
            v.push_back(val);
        u[val]=v.size()-1;
        // Node* curr=new Node(val);
        // u[val]=(curr);
        // Node* nc=head->next;
        // if(nc!=NULL){
        //     nc->prev=curr;
        //     curr->next=nc;
        //     head->next=curr;
        //     curr->prev=head;
        // }
        // else{
        //     head->next=curr;
        //     curr->prev=head;

        // }
        // cout<<sz<<endl;
        return true;
    }
    
    bool remove(int val) {
        if(u.find(val)==u.end())
        return false;

        // Node* find=u[val];
        // if(find->next!=NULL)
        // find->next->prev=find->prev;

        // find->prev->next=find->next;
        
        int idx=u[val];
        int lastElement=v.size()-1;
        u[v[lastElement]]=idx;
        swap(v[idx],v[lastElement]);
        v.pop_back();
        u.erase(val);
        return true;


    }
    
    int getRandom() {

        return v[rand()%v.size()];

        
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */