class Solution {
public:
    bool recur(vector<bool> &vis,vector<int>&nums, int ind, int target, int k, int curr)
    {
        //cout<<k<<" "<<curr<<endl;
       if(k==1)
           return true;
        if(target==curr)
            return recur(vis,nums,0,target,k-1,0);
        if(ind==nums.size() or target<0)
            return false;
        
        for(int j=ind;j<nums.size();j++)
        {
            if(vis[j]==false and curr+nums[j]<=target)
            {
                vis[j]=true;
                if(recur(vis,nums,j+1,target,k,nums[j]+curr))
                    return true;
                vis[j]=false;
            }
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) 
    {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%k!=0)
            return false;
        int target=sum/k;
        sort(nums.begin(),nums.end(),greater<int>());
        if(nums[0]>target)
            return false;
        vector<bool> visited(nums.size(),false);
        return recur(visited,nums,0,target,k,0);
        
    }
};