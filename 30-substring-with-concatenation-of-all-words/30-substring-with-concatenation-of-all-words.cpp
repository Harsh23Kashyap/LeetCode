class Solution {
public:
    bool possible(unordered_map<string,int> u,string s, int i, int c,int each)
    {
        //cout<<"Iteration at "<<i<<endl;
        for(int j=i;j<i+c*each;j+=each)
        {
            string temp=s.substr(j,each);
            //cout<<temp<<endl;
        if(u.find(temp)==u.end() or --u[temp]==-1)
            {
                //cout<<"false"<<endl;
                return false;
            }
        }
        // for(auto it:u)
        //     cout<<it.first<<" "<<it.second<<endl;
        return true;
    }
    vector<int> findSubstring(string s, vector<string>& words) 
    {
        vector<int> ans;
        int c=words.size();
        int each=words[0].size();
        unordered_map<string,int> u;
        for(int i=0;i<c;i++)
            u[words[i]]++;
        
        for(int i=0;i+(c*each)<=s.size();i++)
        {
            if(possible(u,s,i,c,each))
                ans.push_back(i);
            
        }
        return ans;
        
    }
};