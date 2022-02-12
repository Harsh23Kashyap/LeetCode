#include <bits/stdc++.h>
class Solution {
public:
    void tryThis(string curr,unordered_map<string,bool>& u, queue<pair<string,int>>& q, int dis)
    {
        for(int i=0;i<curr.length();i++)
        {
            string temp=curr;
            for(char ch='a';ch<='z';ch++)
            {
                if(temp[i]==ch) continue;
                temp[i]=ch;
                if(u.find(temp)!=u.end() and u[temp]==false)
                {
                    u[temp]=true;
                    q.push(make_pair(temp,dis+1));
                }
            }
        }
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
    {
        queue<pair<string,int>> q;
        unordered_map<string,bool> u;
        for(string s:wordList)
            u[s]=false;
        
        
        q.push(make_pair(beginWord,1));
        while(!q.empty())
        {
            auto it=q.front();
            string curr=it.first;
            int dis=it.second;
            //cout<<curr<<endl;
            q.pop();
            if(curr==endWord)
                return dis;
            
            tryThis(curr,u,q,dis);
        }
        return 0;
        
    }
};