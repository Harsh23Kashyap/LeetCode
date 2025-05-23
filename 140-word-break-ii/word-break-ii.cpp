class Solution {
public:
vector<string> ans;
    struct trie{
        char ch;
        bool ends;
        trie *child[26];
        trie(char c){
            this->ch=c;
            for(int i=0;i<26;i++){
                child[i]=NULL;
            }
            ends=false;
        }
    };
    void insert(string word, trie *root){
        trie *curr=root;
        for(int i=0;i<word.size();i++){
            char cc=word[i];
            int pos=cc-'a';
            if(curr->child[pos]!=NULL){
                curr=curr->child[pos];
            }
            else{
                curr->child[pos]=new trie(cc);
                curr=curr->child[pos];
            }
        }
        curr->ends=true;
    }
    bool search(string word,trie *root){
        trie *curr=root;
        for(int i=0;i<word.size();i++){
            char cc=word[i];
            int pos=cc-'a';
            if(curr->child[pos]==NULL){
                return false;
            }
                curr=curr->child[pos];
        }
        return curr->ends;
    }
    void solve(int i, string s, unordered_set<string> ut, string cs){
        if(i==s.size())
        {
            ans.push_back(cs.substr(1));
            return;
        }

        for(int j=i+1;j<=s.size();j++){
            string sub=s.substr(i,j-i);
            if(ut.find(sub)!=ut.end()){
                solve(j,s,ut,cs+" "+sub);
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        // trie *root= new trie('/');
        unordered_set<string> uu(wordDict.begin(),wordDict.end());
        // for(auto it:wordDict){
        //     insert(it,root);
        // }
        solve(0,s,uu,"");
        return ans;
        
    }
};