class Node
{
    public:
   Node *left;
    Node *right;
};

class Trie
{
    Node *root;
    public:
    Trie()
    {
        root=new Node();
    }
    
    void insert(int num)
    {
        Node *temp=root;
        for(int i=31;i>=0;i--)
        {
            int bit=(num>>i)&1;
            if(bit==0)
            {
                if(temp->left==NULL)
                    temp->left=new Node();
                
                temp=temp->left;
            }
            else
            {
                if(temp->right==NULL)
                    temp->right=new Node();
                
                temp=temp->right;
            }
        }
    }
    int xor_helper(int value)
    {
        int currans=0;
        Node *temp=root;
        for(int i=31;i>=0;i--)
        {
             int bit=(value>>i)&1;
            if(bit==0)
            {
                if(temp->right)
                {
                    temp=temp->right;
                    currans+=(1<<i);
                   
                }
                
                else
                    temp=temp->left;
            }
            else 
            {
                if(temp->left)
                {
                    temp=temp->left;
                    currans+=(1<<i);
                }
                else
                    temp=temp->right;
            }
        }
        return currans;
    }
};
class Solution {
   
public:
    
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) 
    {
        
        Trie t;
        for(int i=0;i<queries.size();i++)
        {
            queries[i].push_back(i);
        }
        sort(queries.begin(),queries.end(),[&](vector<int>&a,vector<int>&b)
        {
            return a[1]<b[1];
        });
        sort(nums.begin(),nums.end());
        int j=0;
        vector<int>ans(queries.size());
        for(int i=0;i<queries.size();i++){
            int x=queries[i][0];
            int a=queries[i][1];
            int indx=queries[i][2];
            while(j<nums.size() && nums[j]<=a) t.insert(nums[j++]);
            if(j==0)ans[indx]=-1;
           else ans[indx]=t.xor_helper(x);
        }
        return ans;
        
    }
};