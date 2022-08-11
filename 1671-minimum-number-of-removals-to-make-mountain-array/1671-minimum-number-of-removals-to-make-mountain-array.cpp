class Solution {
public:
    int lis(vector<int>& nums, int ind,bool ahead)
    {
        vector<int> len;
        
        //LIS
        if(ahead)
        {
            len.push_back(nums[0]);
            for(int i=1;i<=ind;i++)
            {
                if(nums[i]>len[len.size()-1])
                    len.push_back(nums[i]);
                else
                {
                    int pos=lower_bound(len.begin(),len.end(),nums[i])-len.begin();
                    len[pos]=nums[i];
                }
            }
            return len.size();
        }
        //LDS
        len.push_back(nums[nums.size()-1]);
        for(int i=nums.size()-2;i>=ind;i--)
        {
            
            if(nums[i]>len[len.size()-1])
                len.push_back(nums[i]);
            else
            {
                int pos=lower_bound(len.begin(),len.end(),nums[i])-len.begin();
                len[pos]=nums[i];
            }
        }
        return len.size();
        
        
    }
    int minimumMountainRemovals(vector<int>& nums) 
    {
        int maxi=0;
        for(int i=0;i<nums.size();i++)
        {
            int len1=lis(nums,i,true);
            int len2=lis(nums,i,false);
            if(len1==1 or len2==1)
                continue;
            maxi=max(maxi,len1+len2-1);
        }
        return nums.size()-maxi;
        
    }
};