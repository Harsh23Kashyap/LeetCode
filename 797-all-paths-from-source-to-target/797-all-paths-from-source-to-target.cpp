class Solution {
public:
    void recursion(vector<vector<int>>& graph,int pos,vector<vector<int>>& res,vector<int>& ans)
    {
        if(pos==graph.size()-1)
        {
            res.push_back(ans);
            return;
        }
        else
        {
            for(int i=0;i<graph[pos].size();i++)
            {
                //if(pos==0) ans.push_back(0);
                ans.push_back(graph[pos][i]);
                recursion(graph,graph[pos][i],res,ans);
                ans.pop_back();
            }
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) 
    {
        vector<vector<int>> res;
        vector<int> ans;
        recursion(graph,0,res,ans);
        for(int i=0;i<res.size();i++)
        {
            res[i].insert(res[i].begin(),0);
        }
        return res;
    }
};