class Solution {
public:
    unordered_map<string,vector<pair<string,double>>> m;
     void dfs(string num, string denom, set<string> visited ,double& res,double tmp)
    {
        if(visited.find(num)!=visited.end())
        {
            return;
        }
        else
        {
            visited.insert(num);
            if(num==denom)
            {
                res=tmp;
                return;
            }
            else
            {
                for(auto it:m[num])
                {
                    dfs(it.first,denom,visited,res,tmp*it.second);
                }
            }
        }
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) 
    {
        for(int i=0;i<equations.size();i++)
        {
            m[equations[i][0]].push_back({equations[i][1],values[i]});
            m[equations[i][1]].push_back({equations[i][0],1.0/values[i]});
        }
        
        vector<double> ans;
        
        for(int i=0;i<queries.size();i++)
        {
            string num=queries[i][0];
            string denom=queries[i][1];
            if(m.find(num)==m.end())
                ans.push_back(-1);
            else
            {
                set<string> visited;
                double res=-1.0;
                dfs(num,denom,visited,res,1.0);
                ans.push_back(res);
            }
        }
        return ans;
        
        
    }
};