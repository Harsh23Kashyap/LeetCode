class Solution {
public:
    void nextPermutation(vector<int>& nums) 
    {
        int i;
        for(i=nums.size()-2;i>=0;i--)
        {
            if(nums[i]<nums[i+1])
                break;
        }
        if(i==-1)
        {
            sort(nums.begin(),nums.end());
            return;
        }
        int c=0;
        int large=INT_MAX;
        for(int j=i+1;j<nums.size();j++)
        {
            if(nums[j]>nums[i] and large>nums[j])
            {
                c=j;
            }
        }
        swap(nums[i],nums[c]);
        sort(nums.begin()+i+1,nums.end());
        
    }
};


// 158476
    
// 158647