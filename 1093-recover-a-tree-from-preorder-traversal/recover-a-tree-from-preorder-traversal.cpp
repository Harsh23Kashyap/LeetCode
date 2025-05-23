/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
void pass(string tr, int i, int dd,vector<TreeNode*> parents){
    if(i==tr.size())
    return ;
    int cd=0;
    while(tr[i]=='-'){
        cd++;
        i++;
    }
    string s="";
    while(tr[i]>='0' and tr[i]<='9'){
            s+=tr[i];
            i++;
        }
    // cout<<i<<endl;
    TreeNode* t=new TreeNode(stoi(s));
    cout<<cd<<" "<<dd<<endl;
    if(cd>dd)
    {
        TreeNode* abc=parents[parents.size()-1];
        cout<<"Assigning "<<t->val<<" to left of "<<abc->val<<endl;
        
        abc->left=t;
        parents.push_back(t);
        pass(tr,i,cd,parents);
    }
    else if(cd==dd)
    {
        parents.pop_back();
        TreeNode* abc=parents[parents.size()-1];
        abc->right=t;
        cout<<"Assigning "<<t->val<<" to right of "<<abc->val<<endl;
        parents.push_back(t);
         pass(tr,i,cd,parents);
    }
     else 
    {
        parents.pop_back();
        int diff=dd-cd;
        while(diff--)
            parents.pop_back();
        TreeNode* abc=parents[parents.size()-1];
        abc->right=t;
        cout<<"Assigning "<<t->val<<" to right of "<<abc->val<<endl;
        parents.push_back(t);
         pass(tr,i,cd,parents);
    }

}
    TreeNode* recoverFromPreorder(string t) {
        int i=0;
        string s="";
        while(t[i]>='0' and t[i]<='9'){
            s+=t[i];
            i++;
        }
       
         cout<<s<<" "<<i<<endl;
        vector<TreeNode*> parents = {NULL,NULL};
        TreeNode* tt=new TreeNode(stoi(s));
        parents.push_back(tt);
         pass(t,i,0,parents);
         return tt;
        
      
        
    }
};