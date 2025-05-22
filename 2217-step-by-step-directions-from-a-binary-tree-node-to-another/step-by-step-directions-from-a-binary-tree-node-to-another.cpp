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
    bool traversal(TreeNode* r, int f, string& s){
        if(r==NULL)
            return false;
        if(r->val==f)
            return true;
        s+="L";
       bool find=traversal(r->left,f,s);
       if(find)
        return find;
        s.pop_back();
        s+="R";
        find=traversal(r->right,f,s);
         if(find)
        return find;
        s.pop_back();
        return false;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string start="";
        traversal(root,startValue,start);
        cout<<(start)<<endl;;
         string dest="";
        traversal(root,destValue,dest);
        cout<<(dest)<<endl;

        int i=0,l=0;
        while(i<start.size() and l<dest.size() and start[i]==dest[l]){
            i++,l++;

        }
        cout<<start.size()<<endl;
        string first="";
        while(i<start.size()){
            first+="U";
            i++;
        }
        first+=dest.substr(l);
        return first;
    }
};