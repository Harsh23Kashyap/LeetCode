class Solution {
public:
    struct TrieNode
    {
        string data;
        unordered_map<string,TrieNode*> children;
        bool ends;
        TrieNode(string d)
        {
            data=d;
            ends=false;
        }
    };
    TrieNode *buildTrie(vector<string> &words) 
    {
        TrieNode *root = new TrieNode("/");
        for (int j = 0; j < words.size(); j++) 
        {
            string word = words[j];
            word+="/";
            TrieNode *curr = root;
            
            string sub="";
            for (int i = 0; i < word.size(); i++) 
            {
                while(i<word.size())
                {
                    sub+=word[i++];
                    if(word[i-1]=='/')
                    {
                        i--;
                        break;
                    }
                }
                
                //cout<<sub<<endl;
                if (curr->children.count(sub)==0) 
                    curr->children[sub] = new TrieNode(sub);
                
                curr = curr->children[sub];
            }
            curr->ends = true;
        }
        return root;
    }
    vector<string> removeSubfolders(vector<string>& folder) 
    {
        vector<string> ans;
        TrieNode *root = buildTrie(folder);
        
        queue<TrieNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TrieNode *curr=q.front();
            q.pop();
            if(curr->ends)
            {
                ans.push_back(curr->data.substr(0,curr->data.size()-1));
                continue;
            }
            
            for(auto it:curr->children)
            {
                //cout<<it.first<<" ";
                q.push(it.second);
                
            }
            //cout<<endl;
        }
        
        
        return ans;
        
        
    }
};