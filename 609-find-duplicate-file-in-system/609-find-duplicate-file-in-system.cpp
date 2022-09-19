class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) 
    {
       vector<vector<string>> ans;
        unordered_map<string,vector<string>> u;
        
        for(int i=0;i<paths.size();i++)
        {
            stringstream ss(paths[i]);
            string word;
            ss>>word;
            string fw=word+'/';
            while(ss>>word)
            {
                int ind=find(word.begin(),word.end(),'(')-word.begin();
                //cout<<ind<<endl;
                u[word.substr(ind+1)].push_back(fw+word.substr(0,ind));
                //cout<<word.substr(ind+1)<<endl;
            }
        }
        
        for(auto it: u)
        {
            //cout<<it.first<<endl;
            vector<string> temp;
            vector<string> v=it.second;
            for(int i=0;i<v.size();i++)
            {
                //cout<<v[i]<<"  ";
                temp.push_back(v[i]);
            }
            if(temp.size()>1)
                ans.push_back(temp);
        }
        return ans;
    }
};