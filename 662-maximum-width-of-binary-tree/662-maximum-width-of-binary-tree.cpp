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
    int widthOfBinaryTree(TreeNode* root) {
       queue<pair<int,TreeNode*>>q;
       int maxWidth = INT_MIN;
        q.push({0,root});
        
        while(!q.empty()){
            int startIndex = q.front().first;
            int sz = q.size();
            int first,last;
            for(int i = 0;i<sz;i++){
                long long int currId = q.front().first-startIndex;
                if(i == 0)
                    first = q.front().first;
                if(i == sz-1)
                    last = q.front().first;
                
                    if(q.front().second->left){
                        q.push({2*(currId)+1,q.front().second->left});
                    }
                    
                    if(q.front().second->right){
                        q.push({2*(currId)+2,q.front().second->right});
                    }
                
                q.pop();
            }
            
            maxWidth = max(maxWidth,last-first+1);
                             
                   
        }
        return maxWidth;
    }
};