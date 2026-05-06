class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> ans;
        unordered_set<string> u(wordList.begin(),wordList.end());
        unordered_map<string, vector<string>> par;
        if(u.find(endWord)==u.end())
            return ans;
        queue<string> q;
        q.push(beginWord);

        unordered_set<string> visited;
        visited.insert(beginWord);
        bool found=false;
        while(!q.empty()){
            unordered_set<string> lev;
            int sz=q.size();
            while(sz--){
                auto it=q.front();
                q.pop();

                if(it==endWord){
                    found=true;
                    continue;
                }

                string temp=it;

                for(int i=0;i<temp.size();i++)
                {
                    string curr=temp;
                    for(char ch='a';ch<='z';ch++){
                        curr[i]=ch;

                        if(u.find(curr)!=u.end() and visited.find(curr)==visited.end()){
                            if(lev.find(curr)==lev.end())
                            {
                                q.push(curr);
                                lev.insert(curr);
                            }
                            par[curr].push_back(it);
                        }
                    }

                }
            }
            for(auto k:lev)
                visited.insert(k);
            if(found)
                break;
        }

        if(!found)
            return ans;

        vector<string> check;
        check.push_back(endWord);
        dfs(ans,check,endWord,beginWord,par);
        return ans;
    }
    void dfs(vector<vector<string>> &ans, vector<string> curr, string e, string b,  unordered_map<string, vector<string>> &par){

        if(e==b){
            reverse(curr.begin(),curr.end());
            ans.push_back(curr);
            return;
        }

        for(auto it:par[e]){
            curr.push_back(it);
            dfs(ans,curr,it,b,par);
            curr.pop_back();
        }
    }
};