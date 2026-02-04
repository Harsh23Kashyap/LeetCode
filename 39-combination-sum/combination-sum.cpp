class Solution {
public:
void dfs(set<vector<int>>& ans, vector<int>&c, int i, int t, vector<int> &pass){
    if(t==0){
        ans.insert(pass);
        return;
    }
    if(t<0 or i==c.size())
    return;

    //take
    pass.push_back(c[i]);
    dfs(ans, c, i,t-c[i],pass);
    pass.pop_back();

    //skip
    dfs(ans, c, i+1,t,pass);
}
    vector<vector<int>> combinationSum(vector<int>& c, int target) {
        sort(c.begin(),c.end());
        vector<vector<int>> ans;
        set<vector<int>> ta;
        vector<int> u;
         dfs(ta, c, 0, target, u);
         for(auto it:ta)
         ans.push_back(it);
         return ans;
    }
};