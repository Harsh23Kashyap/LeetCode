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
    int findMaximumXOR(vector<int>& nums) 
    {
        Trie *t=new Trie();
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            int val=nums[i];
            t->insert(val);
            int temp=t->xor_helper(val);
            ans=max(ans,temp);
            
        }
        return ans;
        
    }
};