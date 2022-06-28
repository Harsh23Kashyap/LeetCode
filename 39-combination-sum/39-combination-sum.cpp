class Solution {
public:
    void check(vector<int>& candidates,vector<vector<int>> &ans,vector<int> &temp,int target, int i)
    {
        if (target<0 or i==candidates.size())
            return;
        if(target==0)
        {
            ans.push_back(temp);
            return;
        }
        
        temp.push_back(candidates[i]);
            check(candidates,ans,temp,target-candidates[i],i);
            //exclude
            temp.pop_back();
            check(candidates,ans,temp,target,i+1);
            
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        
        check(candidates,ans,temp,target,0);
        return ans;
        
    }
};