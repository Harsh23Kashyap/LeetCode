class Solution {
public:
class Node {
public:
    vector<Node*> bit;

    Node() {
        bit = vector<Node*>(2, NULL);  // Initialize with two null pointers
    }
};


void insert(int num, Node* root){

    for(int i=31;i>=0;i--){
        int bitp=(num>>i) &1;
        if(root->bit[bitp]==NULL){
            root->bit[bitp] = new Node();
            
        }
        root=root->bit[bitp];
    }
}

int maxxor(int num, Node* root){
    int ans=0;
     for(int i=31;i>=0;i--){
        int bitp=(num>>i) &1;
        int tofind=1-bitp;
        if(root->bit[tofind]!=NULL){
            root = root->bit[tofind] ;
            ans=(1<<i)+ans;
        }
        else{
            root = root->bit[bitp];
        }
        
    }
    return ans;
}
static bool cmp(vector<int> &a, vector<int> & b){
    return a[1]<b[1];

}

    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& q) {
        
 sort(nums.begin(), nums.end());
        Node* root= new Node();
        for(int i=0;i<q.size();i++)
            q[i].push_back(i);
        sort(q.begin(),q.end(),cmp);
        vector<int> ans(q.size(),-1);
         int idx = 0;
        for(int i=0;i<q.size();i++){
           while(idx<nums.size() and nums[idx]<=q[i][1]){
                    insert(nums[idx],root);
                idx++;
            }
            if (idx > 0)

                ans[q[i][2]] = (maxxor(q[i][0],root));
            else
                 ans[q[i][2]] = (-1);
        }
        return ans;
    }
};