class Solution {
public:
    bool possible(vector<int>& nums, int size, int  splits)
    {
        int count=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]+count>size)
            {
                count=nums[i];
                if(count>size)
                    return false;
                splits--;
                if(splits<=0)
                    return false;
            }
            else
            count+=nums[i];
            
            //cout<<" count"<<count<<endl;
        }
        if(splits<=0)
            return false;
        return true;
    }
    int splitArray(vector<int>& nums, int m) 
    {
        int low=*min_element(nums.begin(),nums.end());
        int high=accumulate(nums.begin(),nums.end(),0);
        int maxum=high;
        int mid=0;
        while(low<=high)
        {
            mid=(low+high)/2;
            //cout<<mid<<endl;
            if(possible(nums,mid,m))
            {
                //cout<<"runs"<<endl;
                maxum=min(maxum,mid);
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return maxum;
        
    }
};