class Solution {
public:
    void bitWise(vector<int>& nums,int i,vector<vector<int>>& ans,vector<int>& v,int ors,int ored)
    {
        
        if(i==nums.size())
        {
            
            if(ors==ored)
            {
                // for(int i:v)
                //     cout<<i<<" ";
                // cout<<endl;
                ans.push_back(v);
                //return;
            }
            return;
        }
        // Add it
        v.push_back(nums[i]);
        bitWise(nums,i+1,ans,v,ors|nums[i],ored);
        //Pop it
        v.pop_back();
        bitWise(nums,i+1,ans,v,ors,ored);
        
    }
    int countMaxOrSubsets(vector<int>& nums) 
    {
        vector<vector<int>> ans;
        vector<int> v;
        int ored=nums[0];
        int n=nums.size();
        for(int i=1;i<n;i++)
            ored=(nums[i]|ored);
        bitWise(nums,0,ans,v,0,ored);
        return ans.size();
        
    }
};