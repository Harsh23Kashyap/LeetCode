class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) 
    {
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<pivot)
                ans.push_back(nums[i]);
        }
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==pivot)
                ans.push_back(nums[i]);
        }
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>pivot)
                ans.push_back(nums[i]);
        }
        // for(int i:ans)
        //     cout<<i<<" , "<<endl;
        return ans;
    }
};