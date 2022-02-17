class Solution {
public:
    void recursive(vector<vector<int>>& ans, vector<int>& temp,vector<int>& candidates, int target,int i )
    {
        if(target<0)
            return;
        if(target==0)
        {
            ans.push_back(temp);
            return;
        }
        if(i==candidates.size())
            return;
        
        //include
        temp.push_back(candidates[i]);
        recursive(ans,temp,candidates,target-candidates[i],i);
        //exclude
        temp.pop_back();
        recursive(ans,temp,candidates,target,i+1);
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<vector<int>> ans;
        vector<int> temp;
        recursive(ans, temp,candidates,target,0);
        return ans;
        
    }
};