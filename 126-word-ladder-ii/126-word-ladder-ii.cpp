class Solution {
public:
    void dfs(unordered_map<string,int> vis,vector<string> temp, vector<vector<string>> &ans, string ew,string bw,unordered_set<string> &s)
    {
        //cout<<ew<<endl;
        temp.push_back(ew);
        if(ew==bw)
        {
            //cout<<"RUns"<<endl;
            reverse(temp.begin(),temp.end());
            ans.push_back(temp);
            reverse(temp.begin(),temp.end());
            return;
        }
        for(int i=0;i<ew.size();i++)
        {
            string curr=ew;
            for(char ch='a';ch<='z';ch++)
            {
                curr[i]=ch;
                if(s.find(curr)!=s.end() and vis[curr]+1==vis[ew])
                    dfs(vis,temp,ans,curr,bw,s);
            }
        }
        
    }
     void pass(string curr,queue<string> &q, unordered_set<string> &s, unordered_map<string,int> &vis)
    {
        
         int path=vis[curr];
        for(int i=0;i<curr.size();i++)
        {
            string temp=curr;
            for(char ch='a';ch<='z';ch++)
            {
                temp[i]=ch;
                if(s.find(temp)!=s.end() and vis[temp]==-1)
                {
                    q.push(temp);
                    vis[temp]=path+1;
                }
            }
        }
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s(wordList.begin(),wordList.end());
        vector<vector<string>> ans;
        unordered_map<string,int> vis;
        for(auto it:wordList)
            vis[it]=-1;
        queue<string> q;
        vis[beginWord]=1;
        q.push(beginWord);
        while(!q.empty())
        {
            auto it=q.front();
            //cout<<it<<endl;
            q.pop();
            if(it==endWord)
               continue;
            //cout<<vis[it]<<" and "<<vis[endWord]<<endl;
            if(vis[endWord]==-1 or vis[it]<=vis[endWord])
                pass(it,q,s,vis);
        }
        
        // for(auto it:vis)
        // {
        //     cout<<it.first<<" "<<it.second<<endl;
        // }
        if(vis[endWord]!=-1)
        {
            s.insert(beginWord);
            vector<string> temp;
            dfs(vis,temp,ans,endWord, beginWord,s);
        }
        return ans;
    }
};